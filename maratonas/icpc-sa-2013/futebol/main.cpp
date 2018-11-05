# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, g, s, r, total;
    vector<int> matches; matches.reserve(100005);

    while (cin >> n >> g) {
        matches.clear(); total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s >> r;
            if (r >= s) matches.push_back(r - s);
            else total += 3;
        }

        sort(matches.begin(), matches.end());
        for (auto &e : matches) {
            if (e == 0 && g > 0) --g, total += 3;
            else if (e > 0 && g == e) g = 0, total += 1;
            else if (e > 0 && g > e) g -= e + 1, total += 3;
            else if (g == 0 && e == 0) total += 1;
        }

        cout << total << '\n';
    }

    return 0;
}
