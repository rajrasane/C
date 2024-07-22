#include<stdio.h>
int binary_search(int median , int a[] , int n , int ele);
void main(){
    int n , i , j , temp , median , ele , a[10] , position;

    printf("Enter how many elements you want in an array :- \n");
    scanf("%d",&n);

    printf("Enter array elements :- \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    median =  (n-1) / 2 ;

    printf("Enter element you want to search in the array :- \n");
    scanf("%d",&ele);

    // sorting the array
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    position = binary_search(median,a,n,ele);

    if(position==-1){
        printf("Element is not present in the array!");
    }
    else{
        printf("Element is present in array at %d",position);
    }

}

int binary_search(int median , int a[] , int n , int ele){
    int i;
    if(ele==median){
        printf("Element is present in array at %d index",median);
    }
    else if(ele<median){
        for(i=0;i<median;i++){
            if(a[i]==ele){
                return i;
            }
            return -1;
        }
    }
    else{
        for(i=median;i<n-1;i++){
            if(a[i]==ele){
                return i;
            }
            return -1;
        }
    }
}