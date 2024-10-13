#include <stdio.h>

int main() {
    int n;
    int temp;
    int i, j;
    scanf ("%d", &n);
    temp = n;

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (j = 0; j < (2*temp-1); j++) {
            printf("*");
        }
        temp -= 1;
        printf("\n");
    }
    return 0;
}
