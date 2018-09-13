// WA

# include <iostream>

using namespace std;

# define MOD 1000000007

typedef long long ll;

ll dp[100005][55];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, m, n;
    ll ans = 0;

    cin >> t >> m >> n;
    for (int i = m; i <= n; ++i) dp[i][1] = 1;
    for (int j = 2; j <= t; ++j)
        for (int i = m; i <= n; ++i)
            dp[i][j] = dp[i - 1][j - 1] + dp[i + 1][j - 1];

    for (int i = m; i <= n; ++i) ans += dp[i][t];

    cout << ans % MOD << '\n';

    return 0;
}
