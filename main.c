#include <stdio.h>
#include <stdlib.h>
#include "tarefaA.c"
int main()
{

    char **m, **matriz;
    FILE *arq;
    int i, j, linha, coluna;
    tipoCruzada cruzada;
    leArquivo(&cruzada, m);

    m = alocarMatriz(cruzada.linha, cruzada.coluna);
    initStats(&cruzada);
    for (i = 0; i < cruzada.linha; i++)
    {
        for (j = 0; j < cruzada.coluna; j++)
        {
            procura(&cruzada, m, "casa", i, j, 0, 0);
        }
    }
    // procura(&cruzada, m, "casa", 0, 0, 0, 0);
    //printf("oi:%c",m[0][1]);
    printf("\n");
    printf("\n");
    printf("\n");
    imprime(m, cruzada.linha, cruzada.coluna);
    printf("Numero de ocorrencias da palavra procurada: %d\n", cruzada.numOcorrencias);
    printf("Numero de chamadas recursivas: %d\n", cruzada.numRec);
}
