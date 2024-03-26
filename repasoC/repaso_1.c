#include<stdio.h>

int main(){
int alumnos, precio_total, precio_alumno ;

scanf("%d", &alumnos);

switch(alumnos){
case 1:
if(alumnos >= 100){
precio_total = alumnos * 500;
printf("pago del alquiler %d y por alumno 500\n", precio_total);};
break;
case 2:
if(alumnos >= 50 && alumnos < 100){
precio_total= alumnos * 400;
printf("pago del alquiler %d y por alumno 400\n", precio_total);};
break;
case 3:
if (alumnos >= 30 && alumnos < 50){
precio_total = alumnos * 300;
printf("pago del alquiler %d y por alumno 300\n", precio_total);};
break;
default:
if(alumnos < 30){
precio_alumno= 6000 / alumno;
printf("pago del alquiler 6000 y por alumno %d\n", precio_alumno);}
}
return 0;
}
