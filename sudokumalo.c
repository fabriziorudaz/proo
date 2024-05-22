#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int isNumberRepeated(int sudoku[3][3], int row, int col) {
    int num = sudoku[row][col];

    // Verificar fila
    for (int i = 0; i < 3; i++) {
        if (i != col && sudoku[row][i] == num) {
            break;
        }
    }

    // Verificar columna
    for (int i = 0; i < 3; i++) {
        if (i != row && sudoku[i][col] == num) {
            break;
        }
    }

    // Verificar subgrupo (cuadrante)
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if ((i != row || j != col) && sudoku[i][j] == num) {
                return 1;
            }
        }
    }

    return 0; // El número no se repite
}


void generateSudoku(int sudoku[3][3]) {
    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Contador para llevar la cuenta de cuántos números aleatorios se han colocado
    int randomCount = rand() % 5 + 2; // Entre 2 y 6 números aleatorios

    // Llenar el sudoku con 0s
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sudoku[i][j] = 0;
        }
    }

    // Colocar números aleatorios
    while (randomCount > 0) {
        int row = rand() % 3;
        int col = rand() % 3;
        if (sudoku[row][col] == 0 && isNumberRepeated(sudoku, row, col)) { // Asegurarse de no sobrescribir un número existente
            sudoku[row][col] = rand() % 9 + 1; // Número aleatorio del 1 al 9
            randomCount--;
        }
    }
}



void printSudoku(int sudoku[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int sudoku[3][3];
    generateSudoku(sudoku);
    printSudoku(sudoku);
    return 0;
}
