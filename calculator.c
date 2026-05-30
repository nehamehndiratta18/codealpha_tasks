// Calculator in C:

#include <stdio.h>

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}

void displayMenu()
{
    printf("\n==============================");
    printf("\n      CALCULATOR MENU");
    printf("\n==============================");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Exit");
    printf("\n==============================");
}

int main()
{
    float num1, num2, result;
    int choice;

    while(1)
    {
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 5)
        {
            printf("\nThank you for using the calculator!\n");
            break;
        }

        if(choice < 1 || choice > 5)
        {
            printf("\nInvalid choice. Please try again.\n");
            continue;
        }

        printf("\nEnter first number: ");
        scanf("%f", &num1);

        printf("Enter second number: ");
        scanf("%f", &num2);

        switch(choice)
        {
            case 1:
                result = add(num1, num2);
                printf("\nResult = %.2f\n", result);
                break;

            case 2:
                result = subtract(num1, num2);
                printf("\nResult = %.2f\n", result);
                break;

            case 3:
                result = multiply(num1, num2);
                printf("\nResult = %.2f\n", result);
                break;

            case 4:
                if(num2 == 0)
                {
                    printf("\nError: Division by zero is not allowed.\n");
                }
                else
                {
                    result = divide(num1, num2);
                    printf("\nResult = %.2f\n", result);
                }
                break;
        }
    }

    return 0;
}