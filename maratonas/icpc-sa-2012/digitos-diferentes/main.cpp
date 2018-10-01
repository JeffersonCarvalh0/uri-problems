# include <iostream>
# include <string>
# include <cstring>

using namespace std;

int main() {
    int n, m, ans, nums[10];

    while (cin >> n >> m) {
        ans = 0;
        for (int i = n; i <= m; ++i) {
            string s = to_string(i);
            memset(nums, 0, sizeof(nums));
            bool valid = true;

            for (auto &c : s) ++nums[int(c - '0')];
            for (int i = 0; i < 10; ++i) if (nums[i] > 1) valid = false;
            if (valid) ++ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
