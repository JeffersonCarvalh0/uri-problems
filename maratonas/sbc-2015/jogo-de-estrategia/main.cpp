# include <iostream>

using namespace std;

int p[505];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int j, r, cur, w, wp = 0;

    cin >> j >> r;
    for (int i = 0; i < j * r; ++i) cin >> cur, p[i % j] += cur;
    for (int i = 0; i < j; ++i) if (p[i] >= wp) wp = p[i], w = i;

    cout << w + 1 << '\n';

    return 0;
}
