#include <stdio.h>

struct Complex {
    float real;   
    float imag;   
};

struct Complex addComplex(struct Complex first, struct Complex second) {
    struct Complex sum;

    sum.real = first.real + second.real;   
    sum.imag = first.imag + second.imag;   

    return sum;
}

int main() {
    struct Complex number1, number2, result;

    printf("Complex Number Addition Program\n");
    printf("--------------------------------\n");

    printf("Enter the first complex number:\n");
    printf("Real part: ");
    scanf("%f", &number1.real);
    printf("Imaginary part: ");
    scanf("%f", &number1.imag);

    printf("\nEnter the second complex number:\n");
    printf("Real part: ");
    scanf("%f", &number2.real);
    printf("Imaginary part: ");
    scanf("%f", &number2.imag);

    result = addComplex(number1, number2);

    printf("\nThe sum of the complex numbers is: ");
    if(result.imag >= 0)
        printf("%.2f + %.2fi\n", result.real, result.imag);
    else
        printf("%.2f - %.2fi\n", result.real, -result.imag);

    return 0;
}

