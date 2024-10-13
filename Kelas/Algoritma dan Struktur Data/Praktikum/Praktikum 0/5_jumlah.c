#include <stdio.h>

int main() {
    int n, k;
    int a_i;
    int i;
    int temp = 0;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &a_i);
        if (a_i % k != 0){
            temp += a_i;
        }
    }
    printf("%d\n", temp);
    return 0;
}