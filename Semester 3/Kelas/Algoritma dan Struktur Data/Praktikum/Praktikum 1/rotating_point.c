#include "point.h"
#include "boolean.h"
#include "complex.h"
#include <stdio.h>
#include <math.h>

/* Catatan: Hasil perkalian float dan int adalah float*/
/* Fungsi untuk menghitung perpangkatan bilangan kompleks */
/* Formula: Bilangan kompleks dikalikan dirinya sendiri sebanyak P kali */
COMPLEX PowerCOMPLEX(COMPLEX C, int p){
    int i;
    COMPLEX C1 = C;
    for (i = 1; i <= p; i++){
        C1 = MultiplyCOMPLEX(C1, C);
    }
    return C1;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n){
    POINT P2;
    POINT P1;
    int i;
    (P1).X = (*P).X;
    (P1).Y = (*P).Y;
    for (i=0; i < n; i++){
        C = PowerCOMPLEX(C, i);
        (P2).X = (P1).X * C.Re - (P1).Y * C.Im;
        (P2).Y = (P1).X * C.Im - (P1).Y * C.Re;
        (P1).X = (P2).X;
        (P1).Y = (P2).Y;
        if ((((P2).X * (P2).X + (P2).Y * (P2).Y) > 1)){
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
            break;
        }
    }
    if ((((P2).X * (P2).X + (P2).Y * (P2).Y) <= 1)){
        printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", i);
    }
}