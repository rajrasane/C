#include<stdio.h>

void insertionsort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        for(j=i-1;j>=0 && (key<a[j]);j--){
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
}

void main(){
	int n,i;

	printf("Enter how many array elements you want :- \n");
	scanf("%d",&n);
	
	int arr[n];

	printf("\nEnter %d array elements :- \n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("\nWithout Sorting :- \n\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	printf("\n\nWith Sorting\n\n");
	insertionsort(arr,n);
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
