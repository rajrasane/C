#include<stdio.h>
void main(){
	int n,i,j,temp;
	int a[10];

	printf("Enter how many elements of array you want :- \n");
	scanf("%d",&n);

	printf("Enter array elements :- \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	printf("Array without being sorted :- \n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}

	// Bubble Sort
	for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }


	printf("\nSorted Array :- \n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
