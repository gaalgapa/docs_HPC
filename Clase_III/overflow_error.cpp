#include <cstdio>

int main(void){
    int a = 1;

    while(a > 0){
        a *= 3;
        std::printf("%10d\n", a);
    }
    return 0;
}