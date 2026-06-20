#include <stdio.h>

int main() {
    char op;
    double num1, num2;

    printf("=== CodeAlpha Calculator ===\n");
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch(op) {
        case '+':
            printf("Result: %.2lf\n", num1 + num2);
            break;
        case '-':
            printf("Result: %.2lf\n", num1 - num2);
            break;
        case '*':
            printf("Result: %.2lf\n", num1 * num2);
            break;
        case '/':
            if(num2 != 0)
                printf("Result: %.2lf\n", num1 / num2);
            else
                printf("Error: Division by zero not allowed\n");
            break;
        default:
            printf("Invalid operator\n");
    }
    return 0;
}
