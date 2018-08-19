# include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int p, i = 1, count = 0;

    cin >> p;
    do {
        if (i <= p >> 1) i <<= 1;
        else i -= (p - i + 1);
        ++count;
    } while (i != 1);

    cout << count << '\n';

    return 0;
}
