#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

//一些定义
const int ACCEPT = 0;
const int WRONG_ANSWER = 1;
//fstd 标准输出 fout 选手输出 fin 标准输入
FILE *fstd,*fout,*fin;

int LastCharStd = -2,LastCharOut=-2;

//检查下一个字符
inline int Peek(FILE* f){
    if(f==fstd){
	if(LastCharStd == -2)
	    LastCharStd=fgetc(f);
	return LastCharStd;
    }else{
	if(LastCharOut == -2)
	    LastCharOut=fgetc(f);
	return LastCharOut;
    }
}

//取出下一个字符
inline void Pop(FILE* f){
    if(f==fstd){
	if(LastCharStd == -2)
	    fgetc(f);
	else
	    LastCharStd = -2;
    }else{
	if(LastCharOut == -2)
	    fgetc(f);
	else
	    LastCharOut = -2;
    }
}

//判断字符是否为空白
inline bool IsSpace(int ch){
    return ch>=0 && (ch<=32 || ch>=127);
}

//执行比较操作。
bool DoCompare(){
    int stdPosition=0,outPosition=0;
    bool stdInSpace=true,outInSpace=true;
    while(true){
	int stdC=Peek(fstd),outC=Peek(fout);
	if(stdC==EOF && outC==EOF){
	    return true;
	}else if(stdC==EOF && IsSpace(outC)){
	    outPosition++;
	    Pop(fout);
	}else if(outC==EOF && IsSpace(stdC)){
	    stdPosition++;
	    Pop(fstd);
	}else if(IsSpace(stdC) && IsSpace(outC)){
	    stdPosition++;
	    outPosition++;
	    stdInSpace=true;
	    outInSpace=true;
	    Pop(fstd);
	    Pop(fout);
	}else if(IsSpace(stdC) && outInSpace){
	    stdPosition++;
	    Pop(fstd);
	}else if(IsSpace(outC) && stdInSpace){
	    outPosition++;
	    Pop(fout);
	}else if(stdC==outC){
	    stdPosition++;
	    outPosition++;
	    stdInSpace=false;
	    outInSpace=false;
	    Pop(fstd);
	    Pop(fout);
	}else{
	    printf("答案文件的第%d字节",stdPosition+1);
	    if(stdC==EOF){
		printf("<EOF>");
	    }else{
		printf("0x%x",stdC);
	    }
	    printf("不能匹配输出文件的第%d字节",outPosition+1);
	    if(outC==EOF){
		printf("<EOF>");
	    }else{
		printf("0x%x",outC);
	    }
	    puts("");
	    return false;
	}
    }
}

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
    char s[10000];
    fscanf(fstd, "%s", s);
    if ( s[0] == 'S' )
    {
	int t = s[1] - '0';
	fscanf(fout, "%s", s);
	char code[7][100];
	strcpy(code[0], "thankuforparticipatingthiscontest");
	strcpy(code[1], "flslovesguigui");
	strcpy(code[2], "flslovesmathematics");
	strcpy(code[3], "flslovesDP");
	strcpy(code[4], "flslovesgirls");
	strcpy(code[5], "flslovesgay");
	strcpy(code[6], "flslovesu");
	for ( ; t < 7 ; ++t  )
	    if ( strcmp(s, code[t]) == 0 )
		return ACCEPT;
	return WRONG_ANSWER;
    }	
    fseek(fstd, 0, SEEK_SET);
    //fgets(s, sizeof(s), fout);
    if(DoCompare()){
	return ACCEPT;
    }else{
	return WRONG_ANSWER;
    }
}
