#include <stdio.h>
#include <stdlib.h>

int myStrlen(const char *s){
    int len = 0;
    while (*s != '\0'){
        len += 1;
        s++;
    }
    
    return len;
}

int main(void)
{
   char letter[] = "Hello world!";
   int lengthofstring = myStrlen(letter);
   
   printf("the string has a length of %d\n", lengthofstring);

    return 0;
}
