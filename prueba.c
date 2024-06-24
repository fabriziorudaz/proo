// Rudaz Fabrizio hecho en dev++

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor | bgColor);
}


//aqui voy a  poner una funcion la cual me almacene la cantidad de alfajores 

 void alfajores (char * alfaj[], int cantidades[], int cajas){

 srand(time(NULL));
 //estos son los tipos de alfajopres que tengo
    char *tipos_alfaj[3] = {"chocolate", "ddl", "fruta"};

    for (int i = 0; i < cajas; i++) {
        printf("La caja contiene estos alfajores:\n");
        for (int j = 0; j < 3; j++) {
            int cantidad = rand() % 101; // Genera una cantidad aleatoria entre 0 y 100
            cantidades[j] += cantidad;
			  // Suma la cantidad de alfajores al tipo correspondiente
			  setColor(15, 200);
            printf("%s: %d\n", tipos_alfaj[j], cantidad);
        } 
        printf("\n");
    }
}

void ganancia_error(int produccion_empleado[][3], int fuera_produccion) {
    printf("Producción por empleado y tipo de alfajor:\n");
    // esto me va adar la cantidad de alfajores de cada tipo que preparo cada empleado
    for (int i = 0; i < 6; i++) {
        printf("Empleado %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Tipo %d: %d\n", j + 1, produccion_empleado[i][j]);
        }
        printf("\n");
    }
    
    if(fuera_produccion != 0){
	printf("ERROR\n");
	//aqui la cantidad de que fueron hechos fuera de produccion
    printf("Cantidad de alfajores fuera de producción: %d\n", fuera_produccion);
}
}

int main() {
	srand(time(NULL));
    char *tipos_alfaj[3] = {"chocolate", "ddl", "fruta"};
    int produccion_empleado[6][3] = {0};
    int fuera_produccion = rand () % 3 ;
    int cajas;
    puts ("ingrese la cantidad de cajas que desee");
    scanf("%d ", &cajas);
    
    // Llamada a la función para simular la producción de cajas de alfajores
    alfajores (tipos_alfaj, produccion_empleado, cajas);

    // Llamada a la función para mostrar la producción por empleado y tipo de alfajor
    ganancia_error(produccion_empleado, fuera_produccion);

    return 0;
}
    // Llamada a la función para mostrar la producción por empleado y tipo de alfajor
    ganancia_error(produccion_empleado, fuera_de_produccion);

    return 0;
}
