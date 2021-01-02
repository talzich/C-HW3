#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//This method takes input and dynamically places it into a string
void init(char str[], char word[], char *option, int length){
    int skip = 1, op_flag = 0, word_flag = 0;
    int count = 0, i =0;
    char c; 

    while((c = getchar())!=EOF){
        if (count >= length)
            str = realloc(str, (length += 10) * sizeof(char));
        
        if(skip){
            if(c != ' ' && c != '\n' &&!word_flag) word[count++] = c;

            else if (c != ' ' && c != '\n' && !op_flag){
                *option = c;
                op_flag =1;
            }

            else if (c == ' ') {
                word_flag = 1;
                continue;
            }

            if(c == '\n' && skip == 1) skip = 2;
            else if (c == '\n' && skip == 2) skip = 0;
        }
        else str[i++] = c;
    }
}

void print_lines(char str[], char word[]){}

void print_words(char str[], char word[]){
    
}


int main(void){
    int init_len = 10;
    char option;//This char will hold the print option
    char *word = malloc(init_len * sizeof(char));//This string will store the word we are looking for
    char *txt = malloc(init_len * sizeof(char));//This string will store the text we want to search in
    
    init(txt, word, &option, init_len);

    printf("Word to search is %s, search option is %c\n", word, option);
    printf("%s\n", txt);

    if(option == 'a') print_lines(txt, word);
    else print_words(txt, word);
    
    
    return 0;
}