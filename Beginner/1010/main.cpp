# include <cstdio>
# include <iostream>

using namespace std;

int main() {
    int code1, units1; float price1;
    int code2, units2; float price2;
    float total;

    cin >> code1 >> units1 >> price1;
    cin >> code2 >> units2 >> price2;

    total = (price1 * units1) + (price2 * units2);

    printf("VALOR A PAGAR: R$ %.2f\n", total);

    return 0;
}
