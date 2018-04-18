# include <stdio.h>

# define WEIGHT_A 3.5
# define WEIGHT_B 7.5

int main() {
    double A, B, avg;
    scanf("%lf", &A);
    scanf("%lf", &B);

    avg = (A * WEIGHT_A + B * WEIGHT_B) / (WEIGHT_A + WEIGHT_B);

    printf("MEDIA = %.5lf\n", avg);

    return 0;
}
