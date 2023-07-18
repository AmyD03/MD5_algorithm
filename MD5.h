#ifndef MD5_H
#define MD5_H

//初始化缓冲区
typedef struct{
    unsigned int count[2];
    unsigned int state[4];    //A,B,C,D四个常数
    unsigned char buffer[64]; //输入数据缓冲区
}MD5_CTX;

void MD5Init(MD5_CTX* context);//初始化
void MD5Output(unsigned char [16],MD5_CTX *);//经过MD5算法的输出值


#endif