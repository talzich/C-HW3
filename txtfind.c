#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//This method takes input and dynamically places it into a string
void get_string(char str[], int length){
    int count = 0;
    char c; 

    while((c = getchar())!=EOF){
        if (count >= length)
            str = realloc(str, (length += 10) * sizeof(char));
        str[count++] = c;
    }
}

void get_word(char str[], char word[], int len, char *option){
    int count = 0;
    char c;

    while(count < strlen(str)){
        c = str[count];
        if(count >= len)
            word = realloc(word, (len += 5)*sizeof(char));
        if(c != ' '){
            word[count++] = c;
        }
        else break;
    }
    count++;
    *option = str[count];
}

void get_text(char str[], int length){}
void print_lines(char str[], char word[]){}
void print_words(char str[], char word[]){}


int main(void){
    int init_len = 10;
    char option;//This char will hold the print option
    char *init_str = malloc(init_len * sizeof(char));//This string will initially store the entire incoming string
    char *word = malloc(init_len * sizeof(char));//This string will store the word we are looking for
    char *str = malloc(init_len * sizeof(char));//This string will store the text we want to search in
    
    get_string(init_str, init_len);
    get_word(init_str, word, init_len, &option);
    get_text(str, init_len);


    // if(option == 'a') print_lines(str, word);
    // else print_words(str, word);
    
    // printf("Word to search is %s, search option is %c\n", word, option);

    
    
    return 0;
}