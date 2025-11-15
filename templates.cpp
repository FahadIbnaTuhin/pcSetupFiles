/* 
    In the name of ALLAH
    Believe Yourself
    Compete against Yourself
*/
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
#define ff first
#define ss second
const ll inf = LLONG_MAX >> 1;
const double pi = acos(-1.0);
const double eps = 1e-9;
 
void debug(const vector<ll> &v) {for(const ll &x: v) {cout << x << ' ';} cout << endl;}
template<typename T>void o(const T& x, bool space = true) {cout << x;if (space) cout << endl;}
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
template<typename T, typename C, typename Comp> ostream& operator<<(ostream& os, priority_queue<T, C, Comp> pq){os<<"[";while(!pq.empty()){os<<pq.top();pq.pop();if(!pq.empty())os<<", ";}return os<<"]";}
template<typename T, typename Compare> ostream& operator<<(ostream& os, const tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>& t) {os << "[";for (auto it = t.begin(); it != t.end(); ++it) {if (it != t.begin()) os << ", ";os << *it;}return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],ll n){for(ll i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}

inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a*b)%mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a+b)%mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
// If you can't solve a problem with brute force, you likely don't understand it fully yet.
 
ll di[] = {0, 1, 0, -1};
ll dj[] = {1, 0, -1, 0};
string dir = "RDLU";
 
 
 
void solve() {
    


}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": "; // cout << "Case " << i << ": ";
        solve();
    }
 
 
 
 
    return 0;
}

// Bellman Ford
const ll mx = 2510;
vector<tuple<ll, ll, ll>> edges;
ll dist[mx], par[mx];
vector<ll> bellmanFord(ll src, ll n) {
    vector<ll> path;

    for (ll i = 0; i <= n; i++) {
        dist[i] = inf;
        par[i] = -1;
    }
    dist[src] = 0;

    for (ll i = 1; i <= n - 1; i++) {
        bool relaxed = 0;
        for (const auto &e : edges) {
            ll u, v, w; 
            tie(u, v, w) = e;
            if (dist[v] > dist[u] + w) {
                dist[v] = max(-inf, dist[u] + w);
                par[v] = u;
                relaxed = 1;
            }
        }
        if (!relaxed) break;
    }

    ll x = -1;    
    for (const auto &e : edges) {
        ll u, v, w; 
        tie(u, v, w) = e;
        if (dist[v] > dist[u] + w) {
            dist[v] = max(-inf, dist[u] + w);
            par[v] = u;
            x = v;
        }
    }
    if (x == -1) return path;

    for (ll i = 1; i <= n; i++) {
        x = par[x];
    }

    ll y = x; dbg(y);
    while (y != x || sz(path) == 0) {
        path.push_back(y);
        y = par[y];
    }
    path.push_back(x);
    reverse(all(path));

    return path;
}

// Floyd
void floydWarshall() { // No need to clear the dist because when looping nxn already resetting values of dist
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = inf;
        }
    }
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}


// Dijkstra
vector<vector<pair<ll, ll>>> adj;
vector<ll> dist, parent;

