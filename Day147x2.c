// Write a program to find the largest of two numbers //
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b;
    printf("Enter First No. : ");
    scanf("%d",&a);
    printf("Enter Second No. : ");
    scanf("%d",&b);
    if(a>b){
        printf("%d is largest no.", a);
    }
    else if(b>a){
        printf("%d is largest no.", b);
    }
    else{
        printf("a is equal to b");
    } 
    return 0; 
}