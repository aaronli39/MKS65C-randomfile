#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int random_num() {
    int * pointer = malloc(4);
    int dest = open("/dev/random", O_RDONLY);
    read(dest, pointer, 4);
    int ret = *pointer;
    free(pointer);
    return ret;
}

int main() {
    int arr[10];
    int i;
    for(i = 0; i < 10; i++) {
        arr[i] = random_num();
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    
}
