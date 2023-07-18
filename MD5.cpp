#include"md5.h"
#include<string.h>

//数据填充的内容
unsigned char PADDING[64] = {
  0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


void MD5Init(MD5_CTX* context){
    //
    context->count[0]=0;
    context->count[1]=0;
    //初始化A,B,C,D为四个参数
    context->state[0]=0x67452301;
    context->state[1]=0xefcdab89;
    context->state[2]=0x98badcfe;
    context->state[3]=0x10325476;
}

//需要进行四轮运算 Four Round Cycle Operation


void MD5Update(unsigned int inputLen, unsigned char* input, MD5_CTX *context){

}
void MD5Output(unsigned char [16],MD5_CTX *context){

}