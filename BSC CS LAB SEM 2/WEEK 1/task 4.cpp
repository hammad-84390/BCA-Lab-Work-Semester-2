#include <stdio.h>

int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows1, cols1, rows2, cols2;
    int i, j, k;
    char choice;

    printf("Enter number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter elements of first matrix:\n");
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    printf("Enter elements of second matrix:\n");
    for(i = 0; i < rows2; i++) {
        for(j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nChoose operation:\n");
    printf("a) Addition\nb) Subtraction\nc) Multiplication\nd) Transpose of first matrix\n");
    printf("Enter choice (a/b/c/d): ");
    scanf(" %c", &choice);

    switch(choice) {
        case 'a':
            if(rows1 != rows2 || cols1 != cols2) {
                printf("Addition not possible. Matrices must have same size.\n");
            } else {
                printf("Result of addition:\n");
                for(i = 0; i < rows1; i++) {
                    for(j = 0; j < cols1; j++) {
                        result[i][j] = matrix1[i][j] + matrix2[i][j];
                        printf("%d\t", result[i][j]);
                    }
                    printf("\n");
                }
            }
            break;

        case 'b':
            if(rows1 != rows2 || cols1 != cols2) {
                printf("Subtraction not possible. Matrices must have same size.\n");
            } else {
                printf("Result of subtraction:\n");
                for(i = 0; i < rows1; i++) {
                    for(j = 0; j < cols1; j++) {
                        result[i][j] = matrix1[i][j] - matrix2[i][j];
                        printf("%d\t", result[i][j]);
                    }
                    printf("\n");
                }
            }
            break;

        case 'c': 
            if(cols1 != rows2) {
                printf("Multiplication not possible. Columns of first must equal rows of second.\n");
            } else {
                
                for(i = 0; i < rows1; i++)
                    for(j = 0; j < cols2; j++)
                        result[i][j] = 0;

                
                for(i = 0; i < rows1; i++) {
                    for(j = 0; j < cols2; j++) {
                        for(k = 0; k < cols1; k++) {
                            result[i][j] += matrix1[i][k] * matrix2[k][j];
                        }
                    }
                }

    
                printf("Result of multiplication:\n");
                for(i = 0; i < rows1; i++) {
                    for(j = 0; j < cols2; j++)
                        printf("%d\t", result[i][j]);
                    printf("\n");
                }
            }
            break;

        case 'd':
            printf("Transpose of first matrix:\n");
            for(i = 0; i < cols1; i++) {
                for(j = 0; j < rows1; j++)
                    printf("%d\t", matrix1[j][i]);
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

