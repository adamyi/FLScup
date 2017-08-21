// The following program was written by adamyi.

#include <stdio.h>
#include <string.h>
#include <math.h>
double app(double x)
{
    if ( x > 0 )
        return ((int)((x + 0.0005) * 1000)) * 1.0 / 1000.0;
    return ((int)((x - 0.0005) * 1000)) * 1.0 / 1000.0;
}
char BBB[50005];
long long PowHash[10];
void InitPowHash(int n, int mod)
{
    memset(PowHash, 0, sizeof(PowHash));
    PowHash[0] = 1;
    for ( int i = 1 ; i < 10 ; ++i )
    {
        PowHash[i] = PowHash[i - 1] * n % mod;
    }
}
long long pn(long long n, int a, int mod )
{
    n%=mod;  
    long long ans=1;  
    for (;a;a >>= 1)  
    {  
        if (a & 1)
            ans = (ans * n) % mod;  
        n = (n * n) % mod;  
    }  
    return ans;
}
long long pow2(int n, int l, int c)
{
    if (l == 0)
        return 1;
    long long x = pow2(n, l - 1, c);
    long long y = pn(x, 10, c);
    return (y * PowHash[BBB[l - 1]]) % c; //pn(n, BBB[l - 1], c)
}
long long epow(int AAA, int CCC)
{
    int lb = strlen(BBB);
    for ( int i = 0 ; i < lb ; ++i )
    {
        BBB[i] -= '0';
    }
    InitPowHash(AAA, CCC);
    long long r = pow2(AAA, lb, CCC);
    //printf("%lld\n", r);
    return r;
}
int str_len(char x[], bool r, int ln)
{
    if ( ln == -1 )
    {
        if (r)
            return 1;
        return -1;
    }
    /*int i = 0;
      int xx = 0;
      while( x[i] <= '9' && x[i] >= '0' )
      {
      xx *= 10;
      xx += x[i] - '0';
      i++;
      }
      if (r)
      return xx;
      else
      return -xx;
      return 0;*/
    int i = 0;
    while ( x[i] != ')' )
        i++;
    char bak = x[i + 1];
    x[i + 1] = '\0';
    int AAA, CCC;
    memset(BBB, 0, sizeof(BBB));
    sscanf(&x[1], "%d %s %d", &AAA, BBB, &CCC);
    long long re = epow(AAA, CCC);
    x[i + 1] = bak;
    if (r)
        return re;
    else
        return -re;
    return 0;
}
void swap( double &a, double &b )
{
    double c = a;
    a = b;
    b = c;
}
void sort_three( double &a, double &b, double &c )
{
    if ( a > b )
        swap(a, b);
    if ( a > c )
        swap(a, c);
    if ( b > c )
        swap(b,c);
}
double BetterPow( double a, double b )
{
    if ( a >= 0 )
        return pow(a, b);
    else
        return -pow(-a, b);
}
double ABS( double a )
{
    if ( a >= 0 )
        return a;
    else
        return -a;
}
char a[10000000], b[10000000];
int main()
{
    //char a[10005], b[10005];
    int aa[4];
    memset(aa, 0, sizeof(aa));
    fgets(a, sizeof(a), stdin);
    //scanf("%s", a);
    int la = strlen(a), lb, ln = -1;
    bool r = (a[0] != '-');
    for ( int i = 0 ; i < la ; i++ )
    {
        if ( a[i] == '=' )
        {
            strcpy(b, &a[i + 1]);
            a[i] = '\0';
            la = i;
            lb = strlen(b);
            //printf("%s %s\n", a, b);
            break;
        }
        //if ( a[i] <= '9' && a[i] >= '0' && ln == -1 )
        if ( a[i] == '(' && ln == -1 )
        {
            ln = i;
            continue;
        }
        if ( a[i] == '^' )
        {
            aa[a[i + 1] - '0'] += str_len(&a[ln], r, ln);
            ln = -1;
            i++;
        }
        if ( (a[i] == '-' || a[i] == '+') && (i < 2 || a[i - 2] != '^') && i != 0 && a[i - 1] != 'x' )
        {
            aa[0] += str_len(&a[ln], r, ln);
            ln = -1;
        }
        if ( (a[i] == '-' || a[i] == '+') && i != 0 && a[i - 1] == 'x' )
        {
            aa[1] += str_len(&a[ln], r, ln);
            ln = -1;
        }
        if ( a[i] == '+' )
        {
            r = true;
        }
        if ( a[i] == '-' )
        {
            r = false;
        }
    }
    if ( la == 1 && a[0] == 'x' )
    {
        aa[1]++;
    }
    else if ( ln != -1 )
    {
        if ( a[la - 1] == 'x' )
            aa[1] += str_len(&a[ln], r, ln);
        else
            aa[0] += str_len(&a[ln], r, ln);
    }
    else if ( la >= 2 && a[la - 1] == 'x' )
    {
        if ( a[la - 2] == '+' )
            aa[1]++;
        else if ( a[la - 2] == '-' )
            aa[1]--;
    }
    //printf("%d %d %d %d\n", aa[0], aa[1], aa[2], aa[3]);
    ln = -1;
    r = (b[0] == '-');
    for ( int i = 0 ; i < lb ; i++ )
    {
        //printf("%d %d %d %d %d\n", i, aa[0], aa[1], aa[2], aa[3]);
        if ( b[i] == '(' && ln == -1 )
        {
            if ( i == 0 || b[i - 1] == '+' )
                r = false;
            else
                r = true;
            ln = i;
            continue;
        }
        if ( b[i] == '^' )
        {
            aa[b[i + 1] - '0'] += str_len(&b[ln], r, ln);
            ln = -1;
            i++;
        }
        if ( (b[i] == '-' || b[i] == '+') && (i < 2 || b[i - 2] != '^') && i != 0 && b[i - 1] != 'x' )
        {
            aa[0] += str_len(&b[ln], r, ln);
            ln = -1;
        }
        if ( (b[i] == '-' || b[i] == '+') && i != 0 && b[i - 1] == 'x' )
        {
            aa[1] += str_len(&b[ln], r, ln);
            ln = -1;
        }
        if ( b[i] == '-' )
            r = true;
        if ( b[i] == '+' )
            r = false;
    }
    if ( lb == 1 && b[0] == 'x' )
    {
        aa[1]--;
    }
    else if ( ln != -1 )
    {
        if ( b[lb - 1] == 'x' )
            aa[1] += str_len(&b[ln], r, ln);
        else
            aa[0] += str_len(&b[ln], r, ln);
    }
    else if ( lb >= 2 &&b[lb - 1] == 'x' )
    {
        if ( b[lb - 2] == '+' )
            aa[1]--;
        else if ( b[lb - 2] == '-' )
            aa[1]++;
    }
    //printf("%d %d %d %d\n", aa[0], aa[1], aa[2], aa[3]);
    if ( aa[3] == 0 && aa[2] == 0 && aa[1] == 0 )
        return -1;
    if ( aa[3] == 0 && aa[2] == 0 ) //1
        printf( "%.3lf\n", app(1.0 * -aa[0] / aa[1]));
    else
    {
        if ( aa[3] == 0 ) //2
        {
            int delta = aa[1] * aa[1] - 4 * aa[2] * aa[0];
            if ( delta == 0 )
                printf( "%.3lf\n", app(1.0 * -aa[1] / 2.0 / aa[2]));
            if ( delta > 0 )
            {
                double sqrtdelta = sqrt(delta),
                       X1 = (-aa[1] - sqrtdelta) / 2.0 / aa[2],
                       X2 = (-aa[1] + sqrtdelta) / 2.0 / aa[2];
                       if ( X1 > X2 )
                           swap(X1, X2);
                       printf( "%.3lf\n%.3lf\n", app(X1), app(X2));
            }
            if ( delta < 0 )
            {
                double sqrtdelta = ABS(sqrt(-delta) / 2.0 / aa[2]);
                double t = -aa[1] /2.0 / aa[2];
                if ( t != 0 )
                    printf( "%.3lf-%.3lfi\n%.3lf+%.3lfi\n", app(t), app(sqrtdelta), app(t), app(sqrtdelta));
                else
                    printf( "-%.3lfi\n%.3lfi\n", app(sqrtdelta), app(sqrtdelta));
            }
        }
        else //3
        {
            double A = aa[2] * aa[2] - 3 * aa[3] * aa[1],
            B = aa[2] * aa[1] - 9 * aa[3] * aa[0],
            C = aa[1] * aa[1] - 3 * aa[2] * aa[0],
            delta = B * B - 4 * A * C;
            if ( delta > 0 )
            {
                double sqrtdelta = sqrt(delta),
                       Y1 = A * aa[2] + 1.5 * aa[3] * (-B+sqrtdelta),
                       Y2 = A * aa[2] + 1.5 * aa[3] * (-B-sqrtdelta),
                       Y1_3 = BetterPow(Y1, 1.0/3),
                       Y2_3 = BetterPow(Y2, 1.0/3),
                       X1 = (-aa[2] - Y1_3 - Y2_3) / 3.0 / aa[3],
                       X23 = (-aa[2] + 0.5 *(Y1_3 + Y2_3)) / 3.0 / aa[3],
                       X23i = ABS(sqrt(3) * (Y1_3 - Y2_3) / 6.0 / aa[3]);
                       if ( X23i == 0 )
                           printf( "%.3lf\n%.3lf\n", app(X1), app(X23));
                       else
                       {
                           if ( X23 != 0 )
                               printf( "%.3lf\n%.3lf-%.3lfi\n%.3lf+%.3lfi\n", app(X1), app(X23), app(X23i), app(X23), app(X23i));
                           else
                               printf( "%.3lf\n-%.3lf\n%.3lf\n", app(X1), app(X23i), app(X23i));
                       }
            }
            if ( delta == 0 )
            {
                double K = B, X1 = 1.0 * -aa[2]/aa[3] + K, X2 = -K / 2.0;
                if ( X1 > X2 )
                    swap(X1, X2);
                if ( X1 != X2 )
                    printf( "%.3lf\n%.3lf\n", app(X1), app(X2));
                else
                    printf( "%.3lf\n", app(X1));
            }
            if ( delta < 0 )
            {
                double T = (2 * A * aa[2] - 3 * aa[3] * B) / 2.0 / sqrt(A * A * A),
                       theta = acos(T), sqrtA = sqrt(A), cosTheta3 = cos(theta / 3), 
                       X1 = (-aa[2] - 2.0 * sqrtA * cosTheta3) / 3.0 / aa[3],
                       X23 = (-aa[2] + sqrtA * cosTheta3) / 3.0 / aa[3],
                       X23i = sqrtA * sqrt(3) * sin(theta / 3.0) / 3.0 / aa[3],
                       X2 = X23 - X23i, X3 = X23 + X23i;
                       sort_three(X1, X2, X3);
                       printf( "%.3lf\n", app(X1));
                       if ( X2 != X1 )
                           printf( "%.3lf\n", app(X2));
                       if ( X3 != X1 && X3 != X2 )
                           printf( "%.3lf\n", app(X3));
            }
        }
    }
    return 0;
}
