#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void acceptInput(int arr[],int cArr[],int pArr[],int size){
    printf("Enter %d elements :- \n",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
        cArr[i] = arr[i];
        pArr[i] = arr[i];
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

void ascsort(int arr[], int n) {
    int i, j;
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void descsort(int arr[], int n) {
    int i, j;
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main() {
    pid_t child_pid;
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
        sleep(5);
        printf("\nDescending sort by child :- \n");
        descsort(cArr, size);
        display(cArr, size);
        printf("\n------Child Process Completed------\n\n");
    } else {
        wait(NULL); 
        printf("\n\n------The Parent Process------\n");
        printf("\nParent process ID is %d\n", getpid());
        printf("\nChild process ID is %d\n", child_pid);
        sleep(5);
        printf("\nAscending sort by parent :- \n");
        ascsort(pArr, size);
        display(pArr, size);
        printf("\n------Parent process completed-------\n\n");
    }
    return 0;
}