# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a[10005], sum;

        while (cin >> n) {
            sum = 0;
            for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];

            if (sum % n == 0) {
                int avg = sum / n, ans = 0;
                for (int i = 0; i < n; ++i) if (a[i] < avg) ans += (avg - a[i]);
                cout << ans + 1 << '\n';
            } else {
                cout << "-1\n";
            }
        }

    return 0;
}
