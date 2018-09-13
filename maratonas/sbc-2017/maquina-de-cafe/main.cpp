# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a1, a2, a3, ans;

    cin >> a1 >> a2 >> a3;

    ans = (a2 * 2) + (a3 * 4);
    ans = min(ans, (a1 * 2) + (a3 * 2));
    ans = min(ans, (a1 * 4) + (a2 * 2));

    cout << ans << '\n';

    return 0;
}
