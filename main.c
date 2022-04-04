#include <stdio.h>
#include <stdlib.h>


/*
Ращупкин Евгений КЭ-203
28 вариант
Lab5
Сортировка Прямым выбором
В одномерном массиве упорядочить нечетные элементы, 
оставив четные на местах.
*/


void PrintArray(int *arr, int n){
    int i;
    for (i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}




void selectionSort(int *arr, int size){
    int min, tmp;
    for (int i = 0; i < size - 1; i++) {
        min = i; 
        for (int j = i + 1; j < size; j++){  
            if (arr[j] < arr[min]) 
                min = j;
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}



int NuberOfOdd(int *arr, int size){
    int j = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 != 0){
            j++;
        }
    }
    return j;
}


void OddFromArray(int *arr, int size, int *arr2){
    int j = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 != 0){
            arr2[j] = arr[i];    
            j++;      
        }
    }
}

void ReplacedOdd(int *arr, int size, int *arr2){
    int j = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 != 0){
            arr[i] = arr2[j];
            j++;      
        }
    }
}


int main() {
    int *arr;
    int *arr2;
    int n;
    int n2;
    int i;

    printf("Len of arr: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i<n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    PrintArray (arr, n);

    n2 = NuberOfOdd(arr, n);
    arr2 = (int*)malloc(n2 * sizeof(int));
    printf("arr2 len = %d\n", n2);
    printf("Odd:\n");
    OddFromArray(arr, n, arr2);
    PrintArray (arr2, n2);

    selectionSort(arr2, n2);
    printf("Sorted Odd:\n");
    PrintArray (arr2, n2);

    ReplacedOdd (arr, n, arr2);
    printf("Replacement:\n");
    PrintArray (arr, n);
    
    free(arr);
    free(arr2);
    return 0;
}