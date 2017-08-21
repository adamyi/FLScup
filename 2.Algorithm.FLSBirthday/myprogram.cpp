// The following program was written by adamyi.

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
const int siz = 1000;
const int err = -2;
const int grand = 30;
const int grand2 = 2147483647;
const int tryK = 20;
const int maxP = 100000;
const int inputMax = 104857600;
//int ER[4*siz][2*siz];
bool flag_of_er_init = false;
bool flag_of_smallint_rand_init = false;

typedef struct happiness {
    int n[siz];
} happiness;
happiness H[maxP];

void fast_input(char *s);
int bigint_comp(int *a, int *b);
int bigint_comp(int *a, int b);
inline void bigint_opp(int *d);
inline void bigint_shiftleft(int *d);
inline void bigint_shiftright(int *d);
inline void bigint_fromint(long long x, int *d);
inline void bigint_fromstr(string buf, int *d);
inline void bigint_fromchar(char *buf, int *d);
inline void bigint_in(istream &in, int *d);
inline void bigint_out(ostream &out, int *d);
inline void bigint_in(int *d);
inline void bigint_out(int *d);
inline void bigint_adjust(int *c);
inline void bigint_plus(int *a, int *b, int *c);
inline void bigint_times(int *a, int *b, int *c);
inline void bigint_divide(int *a, int *b, int *c, int *g);
//inline void bigint_pow(int *a, int *b, int *m, int *r);
//inline void bigint_ER_init();
inline void bigint_minus(int *a, int *b, int *c);
inline void bigint_cpy(int *a, int *b);
inline void bigint_inc(int *a);
inline void bigint_dec(int *a);
inline void bigint_divide_adjust(int *b, int *c, int *g, int *e);
inline void bigint_rand(int *a, int *b);
inline int smallint_rand(int a);
inline void smallint_rand_init();
//bool bigint_isprime(int *a);
int smallint_rand_general();

inline void smallint_rand_init(){
    srand(time(0));
    rand();
    flag_of_smallint_rand_init = true;
    return ;
}

inline int smallint_rand(int a){
    if(!flag_of_smallint_rand_init)
        smallint_rand_init();
    return (int)((double)a*(double)smallint_rand_general()/(double)grand2);
}

int smallint_rand_general(){
    int r = 0;
    for(int i = 0; i < grand; ++i){
        r += rand()%2;
        r *= 2;
    }
    return r;
}

inline void bigint_rand(int *a, int *b){
    if(a[0]==err || a[ a[0] ]<0){
        b[0] = err;
        return ;
    }
    if(a[0]==1 && a[1]==0){
        b[0] = 1;
        b[1] = 0;
        return ;
    }
    int c[siz], d[siz];
    c[0] = siz-1;
    c[ c[0] ] = smallint_rand(9)+1;
    for(int i = 1; i < c[0]; ++i)
        c[i] = smallint_rand(10);
    bigint_divide(c, a, d, b);
    return ;
}

/*bool bigint_isprime(int *a){
  if(a[0] == err)
  return false;
  if(a[0]==1 && a[1]==1)
  return false;
  if(a[0]==1 && a[1]==2)
  return true;

  int b[siz], c[siz], d[siz], e[siz];
  bool flag = true;
  bigint_cpy(a, d);
  bigint_cpy(a, e);
  for(int i = 0; i < tryK; ++i){
  bigint_cpy(e, a);
  bigint_fromint(0, b);
  bigint_fromint(0, c);
  bigint_rand(a, b);
  if(b[0]==1 && b[1]==0)
  b[1] = 1;
  bigint_cpy(e, a);
  bigint_cpy(e, d);
  bigint_dec(a);
  bigint_pow(b, a, d, c);
  if(bigint_comp(c, 1) != 0){
  flag = false;
  break;
  }
  }
  return flag;
  }*/

int bigint_comp(int *a, int b){
    int c[siz];
    bigint_fromint(b, c);
    return bigint_comp(a, c);
}

inline void bigint_inc(int *a){
    if(a[0] == err)
        return ;
    int lim = 9;
    if(a[ a[0] ] < 0)
        lim = 0;
    ++ a[1];
    a[ ++a[0] ] = 0;
    for(int i = 1; i <= a[0]; ++i)
        if(a[i] > lim){
            a[i] -= 10;
            ++ a[i+1];
        }
    while(a[0]>1 && a[ a[0] ]==0)
        -- a[0];
    return ;
}

