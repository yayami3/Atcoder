
#include <bits/stdc++.h>

// #define fi first
// #define se second
#define rep(i, n) for (ll i=0;i<(n); i++)
#define ALL(v) (v).begin(), (v).end()
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

const ll M=1000000007ll;
const ll MOD=1000000007ll;
const ll MAX=100000001ll;
//const ll M = 1000000000+7;

ll cnt = 0; 

const int mod = 1000000007;
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
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

mint f(ll n){
  if(n==0) return 1;
  mint ans = f(n/2);
  ans *= ans;
  if(n%2==1) ans*= 2;
  return ans;
}

mint choose(ll n, ll k){
  mint x=1, y=1;
  rep(i,k){
    x *= (n-i);
    y *= (i+1);
  }
  return x / y;
}

struct BIT {
  private:
   vector<ll> bit;
   ll N;
 
  public:
   BIT(ll size) {
     N = size;
     bit.resize(N + 1);
   }
 
   // 一点更新です
   void add(ll a, ll w) {
     for (ll x = a; x <= N; x += x & -x) bit[x] += w;
   }
 
   // 1~Nまでの和を求める。
   int sum(ll a) {
     ll ret = 0;
     for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
     return ret;
   }
 };
 

int main(){ 
  string s;
  cin>>s;

  ll n = s.length();
  vector<ll> v(n);
  rep(i, n){
    if(s[i]=='B') v[i]=2;
    else v[i]=1;
  }

  BIT b(2);
  ll ans = 0;
  rep(i, n){
    ans += i - b.sum(v[i]);
    b.add(v[i], 1);
  }
  cout<<ans<<endl;
}
