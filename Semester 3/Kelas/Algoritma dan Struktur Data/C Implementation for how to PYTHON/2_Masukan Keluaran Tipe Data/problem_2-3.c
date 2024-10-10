#include <stdio.h>

int n;
int kubus;
float bola;
int main(){
    printf("Masukkan nilai r: ");
    scanf("%d", &n);
    kubus = n * n * n;
    n = (float)n;
    bola = 1.33333333333333333333333333333333333333333333333333333333333333 * 3.14 * n* n * n;
    printf("Volume kubus adalah %d\n", kubus);
    printf("Volume bola adalah %.2f\n", bola);
}