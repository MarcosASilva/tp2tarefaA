#include <stdio.h>
#include <stdlib.h>
#include "tarefaA.c"
int main()
{

    char **m, **matriz;
    FILE *arq;
    int i,linha,coluna;
    tipoCruzada cruzada;
    leArquivo(&cruzada,m);

    m = alocarMatriz(cruzada.linha, cruzada.coluna);
    initStats(&cruzada);
    procura(&cruzada, m, "casa", 0, 0, 0, 0);
    //printf("oi:%c",m[0][1]);
    printf("\n");
    printf("\n");
    printf("\n");
    imprime(m, cruzada.linha, cruzada.coluna);
    printf("%d", cruzada.numOcorrencias);
    system("pause");

}