inline void bigint_dec(int *a){
    if(a[0] == err)
        return ;
    int lim = 0;
    if(a[ a[0] ] < 0)
        lim = -9;
    -- a[1];
    a[ ++a[0] ] = 0;
    for(int i = 1; i <= a[0]; ++i)
        if(a[i] < lim){
            a[i] += 10;
            -- a[i+1];
        }
    while(a[0]>1 && a[ a[0] ]==0)
        -- a[0];
    return ;
}

inline void bigint_minus(int *a, int *b, int *c){
    bigint_opp(b);
    bigint_plus(a, b, c);
    bigint_opp(b);
    return ;
}

/*inline void bigint_ER_init(){
  flag_of_er_init = true;
  bigint_fromint(1, ER[0]);
  bigint_fromint(2, ER[1]);
  int l = 4*siz;
  for(int i = 2; i < l; ++i){
  bigint_fromint(0, ER[i]);
  bigint_times(ER[i-1],ER[1], ER[i]);
  }
  return ;
  }

  inline void bigint_pow(int *a, int *b, int *m, int *r){
///a^b mod m ==> r
if(a[0]==err || b[0]==err || a[ a[0] ]<0 || b[ b[0] ]<0 || (m[1]==0&&m[0]==1)){
r[0] = err;
return ;
}
if(a[0]==1 && a[1]==0){
r[0] = 1;
r[1] = 0;
return ;
}
if(!flag_of_er_init)
bigint_ER_init();
int l = b[0]*4, CC=0;
int d[2][siz], e[siz];
bigint_fromint(1, d[0]);

for(int i = l; i >= 0; --i){
bigint_times(d[CC], d[CC],e);
bigint_divide(e, m, d[1-CC], d[CC]);
if(bigint_comp(ER[i], b) <= 0){
bigint_fromint(0, e);
bigint_minus(b, ER[i], e);
bigint_cpy(e, b);
bigint_fromint(0, e);
bigint_times(d[CC], a, e);
bigint_divide(e, m, d[CC], d[1-CC]);
CC = 1 - CC;
}
}
bigint_cpy(d[CC], r);
return ;
}*/

inline void bigint_cpy(int *a, int *b){
    for(int i = 0; i <= a[0]; ++i)
        b[i] = a[i];
    return ;
}

inline void bigint_divide_adjust(int *b, int *c, int *g, int *e){
    if(bigint_comp(g, 0) != 0){
        bigint_inc(c);
        bigint_minus(b, g, e);
        bigint_cpy(e, g);
    }
    return ;
}

inline void bigint_divide(int *a, int *b, int *c, int *g){
    ///a/b = c ... g
    if(a[0]==err || b[0]==err){
        c[0] = g[0] = err;
        return ;
    }
    if(b[0]==1 && b[1]==0){
        c[0] = g[0] = err;
        return ;
    }
    if(a[0]==1 && a[1]==0){
        bigint_fromint(0, c);
        bigint_fromint(0, g);
        return ;
    }
    int d[siz], e[siz], f[siz], k;
    bool flag = false;
    bigint_fromint(0, e);
    bigint_fromint(0, d);

    if(a[ a[0] ]<0 && b[ b[0] ]<0){
        bigint_opp(a);
        bigint_opp(b);
        bigint_divide(a, b, c, g);
        bigint_divide_adjust(b, c, g, e);
        bigint_opp(a);
        bigint_opp(b);
        return ;
    }

    if(a[ a[0] ]<0 && b[ b[0] ]>0){
        bigint_opp(a);
        bigint_divide(a, b, c, g);
        bigint_divide_adjust(b, c, g, e);
        bigint_opp(c);
        bigint_opp(a);
        return ;
    }

    if(a[ a[0] ]>0 && b[ b[0] ]<0){
        bigint_opp(b);
        bigint_divide(a, b, c, g);
        bigint_opp(c);
        bigint_opp(b);
        return ;
    }

    if(bigint_comp(a, b) < 0){
        c[0] = 1;
        c[1] = 0;
        bigint_cpy(a, g);
        return ;
    }
    bigint_fromint(0, c);
    c[0] = a[0];
    for(int i = a[0]; i >= 1; --i){
        d[1] = a[i];
        bigint_fromint(0, e);
        for(k = 1; k <= 10; ++k){
            bigint_fromint(k, f);
            bigint_times(b, f, e);
            if(bigint_comp(d, e) < 0)
                break;
        }
        if(k == 11)
            continue;
        c[i] = --k;
        bigint_fromint(k, f);
        bigint_times(f, b, e);
        bigint_opp(e);
        bigint_plus(d, e, f);
        bigint_cpy(f, d);
        bigint_shiftleft(d);
    }
    bigint_adjust(c);
    bigint_shiftright(d);
    bigint_cpy(d, g);
    return ;
}

