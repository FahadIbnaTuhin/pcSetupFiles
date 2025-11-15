// For generating random numbers. You can also write this random output
// to any file using this gen.cpp
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll gen_random(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

// inline double gen_random(double l, double r) {  // for real number generation
//     return uniform_real_distribution<double>(l, r)(rng);
// }

string random_str(ll n) {
    string s;
    for (ll i = 0; i < n; i++)
        s += char('a' + gen_random(0, 25));
    return s;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // freopen("in.txt", "w", stdout);

    // b
    ll t = gen_random(1, 1);
    // cout << t << endl; 

    while (t--) {
        ll n = gen_random(3, 8), s = gen_random(3, 10);
        cout << n << ' ' << s << endl; 

        for (ll i = 0; i < n; i++) cout << gen_random(1, 10) << ' ';
        cout << endl;
    }

    return 0;
}