#include <stdio.h>

int bilangan;
int pembagi = 10000;
int i;
int count;
int main(){
    printf("Masukkan bilangan: ");
    scanf("%d", &bilangan);
    int bilangan1 = bilangan / 10000;
    int bilangan2 = (bilangan / 1000) % 10;
    int bilangan3 = (bilangan / 100) % 10;
    int bilangan4 = (bilangan / 10) % 10;
    int bilangan5 = bilangan % 10;
    count = bilangan1 * bilangan2 * bilangan3 * bilangan4 * bilangan5;
    printf("Hasil perkalian: %d\n", count);
}