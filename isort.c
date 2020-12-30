#include <stdio.h>

void print_array(size_t how_many, int array[]){
    int i;
    for (i = 0; i < how_many; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void shift_element(int *arr, int i){
    for(int j = i; j > 0 ; j--){
        *(arr + j)  = *(arr + j-1);
    }
}

void insertion_sort(int* arr , int len){

}

int main(void){
    
}