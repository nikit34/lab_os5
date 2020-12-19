#include"library.h"


char* translation(long x){
    char *res = (char*)malloc(sizeof(char));
    res[0] = '\0';
    if(!x){
        char *tmp = (char*)malloc((strlen(res) + 2) * sizeof(char));
        strcpy(tmp+1, res);
        free(res);
        res = tmp;
        res[0] = '0';
    }

    while(x > 0){
        char ch = (x % 3) + '0';
        x = x / 3;
        char *tmp = (char*)malloc((strlen(res) + 2) * sizeof(char));
        strcpy(tmp+1, res);
        free(res);
        res = tmp;
        res[0] = ch;
    }
    return res;
}
