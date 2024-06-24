// Rudaz Fabrizio hecho en dev++

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor | bgColor);
}


//aqui voy a  poner una funcion la cual me almacene la cantidad de alfajores 

void alfajores (char * alfaj[], int caja[]){

srand(time(NULL));
alfaj[2] = {chocolate, ddl, fruta};

for (int i = 0; i < 6; i ++){
	i = rand () % alfaj;
	printf("la caja contiene estos alfajores %d ", caja[i]);
}
}  

//operarios son 6 y arman las cajas 

int main(){
	int alfaj[];
	int caja[];
	
alfajores (alfaj, caja);
return 0;	
}
