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
    int min, tmp; // для поиска минимального элемента и для обмена
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

void OddFromArray(int *arr, int size, int *arr2){
    int j = 0; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0){
            arr = (int*)malloc(sizeof(int));
            arr2[j]=arr[i];
        }
    }
}



int main() {
    int *arr;
    int *arr2;
    int n;
    int i;

    printf("Len of arr: ");
    scanf("%d", &n);
    
    arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i<n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    PrintArray (arr, n);

    OddFromArray(arr, n, arr2);
    printf("Odd:\n");
    PrintArray (arr2, n);
    selectionSort(arr2, n);
    PrintArray (arr2, n);

    
    
    PrintArray (arr, n);
    
    free(arr);
    return 0;
}