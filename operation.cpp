#include"library.h"


float E(int x){
    if (!bool(x))
        throw std::runtime_error("[ERROR] argument can not been equal zero");

    uint64_t res = 1;
    uint64_t i;

    if (x > 0)
        for (i = 0; i < x; ++i)
            res = res * (1 + 1 / x);
    else
        for (i = 0; i > x; --i)
            res = res / (1 + 1 / x);
    return res;
}
