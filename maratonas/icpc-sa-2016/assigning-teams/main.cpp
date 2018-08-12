# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, d;

    while (cin >> a >> b >> c >> d)
        cout << abs((a + d) - (b + c)) << '\n';

    return 0;
}
