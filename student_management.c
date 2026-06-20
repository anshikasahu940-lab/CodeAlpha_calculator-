#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[50];
    int i, n;
    
    printf("=== Student Record Management System ===\n");
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("\nStudent %d\n", i+1);
        printf("Enter Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
    
    printf("\n--- All Student Records ---\n");
    printf("Roll\tName\t\tMarks\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
    
    return 0;
}
