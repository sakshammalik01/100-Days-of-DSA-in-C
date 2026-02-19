#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int min_sum = a[0] + a[1];
    int x = a[0], y = a[1];

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            if(abs(sum) < abs(min_sum)) {
                min_sum = sum;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("%d %d", x, y);

    return 0;
}
