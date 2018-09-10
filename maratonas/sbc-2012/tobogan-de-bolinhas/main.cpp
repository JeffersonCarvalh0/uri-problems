// WA 20%

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

struct Flipper {
    double yi, xf, yf;
    Flipper(double yi = 0, double xf = 0, double yf = 0): yi(yi), xf(xf), yf(yf) {}
};

double dist(Flipper *flippers, int i, double l) {
    pair<double, double> a, b, c, ab, ac;

    if ((i + 1) & 1) a.first = 0;
    else a.first = l;
    a.second = flippers[i + 1].yi;

    b.first = flippers[i + 1].xf;
    b.second = flippers[i + 1].yf;

    c.first = flippers[i].xf;
    c.second = flippers[i].yf;

    ab.first = b.first - a.first;
    ab.second = b.second - a.second;

    ac.first = c.first - a.first;
    ac.second = c.second - a.second;

    return (ab.first * ac.second) - (ab.second * ac.first) / sqrt((ab.first * ab.first) + (ab.second * ab.second));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed);
    double n, l, h, yi, xf, yf, ans, cur_min;
    Flipper flippers[1005];

    while (cin >> n) {
        cin >> l >> h;
        for (int i = 1; i <= n; ++i)
            cin >> yi >> xf >> yf, flippers[i] = Flipper(yi, xf, yf);

        ans = 1005;
        for (int i = 1; i <= n; ++i) {
            if (i & 1) cur_min = l - flippers[i].xf;
            else cur_min = flippers[i].xf;

            if (i <= n - 1)
                cur_min = min(cur_min, abs(dist(flippers, i, l)));

            ans = min(ans, cur_min);
        }

        cout << setprecision(2) << ans << '\n';
    }

    return 0;
}