inline void bigint_opp(int *d){
    for(int i = 1; i <= d[0]; ++i)
        d[i] = -d[i];
    return ;
}

int bigint_comp(int *a, int *b){
    ///if(a==b) return 0;
    ///if(a<b) return -1;
    ///if(a>b) return 1;
    if(a[0]==err || b[0]==err)
        return err;
    if(a[0] < b[0])
        return -1;
    else if(a[0] > b[0])
        return 1;
    for(int i = a[0]; i >= 1; --i)
        if(a[i] < b[i])
            return -1;
        else if(a[i] > b[i])
            return 1;
    return 0;
}

inline void bigint_shiftleft(int *d){
    if(d[0] == err)
        return ;
    if(d[0]==1 && d[1]==0)
        return ;
    ++ d[0];
    for(int i = d[0]; i > 1; --i)
        d[i] = d[i-1];
    d[1] = 0;
    return ;
}

inline void bigint_shiftright(int *d){
    if(d[0] == err)
        return ;
    -- d[0];
    for(int i = 1; i <= d[0]; ++i)
        d[i] = d[i+1];
    if(d[0] == 0){
        d[0] = 1;
        d[1] = 0;
    }
    return ;
}

inline void bigint_fromint(long long x, int *d){
    int p = 0;
    for(int i = 0; i < siz; ++i)
        d[i] = 0;
    if(x == 0){
        d[0] = 1;
        return ;
    }

    if(x > 0){
        while(x > 0){
            ++ p;
            d[p] = x%10;
            x /= 10;
        }
    }
    else{
        x = -x;
        while(x > 0){
            ++ p;
            d[p] = x%10;
            x /= 10;
        }
    }
    d[0] = p;
    return ;
}

inline void bigint_fromstr(string buf, int *d){
    int l, x;
    l = buf.length();
    for(int i = 0; i < l; ++i)
        if(buf[i]<'0' || buf[i]>'9'){
            if(i==0 && buf[i]=='-')
                continue;
            d[0] = err;
            return ;
        }
    if(buf[0] == '-'){
        d[0] = l-1;
        for(int i = 1; i <= d[0]; ++i)
            d[l-i] = -(int)(buf[i]-'0');
    }
    else{
        d[0] = l;
        for(int i = 0; i < l; ++i)
            d[l-i] = (int)(buf[i]-'0');
    }
    while(d[0]>1 && d[ d[0] ]==0)
        -- d[0];
    return ;
}

inline void bigint_fromchar(char *buf, int *d){
    int l, x;
    l = strlen(buf);
    for(int i = 0; i < l; ++i)
        if(buf[i]<'0' || buf[i]>'9'){
            if(i==0 && buf[i]=='-')
                continue;
            d[0] = err;
            return ;
        }
    if(buf[0] == '-'){
        d[0] = l-1;
        for(int i = 1; i <= d[0]; ++i)
            d[l-i] = -(int)(buf[i]-'0');
    }
    else{
        d[0] = l;
        for(int i = 0; i < l; ++i)
            d[l-i] = (int)(buf[i]-'0');
    }
    while(d[0]>1 && d[ d[0] ]==0)
        -- d[0];
    return ;
}

inline void bigint_in(istream &in, int *d){
    bigint_fromint(0, d);
    string buf;
    in >> buf;
    bigint_fromstr(buf, d);
    return ;
}

