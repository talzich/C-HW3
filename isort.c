#include <stdio.h>

#define SIZE 50

//A simple method to print an array
void print_array(size_t how_many, int array[]){
    int i;
    for (i = 0; i < how_many; i++)
    {
        if(i == how_many-1)printf("%d\n", *(array + i));
        else printf("%d,", *(array + i));
    }
}

/*
    This method gets a pointer to a position in an array and an integer i; 
    The method procedes to shift i elements, starting at the one received as a parameter, one cell to the right, 
    overriding the current value in each cell. 
*/
void shift_element(int *arr, int i){
    for(int j = i; j > 0 ; j--){
        *(arr + j)  = *(arr + j-1);
    }
}

//Pointer arithmetic implementation of insertion sort. 
void insertion_sort(int* arr , int len){
    
    int *ptr;//We will send this pointer to shift_element
    int counter;
    for(int i = 1; i < len; i++){
        counter = 0;
        if(*(arr+i) < *(arr+i-1)){
            for(int j = i-1; j >= 0; j--){
                if(*(arr + i) < *(arr +j)){
                    ptr = (arr+j);
                    counter++;
                }
            }
            int temp = *(arr + i);
            shift_element(ptr, counter);
            *(ptr) = temp;
        }
    }
}


int main(void){
    int arr[SIZE];
    printf("Please enter 50 numbers:\n");
    for(int i = 0; i < SIZE; i++){
        scanf("%d",(arr + i));
        printf("Number %d registered\n", i);
    }
    insertion_sort(arr, SIZE);
    print_array(SIZE, arr);
    return 0;
}