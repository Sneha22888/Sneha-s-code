#include<stdio.h>
int isPrime(int x){
    if(x<=1){
        return 0;
    }
    for(int i=2;i<=x/2;i++){
        if(x%2==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int num; 
    printf("Enter a number : ");
    scanf("%d",&num);
    if(isPrime(num)){
        printf("%d is a prime number.",num);
    }
    else{
        printf("%d is not a prime number.",num);
    }
    return 0;
}