# include <iostream>
# include <vector>
# include <algorithm>

# define ANGLE 6

using namespace std;

int main() {
    int a;

    while (cin >> a) (a % 6 == 0) ? cout << "Y\n" : cout << "N\n";

    return 0;
}
