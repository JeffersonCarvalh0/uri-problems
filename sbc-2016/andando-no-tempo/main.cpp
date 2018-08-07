# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;

    cin >> a >> b >> c;

    if (a + b == c || a + c == b || b + c == a) cout << "S";
    else if (a == b || a == c || b == c) cout << "S";
    else cout << "N";

    cout << '\n';

    return 0;
}
