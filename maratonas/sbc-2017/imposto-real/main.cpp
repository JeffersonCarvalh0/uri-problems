# include <iostream>
# include <cstring>
# include <vector>
# include <list>

using namespace std;

vector<vector<int>> adj_mat;
vector<list<pair<int, int>>> adj_list;
vector<int> euler;
bool visited[100005];

void dfs(int v) {
    visited[v] = true;
    euler.push_back(v);

    for (auto &adj : adj_list[v])
        if (!visited[adj.first])
            dfs(adj.first), euler.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c, taxes[10005], a, b, w, ans;

    euler.reserve(20005);

    cin >> n >> c;
    for (int i = 1; i <= n; ++i) cin >> taxes[i];

    adj_mat = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    adj_list = vector<list<pair<int, int>>>(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b >> w;
        adj_mat[a][b] = w, adj_mat[b][a] = w;
        adj_list[a].push_back({ b, w }); adj_list[b].push_back({ a, w });
    }

    dfs(1);

    ans = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; ++i) visited[i] = false;
    for (int i = 0; i < (int)euler.size(); ++i) {
        if (!visited[euler[i]]) {
            visited[euler[i]] = true;
            if (i > 0) ans += adj_mat[euler[i - 1]][euler[i]];
        } else {
            if (taxes[euler[i - 1]] <= c) {
                ans += adj_mat[euler[i - 1]][euler[i]];
            } else {
                int times = (taxes[euler[i - 1]] / c) + (taxes[euler[i - 1]] % c != 0);
                times = (times * 2) - 1;
                ans += adj_mat[euler[i - 1]][euler[i]] * times;
            }
            taxes[euler[i]] += taxes[euler[i - 1]];
        }
    }

    cout << ans << '\n';

    return 0;
}
