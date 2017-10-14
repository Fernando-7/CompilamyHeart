# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

char operadores[] = {'/','+','-','*','%'};
char sinais[]     = {'.',';',':','(',')','[',']','{','}','=','/','*'};
char numeros []   = {'0','1','2','3','4','5','6','7','8','9'};
char alfabeto []  = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B',
                     'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','_'};

char *palavras_reservadas [] = {"senao","enquanto","semparam","semretorno","retorne",
                                 "inteiro","caractere","real","booleano","se","do","true","false"};


typedef struct a{ // estrutura que armazenará alguma coisa que n sei explicar

    char valor[1000];
    char categoria[1000];
    int codigo;

}estrutura;

# define palavra 2
# define sn_maior 5
# define sn_menor 51
# define sn_ptvirg 6
# define sn_caractere 40
# define sn_ou 42
# define sn_menos 8
# define sn_negativo 43
# define sn_diferente 10
# define sn_igual 16
# define sn_igual_igual 17
# define sn_soma 21
# define sn_multiplicacao 18
# define sn_and 29
# define sn_divisao 23
# define sn_comentario 27
# define sn_atribuicao 32
# define sn_eof 13
# define num_real 37
# define num_inteiro 34
# define sn_abrirParenteses 19
# define sn_fecharParenteses 20
# define sn_AbrirColchetes 11
# define sn_fecharColchetes 12
# define sn_abrirChaves 14
# define sn_fecharChaves 7



int cont_line = 1; // conta linha
//-------------------------
//Variaveis para armazenar os tokens processados
int cont_codigo = 0;
estrutura codigo[1000];
//-------------------------
int check_letra(char caractere){ // Confere se o caractere é uma letra

    int cont;
    int aux =  sizeof(alfabeto)/sizeof(alfabeto[0]);

    for(cont = 0; cont < aux; cont++){
            if(caractere == alfabeto[cont]){
                return 1;
            }
    }

    return 0;
}

int check_marcadores(char caractere){

    int cont,cont2;
    int aux =  sizeof(operadores)/sizeof(operadores[0]);
    int aux2 =  sizeof(sinais)/sizeof(sinais[0]);

    for(cont = 0; cont < aux; cont++){
            if(caractere == operadores[cont]){
                return 1;
            }
    }

    for(cont2 = 0; cont2 < aux2; cont2++){
            if(caractere == sinais[cont2]){
                return 1;
            }
    }

    return 0;
}

int check_sinal(char caractere){ //checa se o solicitado é um sinal

    int cont;
    int aux =  sizeof(sinais)/sizeof(sinais[0]);

    for(cont = 0; cont < aux; cont++){
            if(caractere == sinais[cont])
                return 1;
    }

    return 0;
}

void check_palavra_reservada(char *cadeia){ // confere se a palavra formada é uma palavra reservada IMPORTANTE
    int cont;
    int aux = sizeof(palavras_reservadas)/sizeof(palavras_reservadas[0]);
    int flag = 0;

 //   strcpy(codigo[cont_codigo].valor,cadeia);

    for(cont = 0; cont < aux; cont++){

        if(strcmp(cadeia,palavras_reservadas[cont]) == 0){
            flag = 1;
            strcpy(codigo[cont_codigo].categoria,"PR");
            break;
        }
    }

    if(flag == 0){
            strcpy(codigo[cont_codigo].categoria,"ID");
    }

    cont_codigo++;

}

int estado = 0;
char armazenamento[100];
estrutura codigo [1000];