void dijkstra(ll src, ll n) {
    dist.assign(n + 1, inf);
    parent.assign(n + 1, -1);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[src] = 0;
    parent[src] = -1;
    pq.push({0ll, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}  
void get_Path(ll des) {
    if (dist[des] == inf) cout << -1 << endl;
    else {
        vector<ll> res;
        ll cur = des;
        while (cur != -1) {
            res.push_back(cur);
            cur = parent[cur];
        }
        reverse(all(res));
        for (ll &i : res) cout << i << ' ';
        cout << endl;
    }
}
// Dijkstra with a priority queue: O((V + E) logV). [This is the standard. CONSIDER THIS!!]

// topologicalSort
//const ll mx = 1e5+123;
//vector<ll> indeg(mx);
//vector<ll> adj[mx];
//bool vis[mx];
//
//ll topologicalSort() {
//    vector<ll> z;
//    for (ll i = 1; i <= n; i++) {
//        if (indeg[i] == 0) {
//            z.push_back(i);
//            vis[i] = 1;
//        }
//    } 
//    vector<ll> ans;
//    while (sz(ans) < n) {
//        if (z.empty()) return -1;
//
//        ll cur = z.back(); 
//        z.pop_back();
//        ans.push_back(cur);
//        for (const ll &v : adj[cur]) {
//            --indeg[v];
//            if (!vis[v] && indeg[v] == 0) {
//                z.push_back(v);
//                vis[v] = 1;
//            }
//        }
//    }
//    return ans;
//}


// BS Unidominal
// const dl EPS = 1e-9;
    // dl l = 0, r = 1e9;
    // while (r - l > EPS) {
    //     dl m1 = l + (r - l) / 3;
    //     dl m2 = r - (r - l) / 3;
        
    //     // cout << "m1: " << m1 << " , m2: " << m2 << ", f(m1): " << f(m1) << ", f(m2): " << f(m2) << endl;
    //     if (f(m1) < f(m2)) l = m1;
    //     else r = m2;
    // }
    // cout << f(l) << endl;



// --- Single Hashing Setup ---
const ll P = 31;
const ll HASH_MOD = 1e9 + 7;
const ll MAX_LEN = 1e6 + 123;

vector<ll> p_pow(MAX_LEN);       // Powers of P
vector<ll> inv_p_pow(MAX_LEN);   // Modular inverses of powers of P

// Fast modular exponentiation
inline ll modPowH(ll b, ll p, ll m) { ll r = 1; while (p) { if (p & 1) r = (r * b) % m; b = (b * b) % m; p >>= 1;} return r; }
inline ll modInverseH(ll a, ll m) {return modPowH(a, m - 2, m);}

// Precompute powers and inverse powers
void precomputeHash() {
    p_pow[0] = 1;
    for (ll i = 1; i < MAX_LEN; i++) {
        p_pow[i] = (p_pow[i - 1] * P) % HASH_MOD;
    }

    inv_p_pow[MAX_LEN - 1] = modInverseH(p_pow[MAX_LEN - 1], HASH_MOD);
    for (ll i = MAX_LEN - 2; i >= 0; i--) {
        inv_p_pow[i] = (inv_p_pow[i + 1] * P) % HASH_MOD;
    }
}

// Computes hash of full string
ll compute_hash(const string& s) {
    ll hash_value = 0;
    for (ll i = 0; i < (ll)s.size(); i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1ll) * p_pow[i]) % HASH_MOD;
    }
    return hash_value;
}

// Prefix hashes: h[i] = hash of s[0..i-1]
vector<ll> compute_prefix_hashes(const string& s) {
    ll n = s.size();
    vector<ll> h(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % HASH_MOD;
    }
    return h;
}

