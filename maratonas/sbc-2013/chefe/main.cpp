// WA at URI, gives the right answer to every single test case available

# include <iostream>
# include <cstring>

using namespace std;

bool adj_mat[505][505], visited[505];
int n, m, i, k[505], x, y, a, b, min_age;
char t;

void change(int v1, int v2) {
    bool c1, c2;
    c1 = adj_mat[v1][v2]; c2 = adj_mat[v2][v1];

    for (int i = 0; i < n; ++i) swap(adj_mat[v1][i], adj_mat[v2][i]);
    for (int i = 0; i < n; ++i) swap(adj_mat[i][v1], adj_mat[i][v2]);

    adj_mat[v1][v1] = adj_mat[v2][v2] = 0; adj_mat[v1][v2] = c2; adj_mat[v2][v1] = c1;
}

void dfs(int v) {
    visited[v] = true;
    if (v != a) min_age = min(min_age, k[v]);
    for (int i = 0; i < n; ++i)
        if (!visited[i] && adj_mat[i][v]) dfs(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (cin >> n >> m >> i) {
        for (int c = 0; c < n; ++c) cin >> k[c];
        for (int c = 0; c < m; ++c) cin >> x >> y, adj_mat[--x][--y] = true;
        while (i--) {
            cin >> t;
            if (t == 'T') cin >> a >> b, change(--a, --b);
            if (t == 'P') {
                memset(visited, 0, sizeof(visited));
                cin >> a; min_age = 105; dfs(--a);
                if (min_age == 105) cout << "*\n";
                else cout << min_age << '\n';
            }
        }
    }

    return 0;
}
