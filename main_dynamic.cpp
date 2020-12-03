#include<iostream>
#include<dlfcn.h>


void *handleLib = nullptr;

extern bool mode = false;

float (* calcE)(int x) = nullptr;
int* (* Sort)(int * array, uint64_t&& n) = nullptr;
char *error;


void loadDLibs(){
    const char *name;

    if(mode){
        name = "operation.so";
    } else {
        name = "translation.so";
    }

    handleLib = dlopen(name, RTLD_LAZY);
    if(!handleLib){
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
}

void closeLib(){
    dlclose(handleLib);
}

void openLib(){
    loadDLibs();

    float* calcE = (float*) dlsym(handleLib, "calcE");
    int* Sort = (int*) dlsym(handleLib, "Sort");

    if(error = dlerror()) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
}

void changeContext(){
    closeLib();

    mode = (bool(mode)) ? false : true;
    std::cout << "Contract was changed" << std::endl;

    openLib();
}

inline void menu(){
    std::cout << "1. Calc (1 + 1/x) ^ x" << std::endl;
    std::cout << "2. Sort Hoarry" << std::endl;
}

int main(){
    mode = false;
    openLib();

    uint16_t cmd = 0;
    bool inloop;
    char c;
    int tmp;

    int x;

    int* array;
    uint64_t size, capacity;

    do{
        menu();
        std::cin >> cmd;
        std::cin.get();

        switch(cmd){
            case 0:{
                changeContext();
                break;
            }
            case 1:{
                std::cout << std::endl << "x: ";
                std::cin >> x;
                std::cout << "Result calcE(x): " << calcE(x) << std::endl << std::endl;
                break;
            }
            case 2:{
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
                    capacity = sizeof(array) / sizeof(array[0]);
                }
                Sort(array, size - 1);
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
    } while(true);
    closeLib();
}