// Get hash of s[l..r] (0-indexed) using precomputed prefix hashes
ll get_substring_hash(const vector<ll>& h, ll l, ll r) {
    ll raw_hash = (h[r + 1] - h[l] + HASH_MOD) % HASH_MOD;
    return (raw_hash * inv_p_pow[l]) % HASH_MOD;
}
vector<vector<ll>> group_identical_strings(vector<string> const& s) { // O(nm + nlogn) [m = highest len of any string]
    ll n = s.size();
    vector<pair<ll, ll>> hashes(n);
    for (ll i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end()); // O(nlogn)

    vector<vector<ll>> groups;
    for (ll i = 0; i < n; i++) { // O(n)
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
} 
ll count_unique_substrings(string const& s) { // TC: O(n^2)
    ll n = s.size();

    const ll p = 31;
    const ll m = 1e9 + 9;
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (ll i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(n + 1, 0);
    for (ll i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    ll cnt = 0;
    for (ll l = 1; l <= n; l++) {
        unordered_set<ll> hs;
        for (ll i = 0; i <= n - l; i++) {
            ll cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
} 
vector<ll> rabin_karp(string const& pattern, string const& text) { // O(|s| + |t|)
    const ll p = 31; 
    const ll m = 1e9 + 9;
    ll S = pattern.size(), T = text.size();

    vector<ll> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (ll i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(T + 1, 0); 
    for (ll i = 0; i < T; i++)
        h[i+1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % m; 
    ll h_s = 0; 
    for (ll i = 0; i < S; i++) 
        h_s = (h_s + (pattern[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<ll> occurrences;
    for (ll i = 0; i + S - 1 < T; i++) {
        ll cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}
// ----------------------


// --- Double Hashing Setup ---
const ll P1 = 31, P2 = 53;
const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const ll MAX_LEN = 1e6 + 123;

vector<ll> p_pow1(MAX_LEN), p_pow2(MAX_LEN);
vector<ll> inv_p_pow1(MAX_LEN), inv_p_pow2(MAX_LEN);

inline ll modPowH(ll b, ll p, ll m) { ll r = 1; while (p) { if (p & 1) r = (r * b) % m; b = (b * b) % m; p >>= 1;} return r; }
inline ll modInverseH(ll a, ll m) {return modPowH(a, m - 2, m);}

void precomputeHash() {
    p_pow1[0] = p_pow2[0] = 1;
    for (ll i = 1; i < MAX_LEN; i++) {
        p_pow1[i] = (p_pow1[i - 1] * P1) % MOD1;
        p_pow2[i] = (p_pow2[i - 1] * P2) % MOD2;
    }

    inv_p_pow1[MAX_LEN - 1] = modInverseH(p_pow1[MAX_LEN - 1], MOD1);
    inv_p_pow2[MAX_LEN - 1] = modInverseH(p_pow2[MAX_LEN - 1], MOD2);
    for (ll i = MAX_LEN - 2; i >= 0; i--) {
        inv_p_pow1[i] = (inv_p_pow1[i + 1] * P1) % MOD1;
        inv_p_pow2[i] = (inv_p_pow2[i + 1] * P2) % MOD2;
    }
}
pair<ll, ll> compute_hash(const string& s) {
    ll h1 = 0, h2 = 0;
    for (ll i = 0; i < (ll)s.size(); i++) {
        ll val = s[i] - 'a' + 1;
        h1 = (h1 + val * p_pow1[i]) % MOD1;
        h2 = (h2 + val * p_pow2[i]) % MOD2;
    }
    return {h1, h2};
}
vector<pair<ll, ll>> compute_prefix_hashes(const string& s) {
    ll n = s.size();
    vector<pair<ll, ll>> h(n + 1, {0, 0});
    for (ll i = 0; i < n; i++) {
        ll val = s[i] - 'a' + 1;
        h[i + 1].first  = (h[i].first + val * p_pow1[i]) % MOD1;
        h[i + 1].second = (h[i].second + val * p_pow2[i]) % MOD2;
    }
    return h;
}
pair<ll, ll> get_substring_hash(const vector<pair<ll, ll>>& h, ll l, ll r) {
    ll raw1 = (h[r + 1].first - h[l].first + MOD1) % MOD1;
    ll raw2 = (h[r + 1].second - h[l].second + MOD2) % MOD2;
    ll hash1 = (raw1 * inv_p_pow1[l]) % MOD1;
    ll hash2 = (raw2 * inv_p_pow2[l]) % MOD2;
    return {hash1, hash2};
}
vector<vector<ll>> group_identical_strings(const vector<string>& s) {
    ll n = s.size();
    vector<pair<pair<ll, ll>, ll>> hashes(n);
    for (ll i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<ll>> groups;
    for (ll i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i - 1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
ll count_unique_substrings(const string& s) {
    ll n = s.size();
    set<pair<ll, ll>> seen;

    for (ll i = 0; i < n; i++) {
        ll h1 = 0, h2 = 0;
        for (ll j = i; j < n; j++) {
            ll val = s[j] - 'a' + 1;
            h1 = (h1 * P1 + val) % MOD1;
            h2 = (h2 * P2 + val) % MOD2;
            seen.insert({h1, h2});
        }
    }
    return seen.size();
}
vector<ll> rabin_karp(const string& pattern, const string& text) {
    ll S = pattern.size(), T = text.size();

    vector<ll> h1(T + 1, 0), h2(T + 1, 0);
    for (ll i = 0; i < T; i++) {
        h1[i + 1] = (h1[i] + (text[i] - 'a' + 1) * p_pow1[i]) % MOD1;
        h2[i + 1] = (h2[i] + (text[i] - 'a' + 1) * p_pow2[i]) % MOD2;
    }

    ll hp1 = 0, hp2 = 0;
    for (ll i = 0; i < S; i++) {
        hp1 = (hp1 + (pattern[i] - 'a' + 1) * p_pow1[i]) % MOD1;
        hp2 = (hp2 + (pattern[i] - 'a' + 1) * p_pow2[i]) % MOD2;
    }

    vector<ll> occurrences;
    for (ll i = 0; i + S <= T; i++) {
        ll cur1 = (h1[i + S] - h1[i] + MOD1) % MOD1;
        ll cur2 = (h2[i + S] - h2[i] + MOD2) % MOD2;

        ll h_sub1 = (cur1 * inv_p_pow1[i]) % MOD1;
        ll h_sub2 = (cur2 * inv_p_pow2[i]) % MOD2;

        if (h_sub1 == hp1 && h_sub2 == hp2)
            occurrences.push_back(i);
    }
    return occurrences;
}
struct pair_hash { // for set, unordered_set
    size_t operator()(const pair<ll, ll>& p) const {
        auto h1 = hash<ll>{}(p.first);
        auto h2 = hash<ll>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};
// ----------------------
