# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T, N, M, a[25], dp[1000001];
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; ++i) cin >> a[i];
        for (int i = 0; i <= M; ++i) dp[i] = 1000001;

        dp[0] = 0;
        for (int i = 1; i <= M; ++i) {
            for (int j = 0; j < N; ++j) {
                int value = i - a[j];
                if(value >= 0 && dp[value] + 1 < dp[i]) dp[i] = dp[value] + 1;
            }
        }
        cout << dp[M] << '\n';
    }
    return 0;
}
