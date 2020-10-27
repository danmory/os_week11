#include <stdio.h>
#include <unistd.h>



int main(){
    size_t strLength = 6;
	char* text = "Hello\n";
	
	setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	
	for(size_t i=0; i < strLength; i++){
		printf("%c", *(text + i));
		sleep(1);
	}
    
	return 0;
}