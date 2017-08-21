#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int ACCEPT = 0;
const int WRONG_ANSWER = 1;
FILE *fstd, *fout, *fin;
int n, p, q, status[105][105], ans;
int robots[105], rpx[105], rpy[105];
void InputData()
{
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &p);
    fscanf(fin, "%d", &q);
    for ( int i = 0 ; i < q ; ++i )
	for ( int j = 0 ; j < p ; ++j )
	    fscanf(fin, "%d", &status[i][j]);
    fscanf(fstd, "%d", &ans);
    return;
}
int getUserResult()
{
    int t1, t2, ox, oy, r = 0;
    while( fscanf(fout, "%d %d", &t1, &t2) != EOF )
    {
	ox = 1; oy = 0;
	if (t2 == 1)
	{
	    ox = 0; oy = 1;
	}
	ox += rpx[t1];
	oy += rpy[t1];
	//printf("%d %d %d\n", t1, ox, oy);
	if ( ox == q || oy == p )
	    return -1;
	if ( status[ox][oy] == 1 )
	    return -1;
	if ( status[ox][oy] == 2 )
	{
	    robots[t1]++;
	    status[ox][oy] = 0;
	}
	rpx[t1] = ox; rpy[t1] = oy;
	if ( ox == q - 1 && oy == p - 1 )
	    r += robots[t1];
    }
    return r;
}
int main(int argc, char *argv[])
{
    memset(robots, 0, sizeof(robots));
    memset(rpx, 0, sizeof(rpx));
    memset(rpy, 0, sizeof(rpy));
    if ( argc != 4 )
    {
	printf("Invalid Arguments! %d\n", argc);
	return -1;
    }
    if ( NULL == ( fstd = fopen(argv[1],"r") ) )
	return -1;
    if ( NULL == ( fout = fopen(argv[2],"r") ) )
	return -1;
    if ( NULL == ( fin = fopen(argv[3],"r") ) )
	return -1;
    InputData();
    int s = getUserResult();
    //printf("%d\n", s);
    if ( s >= ans )
	return ACCEPT;
    else
	return WRONG_ANSWER;
    return -1;
}
