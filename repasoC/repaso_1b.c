#include <stdio.h>
#include <stdlib.h>


int main(){
   int sb, v1, v2, v3;
   printf("ingrese sueldo base");
     scanf("%d", &sb);
   printf("ingrese venta 1");
     scanf("%d", &v1);
   printf("ingrese venta 2 ");
     scanf("%d", &v2);
   printf("ingrese venta 3");
     scanf("%d", &v3);

   int comision= (v1+v2+v3)*0.10;
        printf("el sueldo del vendedor es de %d", sb+comision);

   return 0;         
}
