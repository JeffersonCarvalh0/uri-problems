# include <iostream>
# include <string>
# include <set>
# include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l, c, row_sum[105], col_sum[105], calculated = 0;
    string mat[105][105], cur;
    set<string> row_vars[105], col_vars[105];
    map<string, int> var_values;

    cin >> l >> c;
    for (int i = 0; i < l; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> mat[i][j];
            col_vars[j].insert(mat[i][j]);
            row_vars[i].insert(mat[i][j]);
            var_values[mat[i][j]] = 1e9;
        }
        cin >> row_sum[i];
    }

    for (int i = 0; i < c; ++i) cin >> col_sum[i];

    while (calculated < var_values.size()) {
        for (int i = 0; i < l; ++i) {
            if (row_vars[i].size() <= calculated + 1) {
                int unknown_qtd = 0; string unknown;
                for (auto &var : row_vars[i]) if (var_values[var] == 1e9) ++unknown_qtd, unknown = var;
                if (unknown_qtd == 1) {
                    int a = 0, count = 0;
                    for (int j = 0; j < c; ++j)
                        var_values[mat[i][j]] != 1e9 ? a += var_values[mat[i][j]] : ++count;
                    var_values[unknown] = (row_sum[i] - a) / count; ++calculated;
                }
            }
        }

        for (int j = 0; j < c; ++j) {
            if (col_vars[j].size() <= calculated + 1) {
                int unknown_qtd = 0; string unknown;
                for (auto &var : col_vars[j]) if (var_values[var] == 1e9) ++unknown_qtd, unknown = var;
                if (unknown_qtd == 1) {
                    int a = 0, count = 0;
                    for (int i = 0; i < l; ++i)
                        var_values[mat[i][j]] != 1e9 ? a += var_values[mat[i][j]] : ++count;
                    var_values[unknown] = (col_sum[j] - a) / count; ++calculated;
                }
            }
        }
    }

    for (auto &e : var_values) cout << e.first << ' ' << e.second << '\n';

    return 0;
}