void Analizador_lexico(FILE *arq){

     char conferidor;
     int contador = 0;
     char auxiliador[1000];

     do{
        conferidor = fgetc(arq);

        switch (estado){

            case 0:

                if(conferidor == ';'){
                    estado = 6;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '>' || conferidor == '<' ){
                    estado = 3;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(isdigit(conferidor)){
                    estado = 33;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(isalpha(conferidor)){
                    estado = 1;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '-'){
                    estado = 8;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '/'){
                    estado = 22;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == ':'){
                    estado = 30;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '&'){
                    estado = 28;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '='){
                    estado = 15;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '!'){
                    estado = 9;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '+'){
                    estado = 21;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '*'){
                    estado = 18;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == EOF){
                    estado = 13;
                }else if(conferidor == '('){
                    estado = 19;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == ')'){
                    estado = 20;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '['){
                    estado = 11;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == ']'){
                    estado = 12;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '{'){
                    estado = 14;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '}'){
                    estado = 7;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '|'){
                    estado = 41;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor =='"'){
                    estado = 38;
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == 10 || conferidor == 13){ //enter
                    cont_line++;

                }else if(conferidor != 32 && conferidor != 9){ //espaço e tab

                    printf("Erro lexico encontrado na linha %d, expressao nao corresponde a gramatica",cont_line);
                    exit(1);
                }
            break;
            case 1:
                if(isdigit(conferidor) || isalpha(conferidor) || conferidor =='_'){
                    auxiliador[contador] = conferidor;
                    contador++;

                }else{
                    ungetc(conferidor,arq);
                    estado = 2;
                }

            break;
            case 2:

                    ungetc(conferidor,arq);
                    check_palavra_reservada(auxiliador);
                    estado = 0;
                    contador = 0;
                    memset(&auxiliador[0],0,sizeof(auxiliador));
            break;
            case 3:
                if(conferidor == '='){
                    estado = 4;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    ungetc(conferidor,arq);
                    estado = 5;
                }
            break;
            case 4:
                if(strcmp(auxiliador,"<=") == 0){
                    ungetc(conferidor,arq);
                    strcpy(codigo[cont_codigo].valor,auxiliador);
                    strcpy(codigo[cont_codigo].categoria,"Sinal_Menor_igual");
                    memset(&auxiliador[0],0,sizeof(auxiliador));
                    contador = 0;
                    estado = 0;
                    cont_codigo++;
                }else if (strcmp(auxiliador,">=") == 0){
                    ungetc(conferidor,arq);
                    strcpy(codigo[cont_codigo].valor,auxiliador);
                    strcpy(codigo[cont_codigo].categoria,"Sinal_Maior_igual");
                    memset(&auxiliador[0],0,sizeof(auxiliador));
                    contador = 0;
                    estado = 0;
                    cont_codigo++;

                }
            break;
            case 5:
                if(strcmp(auxiliador,">") == 0){
                    ungetc(conferidor,arq);
                    strcpy(codigo[cont_codigo].valor,auxiliador);
                    strcpy(codigo[cont_codigo].categoria,"Sinal_Maior");
                    memset(&auxiliador[0],0,sizeof(auxiliador));
                    contador = 0;
                    estado = 0;
                    cont_codigo++;

                }else if(strcmp(auxiliador,"<") == 0){
                    ungetc(conferidor,arq);
                    strcpy(codigo[cont_codigo].valor,auxiliador);
                    strcpy(codigo[cont_codigo].categoria,"Sinal_Menor");
                    memset(&auxiliador[0],0,sizeof(auxiliador));
                    contador = 0;
                    estado = 0;
                    cont_codigo++;
                }
            break;
            case 6:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Sinal_ponto_Virgula");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 7:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Sinal_fecha_chaves");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 8:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Operador_menos");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 9:
                if(conferidor == '='){
                    estado = 10;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    ungetc(conferidor,arq);
                    estado = 43;
                }
            break;
            case 10:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Operador_diferente");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 11:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Sinal_abre_cochetes");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 12:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Sinal_fecha_cochetes");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 13:
                exit(1);
            break;
            case 14:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Sinal_abre_chaves");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 15:
                if(conferidor == '='){
                    estado = 17;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    ungetc(conferidor,arq);
                    estado = 16;
                }
            break;
            case 16:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Operador_igual");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 17:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Operador_igual_igual");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 18:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Operador_multiplicacao");
                memset(&auxiliador[0],0,sizeof(auxiliador));;
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 19:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Sinal_Abrir_Aspas");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 20:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Fechar_Abrir_Aspas");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 21:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Sinal_Soma");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 22:
                if(conferidor == '*'){
                    estado = 24;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    ungetc(conferidor,arq);
                    estado = 23;
                }
            break;
            case 23:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Sinal_Dividir");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 24:

                if(conferidor == 13)
                    cont_line++;

                    auxiliador[contador] = conferidor;
                    contador++;
                    estado = 25;
            break;
            case 25:
                if(conferidor == '*'){
                    estado = 26;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else if(conferidor == 13){
                    auxiliador[contador] = conferidor;
                    contador++;
                    cont_line++;
                }else{
                    auxiliador[contador] = conferidor;
                    contador++;
                }
            break;
            case 26:
                if(conferidor == '/'){
                    estado = 27;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    printf("Erro lexico linha %d",cont_line);
                    exit(1);
                }
            break;
            case 27:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"comentario");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 28:
                if(conferidor == '&'){
                    estado = 29;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    printf("Erro lexico linha %d",cont_line);
                    exit(1);
                }
            break;
            case 29:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"Operador_And");
                strcpy(auxiliador,"");
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 30:
                if(conferidor == ':'){
                    estado = 31;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    printf("Erro lexico linha %d",cont_line);
                    exit(1);
                }
            break;
            case 31:
                if(conferidor == '='){
                    estado = 32;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    printf("Erro lexico linha %d",cont_line);
                    exit(1);
                }
            break;
            case 32:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"atribuicao");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 33:
                if(isdigit(conferidor)){
                    auxiliador[contador] = conferidor;
                    contador++;

                }else if(conferidor == '.'){
                    estado = 35;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    ungetc(conferidor,arq);
                    estado = 34;
                }
            break;
            case 34:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"inteiro");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 35:
                if(isdigit(conferidor)){
                    estado = 36;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    printf("Erro lexico linha %d",cont_line);
                    exit(1);
                }
            break;
            case 36:
                if(isdigit(conferidor)){
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    ungetc(conferidor,arq);
                    estado = 37;
                }
            break;
            case 37:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"real");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 38:
                 if(isalpha(conferidor)){
                    estado = 39;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    printf("Erro no analisador lexico %d", cont_line);
                }
            break;
            case 39:
                if(conferidor == '"'){
                    estado = 40;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    printf("Erro no analisador lexico %d", cont_line);
                }
            break;
            case 40:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"caractere");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 41:
                if(conferidor == '|'){
                    estado = 42;
                    auxiliador[contador] = conferidor;
                    contador++;
                }else{
                    printf("Erro no analisador lexico %d", cont_line);
                }
            break;
            case 42:
                ungetc(conferidor,arq);
                strcpy(codigo[cont_codigo].valor,auxiliador);
                strcpy(codigo[cont_codigo].categoria,"ou");
                memset(&auxiliador[0],0,sizeof(auxiliador));
                contador = 0;
                estado = 0;
                cont_codigo++;
            break;
            case 43:
                ungetc(conferidor,arq);
                    strcpy(codigo[cont_codigo].valor,auxiliador);
                    strcpy(codigo[cont_codigo].categoria,"Negacao");
                    memset(&auxiliador[0],0,sizeof(auxiliador));
                    contador = 0;
                    estado = 0;
                    cont_codigo++;
            break;
        }
     }while(!feof(arq));
     printf(" cont_line %d\n",cont_line);
     int novo;
      for(novo = 0; novo < cont_codigo;novo++){
        printf("%s \n",codigo[novo].categoria);
      }

}

int main()
{
   // printf("dcdcd %s",palavras_reservadas[9]);
    FILE *arquivo = fopen("teste.txt","rt");
    Analizador_lexico(arquivo);
}
