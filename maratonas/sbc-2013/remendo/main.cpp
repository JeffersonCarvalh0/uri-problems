// Not finished yet

# include <iostream>
# include <vector>
# include <list>
# include <cstring>
# include <bitset>

using namespace std;

# define MAXC 1000005

bitset<MAXC> holes;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c, t1, t2, first, last, cur, sum;
    vector<pair<int, int>> dp;
    list<pair<int, int>> patches;
    dp.reserve(MAXC);

    while (cin >> n >> c >> t1 >> t2) {
        holes.reset(); dp.clear(); patches.clear();

        cin >> first;
        holes[0] = true;
        for (int i = 0; i < n - 1; ++i) cin >> cur, holes[cur - first] = true;

        last = cur - first;
        dp.resize(last + 1);
        if (t2 < t1) swap(t1, t2);

        dp[0] = { 0, t1 };
        for (int i = 1; i <= last; ++i) {
            if (holes[i]) {
                if (dp[i - 1].first + t1 >= i) dp[i] = dp[i - 1];
                else dp[i] = { i, dp[i - 1].second + t1 };
            }
            else dp[i] = dp[i - 1];
        }

        for (int i = 0; i <= last; ++i) {
            if (holes[i]) {
                if (i < t2 || (i >= t2 && t2 > dp[i].second)) patches.push_back({ dp[i].first, t1 });
                else {
                    dp[i] = { i - t2, t2 };
                    auto it = patches.begin();
                    for (; it != patches.end(); ++it) if (it->first >= i - t2) break;
                    patches.erase(it, patches.end());
                    patches.push_back(dp[i]);
                }
            }
        }

        sum = 0;
        for (auto &e : patches) sum += e.second;
        cout << sum << '\n';
    }

    return 0;
}
