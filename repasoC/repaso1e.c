#include<stdio.h>

int main(){
    int v1, v2;
    v1 = v2;
    scanf("%d", &v1);

    float te = 80 / (v1 + v2);
    float encuentro = (v1 + v2) * te;

    printf("se encontraran en el kilometro %.2f", encuentro)

return 0;
}
