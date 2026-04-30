#include<stdio.h>
int main(){
    int num;
    long long fact=1;
    printf("Enter a number : ");
    scanf("%d",&num);
    if(num<0){
        printf("Error: Factorial not defined.");
    }
    else if(num==0){
        printf("0! = 1\n");
    }
    else{
        if(num>20){
            printf("Error: %d! factorial exceeds long long limit.\n");
        }
        else{
            for(int i=1; i<=num; i++){
                fact *= i;
            }
        printf("%d! = %lld\n",num,fact);
        }
    }
    return 0;
}