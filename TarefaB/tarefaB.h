typedef struct sudoku{
    int matrizS[9][9];
    int qtdTentativas;
}tipoSudoku;

void leArquivo(tipoSudoku *s);