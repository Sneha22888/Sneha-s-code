#include<stdio.h>
int main() {
    int num1=0, num2=1, term, nextterm;
    printf("Enter the number of terms : ");
    scanf("%d",&term);
    for(int i=1;i<=term;i++){
        printf("%d ",num1);
        nextterm = num1+num2;
        num1=num2; 
        num2=nextterm;
    }
    return 0;
}