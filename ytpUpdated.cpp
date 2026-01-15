#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double dl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define sz(x) (int)x.size()
#define mid(l, r) ((r + l) / 2)
#define left(node) (node * 2)
#define mx_int_prime 999999937

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed, ios::floatfield);
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};

// Debugger
template <typename F, typename S>
ostream& operator << (ostream& os, const pair<F, S>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream &operator << (ostream &os, const vector<T>& v) {
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}

template <typename T>
ostream &operator << (ostream &os, const set<T>& v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "]";
}

template <typename T>
ostream &operator << (ostream &os, const multiset<T>& v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "]";
}

template <typename F, typename S>
ostream &operator << (ostream &os, const map<F, S>& v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) os << ", ";
        os << it->first << " - " << it->second;
    }
    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

void faltu() {
    cerr << endl;
}

template <typename T>
void faltu(T a[], int n) {
    for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
    cerr << endl;
}

template <typename T, typename... hello>
void faltu(T arg, const hello&... rest) {
    cerr << arg << ' ';
    faltu(rest...);
}

// Bitwise operations
ll check_kth_bit(ll x, ll k) {  // return 1 if kth bit is on, otherwise 0
    return (x & (1ULL << k)) != 0;
}

void print_on_bits(ll x) {
    for (ll k = 0; k < 32; k++) {
        if (check_kth_bit(x, k)) {
            cout << k << ' '; // prints the position of the set bit
        }
    }
    cout << '\n';
}

ll count_on_bits(ll x) {
    ll ans = 0;
    for (ll k = 0; k < 32; k++) {
        if (check_kth_bit(x, k)) {
            ans++;
        }
    }
    return ans;
}

void binaryRepresentation(ll x) {
    for (ll i = 31; i >= 0; i--) {
        cout << check_kth_bit(x, i);
    }
    cout << '\n';
}

bool is_even(ll x) {
    return (x & 1) == 0;
}

ll set_kth_bit(ll x, ll k) {
    return x | (1 << k);
}

ll unset_kth_bit(ll x, ll k) {
    return (x & (~(1 << k)));
}

ll toggle_kth_bit(ll x, ll k) {
    return x ^ (1 << k);
}

bool check_power_of_2(ll x) {  // Better
    return x > 0 && (x & (x - 1)) == 0;
}

// Modular arithmetic
const ll mod = 1e9 + 7;

ll modPow(ll x, ll y) {
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll add(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

ll sub(ll a, ll b) {
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll modInverse(ll a) {
    return modPow(a, mod - 2);
}

ll divi(ll a, ll b) {
    return mul(a, modInverse(b));
}

void solve() {
    
}

int main() {
    // optimize();
    ll t; cin >> t;
    for (ll tc = 1; tc <= t; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    
    return 0;
}