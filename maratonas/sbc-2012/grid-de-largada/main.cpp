# include <iostream>

using namespace std;

inline int find(int *a, int n, int v) { for (int i = 0; i < n; ++i) if (a[i] == v) return i; }

inline void update(int *a, int n, int i, int j) {
    if (i < j) for (int c = i; c + 1 <= j; ++c) swap(a[c], a[c + 1]);
    else for (int c = i; c - 1 >= j; --c) swap(a[c], a[c - 1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s[30], e[30], ans;

    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> s[i];
        for (int i = 0; i < n; ++i) cin >> e[i];

        ans = 0;
        for (int i = 0; i < n; ++i) {
            if (e[i] != s[i]) {
                int pos = find(s, n, e[i]);
                ans += abs(i - pos);
                update(s, n, pos, i);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
