# include <iostream>
# include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double x, y;

    cin >> x >> y;

    cout << ceil(max(x, y) / abs(x - y)) << '\n';

    return 0;
}
