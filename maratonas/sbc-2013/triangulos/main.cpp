// RTE

# include <iostream>
# include <cstring>

using namespace std;

// inline int mod(int a, int b) { return (b + (a % b)) % b; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool c[100005];
    int n, sum, cur, size, ans;

    while (cin >> n) {
        memset(c, 0, sizeof(c));
        sum = ans = 0; c[0] = true;
        for (int i = 0; i < n; ++i) cin >> cur, c[sum += cur] = true;

        if (sum % 3 != 0) cout << "0\n";
        else {
            size = sum / 3;
            for (int i = 0; i < sum; ++i)
                if (c[i] && c[(i + size) % sum] && c[((i + (size * 2)) % sum)])
                    ++ans, c[(i + size) % sum] = c[((i + (size * 2)) % sum)] = false;
            cout << ans << '\n';
        }
    }

    return 0;
}
