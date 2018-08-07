// TLE
# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, d, m;

    cin >> a >> b >> c >> d;

    m = max(a, b); m = max(m, c); m = max(m, d);

    for (int i = 1; i <= m; ++i) {
        if (i % a == 0 && i % b != 0 && c % i == 0 && d % i != 0) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}
