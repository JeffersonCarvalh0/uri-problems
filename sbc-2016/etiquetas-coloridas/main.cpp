# include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll r, g, b, qtd_green, qtd_blue;

    cin >> hex >> r >> g >> b;

    qtd_green = (r / g) * (r / g);
    qtd_blue = (g / b) * (g / b) * qtd_green;

    cout << hex << 1 + qtd_green + qtd_blue << '\n';

    return 0;
}
