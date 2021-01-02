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

int check_word(char *piece, char *word){
    int i;
    for(i = 0; i < strlen(word); i++){
        if(word[i] != piece[i]){
            if(word[i] != piece[i+1]) return 0;
        }
    }
    return 1;
}

void print_lines(char line[], char word[]){
    char copy[strlen(line)];
    memcpy(copy, line, strlen(line));

    char *piece = strtok(copy, " \t\r\n\v\f");

    while(piece != NULL)
    {
        if(strlen(piece) >= strlen(word) && strlen(piece) <= strlen(word) + 1)
            if(check_word(piece,word)) printf("%s\n", copy);
        piece = strtok(NULL, " \t\r\n\v\f");
    }
}

void check_lines(char txt[], char word[]){

    //We need a copy of the original txt because strtok modifies the string it is working on
    char copy[strlen(txt)];
    memcpy(copy, txt, strlen(txt));

    char *line = strtok(copy, "\n");
    char *piece;
    while(line != NULL)
    {   
        printf("Current line: %s\n", line);
        print_lines(line, word);
        line = strtok(NULL, "\n");
        printf("Next line: %s\n", line);
    }

}

void print_words(char txt[], char word[]){
    //We need a copy of the original txt because strtok modifies the string it is working on
    char copy[strlen(txt)];
    memcpy(copy, txt, strlen(txt));

    char *piece = strtok(copy, " \t\r\n\v\f");
    while(piece != NULL)
    {
        if(strlen(piece) >= strlen(word) && strlen(piece) <= strlen(word) + 1)
            if(check_word(piece,word)) printf("%s\n", piece);
        piece = strtok(NULL, " \t\r\n\v\f");
    }
}

int main(void){
    int init_len = 10;
    char option;//This char will hold the print option
    char *word = malloc(init_len * sizeof(char));//This string will store the word we are looking for
    char *txt = malloc(init_len * sizeof(char));//This string will store the text we want to search in
    
    init(txt, word, &option, init_len);

    if(option == 'a') check_lines(txt, word);
    else print_words(txt, word);
    

    return 0;
}