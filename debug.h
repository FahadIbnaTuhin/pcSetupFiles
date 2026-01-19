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