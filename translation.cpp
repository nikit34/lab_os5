#include"library.h"


void sortHoary(int* array, uint64_t& first, uint64_t& last) {
    uint64_t i = first;
    uint64_t j = last;
    int tmp;
    int middle = array[(first + last) / 2];
    do {
        while (array[i] < middle)
            ++i;
        while (array[j] > middle)
            --j;
        if (i <= j) {
            if (i < j) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            ++i;
            --j;
        }
    } while (i <= j);

    if (i < last)
        sortHoary(array, i, last);
    if (first < j)
        sortHoary(array, first, j);
}

int * Sort(int * array, uint64_t&& n){
    uint64_t s = 0;
    if (n < 2)
        throw std::runtime_error("[ERROR] count element of array must be great 2");
    sortHoary(array, s, n);
    return array;
}
