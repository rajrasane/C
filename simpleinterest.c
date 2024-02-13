#include<stdio.h>
void main(){
    float principal,time,rate,SI;

    printf("Enter principal amount :\n");
    scanf("%f",&principal);

    printf("Enter time period :\n");
    scanf("%f",&time);

    printf("Enter rate :\n");
    scanf("%f",&rate);

    SI = (principal*time*rate)/100;

    printf("Simple Interest of Given Values is : %f\n",SI);
}