#include <stdio.h>
#include <stdlib.h>
#include "tarefaB.c"

int main(){
int i, j;
tipoSudoku sudoku;
leArquivo(&sudoku);
solucionaSudoku(&sudoku);
imprime(&sudoku);


}