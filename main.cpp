#include <stdio.h>
#include <string.h>
#include "MD5.h"

int main(){
    unsigned char encrypt[]="woyuditan";
    unsigned char decrypt[16];
    MD5_CTX md5;
    MD5Init(&md5);
    MD5Update(&md5, encrypt, strlen((char*)encrypt));
    MD5Output(decrypt,&md5);
    printf("加密前：%s\n MD5算法加密后的结果：%s\n",encrypt,decrypt);
}