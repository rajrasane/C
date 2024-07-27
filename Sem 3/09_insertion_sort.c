#include<stdio.h>
int insertion_sort(int a[],int n);
void main(){
    int n=5,i;
    int a[10];
    
    printf("Enter %d array elements :- \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Entered array :- \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    insertion_sort(a,n);

    printf("\nSorted Array :- \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }


}

int insertion_sort(int a[],int n){
	int i,j,temp;
	
	for(i=i;i<=n-1;i++){
		for(j=i;j>0 && a[j-1]>a[j];j--){
			temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
		}
	}
}
