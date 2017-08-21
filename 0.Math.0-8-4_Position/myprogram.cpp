// The following program was written by adamyi.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    int n, m, x, y, z;
    unsigned long long Sx = 0, Sy = 0, Sz = 0;
    unsigned long long Sx2 = 0, Sy2 = 0, Sz2 = 0;
    unsigned long long Sxy = 0, Sxz = 0, Syz = 0;
    scanf("%d %d", &n, &m);
    for ( x = 1 ; x <= n ; ++x )
    {
        scanf("%d %d", &y, &z);
        Sx += x;
        Sy += y;
        Sz += z;
        Sx2 += x * x;
        Sy2 += y * y;
        Sz2 += z * z;
        Sxy += x * y;
        Sxz += x * z;
        Syz += y * z;
    }
    double temp = n * Sx2 - Sx * Sx;
    double Bz = 1.0 * (Sz * Sx2 - Sx * Sxz) / temp;
    double Kz = 1.0 * (n * Sxz - Sx * Sz) / temp;
    double Z = Kz * (m + n) + Bz;
    temp = n * Syz - Sy * Sz;
    double By = 1.0 * (Sy * Syz - Sz * Sy2) / temp;
    double Ky = 1.0 * (n * Sy2 - Sy * Sy)  / temp;
    double Y = Ky * Z + By;
    printf("%.3lf %.3lf\n", Y, Z);
    return 0;
}

