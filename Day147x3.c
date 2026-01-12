// Write a program to check if a number is even or odd //
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b;
    
    int choice ;
    choice=1; 
    while(choice==1){
        printf("Enter a No. : ");
        scanf("%d",&a);
        if(a%2==1){
        printf("%d is an Odd No.\n", a);
        }
        else if(a%2!=1){
            printf("%d is an Even No. \n", a);
        } 

        printf("If you want to do again: 1- yes , 0- no \n");
        
        scanf("%d", &choice);


    }
    
    return 0;
}