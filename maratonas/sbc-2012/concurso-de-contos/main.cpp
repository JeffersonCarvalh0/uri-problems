// WA

# include <iostream>
# include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l, c, c_total, l_total;
    string s;

    while (cin >> n >> l >> c) {
        l_total = c_total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            if (c_total + s.size() + 1 <= c || c_total + s.size() == c)
                c_total += s.size() + 1;
            else
                ++l_total, c_total = s.size() + 1;
        }

        if (c_total <= c) ++l_total;

        cout << (l_total / l) + (l_total % l != 0) << '\n';
    }

    return 0;
}
