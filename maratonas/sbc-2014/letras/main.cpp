# include <iostream>
# include <cstring>
# include <string>
# include <vector>
# include <bitset>
# include <queue>

using namespace std;

char mat[105][105];
bool visited[105][105];
int n, min_size = 1e9;

void find_path(string &mask) {
    queue<int> qi, qj, qs;

    qi.push(0); qj.push(0); qs.push(1);

    while (!qi.empty()) {
        int i = qi.front(); qi.pop();
        int j = qj.front(); qj.pop();
        int size = qs.front(); qs.pop();

        visited[i][j] = true;

        if ((mat[i][j] >= 97 && mask[mat[i][j] - 'a'] == '0') || (mat[i][j] < 97 && mask[mat[i][j] - 'A'] == '1')) {
            if (i == n - 1 && j == n - 1) min_size = min(min_size, size);
            else {
                if (i > 0 && !visited[i - 1][j]) qi.push(i - 1), qj.push(j), qs.push(size + 1);
                if (i < n - 1 && !visited[i + 1][j]) qi.push(i + 1), qj.push(j), qs.push(size + 1);
                if (j > 0 && !visited[i][j - 1]) qi.push(i), qj.push(j - 1), qs.push(size + 1);
                if (j < n - 1 && !visited[i][j + 1]) qi.push(i), qj.push(j + 1), qs.push(size + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> mat[i][j];

    for (int i = 0; i < 1024; ++i) {
        string mask = bitset<10>(i).to_string();
        memset(visited, 0, sizeof(visited));
        find_path(mask);
    }

    if (min_size == 1e9) cout << "-1\n";
    else cout << min_size << '\n';

    return 0;
}
