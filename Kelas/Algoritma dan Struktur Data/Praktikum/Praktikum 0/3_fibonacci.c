#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int deret (int p, int q, int r) {
        int i;
        int a1, a2, a3;
        a1 = q;
        a2 = r;
        for (i = 3; i <= p; i++) {
            a3 = a1 + a2;
            a1 = a2;
            a2 = a3;
        }
        return a3;
    }
    printf("%d\n", deret(n, a, b));
    return 0;
}