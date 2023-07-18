#ifndef MD5_H
#define MD5_H

//初始化缓冲区
typedef struct{
    unsigned int count[2];
    unsigned int state[4];    //A,B,C,D四个常数
    unsigned char buffer[64]; //输入数据缓冲区
}MD5_CTX;

/*
four basic bit operation functions:
    F(X,Y,Z) = ( X and Y ) or ( not(X) and Z )
    G(X,Y,Z) = ( X and Z ) or ( Y and not(Z) )
    H(X,Y,Z) = X xor Y xor Z
    I(X,Y,Z) =Y xor (X or not(Z))
*/
#define F(x,y,z) (( x & y ) | ( ~x & z))
#define G(x,y,z) (( x & z ) | ( y & ~z))
#define H(x,y,z) ((x) ^ (y) ^ (z))
#define I(x,y,z) ((y) ^ ((x) | (~z)))


/*
four round cycle functions:
    FF(a,b,c,d,Mj,s,Ti):a = b + (( a + F(b,c,d) + Mj + Ti) <<<s)
    GG(a,b,c,d,Mj,s,Ti):a = b + (( a + G(b,c,d) + Mj + Ti) <<<s)
    HH(a,b,c,d,Mj,s,Ti):a = b + (( a + H(b,c,d) + Mj + Ti) <<<s)
    II(a,b,c,d,Mj,s,Ti):a = b + (( a + I(b,c,d) + Mj + Ti) <<<s)
    宏定义非末行结尾加反斜杠
*/
#define FF(a,b,c,d,Mj,s,Ti) \ 
{ \
    a += F(b, c, d) + Mj + Ti; \
    a = ROTATE_LEFT(a, s); \
    a += b; \
}
#define GG(a,b,c,d,Mj,s,Ti) \ 
{ \
    a += G(b, c, d) + Mj + Ti; \
    a = ROTATE_LEFT(a, s); \
    a += b; \
}
#define HH(a,b,c,d,Mj,s,Ti) \ 
{ \
    a += H(b, c, d) + Mj + Ti; \
    a = ROTATE_LEFT(a, s); \
    a += b; \
}
#define II(a,b,c,d,Mj,s,Ti) \ 
{ \
    a += I(b, c, d) + Mj + Ti; \
    a = ROTATE_LEFT(a, s); \
    a += b; \
}

void MD5Init(MD5_CTX* context);//初始化
void MD5Update(unsigned int inputLen, unsigned char* input, MD5_CTX *context); //MD5算法运行
void MD5Output(unsigned char [16],MD5_CTX *context);//经过MD5算法的输出值
#endif