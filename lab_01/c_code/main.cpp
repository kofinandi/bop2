#include <stdio.h>

void f(int i){
    i = i + 2;
}

void g(int *i){
    *i = *i + 2;
}

int main() {
    int i = 0;
    printf("The number before the function: %d\n", i);

    f(i);
    printf("The number after the function: %d\n", i);

//    g(&i);
//    printf("The number after the function: %d\n", i);
    return 0;
}