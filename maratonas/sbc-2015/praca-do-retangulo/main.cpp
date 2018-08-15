# include <iostream>
# include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point (int x = 0, int y = 0): x(x), y(y) {}
};

bool cmp(Point &lhs, Point &rhs) {
    if (lhs.y != rhs.y)
        return lhs.y > rhs.y;
    return lhs.x < rhs.x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y, ans = 0;
    Point points[3000];

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x >> y, points[i] = Point(x, y);

    sort(points, points + n, cmp);

    for (int i = 0; i < n; ++i) {
        int l = -1e9, r = 1e9;
        for (int j = i + 1; j < n; ++j) {
            if (points[j].x > points[i].x) {
                if (points[j].x < r) r = points[j].x, ++ans;
            } else {
                if (points[j].x > l) l = points[j].x, ++ans;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
