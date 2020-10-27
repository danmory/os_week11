#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    struct stat sb;

    int srcFileDescriptor = open("ex1.txt", O_RDONLY);
    int destFileDescriptor = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    fstat(srcFileDescriptor, &sb);
    char* src = mmap(0, sb.st_size, PROT_READ, MAP_PRIVATE, srcFileDescriptor, 0);
    ftruncate(destFileDescriptor, sb.st_size);
    char* dest = mmap(0, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, destFileDescriptor, 0);

    memcpy(dest, src, sb.st_size);
    
    close(srcFileDescriptor);
    close(destFileDescriptor);
    munmap(src, sb.st_size);
    munmap(dest, sb.st_size);

    return 0;
}