# include <stdio.h>

int main() {
    int workerNum, hours;
    float amountPerHour;

    scanf("%d", &workerNum);
    scanf("%d", &hours);
    scanf("%f", &amountPerHour);

    printf("NUMBER = %d\n", workerNum);
    printf("SALARY = U$ %.2f\n", amountPerHour * hours);

    return 0;
}
