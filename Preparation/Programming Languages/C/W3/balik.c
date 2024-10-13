#include <stdio.h>

int main() {
    int n;
    int i;
    int j;
    int temp;
    scanf ("%d", &n);

    temp = n;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= (n-1); j++) {
            printf(" ");
        }
        for (j = (2*temp-1); j >= 1; j--) {
            printf("*");
            temp -= 1;
        }
        printf("\n");
    }
    
}