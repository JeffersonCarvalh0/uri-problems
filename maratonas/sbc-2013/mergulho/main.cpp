# include <iostream>
# include <cstring> // memset

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r, cur;
    bool a[10005];

    while (cin >> n >> r) {
        memset(a, 0, (sizeof(bool) * n) + 1);
        for (int i = 1; i <= r; ++i) cin >> cur, a[cur] = true;
        if (n == r) cout << "*\n";
        else {
            for (int i = 1; i <= n; ++i) if (!a[i]) cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}
