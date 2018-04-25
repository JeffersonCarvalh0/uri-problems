# include <stdio.h>

# define WEIGHT_A 2
# define WEIGHT_B 3
# define WEIGHT_C 5

int main() {
    float A, B, C, avg;
    scanf("%f", &A);
    scanf("%f", &B);
    scanf("%f", &C);

    avg = (A * WEIGHT_A + B * WEIGHT_B + C * WEIGHT_C) / (WEIGHT_A + WEIGHT_B + WEIGHT_C);

    printf("MEDIA = %.1f\n", avg);

    return 0;
}
