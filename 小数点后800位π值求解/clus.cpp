#include <stdio.h>
long a = 10000;
long b;
long c = 2800;
long d;
long e;
long f[2801];
long g;
int main() {
    for (; b - c;) f[b++] = a / 5;
    while (1) {
        if (0 == b - c) break;
        f[b] = a / 5;
        b++;
    }
    for (; d = 0, g = c * 2; c -= 14, printf("%.4d", e + d / a), e = d % a)
        for (b = c; d += f[b] * a, f[b] = d % --g, d /= g--, --b; d *= b);
    while (1) {
        d = 0;
        g = c * 2;
        if (0 == g) break;
        b = c;
        while (1) {
            d += f[b] * a;
            f[b] = d % --g;
            d /= g--;
            --b;
            if (0 == b) break;
            d *= b;
        }
        c -= 14;
        printf("%.4d", e + d / a);
        e = d % a;
    }

    return 0;
}