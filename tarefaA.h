typedef struct cruzada{
    char** matriz;
    int linha;
    int coluna;
    int numOcorrencias;
    int numRec;

}tipoCruzada;

void imprime(char **m, int c, int l);
void leArquivo(tipoCruzada *c, char **m);
int valida(int linha, int coluna, int x, int y, int TamPalavra, int posPalavra);
