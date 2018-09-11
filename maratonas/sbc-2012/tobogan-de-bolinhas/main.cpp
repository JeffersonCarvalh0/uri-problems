# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};

struct Flipper {
    double y;
    Point f;
    Flipper(double yi = 0, double xf = 0, double yf = 0): y(yi) { f = Point(xf, yf); }
};

inline double dot(Point &v1, Point &v2) { return (v1.x * v2.x) + (v1.y * v2.y); }
inline double cross(Point &v1, Point &v2) { return (v1.x * v2.y) - (v1.y * v2.x); }

double dist(Flipper *flippers, int i, double l) {
    Point a, b, c, ab, bc, ba, ac;

    if ((i + 1) & 1) a.x = 0;
    else a.x = l;
    a.y = flippers[i + 1].y;

    b = flippers[i + 1].f;
    c = flippers[i].f;

    ab.x = b.x - a.x;
    ab.y = b.y - a.y;

    bc.x = c.x - b.x;
    bc.y = c.y - b.y;

    ba.x = a.x - b.x;
    ba.y = a.y - b.y;

    ac.x = c.x - a.x;
    ac.y = c.y - a.y;

    if (dot(ab, bc) > 0) return hypot(b.x - c.x, b.y - c.y);
    else if (dot(ba, ac) > 0) return hypot(a.x - c.x, a.y - c.y);
    else return cross(ab, ac) / hypot(ab.x, ab.y);
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
            if (i & 1) cur_min = l - flippers[i].f.x;
            else cur_min = flippers[i].f.x;

            if (i <= n - 1)
                cur_min = min(cur_min, abs(dist(flippers, i, l)));

            ans = min(ans, cur_min);
        }

        cout << setprecision(2) << ans << '\n';
    }

    return 0;
}
