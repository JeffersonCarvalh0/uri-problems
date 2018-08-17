// WA 20%

# include <iostream>
# include <string>

using namespace std;

int dp[2005][2005];
int specials[2005][2005];
bool a[2005];
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cur;

    cin >> s >> n;
    while (n--) cin >> cur, a[cur] = 1, specials[cur][cur] = 1;

    for (int i = 0; i <= s.size(); ++i) dp[i][i] = 1;

    for (int slice = 1; slice <= s.size(); ++slice) {
        for (int i = 1, j = i + slice; j <= s.size(); ++i, ++j) {
            if (s[i - 1] == s[j - 1] && (a[i] || a[j])) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
                specials[i][j] = specials[i + 1][j - 1] + a[i] + a[j];
            }

            else {
                if (specials[i + 1][j] != specials[i][j - 1]) {
                    if (specials[i + 1][j] > specials[i][j - 1]) {
                        specials[i][j] = specials[i + 1][j];
                        dp[i][j] = dp[i + 1][j];
                    }
                    else {
                        specials[i][j] = specials[i][j - 1];
                        dp[i][j] = dp[i][j - 1];
                    }
                } else {
                    if (s[i - 1] == s[j - 1]) dp[i][j] = 2 + dp[i + 1][j - 1];
                    else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    specials[i][j] = max(specials[i + 1][j], specials[i][j - 1]);
                }
            }
        }
    }

    // cout << "dp:\n";
    // for (int i = 0; i <= s.size(); ++i) {
    //     for (int j = 0; j <= s.size(); ++j) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    //
    // cout << "\nspecials:\n";
    // for (int i = 0; i <= s.size(); ++i) {
    //     for (int j = 0; j <= s.size(); ++j) cout << specials[i][j] << ' ';
    //     cout << '\n';
    // }

    cout << dp[1][s.size()] << '\n';

    return 0;
}
