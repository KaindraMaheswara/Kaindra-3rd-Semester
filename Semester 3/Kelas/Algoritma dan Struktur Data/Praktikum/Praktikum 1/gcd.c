#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int a, b;
    int hasil;
    scanf("%d %d", &a, &b);
    hasil = gcd(a, b);
    printf("%d", hasil);
}