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

    // write to file
    int dest = open("temp.txt", O_CREAT | O_WRONLY, 0777);
    write(dest, arr, sizeof(arr));
    printf("writing to file...\n\n");
    close(dest);

    // read from file
    int * data = malloc(4);
    dest = open("temp.txt", O_RDONLY);
    read(dest, data, sizeof(arr));
    printf("reading from file...\n\n");
    close(dest);
    printf("results: \n");
    for(i = 0; i < 10; i++) {
        printf("val: %d\n", * (data + i));
    }

}
