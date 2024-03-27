#include<stdio.h>


int main (){
    float cp1, cp2, cp3, ef, tf;

     printf("ingrese calificacion parcial 1 ");
     scanf("%d", &cp1);
      printf("ingrese calificacion parcial 2 ");
     scanf("%d", &cp2);
     printf("ingrese calificacion parcial 2 ");
     scanf("%d", &cp3);
      printf("ingrese examen final");
     scanf("%d", &ef);
      printf("ingrese trabajo final ");
     scanf("%d", &tf);

     float calificacion = 0.55 * ((cp1+cp2+cp3)/3) + 0.30 * ef + 0.15 * tf;

     printf("la calificacion final del alumno fue %.2f", calificacion);

     return 0;
     
}
