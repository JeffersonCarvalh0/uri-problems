# include <iostream>
# include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int sum = 0;
    string n;

    cin >> n;
    for (auto &c : n) sum += int(c - '0');

    cout << sum % 3 << '\n';

    return 0;
}
