#include <stdio.h>

int main() {
    int a, b;
    int temp;
    scanf("%d %d", &a, &b);
    temp = a;
    printf("%d", temp);
    while (temp <= b) {
        if (temp % 2 == 1) {
            temp += 1;
        }
        else {
            temp = 2*temp;
        }
        if (temp >= b) {
            break;
        }
        printf(" ");
        printf("%d", temp);
    }
    printf("\n");
    return 0;
}