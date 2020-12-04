#include"library.h"


float calcE(int x){
    if (!bool(x))
        throw std::runtime_error("[ERROR] argument can not been equal zero");

    float res = 1;
    int i;

    if (x > 0)
        for (i = 0; i < x; ++i)
            res = res * (1 + 1 / (float)x);
    else
        for (i = 0; i > x; --i)
            res = res / (1 + 1 / x);
    return res;
}
