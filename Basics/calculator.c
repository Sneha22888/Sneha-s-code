#include<stdio.h>
int main(){
    int choice;
    float num1,num2,result;
    while(1){
        printf("----------SIMPLE CALCULATOR----------\n");
        printf("1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        if(choice==5){
            printf("Exiting.....");
        }
        break;
    }
    printf("Enter two numbers : ");
    scanf("%f %f",&num1, &num2);

    switch(choice){
        case 1:
               result=num1+num2;
               printf("Result = %.2f\n",result);
               break;
        case 2:
               result=num1-num2;
               printf("Result = %.2f\n",result);
               break;
        case 3:
               result=num1*num2;
               printf("Result = %.2f\n",result);
               break;
        case 4:
               if(num2==0){
                    printf("Division by zero is not possible.");
               }
               else{
                    result=num1/num2;
                    printf("Result = %.2f\n",result);
               }
               break;
        default:
                printf("Invalid choice. Please select 1-5.\n");
    }
    return 0;
}