inline void bigint_out(ostream &out, int *d){
    if(d[0] == err){
        out << "#ERROR#";
        return ;
    }
    if(d[0] == 0){
        out << 0;
        d[0] = 1;
        d[1] = 0;
        return ;
    }

    if(d[ d[0] ] < 0){
        out << '-';
        for(int i = d[0]; i >= 1; --i)
            out << -d[i];
    }
    else for(int i = d[0]; i >= 1; --i)
        out << d[i];
    return ;
}

inline void bigint_in(int *d){
    bigint_fromint(0, d);
    //string buf;
    char buf[siz];
    //scanf("%s", buf);
    fast_input(buf);
    bigint_fromchar(buf, d);
    return ;
}

inline void bigint_out(int *d){
    if(d[0] == err){
        printf("#ERROR#");
        return ;
    }
    if(d[0] == 0){
        printf("0");
        d[0] = 1;
        d[1] = 0;
        return ;
    }

    if(d[ d[0] ] < 0){
        printf("-");
        for(int i = d[0]; i >= 1; --i)
            printf("%d", -d[i]);
    }
    else for(int i = d[0]; i >= 1; --i)
        printf("%d", d[i]);
    return ;
}

inline void bigint_adjust(int *c){
    while(c[0]>1 && c[ c[0] ]==0)
        -- c[0];
    if(c[ c[0] ] > 0){
        for(int i = 1; i < c[0]; ++i)
            while(c[i] < 0){
                -- c[i+1];
                c[i] += 10;
            }
    }
    else{
        for(int i = 1; i < c[0]; ++i)
            while(c[i] > 0){
                ++ c[i+1];
                c[i] -= 10;
            }
    }
    ++ c[0];
    while(c[0]>1 && c[ c[0] ]==0)
        -- c[0];
    return ;
}

inline void bigint_plus(int *a, int *b, int *c){
    if(a[0]==err || b[0]==err){
        c[0] = err;
        return ;
    }
    int l = a[0];
    if(b[0] > l)
        l = b[0];
    c[0] = l+1;
    for(int i = 1; i <= c[0]; ++i)
        c[i] = 0;

    for(int i = 1; i <= l; ++i){
        c[i] += a[i]+b[i];
        while(c[i] > 9){
            ++ c[i+1];
            c[i] -= 10;
        }
        while(c[i] < -9){
            -- c[i+1];
            c[i] += 10;
        }
    }
    bigint_adjust(c);
    return ;
}

inline void bigint_times(int *a, int *b, int *c){
    c[0] = a[0]+b[0]+1;
    for(int i = 1; i <= c[0]; ++i)
        c[i] = 0;
    for(int i = 1; i <= a[0]; ++i)
        for(int j = 1; j <= b[0]; ++j){
            c[i+j-1] += a[i]*b[j];
            while(c[i+j-1] > 9){
                ++ c[i+j];
                c[i+j-1] -= 10;
            }
            while(c[i+j-1] < -9){
                -- c[i+j];
                c[i+j-1] += 10;
            }
        }
    bigint_adjust(c);
    return ;
}

bool happiness_cmp(happiness a, happiness b)
{
    return (bigint_comp(a.n, b.n) == 1);
}

void fast_input(char *s)
{
    int t = 0;
    s[0] = getchar();
    while(s[0] < '0' || s[t] > '9')
        s[0] = getchar();
    while(s[t] >= '0' && s[t] <= '9')
        s[++t] = getchar();
    s[t] = '\0';
    //printf("%s\n", s);
    return;
}
void Input_dinner(int &n, int &w)
{
    //freopen("test.in", "r", stdin);
    unsigned int c;
    char *buf = (char*)malloc(inputMax);
    //while((c = fread(buf, 1, inputMax, stdin)) <= 0);
    c = fread(buf, 1, inputMax, stdin);
    unsigned int i = 0;
    n = 0;
    w = 0;
    while(buf[i] == '\n' || buf[i] == '\r' || buf[i] == ' ')
        i++;
    while(buf[i] != '\n' && buf[i] != '\r' && buf[i] != ' ')
    {
        n *= 10;
        n += buf[i] - '0';
        i++;
    }
    while(buf[i] == '\n' || buf[i] == '\r' || buf[i] == ' ')
        i++;
    while(buf[i] != '\n' && buf[i] != '\r' && buf[i] != ' ')
    {
        w *= 10;
        w += buf[i] - '0';
        i++;
    }
    while(buf[i] == '\n' || buf[i] == '\r' || buf[i] == ' ')
        i++;
    int ii = 0, l = i;
    char tmp[siz];
    for ( ; i < c ; ++i )
    {
        if ( buf[i] == '\r' || buf[i] == '\n' || buf[i] == ' ' )
        {
            memset(tmp, 0, sizeof(tmp));
            memcpy(tmp, &buf[l], i - l);
            //printf("%s\n", tmp);
            bigint_fromint(0, H[ii].n);
            bigint_fromchar(tmp, H[ii].n);
            while(buf[i] == '\n' || buf[i] == '\r' || buf[i] == ' ')
                i++;
            i--;
            l = i + 1;
            ii++;
            continue;
        }
    }
}

