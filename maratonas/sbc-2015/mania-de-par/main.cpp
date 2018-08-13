// Not finished yet
# include <iostream>
# include <vector>
# include <list>
# include <set>

# define INF 1e9

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c, v, c1, c2, g;
    vector<list<pair<int, int>>> adj_list;

    cin >> c >> v;
    adj_list.resize(c + 1);

    for (int i = 0; i < v; ++i) {
        cin >> c1 >> c2 >> g;
        adj_list[c1].push_back({ c2, g });
        adj_list[c2].push_back({ c1, g });
    }

    vector<int> weights(c + 1, INF);
    vector<bool> visited(c + 1, false);
    multiset<pair<int, int>> costs;
    visited[1] = true; weights[1] = 0; costs.insert(adj_list[1])
    for (int i = )

    return 0;
}
