# include <iostream>
# include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    for (int i = 1; i <= sqrt(c); ++i) {
        if (i % a == 0 && i % b != 0 && c % i == 0 && d % i != 0) {
            cout << i << '\n';
            return 0;
        }
    }

    int i = c / 2;
    if (i % a == 0 && i % b != 0 && c % i == 0 && d % i != 0) {
        cout << i << '\n';
        return 0;
    }

    i = c;
    if (i % a == 0 && i % b != 0 && c % i == 0 && d % i != 0) {
        cout << i << '\n';
        return 0;
    }

    cout << "-1\n";

    return 0;
}
