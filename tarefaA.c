#include "tarefaA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
void initStats(tipoCruzada *c){
    c->numOcorrencias =0;
}
int **alocarMatriz(int Linhas, int Colunas)
{
    int i, j;

    char **m = (char **)malloc(Linhas * sizeof(char *));

    for (i = 0; i < Linhas; i++) //Percorre as linhas do Vetor de Ponteiros
    {
        m[i] = (char *)malloc(Colunas * sizeof(char)); //Aloca um Vetor de Inteiros para cada posi��o do Vetor de Ponteiros.
        for (j = 0; j < Colunas; j++)
        {
            m[i][j] = '*';
        }
    }
    return m;
}
void inicializarCruzada(tipoCruzada *c)
{
    int i;
    c->matriz = (char **)malloc(c->linha * sizeof(char *));

    for (i = 0; i < c->linha; i++)
    {
        c->matriz[i] = (char *)malloc(c->coluna * sizeof(char));
    }
}
void imprime(char **m, int c, int l)
{
    int i, j;
    for (i = 0; i < l; i++)
    {

        for (j = 0; j < c; j++)
        {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }
}
void leArquivo(tipoCruzada *c, char **m)
{
    FILE *arq;
    int i, j;
    int linha, coluna;
    char car;
    arq = fopen("arq.txt", "r");

    if (arq == NULL)
    {
        printf("N�o foi possivel abrir o arquivo desejado!\n");
        return;
    }
    else
    {
        fscanf(arq, "%d %d\n", &linha, &coluna);
        c->linha = linha;
        c->coluna = coluna;
        inicializarCruzada(c);
        while (!feof(arq))
        {
            for (i = 0; i < c->linha; i++)
            {
                for (j = 0; j < c->coluna; j++)
                {
                    fscanf(arq, "%c ", &car);
                    c->matriz[i][j] = car;
                }
            }
        }
    }

    //imprime(c->matriz, c->linha, c->coluna);
}
int valida(int linha, int coluna, int x, int y, int tamPalavra, int posPalavra)
{
    if (x < linha && y < coluna && posPalavra < tamPalavra && x >= 0 && y >= 0)
        return 1;
    return 0;
}
int procura(tipoCruzada *c, char **m, char *nome, int x, int y, int posPalavra, int direcao)
{
    printf("%d - %d\n", x, y);
    printf("direcao = %d\n", direcao);
    if (posPalavra == strlen(nome) - 1)
    {
        m[x][y] = nome[posPalavra];
        if (c->matriz[x][y] == nome[posPalavra]){
            c->numOcorrencias++;
            return 1;}

        m[x][y] = '*';
        return 0;
    }

    if (valida(c->linha, c->coluna, x, y, strlen(nome), posPalavra))
    {
        /* if (y != (c->coluna - 1))
        {

            procura(c, m, nome, x, y + 1, 0, 0);
        }
        else
        {

            procura(c, m, nome, x + 1, 0, 0, 0); //Movimento para direita
        }*/

        if (c->matriz[x][y] == nome[posPalavra])
        {
            m[x][y] = nome[posPalavra];
            if (direcao == 0)
            {
                if (procura(c, m, nome, x, y + 1, posPalavra + 1, 1))
                    return 1;
                //procura(c, m, nome, x, y - 1,  posPalavra+1, 2);
                if (procura(c, m, nome, x + 1, y, posPalavra + 1, 3))
                    return 1;
                if (procura(c, m, nome, x, y - 1, posPalavra + 1, 1))
                    return 1;
            }
            if (direcao == 1)
            {
                // procura(c, m, nome, x, y + 1, posPalavra+1, 1);
                if (procura(c, m, nome, x + 1, y, posPalavra + 1, 3))
                    return 1;
            }
            // if(direcao==2)
            // {
            //     //procura(c, m, nome, x, y + 1, posPalavra+1, 1);
            //     //procura(c, m, nome, x, y - 1,  posPalavra+1, 2);
            //     if(procura(c, m, nome, x+1, y, posPalavra+1, 3))
            //         return 1;

            // }
            if (direcao == 3)
            {
                if (procura(c, m, nome, x, y + 1, posPalavra + 1, 1))
                    return 1;
                if (procura(c, m, nome, x, y - 1, posPalavra + 1, 1))
                    return 1;
                //procura(c, m, nome, x, y - 1,  posPalavra+1, 2);
                //procura(c, m, nome, x+1, y,  posPalavra+1, 3);
            }
            m[x][y] = '*';
            return 0;
        }
        else
        {
            if (y != (c->coluna - 1))
            {

                procura(c, m, nome, x, y + 1, 0, 0);
            }
            else
            {

                procura(c, m, nome, x + 1, 0, 0, 0); //Movimento para direita
            }
        }
    }
    return 0;
}
