// Implement an array of integers of size 10 with the create, insert, delele and display operations. Write a menu-driven program to call these operations

#include <stdio.h>

void create(int a[], int size);
void insert(int a[], int *size);
void delete(int a[],int *size);
void display(int a[], int size);

void main() {
    int a[10], size = 0, choice,p=0;

    do {
        printf("\n********** Menu **********\n");
        printf("1. Create\n2. Insert\n3. Display\n4. Delete\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if(p<=0){
                    printf("Enter the number of elements (max 10): ");
                    scanf("%d", &size);
                    create(a, size);
                    p++;
                    break;
                }else{
                    printf("You have already created a array ! Pls exit and restart again to make one .");
                    break;
                }
                
            case 2:
                insert(a, &size);
                break;
            case 3:
                display(a, size);
                break;
            case 4:
                delete(a,&size);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

}

void create(int a[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    printf("Array created successfully.\n");
}

void insert(int a[], int *size) {
    if (*size >= 10) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    int ele, index;
    printf("Enter the element to insert: ");
    scanf("%d", &ele);
    printf("Enter the index (0 to %d): ", *size);
    scanf("%d", &index);

    for(int i=(*size)-1;i>=index;i--){
        a[i+1] = a[i];
    }

    a[index] = ele;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void delete(int a[], int *size) {
    int ele, i, loc = -1;

    printf("Enter the element to be deleted: ");
    scanf("%d", &ele);

    for (i = 0; i < *size; i++) {
        if (a[i] == ele) {
            loc = i;
            break;
        }
    }

    if (loc == -1) {
        printf("Element not found in the array.\n");
        return;
    }

    for (i = loc; i < *size - 1; i++) {
        a[i] = a[i + 1];
    }

    (*size)--; 
    printf("Element deleted successfully.\n");
}


void display(int a[], int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
