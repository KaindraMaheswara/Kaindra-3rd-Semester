#include <stdio.h>

int main() {
    int n, a, b, result;
    scanf("%d %d %d", &n, &a, &b);

    int fibonacci(int m, int n, int o) {
        int i;
        int func1, func2, func3;
        int *f;
        
        func1 = n;
        func2 = o;
        for(i=1; i<=m-2; i++) {
            func3 = func1 + func2;
            func1 = func2;
            func2 = func3;
        }
        return(func3);
        }
    
    result = fibonacci(n, a, b);
    printf("%d\n", result);
    }
