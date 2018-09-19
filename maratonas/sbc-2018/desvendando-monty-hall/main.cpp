# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cur, ans = 0;

    cin >> n;
    while (n--) {
        cin >> cur; if (cur != 1) ++ans;
    }

    cout << ans << '\n';

    return 0;
}
