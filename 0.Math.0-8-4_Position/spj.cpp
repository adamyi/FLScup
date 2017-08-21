#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int ACCEPT = 0;
const int WRONG_ANSWER = 1;
//fstd 标准输出 fout 选手输出 fin 标准输入
FILE *fstd,*fout,*fin;

int main(int argc, char* argv[])
{
    if(argc!=4){
        printf("参数不足 %d",argc);
        return -1;
    }

    //打开文件
    if(NULL==(fstd=fopen(argv[1],"r"))){
        return -1;
    }
    if(NULL==(fout=fopen(argv[2],"r"))){
        return -1;
    }
    if(NULL==(fin=fopen(argv[3],"r"))){
        return -1;
    }
	double sa, sb;
    fscanf(fstd, "%lf %lf", &sa, &sb);
    double ua, ub;
    fscanf(fout, "%lf %lf", &ua, &ub);
    if ( abs(ua - sa) <= 1 && abs(ub - sb) <= 1 )
        return ACCEPT;
    return WRONG_ANSWER;
}
