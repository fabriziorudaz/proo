#include <stdio.h>
#include <stdlib.h>


int main() {
    // precios viandas: vegetales, carne, pescado, frutas
    float precios[4] = {10.0, 20.0, 15.0, 8.0};

   // variables que acumulan
    int ventasSup4 = 0;
    float gananciaViandas[4] = {0.0, 0.0, 0.0, 0.0};
    int cantViandasOperadores[7] = {0, 0, 0, 0, 0, 0, 0};
    float comOperadores[7] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    	
		printf("ingrese datos de los pedidos  o  ingrese 0 para terminar.\n");

    while (1) {
        int operador, tipoVianda, cantidad;
        
        // entrada para el operador
        printf("Operador 1-7 y si es 0 termina: ");
        scanf("%d", &operador);

        if (operador == 0) break; // si el operador es igual a 0 sale 
        if (operador < 1 || operador > 7) {
            printf("Operador inválido. Intente de nuevo.\n");
            continue;
        }
        
        

        // entrada del tipo de vianda
        printf("Tipo de vianda 0=vegetales, 1=carne, 2=pescado, 3=frutas:\n ");
        scanf("%d", &tipoVianda);

        if (tipoVianda < 0 || tipoVianda > 3) {
            printf("Tipo de vianda inválido. Intente de nuevo.\n");
            continue;
        }
        
        
        

        // entrada de la cantidad de vianda qu puede haber
        printf("cantidad: \n");
        scanf("%d", &cantidad);

        if (cantidad <= 0) {
            printf("cantidad invalida. Intente de nuevo.\n");
            continue;
        }




        // calcular las ventas y las comisiones
        float totalVenta = precios[tipoVianda] * cantidad;
        gananciaViandas[tipoVianda] += totalVenta;
        cantViandasOperadores[operador - 1] += cantidad;

        if (cantidad > 4) {
            ventasSup4++;
            comOperadores[operador - 1] += totalVenta * 0.03; // comision extra para las venta mayores de 4
        }

        comOperadores[operador - 1] += totalVenta * 0.10; // la comision base
    }
     
     printf("\n ------------------------------------------------------RESULTADOS-------------------------------------------------------- \n");
     printf("\n");
     
     
    // ventas qu superan las 4 unidades 
    printf("cantidad de ventas que superan las 4: %d\n", ventasSup4);


    // ganancias por tipo de vianda 
    printf("\n   ganancia por tipo de vianda:\n");
    printf("vegetales: %.2f\n", gananciaViandas[0]);
    printf("carne: %.2f\n", gananciaViandas[1]);
    printf("pescado: %.2f\n", gananciaViandas[2]);
    printf("frutas: %.2f\n", gananciaViandas[3]);
    
    

    // cantidad de viandas vendidas por operador y comisiones
    printf("\n      cantidad de viandas vendidas por operador y su comisión:\n");
    
    
    for (int i = 0; i < 7; i++) {
        printf("Operador %d: %d viandas, comision: %.2f\n", i + 1, cantViandasOperadores[i], comOperadores[i]);
    }

    return 0;
}
