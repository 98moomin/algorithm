#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void* second){
    if(*(int*)first > *(int*)second)
        return 1;
    else if(*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int search(int *arr, int tmp, int size){
    int front, mid, rear;
    front = 0; rear = size - 1;
    while(1){
        mid = (front + rear) / 2;
        if(arr[mid] == tmp)
            return 1;
        if(arr[front] == tmp)
            return 1;
        if(arr[rear] == tmp)
            return 1;
        
        if(arr[mid] < tmp)
            front = mid + 1;
        else
            rear = mid - 1;
        
        if(rear <= front)
            return 0;
    }
}

int main()
{
    int N, M, tmp;
    scanf("%d", &N);
    int *arrayN = (int *)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arrayN[i]);
    }
    qsort(arrayN, N, sizeof(int), compare);
    
    scanf("%d", &M);
    int *result = (int *)malloc(sizeof(int) * M);
    for(int i = 0; i < M; i++){
        scanf("%d", &tmp);
        result[i] = search(arrayN, tmp, N);
    }
    for(int i = 0; i < M; i++){
        printf("%d\n", result[i]);
    }
}
