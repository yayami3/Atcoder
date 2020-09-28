#include <bits/stdc++.h>
#include <unistd.h>

#define fi first
#define se second
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep1(i,n) for (ll i = 1; i <= (n); ++i)
#define rrep(i,n) for (ll i = (n)-1; i >=0; --i)
#define ALL(a) a.begin(),a.end()
#define pb push_back
#define dame { puts("-1"); return 0;}
#define show(x) cerr<<#x<<" = "<<x<<endl;

using namespace std;
using ll = long long;
using ld = long double;
using pl = pair<ll, ll>;
ll LINF = 1000000000000000000;

typedef vector<ll> vl;
typedef vector<pl> vp;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n, -1){}
  int root(int x) {
    if(d[x]<0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x); y=root(y);
    if(x==y) return false;
    if (d[x]>d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) {return root(x)==root(y);}
  int size(int x) {return -d[root(x)];}
  int factor_size() {
    int ans=0;
    rep(i,d.size()){
      if (d[i]<0) {ans++;}
    }
    return ans;
  }
  
};



ll d[201][201];

void warshall_floyd(ll n) {
  rep(k, n){
    rep(i, n){
      rep(j, n){
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}



struct edge{ll to, cost;};

struct dijkstra{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  dijkstra(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = LINF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void run(ll s){
    rep(i,V){
      d[i] = LINF;
    }
    d[s] = 0;
    priority_queue<pl,vector<pl>, greater<pl> > que;
    que.push(pl(0,s));
    while(!que.empty()){
      pl p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(pl(d[e.to],e.to));
        }
      }
    }
  }
};
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const ll mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
} c(200005);

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<pl> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<pl> res(1, pl(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (int p : primes) {
      int y = 0;
      while (x%p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p,y);
    }
    if (x != 1) res.emplace_back(x,1);
    return res;
  }
};

using data = pair<ll, vector<ll> >;


int main() {
  ll n,m;
  cin >> n>>m;

  vector<ll> p(n);

  ll ans = 0;
  rep(i, n) {
    cin >> p[i];
    if((i+1)==p[i]) ans++;
  }

  ans = 0;
  UnionFind uf(n);
  
  rep(i, m) {
    ll x,y;
    cin >> x>>y;
    x--;y--;
    uf.unite(x, y);
  }

  //show(ans);
  
  ll x = uf.factor_size();

  vector<set<int> > v(n, set<int>());
  rep(i, n) {
    ll y = uf.root(i);
    //show(y);
    v[y].insert(i);
  }

  //show(ans);

  
  rep(i, n) {
    set<int> w;
    set<int> result;
    for (auto z : v[i]) {
      w.insert(p[z]-1);
    }

    set_intersection(v[i].begin(), v[i].end(),
		     w.begin(), w.end(),
		     inserter(result, result.end()));
    ans += result.size();
  }

  cout << ans << endl;
  return 0;
}
