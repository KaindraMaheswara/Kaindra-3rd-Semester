#include <stdio.h>

char nama[];
int main(){
    printf("Masukkan nama mahasiswa : ");
    scanf("%s", &nama);
    printf("Halo %s, selamat datang di ITB!\n", nama);
}