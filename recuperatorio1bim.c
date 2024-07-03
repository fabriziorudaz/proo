#include <stdio.h>
#include <stdlib.h>


int main (){
	while(1){
	
	puts("organizacion del viaje de estudios: 1");
	puts("recibo del sueldo: 2");
	puts("calificacion: 3");
	puts("impresion de numeros pares: 4");
	puts("punto de encuentro: 5");
	int a;
	printf("ponga el ejercicio que desee realizaqr con el numero asignado: ");
	scanf(" %d", &a );
	
	switch(a){
		case 1:{
				int alumnos;
				printf("ponga la cantidad de alumnos que haya: \n");
		scanf("%d", &alumnos);
			if (alumnos >= 100){
			alumnos = alumnos*500;
			printf("el costo del micro sera de %d y cada a alumno debera pagar $500\n", alumnos);
		}
			else if (alumnos >= 50 || alumnos <= 99){
			alumnos = alumnos*400;
			printf("el costo del micro sera de %d y cada a alumno debera pagar $400\n", alumnos);	
		}
			else if (alumnos >= 30 || alumnos <= 49){
			alumnos = alumnos*300;
			printf("el costo del micro sera de %d y cada a alumno debera pagar $300\n", alumnos);
		}
		else{
			printf("el costo el micro sera de &6000\n");
		}
			break;
		}
		
		
			case 2:{
				float venta1, venta2, venta3, sueldo, comision;
				
				printf("indique las ventas y el sueldo:");
				scanf("%f %f %f %f", &venta1, &venta2, &venta3, &sueldo);
				
				comision = (venta1+venta2+venta3)*0.10;
				printf("el sueldo del empleado sera %.2f\n", comision+sueldo);
				break;
			}
			
			
			case 3:{
				float parcial1, parcial2, parcial3, examenF, TPF, total;
				
				printf("ingrese las calificaciones del alumno en orden: ");
				scanf("%f %f %f %f %f", &parcial1, &parcial2, &parcial3, &examenF, &TPF);
				total = (((parcial1+parcial2+parcial3)/3)*0.55)+ examenF*0.30 + TPF*0.15;
				
				if (total <= 5){
					printf("desaprobado, tu calificacion fue %.2f\n", total);
				}
				else if(total <=10 && total > 5){
					printf("aprobado, tu calificacion fue %.2f\n", total);
				}
				
				break;
			}
			case 4:{		
   			 	int num1, num2, prin, fin;

    			printf("Introduzca sus numeros: ");
    			scanf("%d %d", &num1, &num2);
    			if (num1 < num2) {
        		prin = num1;
        		fin = num2;
    			} 
				else {
        		prin = num1;
        		fin = num2;
    			}
    			if (prin % 2 != 0) {
        		prin++;
    			}
    			printf("numeros pares entre %d y %d:\n", num1, num2);
    			for (int i = prin; i <= fin; i += 2) {
        		printf("%d\n", i);
    			}
				break;
			}
			
			
				case 5:{
					float auto1 = 70;
					float auto2 = 150;
					
					float pE = (auto2+auto1)/ 2;
					
					printf("el punto de encuentro sera en el kilometro %.f \n", pE);	
				
					break;
				}
			}
		} ;
		
	}
