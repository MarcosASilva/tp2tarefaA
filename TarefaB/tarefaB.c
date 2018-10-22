#include <stdio.h>
#include <stdlib.h>
#include "tarefaB.h"
#define N 9

void leArquivo(tipoSudoku *s)
{
    FILE *arq;
    int i, j;
    char car;
    arq = fopen("arq.txt", "r");

    if (arq == NULL)
    {
        printf("N�o foi possivel abrir o arquivo desejado!\n");
        return;
    }
    else
    {
        while (!feof(arq))
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    fscanf(arq, "%c ", &car);
                    s->matrizS[i][j] = car;
                }
            }
        }
    }
}
void imprime(tipoSudoku *s)
{
    int i, j;
    for (i = 0; i < N; i++)
    {

        for (j = 0; j < N; j++)
        {
            printf("%c", s->matrizS[i][j]);
        }
        printf("\n");
    }
}
int verificaCol(tipoSudoku *s, int num, int col)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (s->matrizS[i][col] == num)
            return 1;
    }
    return 0;
}
int verificaLin(tipoSudoku *s, int num, int lin)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (s->matrizS[lin][i] == num)
            return 1;
    }
    return 0;
}
int verificaGrid(tipoSudoku *s, int num, int col, int lin)
{
    int i, j;
    for (i = 0; i < N / 3; i++)
    {
        for (j = 0; j < N / 3; j++)
        {
            if (s->matrizS[i + lin][j + col] == num)
                return 1;
        }
    }
    return 0;
}
int valida(tipoSudoku *s, int num, int col, int lin)
{
    if (!verificaCol(s, num, col) && !verificaLin(s, num, lin) && !verificaGrid(s, num, col, lin))
        return 1;
    return 0;
}
int encontraVazio(tipoSudoku *s){
    int i, j;
    for(i=0;i<N;i++0){
        for(j=0;j<N;j++){
            if(s->matrizS==0)
            return 1;
        }
    }
    return 0;

}
int solucionaSudoku(tipoSudoku *s){
    int i,j;
}