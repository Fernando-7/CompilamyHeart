# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "analex.h" //Funcao do do analisador lexico
int main()
{

    FILE *arquivo = fopen("teste_analisador_lexico.txt","rt");
    Analizador_lexico(arquivo);
}
