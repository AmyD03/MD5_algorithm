#ifndef MD5_H
#define MD5_H
#include<string.h>

//初始化缓冲区
typedef struct{
    unsigned int count[2];  //count数组用于记录已处理的数据长度，以位为单位
                            //count[0]为处理数字的低位，count[1]为处理数字的高位
    unsigned int state[4];    //A,B,C,D四个常数
    /*A,B,C,D代表四个32位的状态寄存器，这些寄存器在处理每个分组时被更新
        初始化使用的是十六进制表示的数字，
        A为最低字节*/
    unsigned char buffer[64]; //输入数据缓冲区
}MD5_CTX;

/*
four basic bit operation functions:
    输入三个32位的字，输出一个32位的字
    F(X,Y,Z) = ( X and Y ) or ( not(X) and Z )
    G(X,Y,Z) = ( X and Z ) or ( Y and not(Z) )
    H(X,Y,Z) = X xor Y xor Z
    I(X,Y,Z) =Y xor (X or not(Z))
*/
#define F(x,y,z) (( x & y ) | ( ~x & z))
#define G(x,y,z) (( x & z ) | ( y & ~z))
#define H(x,y,z) ((x) ^ (y) ^ (z))
#define I(x,y,z) ((y) ^ ((x) | (~z)))

/*对于32位的操作数，实现循环左移：
    将操作数 x 向左移动 s 位：x << s
    将操作数 x 向右移动 32 - s 位：x >> (32 - s)
*/
#define ROTATE_LEFT(x,s) (( x << s ) | ( x >> (32-s)))

/*
four round cycle functions:
    FF(a,b,c,d,Mj,s,Ti):a = b + (( a + F(b,c,d) + Mj + Ti) <<<s)
    GG(a,b,c,d,Mj,s,Ti):a = b + (( a + G(b,c,d) + Mj + Ti) <<<s)
    HH(a,b,c,d,Mj,s,Ti):a = b + (( a + H(b,c,d) + Mj + Ti) <<<s)
    II(a,b,c,d,Mj,s,Ti):a = b + (( a + I(b,c,d) + Mj + Ti) <<<s)
    宏定义非末行结尾加反斜杠:
        The backslash (\) character is used as the continuation character 
        to  continue #define statements and strings to the next line. 
*/

#define FF(a,b,c,d,x,s,ac) \
	{ \
		a += F(b,c,d) + x + ac; \
		a = ROTATE_LEFT(a,s); \
		a += b; \
	}
#define GG(a,b,c,d,x,s,ac) \
	{ \
		a += G(b,c,d) + x + ac; \
		a = ROTATE_LEFT(a,s); \
		a += b; \
	}
#define HH(a,b,c,d,x,s,ac) \
	{ \
		a += H(b,c,d) + x + ac; \
		a = ROTATE_LEFT(a,s); \
		a += b; \
	}
#define II(a,b,c,d,x,s,ac) \
	{ \
		a += I(b,c,d) + x + ac; \
		a = ROTATE_LEFT(a,s); \
		a += b; \
	}

void MD5Init(MD5_CTX* context);//初始化
void Encode(unsigned int* input,unsigned char* output,unsigned int len);
void Decode(unsigned char* input,unsigned int* output,unsigned int len);
void MD5Update( MD5_CTX *context, unsigned char* input, unsigned int inputLen); //MD5算法运行
void MD5Transform(unsigned int state[4], unsigned char block[64]);
void MD5Output(unsigned char [16],MD5_CTX *context);//经过MD5算法的输出值
#endif