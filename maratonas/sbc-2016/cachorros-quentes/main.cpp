# include <iostream>
# include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed);
    double h, p;

    cin >> h >> p;
    cout << setprecision(2) << h / p << '\n';

    return 0;
}
