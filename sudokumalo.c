#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor | bgColor);
}


int isNumberRepeated(int sudoku[9][9], int row, int col, int randome) {
    // Hace el recorrido de el array verificando cada lugar
     
    for (int i = 0; i < 9; i++) {
        // Se fija si en la fila o columna está repetido el número
        if (sudoku[row][i] == randome || sudoku[i][col] == randome) {
            return 1; // El número está repetido
        }
    }

    // Verificar si el número ya está en el subcuadro 3x3
    // Estos dos hacen que nos demos una idea de en qué cuadro se encuentran
    // con la división de el row y col resto de 3 queda el número de la celda y multiplica por 3 que da el índice de ese cuadro
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (sudoku[i][j] == randome) {
                return 1; // El número está repetido
            }
        }
    }
 
    return 0; // El número no se repite
}

void generateSudoku(int sudoku[9][9]) {
    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Llenar el sudoku con 0
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = 0;
        }
    } 

    // Colocar al menos un número en cada subcuadro 3x3
    // Se usa cada cuadro 3x3 por eso suma de 3 en 3
    for (int startRow = 0; startRow < 9; startRow += 3) {
        for (int startCol = 0; startCol < 9; startCol += 3) {
            int randome;
            int row, col;
            // Se repite hasta que sea válido
            do {
                randome = rand() % 9 + 1;
                row = startRow + rand() % 3;
                col = startCol + rand() % 3;
            } while (isNumberRepeated(sudoku, row, col, randome));
            
            sudoku[row][col] = randome;
        }
    }

    // Añadir números adicionales aleatoriamente
    int additionalNumbers = rand() % 11 + 10; // Entre 10 y 20 números aleatorios adicionales
    while (additionalNumbers > 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        int randome = rand() % 9 + 1;
        if (sudoku[row][col] == 0 && !isNumberRepeated(sudoku, row, col, randome)) { // Asegurarse de no sobrescribir un número existente
            sudoku[row][col] = randome; // Asignar el número aleatorio
            additionalNumbers--;
        }
    }
}

	void printSudoku(int sudoku[9][9]) {
   
    printf("  ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", i + 1);
        if ((i + 1) % 3 == 0) {
            printf("  "); // Extra space after every third number
        }
    }
    printf("\n");

   
    for (int i = 0; i < 9; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
            if ((j + 1) % 3 == 0 && j != 8) {
                printf("| "); // Vertical line after every third number in a block
            }
        }
        printf("\n");

        if ((i + 1) % 3 == 0 && i != 8) {
            // Print horizontal line after every third row
            printf("  ------+-------+------\n");
        }
    }
}

int playSudoku(int sudoku[9][9], int row, int col, int n) {
    // Verifica si la posición está dentro de los límites del sudoku
    if (row < 0 || row >= 9 || col < 0 || col >= 9) {
        printf("Posición inválida.\n");
        return 1;
    }
    
    // Verifica si la celda está vacía
    if (sudoku[row][col] != 0) {
        printf("Cambio su numero .\n");
        sudoku[row][col] = n;
        return 1;
    }

    // Verifica si el número es válido en esa posición
    if (isNumberRepeated(sudoku, row, col, n)) {
        printf("El número no es válido en esa posición.\n");
        
        
        //hay que hacer otro color los numeros que esten mal
          setColor(15, 200); 
		sudoku[row][col] = n;
        printf("%d ", sudoku[row][col]);
        setColor(15, 0);
        printf("\n");
        
     
        
        return 1;
    }
    

    // Coloca el número en la posición especificada
    sudoku[row][col] = n;
    return 1;
    
    if(sudoku != 0 && isNumberRepeated(sudoku, row, col, n) ){
    	printf("GANASTEEEEE");
	}
}

int main() {
    int elec;
    while(1) {
        printf("Menu sudoku\n");
        printf("1- Jugar sudoku\n");
        printf("2- Reglas sudoku\n");
        scanf("%d", &elec);
        switch (elec) {
            case 1: {
                int sudoku[9][9];
                generateSudoku(sudoku);
                int n, row, col;
				printSudoku(sudoku);
				getchar(); 
				 while(1){ 
                printf("Ingrese la fila (A-I), columna (1-9) y el número que desea colocar: ");
                scanf(" %c%d %d", &row, &col, &n);
                	system("cls");	
                row -= 'A'; // Convertir la letra de fila a índice de matriz
                col--; 
				 // Ajustar el índice de columna de 0 a 8
                playSudoku(sudoku, row, col, n);
                printSudoku(sudoku);
				 getchar();
            }
        
        }
            case 2: {
                printf("El Sudoku se juega en una cuadrícula de 9x9, dividida en 9 subcuadros de 3x3.\n"
                       "El objetivo es llenar todas las celdas vacías con números del 1 al 9.\n"
                       "Para hacerlo, debes seguir estas reglas:\n"
                       "- Cada fila debe contener los números del 1 al 9, sin repetir.\n"
                       "- Cada columna debe contener los números del 1 al 9, sin repetir.\n"
                       "- Cada subcuadro 3x3 debe contener los números del 1 al 9, sin repetir.\n"
                       "Para jugar Sudoku, comienza con las pistas iniciales que ya están colocadas en la cuadrícula.\n"
                       "Usa estos números como referencia para rellenar las celdas vacías.\n"
                       "Busca celdas vacías y determina qué números del 1 al 9 pueden ir en esas celdas sin violar las reglas de fila, columna y subcuadro 3x3.\n"
                       "Utiliza la deducción lógica para eliminar opciones incorrectas y deducir los números correctos.\n"
                       "Asegúrate de que cada número del 1 al 9 aparezca solo una vez por fila, columna y subcuadro 3x3.\n\n"
                       "Presione cualquier tecla para continuar...");
                getchar(); // Consumir el salto de línea
                getchar(); // Esperar a que el usuario presione una tecla
                break;
            }
            default:{
            	printf("opcion invalida down");
				break;
			}
        };
        system("cls");
    };
}

