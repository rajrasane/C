#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void acceptInput(int arr[] , int cArr[], int pArr[] , int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", (i + 1));
        scanf("%d", &arr[i]);
        pArr[i] = arr[i];
        cArr[i] = arr[i];
    }
}

void display(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubblesort(int arr[], int n) {
    int i, j;
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void insertionsort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        for(j=i-1;j>=0 && (key<arr[j]);j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

int main() {
    int child_pid;
    int size ;

    printf("Enter number of integer to be sort:\n");
    scanf("%d", &size);

    int arr[size];
    int pArr[size];
    int cArr[size];

    acceptInput(arr, cArr, pArr, size);

    printf("\nYou entered :- \n");
    display(arr, size);

    printf("\nParent process ID is : %d\n", getpid());
    printf("\n[ Forking Child Process...]\n");
    child_pid = fork();

    if (child_pid < 0) {
        printf("\nChild Process Creation Failed!!!!\n");
        exit(-1);
    }
    else if (child_pid == 0) {
        printf("\n\n------The Child Process------\n");
        printf("\nChild process ID is %d\n", getpid());
        printf("\nParent process ID is %d\n",getppid());
        sleep(15);
        printf("\nInsertion sort by child :- \n");
        insertionsort(cArr, size);
        display(cArr, size);
        printf("\n------Child Process Completed------\n\n");
    } else {
        wait(NULL); 
        printf("\n\n------The Parent Process------\n");
        printf("\nParent process ID is %d\n", getpid());
        printf("\nChild process ID is %d\n", child_pid);
        sleep(15);
        printf("\nBubble sort by parent :- \n");
        bubblesort(pArr, size);
        display(pArr, size);
        printf("\n------Parent process completed-------\n\n");
    }
    return 0;
}