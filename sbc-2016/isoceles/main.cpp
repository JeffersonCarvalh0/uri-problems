# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a[50005], l[50005], r[50005], max_value = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    l[0] = 1;
    for (int i = 1; i < n; ++i) l[i] = min(l[i - 1] + 1, a[i]);

    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) r[i] = min(r[i + 1] + 1, a[i]);

    for (int i = 0; i < n; ++i) max_value = max(max_value, min(l[i], r[i]));

    cout << max_value << '\n';

    return 0;
}
