# include <iostream>
# include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n, v, a, v1, v2;
    bool adj_mat[55][55];

    cin >> t;
    while (t--) {
        int edges = 0;
        memset(adj_mat, false, sizeof(adj_mat));
        cin >> n >> v >> a;
        while (a--) {
            cin >> v1 >> v2;
            if (!adj_mat[v1][v2]) {
                adj_mat[v1][v2] = true;
                adj_mat[v2][v1] = true;
                ++edges;
            }
        }
        cout << edges * 2 << '\n';
    }

    return 0;
}
