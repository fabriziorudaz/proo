#include <stdio.h>

// Definición del tablero
char board[3][3] ;

char current_marker;
char current_player;

// Función para imprimir el tablero
void printBoard() {
for(int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
board[i][j] = 1;
if(board[i][j] == 1){
	printf(" * ", board[i][j]);
}
}
printf(" \n");
}
}
// Función para hacer una jugada
int placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return 1;
    }
    return 0;
}

// Función para verificar el ganador
int checkWinner() {
    // Verificar filas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }

    // Verificar columnas
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }

    // Verificar diagonales
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }

    return 0;
}

// Cambiar jugador
void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

int main() {
    int slot;
    int winner = 0;

    current_marker = 'X';
    current_player = 1;

    for (int i = 0; i < 9; i++) {
        printBoard();
        printf("Es el turno del jugador %d. Introduzca el número del lugar: ", current_player);
        scanf("%d", &slot);

        if (slot < 1 || slot > 9) {
            printf("Número inválido. Intente de nuevo.\n");
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            printf("Este lugar ya está ocupado. Intente de nuevo.\n");
            i--;
            continue;
        }

        winner = checkWinner();
        if (winner != 0) {
            printBoard();
            printf("¡El jugador %d gana!\n", winner);
            break;
        }

        swapPlayerAndMarker();
    }

    if (winner == 0) {
        printBoard();
        printf("Es un empate.\n");
    }

    return 0;
}
