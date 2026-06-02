#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[50];
    int roll;
    int age;
    char department[50];
    float cgpa;
    char grade;
};
struct student s[50];
int count=0;
//calculate grade system
char calculateGrade(float cgpa){
    if(cgpa>=9.0){
        return 'O';
    }
    if(cgpa>=8.0 && cgpa<9.0){
        return 'E';
    }
    if(cgpa>=7.0 && cgpa<8.0){
        return 'A';
    }
    if(cgpa>=6.0 && cgpa<7.0){
        return 'A';
    }
    if(cgpa>=5.0 && cgpa<6.0){
        return 'A';
    }
    if(cgpa<5.0){
        return 'F';
    }
}
//add students
void addStudents(){
    printf("Enter roll no. : ");
    scanf("%d",&s[count].roll);
    printf("Enter name : ");
    scanf(" %[^\n]",s[count].name);
    printf("Enter age : ");
    scanf("%d",&s[count].age);
    printf("Enter department : ");
    scanf("%s",s[count].department);
    printf("Enter cgpa : ");
    scanf("%f",&s[count].cgpa);
    s[count].grade=calculateGrade(s[count].cgpa);
    count++;
    printf("\nStudent added successfully.\n");
}
//display students
void displayStudents(){
    if(count==0){
        printf("\nNo record found.\n");
        return;
    }
    printf("\n%-6s %-15s %-4s %-15s %-6s %-5s\n","Roll","Name","Age","Department","CGPA","Grade");
    for(int i=0;i<count;i++){
        printf("%-6d %-15s %-4d %-15s %-6.2f %-5c\n",s[i].roll,s[i].name,s[i].age,s[i].department,s[i].cgpa,s[i].grade);
    }
}
//delete students
void deleteStudents(){
    int roll,found=0;
    printf("Enter the roll no you want to delete : ");
    scanf("%d",&roll);
    for(int i=0;i<count;i++){
        if(s[i].roll==roll){
            for(int j=i;j<count-1;j++){
                s[j]=s[j+1];
            }
            count--;
            printf("\nRecord deleted successfully.\n");
            found=1;
            break;
        }
    }
    if(found==0){
        printf("\nStudent not found.\n");
    }
}
//count students
void countStudents(){
    printf("\nTotal number of students = %d\n",count);
}
//search students
void searchStudents(){
    int roll,found=0;
    printf("Enter the roll no you want to search : ");
    scanf("%d",&roll);
    for(int i=0;i<count;i++){
        if(roll==s[i].roll){
            printf("\nStudent found.\n");
            printf("\n%-6s %-15s %-4s %-15s %-6s %-5s\n","Roll","Name","Age","Department","CGPA","Grade");
            printf("%-6d %-15s %-4d %-15s %-6.2f %-5c\n",s[i].roll,s[i].name,s[i].age,s[i].department,s[i].cgpa,s[i].grade);
            found=1;
            break;
        }    
    }
    if(found==0){
        printf("\nStudent not found.\n");
    }
}
//update details
void updateDetails(){
    int roll,found=0;
    printf("Enter the roll no you want to update the details of : ");
    scanf("%d",&roll);
    for(int i=0;i<count;i++){
        if(roll==s[i].roll){
            printf("Enter new name : ");
            scanf(" %[^\n]",s[i].name);
            printf("Enter new age : ");
            scanf("%d",&s[i].age);
            printf("Enter new department : ");
            scanf("%s",s[i].department);
            printf("Enter new cgpa : ");
            scanf("%f",&s[i].cgpa);  
            s[i].grade=calculateGrade(s[i].cgpa);
            printf("\nRecord updated sucessfully.\n");
            found=1;
            break;
        }
    }
    if(count==0){
        printf("\nStudent not found.\n");
    }
}
//display topper
void displayTopper(){
    int topper=0;
    if(count==0){
        printf("\nStudent not found.\n");
    }
    for(int i=1;i<count;i++){
        if(s[i].cgpa>s[topper].cgpa){
            topper=i;
        }
    }
    printf("\nTopper Details\n");
    printf("\n%-6s %-15s %-4s %-15s %-6s %-5s\n","Roll","Name","Age","Department","CGPA","Grade");
    printf("%-6d %-15s %-4d %-15s %-6.2f %-5c\n",s[topper].roll,s[topper].name,s[topper].age,s[topper].department,s[topper].cgpa,s[topper].grade);
}
int main(){
    int choice;
    do{
        printf("\n\n----------STUDENT RECORD MANAGEMENT----------\n\n");
        printf("1. Add Students\n");
        printf("2. Display Students\n");
        printf("3. Delete studets\n");
        printf("4. Count students\n");
        printf("5. Search students\n");
        printf("6. Update students\n");
        printf("7. Display topper\n");
        printf("8. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addStudents();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                deleteStudents();
                break;
            case 4:
                countStudents();
                break;
            case 5:
                searchStudents();
                break;
            case 6:
                updateDetails();
                break;
            case 7:
                displayTopper();
                break;
            case 8:
                printf("\nThank You\n");
                break;
            default:
                printf("\nInvalid Choice.\n");
        }
    }while(choice!=8);
    return 0;
}
