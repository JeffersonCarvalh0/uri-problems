# include <cstdio>      // printf
# include <iostream>    // cin
# include <string>      // string

using namespace std;

int main() {
    string name;
    double salary, sale;

    cin >> name >> salary >> sale;
    printf("TOTAL = R$ %.2lf\n", salary + (15.0/100 * sale));
    return 0;
}
