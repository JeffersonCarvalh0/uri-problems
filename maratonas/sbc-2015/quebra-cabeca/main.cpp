// Not finshed yet

# include <iostream>
# include <algorithm>
# include <string>
# include <set>
# include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l, c, row_sums[105], col_sums[105];
    pair<int, set<string>> row[105], col[105];
    map<string, int> vars;
    string mat[105][105], cur;

    cin >> l >> c;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> cur; mat[i][j] = cur;
            row[i].second.insert(cur); row[i].first = row[i].second.size();
            col[j].second.insert(cur); col[j].first = col[j].second.size();
            vars[cur] = 1e9;
        }
        cin >> row_sums[i];
    }

    for (int i = 0; i < c; ++i) cin >> col_sums[i];
    sort(row, row + l);
    sort(col, col + c);

    int cur_vars = 0;
    for (int i = 0; i < vars.size(); ++i) {
        for (int j = 0; j < c && row[j].first > cur_vars + 1; ++j) {
            if (row[j].first == cur_vars + 1) {

            }
        }
    }

    return 0;
}
