#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rrep(i,n) for (ll i = (n)-1; i >=0; --i)
#define ALL(a) a.begin(),a.end()
#define pb push_back
#define dame { puts("-1"); return 0;}
#define show(x) cerr<<#x<<" = "<<x<<endl;

using namespace std;
using ll = long long;
using ld = long double;
using pl = pair<ll, ll>;

typedef vector<ll> vl;
typedef vector<pl> vp;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }


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
} cc(200005);

ll n,a,b,c,d;
ll save[10000000];
map<ll,ll> mem;


ll dfs(ll x){
  ll ans = 2500020000000000000LL;
  if(ans/d>x) ans = d*x;
  //show(x);
  if (mem.count(x)) {
    //show(x);
    return mem[x];
  }
  else{
    ll tmp = 0;
    ll y = x;
    while(y%2!=0){
      y--;
      tmp++;
    }
    if(y>0 ) chmin(ans, a+tmp*d+dfs(y/2));
    if(tmp>0 ) chmin(ans, a+tmp*d+dfs(y/2+1));

    tmp = 0;
    y = x;
    while(y%3!=0){
      y--;
      tmp++;
    }
    if(y>0 ) chmin(ans, b+tmp*d+dfs(y/3));
    if(tmp>0 ) chmin(ans, b+(3-tmp)*d+dfs(y/3+1));

    tmp = 0;
    y = x;
    while(y%5!=0){
      y--;
      tmp++;
    }
    if(y>0 )  chmin(ans, c+tmp*d+dfs(y/5));
    if(tmp>0 ) chmin(ans, c+(5-tmp)*d+dfs(y/5+1));
  }
  return mem[x] = ans;

}

int main() {
  ll t;
  cin >> t;

  rep(i, t){
    cin >> n >> a >> b >> c >> d;
    
    mem = map<ll, ll>();
    mem[1] = d;
    cout << dfs(n) << endl;
    
    
  }

  //cout << ans << endl;
  return 0;
}
