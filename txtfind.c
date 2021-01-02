#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SIZE 250

struct arr{
    char text[SIZE][SIZE];
};

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

int check_line(char *line, char *word){
    char copy[strlen(line)];
    memcpy(copy, line, strlen(line));

    char *piece = strtok(copy, " \t\r\n\v");
    while(piece != NULL){
        if(!check_word(piece, word)) return 0;
        piece = strtok(NULL, " \t\r\n\v");
    }
    return 1;
}

int split(char txt[], struct arr *lines){
    char copy[strlen(txt)];
    memcpy(copy, txt, strlen(txt));

    char *piece = strtok(copy, "\n");
    int i = 0;
    struct arr res;
    while(piece != NULL){
        strcpy((*lines).text[i], piece);
        piece = strtok(NULL, "\n");
        i++;

    }
    return (i);
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

void print_lines(char txt[], char word[]){
    struct arr lines;
    int num_lines = split(txt, &lines); 
    
    int i;
    for(i=0; i < num_lines; i++){
        printf("%s\n", lines.text[i]);
    }
}

int main(void){
    int init_len = 10;
    char option;//This char will hold the print option
    char *word = malloc(init_len * sizeof(char));//This string will store the word we are looking for
    char *txt = malloc(init_len * sizeof(char));//This string will store the text we want to search in
    
    init(txt, word, &option, init_len);

     if(option == 'a') print_lines(txt, word);
    // else print_words(txt, word);
    

    return 0;
}