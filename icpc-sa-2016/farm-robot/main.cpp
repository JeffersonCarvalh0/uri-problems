# include <iostream>

using namespace std;

inline int mod(int a, int b) { return (a % b + b) % b; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c, s, cur, p, ans;

    while (cin >> n >> c >> s) {
        --s;
        p = 0;
        ans = s == 0;
        while (c--) {
            cin >> cur;
            p = mod(p + cur, n);
            if (p == s) ++ans;
        }
        cout << ans << '\n';
    }

    return 0;
}
