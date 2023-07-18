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
    //初始化A,B,C,D为四个特定的常数
    state[0]=0x67452301;
    state[1]=0xefcdab89;
    state[2]=0x98badcfe;
    state[3]=0x10325476;
}