int Sigma_h[siz];
int tempBI[siz];
int Sigma_ht[siz];
int divide_pN[siz];
int remainder[siz];
int main(int argc, const char *argv[])
{
    int n, w;
    //scanf("%d %d", &n, &w);
    Input_dinner(n, w);
    w /= 20;
    bigint_fromint(0, Sigma_h);
    //double lt = clock() / CLOCKS_PER_SEC;
    /*if (w >= n)
      {
      for (int i = 0 ;i < n ; ++i)
      {
      bigint_in(remainder);
      memcpy(tempBI, Sigma_h, sizeof(Sigma_h));
      bigint_plus(tempBI, remainder, Sigma_h);
      }
      bigint_out(Sigma_h);
      return 0;
      }*/
    //for (int i = 0 ;i < n ; ++i)
    //	bigint_in(H[i].n);
    //printf("Input: %lf\n", clock() / CLOCKS_PER_SEC - lt);
    //lt = clock() / CLOCKS_PER_SEC;
    if ( w >= n )
    {
        for (int i = 0 ; i < n ; ++i)
        {
            memcpy(tempBI, Sigma_h, sizeof(Sigma_h));
            bigint_plus(tempBI, remainder, Sigma_h);
        }
        bigint_out(Sigma_h);
        return 0;
    }
    sort(H, H + n, happiness_cmp);
    //printf("Sort: %lf\n", clock() / CLOCKS_PER_SEC - lt);
    //lt = clock() / CLOCKS_PER_SEC;
    for (int i = w - 2 ; i > -1 ; --i)
    {
        memcpy(tempBI, Sigma_h, sizeof(Sigma_h));
        bigint_plus(tempBI, H[i].n, Sigma_h);
    }
    bigint_fromint(0, Sigma_ht);
    //printf("Plus A: %lf\n", clock() / CLOCKS_PER_SEC - lt);
    //lt = clock() / CLOCKS_PER_SEC;
    for (int i = w - 1 ; i < n ; ++i)
    {
        memcpy(tempBI, Sigma_ht, sizeof(Sigma_ht));
        bigint_plus(tempBI, H[i].n, Sigma_ht);
    }
    //printf("Plus B: %lf\n", clock() / CLOCKS_PER_SEC - lt);
    //lt = clock() / CLOCKS_PER_SEC;
    memcpy(tempBI, Sigma_ht, sizeof(Sigma_ht));
    bigint_fromint(n - w + 1, divide_pN);
    bigint_divide(tempBI, divide_pN, Sigma_ht, remainder );
    //printf("Divide: %lf\n", clock() / CLOCKS_PER_SEC - lt);
    //lt = clock() / CLOCKS_PER_SEC;
    memcpy(tempBI, Sigma_h, sizeof(Sigma_h));
    bigint_plus(tempBI, Sigma_ht, Sigma_h);
    //printf("Final Plus: %lf\n", clock() / CLOCKS_PER_SEC - lt);
    //lt = clock() / CLOCKS_PER_SEC;
    bigint_out(Sigma_h);
    //printf("Out: %lf\n", clock() / CLOCKS_PER_SEC - lt);
    //lt = clock() / CLOCKS_PER_SEC;
    return 0;
}
