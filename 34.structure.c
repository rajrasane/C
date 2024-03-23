#include<stdio.h>
#include<string.h>
struct student{
        int sno;
        char name[20];
        int sub1;
        int sub2;
        int sub3;
        float percentage;
    } s[20];

void main(){
    int n,i,ch;
    char n1[20],n2[20];
    float max = s[0].percentage;

    printf("Enter how many students \n");
    scanf("%d",&n);

    for(i = 0;i<n;i++){
        printf("Enter student number : ");
        scanf("%d",&s[i].sno);
        printf("Enter student name : ");
        scanf("%s",&s[i].name);
        printf("Enter subject 1 marks : ");
        scanf("%d",&s[i].sub1);
        printf("Enter subject 2 marks : ");
        scanf("%d",&s[i].sub2);
        printf("Enter subject 3 marks : ");
        scanf("%d",&s[i].sub3);
        printf("Enter student percentage : ");
        scanf("%f",&s[i].percentage);
    }

    printf("\n----------Menu----------\n");
    printf("1) Search a student\n2) Modify Data\n3) Display all student details\n4) Display student having percentage > 80\n5) Display student having maximum percentage \n\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);

    switch(ch){
        case 1 : 
        printf("Enter student name to search : ");
        scanf("%s",&n1);
        for(i=0;i<n;i++){
            if (strcmp(n1,s[i].name)==0)
            {
                printf("\nRecord of Student %s was found\n",n1);
            }else{
                printf("\nRecord of Student %s was not found\n",n1);
            }
            
        }

        case 2 :
        printf("Enter whose record you want to modify : ");
        scanf("%s",&n2);

        

        case 3 : 
        for(i=0;i<n;i++){
            printf("\tSno\t\tSname\t\tSub1 Marks\t\tSub2 Marks\t\tSub3 Marks\t\tPercentage\n");
            printf("---------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t%d\t\t%s\t\t%d\t\t\t%d\t\t\t%d\t\t\t%.2f\n",s[i].sno,s[i].name,s[i].sub1,s[i].sub2,s[i].sub3,s[i].percentage);
        }

        case 4 : 
        for(i=0;i<n;i++){
            if(s[i].percentage>80.00){
            printf("\tSno\t\tSname\t\tSub1 Marks\t\tSub2 Marks\t\tSub3 Marks\t\tPercentage\n");
            printf("---------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t%d\t\t%s\t\t%d\t\t\t%d\t\t\t%d\t\t\t%.2f\n",s[i].sno,s[i].name,s[i].sub1,s[i].sub2,s[i].sub3,s[i].percentage);
        }
        }

        case 5 : 
        for(i=0;i<n;i++){
            if(s[i].percentage>max){
                max = s[i].percentage;
        }
        }
        for(i=0;i<n;i++){
            if(s[i].percentage==max){
            printf("\tSno\t\tSname\t\tSub1 Marks\t\tSub2 Marks\t\tSub3 Marks\t\tPercentage\n");
            printf("---------------------------------------------------------------------------------------------------------------------------\n");
            printf("\t%d\t\t%s\t\t%d\t\t\t%d\t\t\t%d\t\t\t%.2f\n",s[i].sno,s[i].name,s[i].sub1,s[i].sub2,s[i].sub3,s[i].percentage);
        }
        }
}
}