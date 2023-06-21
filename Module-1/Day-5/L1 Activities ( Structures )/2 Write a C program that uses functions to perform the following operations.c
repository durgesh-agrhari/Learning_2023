#include <stdio.h>

struct ComplexNumber {
    float real;
    float imaginary;
};

void readComplexNumber(struct ComplexNumber* complex) {
    printf("Enter real part: ");
    scanf("%f", &(complex->real));
    
    printf("Enter imaginary part: ");
    scanf("%f", &(complex->imaginary));
}

void writeComplexNumber(const struct ComplexNumber* complex) {
    printf("%.2f + %.2fi\n", complex->real, complex->imaginary);
}

struct ComplexNumber addComplexNumbers(const struct ComplexNumber* complex1, const struct ComplexNumber* complex2) {
    struct ComplexNumber result;
    result.real = complex1->real + complex2->real;
    result.imaginary = complex1->imaginary + complex2->imaginary;
    return result;
}

struct ComplexNumber multiplyComplexNumbers(const struct ComplexNumber* complex1, const struct ComplexNumber* complex2) {
    struct ComplexNumber result;
    result.real = complex1->real * complex2->real - complex1->imaginary * complex2->imaginary;
    result.imaginary = complex1->real * complex2->imaginary + complex1->imaginary * complex2->real;
    return result;
}

int main() {
    struct ComplexNumber complex1, complex2, sum, product;

    printf("Enter first complex number:\n");
    readComplexNumber(&complex1);

    printf("Enter second complex number:\n");
    readComplexNumber(&complex2);

    printf("First complex number: ");
    writeComplexNumber(&complex1);

    printf("Second complex number: ");
    writeComplexNumber(&complex2);

    sum = addComplexNumbers(&complex1, &complex2);
    printf("Sum of the complex numbers: ");
    writeComplexNumber(&sum);

    product = multiplyComplexNumbers(&complex1, &complex2);
    printf("Product of the complex numbers: ");
    writeComplexNumber(&product);

    return 0;
}
