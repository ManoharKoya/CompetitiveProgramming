#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pii pair<int, int>
#define fr(n) for (int i = 0; i < n; i++)
#define fr1(n) for (int i = 1; i <= n; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T, n, m, a[256][256] = {};
    string s[256] = {};
    cin >> T;
    for (int U = 1; U <= T; U++) {
        cout << "Case #" << U << ": ";
        cin >> n >> m;
        int z = 890328;
        //fr(n) for (int j = 0; j < m; j++) a[i][j] = (rand() % 10 == 0);
        fr(n) cin >> s[i];
        fr(n) for (int j = 0; j < m; j++) a[i][j] = (s[i][j] == '1');
        queue<pii> q;
        int b[256][256] = {};
        for (int k = 0; k < n; k++) for (int l = 0; l < m; l++) if (a[k][l]) q.push({k, l}), b[k][l] = 1;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (x && !b[x - 1][y]) b[x - 1][y] = b[x][y] + 1, q.push({x - 1, y});
            if (x + 1 < n && !b[x + 1][y]) b[x + 1][y] = b[x][y] + 1, q.push({x + 1, y});
            if (y && !b[x][y - 1]) b[x][y - 1] = b[x][y] + 1, q.push({x, y - 1});
            if (y + 1 < m && !b[x][y + 1]) b[x][y + 1] = b[x][y] + 1, q.push({x, y + 1});
        }
        fr(n) for (int j = 0; j < m; j++) b[i][j]--;
        pair<int, pii> c[65536] = {};
        fr(n) for (int j = 0; j < m; j++) c[i * m + j] = {b[i][j], {i, j}};
        //fr(n) {for (int j = 0; j < m; j++) cout << b[i][j]; cout << '\n';}
        sort(c, c + n * m); reverse(c, c + n * m);
        fr(n) for (int j = 0; j < m; j++) if (!a[i][j]) {
            int o = 0;
            for (int k = 0; k < n * m; k++) {
                int d = abs(i - c[k].second.first) + abs(j - c[k].second.second);
                o = max(o, min(c[k].first, d));
                if (c[k].first <= o) {
                    break;
                }
            }
            z = min(z, o);
        }
        if (z == 890328) z = 0;
        cout << z << '\n';
    }
}
