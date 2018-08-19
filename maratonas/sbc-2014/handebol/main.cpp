# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, cur, count = 0;
    bool flag;

    cin >> n >> m;

    while (n--) {
        flag = true;
        for (int i = 0; i < m; ++i) {
            cin >> cur;
            if (cur == 0) flag = false;
        }
        if (flag) ++count;
    }

    cout << count << '\n';

    return 0;
}
