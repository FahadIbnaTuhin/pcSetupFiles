#include <bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double dl;
template <typename T, typename P = null_type> using pbds = tree<T, P, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
 
#define endl '\n'
#define all(v) v.begin(), v.end()
#define sz(x) (ll)x.size()
#define mod 1000000007
#define pb push_back
#define ppb pop_back
#define xx first
#define yy second
#define mp make_pair
const ll inf = LLONG_MAX >> 1;
const double pi = acos(-1.0);
const double eps = 1e-9;

ll di[] = {0, 0, -1, 1};
ll dj[] = {-1, 1, 0, 0}; 
string dir = "LRUD";

// void solve() {
//     ll n, m, sx, sy, d; cin >> n >> m >> sx >> sy >> d;
//     --sx, --sy;

//     vector<vector<ll>> dp(n, vector<ll>(m, -1));
//     for (ll i = 0; i < n; i++) {
//         for (ll j = 0; j < m; j++) {
//             ll dis = abs(i - sx) + abs(j - sy);
//             if (dis <= d) dp[i][j] = 0;
//             // cout << dp[i][j];
//         }
//         // cout << endl;
//     }
//     if (dp[n - 1][m - 1] == 0) {cout << -1 << endl; return;}
//     dp[n - 1][m - 1] = 1;

//     for (ll i = m - 2; i >= 0; i--) {
//         dp[n - 1][i] = (dp[n - 1][i + 1] == 1);
//     }
//     for (ll i = n - 2; i >= 0; i--) {
//         for (ll j = m - 1; j >= 0; j--) {
//             ll yes = 0;
//             if (j + 1 < m && dp[i][j + 1] == 1) yes = 1;
//             if (i + 1 < n && dp[i + 1][j] == 1) yes = 1;

//             dp[i][j] = yes;
//         }
//     }

//     if (dp[0][0] == 1) cout << n + m - 2 << endl;
//     else cout << -1 << endl;
// }

ll n, m, sx, sy, d; 
const ll mx = 1e3+123;
vector<vector<bool>> mark(mx, vector<bool>(mx));
vector<vector<bool>> vis(mx, vector<bool>(mx));
ll dp[mx][mx];

void dfs(ll x, ll y) {
    if (dp[x][y] != -1) return;
    vis[x][y] = 1;
    dp[x][y] = 1;

    for (ll j = 0; j < 4; j++) {
        ll nx = x + di[j];
        ll ny = y + dj[j];

        // if (nx >= 0 && nx < n && ny >= 0 && ny < m && !mark[nx][ny] && !vis[nx][ny]) {
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && !mark[nx][ny]) {
            ll dis = abs(nx - sx) + abs(ny - sy);

            if (dis <= d) {
                mark[nx][ny] = 1;
                continue;
            }
            dfs(nx, ny);
        }
    }
}

void solve() {
    cin >> n >> m >> sx >> sy >> d;
    --sx, --sy;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            mark[i][j] = 0;
            vis[i][j] = 0;
            dp[i][j] = -1;
        }
    }

    //         ll dis = abs(i - sx) + abs(j - sy);
    //         if (dis <= d) mark[i][j] = 1;
    //         // cout << mark[i][j];
    //     }
    //     // cout << endl;
    // }
    // if (mark[n - 1][m - 1]) {cout << -1 << endl; return;}

    dfs(0, 0);

    // for (ll i = 0; i < n; i++) {
    //     for (ll j = 0; j < m; j++) {
    //         cout << mark[i][j];
    //     }
    //     cout << endl;
    // }

    if (vis[n - 1][m - 1]) cout << n + m - 2 << endl;
    else cout << -1 << endl;
}

// ll n, m, sx, sy, d; 
// vector<vector<bool>> mark;
// vector<vector<bool>> vis;

// void dfs(ll x, ll y) {
//     vis[x][y] = 1;

//     for (ll j = 0; j < 4; j++) {
//         ll nx = x + di[j];
//         ll ny = y + dj[j];

//         if (nx >= 0 && nx < n && ny >= 0 && ny < m && !mark[nx][ny]) {
//             dfs(nx, ny);
//         }
//     }
// }

// void solve() {
//     cin >> n >> m >> sx >> sy >> d;
//     mark.assign(n, vector<bool>(m, 0));
//     vis.assign(n, vector<bool>(m, 0));

//     for (ll i = 0; i < n; i++) {
//         for (ll j = 0; j < m; j++) {
//             ll dis = abs(i - sx) + abs(j - sy);
//             if (dis <= d) mark[i][j] = 1;
//             // cout << mark[i][j];
//         }
//         // cout << endl;
//     }

//     dfs(0, 0);

//     if (vis[n - 1][m - 1]) cout << n + m - 2 << endl;
//     else cout << -1 << endl;
// }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        solve();
    }

    return 0;
} 