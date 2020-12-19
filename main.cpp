#include<iostream>
#include<cstring>
#include"library.h"


inline void menu(){
    std::cout << "1. translation to bin" << std::endl;
    std::cout << "2. Sort Hoarry" << std::endl;
}

int main() {
    uint16_t cmd = 0;
    bool inloop;
    char c;
    int tmp;

    int x;

    int* array;
    uint64_t size, capacity;

    while(true) {
        menu();
        std::cin >> cmd;
        std::cin.get();
        switch (cmd) {
            case 1:{
                std::cout << std::endl << "x: ";
                std::cin >> x;
                std::cout << "Result translation(x): " << translation(x) << std::endl << std::endl;
                break;
            }
            case 2: {
                inloop = true;

                capacity = 1;
                size = 0;
                array = nullptr;
                std::cout << "array: ";

                while (inloop) {
                    tmp = 0;
                    while(true){
                        c = std::cin.get();
                        if (c == '\n') {
                            inloop = false;
                            break;
                        } else if (c == ' ') {
                            break;
                        }
                        tmp = tmp * 10 + (int)c - '0';
                    }

                    if (size == capacity - 1){
                        capacity = capacity * 2;
                        int * new_array = new int[capacity];
                        for(uint64_t i = 0; i < size; ++i)
                            new_array[i] = array[i];
                        delete[] array;
                        array = new_array;
                        new_array = nullptr;
                    }

                    array[size] = (int)tmp;
                    ++size;
                    capacity = sizeof(*array) / sizeof(array[0]);
                }
                array = Sort(array, size - 1);
                std::cout << "Result Sort(array): ";
                for (uint64_t i = 0; i < size; ++i)
                    std::cout << array[i] << " ";
                std::cout << std::endl << std::endl;

                array = nullptr;
                break;
            }
            default:{
                std::cout << std::endl << "[ERROR] Key is not defined" << std::endl;
            }
        }
    }
    return 0;
}
