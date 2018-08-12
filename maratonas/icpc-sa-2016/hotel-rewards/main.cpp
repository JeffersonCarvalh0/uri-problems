# include <iostream>
# include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, cur, sum = 0, points;
    multiset<int> s;

    cin >> n >> k;
    points = n;
    for (int i = 0; i < n; ++i) {
        cin >> cur; sum += cur;
        if (i >= k) s.insert(cur);
    }

    while (points >= k + 1) sum -= *s.rbegin(), s.erase(prev(s.end())), points -= (k + 1);

    cout << sum << '\n';

    return 0;
}
