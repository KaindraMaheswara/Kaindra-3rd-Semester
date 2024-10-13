#include <stdio.h>

int harga;
float diskon;
float hasil;
int main(){
    printf("Harga sebelum diskon: ");
    scanf("%d", &harga);
    printf("Besar diskon (dalam persen): ");
    scanf("%f", &diskon);
    diskon = diskon / 100;
    harga = (float) harga;
    hasil = (1-diskon) * harga;
    printf("Harga setelah diskon adalah %.2f\n", hasil);
}