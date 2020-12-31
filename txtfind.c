#include <stdio.h> 

#define LINE 256

int get_line(char s[]){
    char next;
    int counter = 1;
    for(int i = 0; s[i] != '\0'; i++){
        scanf("%c",&next);
        if(next == '\n'){
            counter++;
        }
    }
    return counter;
}

int main(void){

    char s[LINE];
    printf("%d\n", get_line(s));
    return 0;
}