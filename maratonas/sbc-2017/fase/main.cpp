# include <iostream>
# include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, ans, a[1005];

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    ans = k;
    for (int i = n - k - 1; i >= 0; --i) if (a[i] == a[n - k]) ++ans;

    cout << ans << '\n';

    return 0;
}
