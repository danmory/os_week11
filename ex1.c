#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fileDescriptor = open("ex1.txt",  O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    char* str = "This is a nice day";
    size_t strLength = 18;
    ftruncate(fileDescriptor, strLength);
    char *m = mmap(0, strLength, PROT_READ | PROT_WRITE, MAP_SHARED, fileDescriptor, 0);
    memcpy(m, str, strLength);
    munmap(m, strLength);
    close(fileDescriptor);
}