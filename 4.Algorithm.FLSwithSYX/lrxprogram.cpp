// The following program was written by lrx during the contest.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long n,m,sx,sy,ex,ey,is[1005][1005]={{0}};
long mi[1005][1005];
long min(long x,long y)
{
	return x<y?x:y;
}
void swap(long *x,long *y)
{
	long t=*x;
	*x=*y;
	*y=t;
}
long dis(long x,long y,long z,long w)
{
	long a=x-z,b=y-w;
	return a*a+b*b;
}
long fx[4]={0,0,-1,1},fy[4]={1,-1,0,0},vis[1005][1005];
int hf(long x,long y,long i)
{
	long a=x+fx[i],b=y+fy[i];
	if (a<=0||a>n||b<=0||b>m||vis[a][b]) return 0;
	return 1;
}
int dfs(long b,long x,long y)
{
	long i;
	if (x==ex&&y==ey) return 1;
	vis[x][y]=1;
	for (i=0;i<4;i++) if (hf(x,y,i)&&b<mi[x+fx[i]][y+fy[i]]&&dfs(b,x+fx[i],y+fy[i])) return 1;
	return 0;
}
int check(long x)
{
	memset(vis,0,sizeof(vis));
	return !dfs(x,sx,sy);
}
long que[1005],st,en,w[1005],f[1005];
void getmi(long o)
{
	long i,j,x,y;
	for (i=1;i<=m;i++) w[i]=-2000;
	for (i=1;i<=n;i++)
	{
		if (o) x=n-i+1;
		else x=i;
		st=en=0;
		for (j=1;j<=m;j++) if (is[i][j]) w[j]=i;
		for (j=1;j<=m;j++) f[j]=w[j]*w[j]-2*i*w[j]+j*j;
		for (j=1;j<=m;j++)
		{
			if (st==en) que[en++]=j;
			else
			{
				while(en-st>1&&(double)(f[j]-f[que[en-1]])/(j-que[en-1])<(double)(f[que[en-1]]-f[que[en-2]])/(que[en-1]-que[en-2])) en--;
				que[en++]=j;
			}
		}
		for (j=1;j<=m;j++)
		{
			y=j;
			while(en-st>1&&(double)(f[que[st]]-f[que[st+1]])/(que[st]-que[st+1])<=2*j) st++;
			mi[x][y]=min(mi[x][y],dis(j,i,que[st],w[que[st]]));
		}
	}
}
int main()
{
	long x,y,i,j,le,ri,mid;
	scanf("%ld %ld",&n,&m);
	scanf("%ld %ld",&sx,&sy);
	scanf("%ld %ld",&ex,&ey);
	while(scanf("%ld %ld",&x,&y)!=EOF) is[x][y]=1;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) mi[i][j]=99999999;
	getmi(0);
	for (i=1;i<=n/2;i++) for (j=1;j<=m;j++) swap(&is[n-i+1][j],&is[i][j]);
	getmi(1);
	for (i=1;i<=n/2;i++) for (j=1;j<=m;j++) swap(&is[n-i+1][j],&is[i][j]);
	le=-1;
	ri=min(mi[sx][sy],mi[ex][ey]);
	do
	{
		mid=(le+ri)>>1;
		if (check(mid)) ri=mid;
		else le=mid;
	}while(ri-le>1);
	printf("%ld",ri);
	return 0;
}
