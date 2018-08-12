// WA

# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;

    cin >> n;

    if (n == 2) cout << 2;
    else if (n & 1) cout << n;
    else cout << n - 1;

    cout << '\n';

    return 0;
}
