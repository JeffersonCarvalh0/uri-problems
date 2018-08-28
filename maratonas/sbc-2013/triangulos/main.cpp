# include <iostream>
# include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<int> points;
    int n, sum, cur, arc, ans;

    while (cin >> n) {
        points.clear(); sum = ans = 0;
        while (n--) cin >> cur, points.insert(sum += cur);

        if (sum % 3 != 0) cout << "0\n";
        else {
            arc = sum / 3;
            for (auto point : points)
                if (points.find(point + arc) != points.end() &&
                points.find(point + (arc * 2)) != points.end()) ++ans;
            cout << ans << '\n';
        }
    }

    return 0;
}
