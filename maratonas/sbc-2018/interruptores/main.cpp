# include <iostream>
# include <list>

using namespace std;

bool lamps[1005];
list<int> ints[1005];

inline bool lamps_off(int n) {
    for (int i = 1; i <= n; ++i) if (lamps[i] == true) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, l, cur;

    cin >> n >> m >> l;
    while (l--) cin >> cur, lamps[cur] = true;

    for (int i = 0; i < n; ++i) {
        cin >> l;
        while (l--) cin >> cur, ints[i].push_back(cur);
    }

    for (int i = 0; i < n; ++i) {
        for (auto &e : ints[i]) lamps[e] = !lamps[e];
        if (lamps_off(m)) { cout << i + 1 << '\n'; return 0; }
    }

    for (int i = 0; i < n; ++i) {
        for (auto &e : ints[i]) lamps[e] = !lamps[e];
        if (lamps_off(m)) { cout << n + i + 1 << '\n'; return 0; }
    }

    cout << "-1\n";

    return 0;
}
