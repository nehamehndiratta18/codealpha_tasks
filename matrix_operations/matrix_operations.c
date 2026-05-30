//Matrix operations in C:

#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[10][10]);
void displayMatrix(int rows, int cols, int matrix[10][10]);
void addMatrices(int rows, int cols, int A[10][10], int B[10][10]);
void multiplyMatrices(int r1, int c1, int r2, int c2, int A[10][10], int B[10][10]);
void transposeMatrix(int rows, int cols, int matrix[10][10]);

int main()
{
    int choice;
    int A[10][10], B[10][10];
    int rows, cols, r1, c1, r2, c2;

    do
    {
        printf("\n=================================");
        printf("\n      MATRIX OPERATIONS");
        printf("\n=================================");
        printf("\n1. Matrix Addition");
        printf("\n2. Matrix Multiplication");
        printf("\n3. Matrix Transpose");
        printf("\n4. Exit");
        printf("\n=================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter rows and columns: ");
                scanf("%d %d", &rows, &cols);

                printf("\nEnter First Matrix:\n");
                inputMatrix(rows, cols, A);

                printf("\nEnter Second Matrix:\n");
                inputMatrix(rows, cols, B);

                printf("\nResultant Matrix:\n");
                addMatrices(rows, cols, A, B);
                break;

            case 2:
                printf("\nEnter rows and columns of First Matrix: ");
                scanf("%d %d", &r1, &c1);

                printf("\nEnter First Matrix:\n");
                inputMatrix(r1, c1, A);

                printf("\nEnter rows and columns of Second Matrix: ");
                scanf("%d %d", &r2, &c2);

                if(c1 != r2)
                {
                    printf("\nMatrix multiplication not possible!\n");
                }
                else
                {
                    printf("\nEnter Second Matrix:\n");
                    inputMatrix(r2, c2, B);

                    printf("\nResultant Matrix:\n");
                    multiplyMatrices(r1, c1, r2, c2, A, B);
                }
                break;

            case 3:
                printf("\nEnter rows and columns: ");
                scanf("%d %d", &rows, &cols);

                printf("\nEnter Matrix:\n");
                inputMatrix(rows, cols, A);

                printf("\nTranspose Matrix:\n");
                transposeMatrix(rows, cols, A);
                break;

            case 4:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}

void inputMatrix(int rows, int cols, int matrix[10][10])
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[10][10])
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int A[10][10], int B[10][10])
{
    int i, j, result[10][10];

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    displayMatrix(rows, cols, result);
}

void multiplyMatrices(int r1, int c1, int r2, int c2, int A[10][10], int B[10][10])
{
    int i, j, k;
    int result[10][10];

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    displayMatrix(r1, c2, result);
}

void transposeMatrix(int rows, int cols, int matrix[10][10])
{
    int i, j;
    int transpose[10][10];

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    displayMatrix(cols, rows, transpose);
}
