# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, i, k, f[10];

    cin >> n;

    f[0] = 1; f[1] = 1; f[2] = 2; f[3] = 6; f[4] = 24; f[5] = 120; f[6] = 720;
    f[7] = 5040; f[8] = 40320; f[9] = 362880;

    i = 9; k = 0;
    while(n > 0) {
        if (f[i] > n) --i;
        else n -= f[i], ++k;
    }

    cout << k << '\n';

    return 0;
}
