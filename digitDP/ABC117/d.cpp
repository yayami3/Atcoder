
#include <bits/stdc++.h>

#define fi first
#define se second
#define rep(i, n) for (ll i=0;i<(n); i++)
#define rrep(i, n) for (ll (i) = n-1;(i) >= 0;--(i))
#define ALL(v) (v).begin(), (v).end()
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;

//const ll M=1000000007ll;
//const ll MOD=1000000007ll;
const ll MOD=2019ll;
const ll MAX=100000001ll;
//const ll M = 1000000000+7;

//const int mod = 1000000007;
const int mod = 2019;
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

mint g(ll n, ll x){
  if(x==0) return 1;
  mint ans = g(n, x/2);
  ans *= ans;
  if(x%2==1) ans*= n;
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
 
ll fff(ll n, vector<ll>& v, ll i, ll j, ll rl){
  ll can = 0;
  ll can_i = 0;

  cout << v[0]<<endl;
  
  // right
  if(rl == 0){
    rep(k, n){
      if(v[k]*(j-k)>can){
	can = v[k]*(j-k);
	can_i = k;
      }
      //cout << can<<endl;
    }
    v[can_i] = 0;
    return can;
  }
  // left
  else{
    rep(k, n){
      if(v[k]*(k-i)>can){
	can = v[k]*(k-i);
	can_i = k;
      }
      //cout << can<<endl;

    }
    v[can_i] = 0;
    return can;
  }
  
}

ll ff(ll x){
  return x * (x+1) / 2;
}

ll n,m,q, ans;
vector<ll> a,b,c,d; 


void dfs(ll A){  
  if (A > n) {
    return;
  }
  for (ll v=3;v<=7 ;v+=2) {
    //    cout << A<<endl;
    A *= 10;
    A += v;
    dfs(A);
    A /= 10;
  }
  map<ll, ll> m;
  while(A>0){
    m[A%10]++;
    A/=10;
  }
  if(m[3]>0 && m[5]>0 && m[7]>0) ans++;

}

const int MAX_DIGIT = 50;
ll dp[100][2];

int main(){
  int n;
  ll k;
  cin>>n>>k;

  vector<ll> a(n);
  rep(i, n) cin>>a[i];

  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for(int d=0;d<MAX_DIGIT;++d){
    ll mask = 1LL<<(MAX_DIGIT-d-1);

    int num = 0;
    rep(i, n) if(mask & a[i]) ++num;

    ll cost0 = num * mask;
    ll cost1 = (n-num) * mask;

    //small -> small
    if(dp[d][1]!=-1 ){
      chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1));
    }

    //exact->small
    if(dp[d][0]!=-1 ){    
      if(k & mask){
	chmax(dp[d+1][1], dp[d][0] + cost0);
      }
    }
    //exact->exact
    if(dp[d][0]!=-1 ){    
      if(k & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
      else chmax(dp[d+1][0], dp[d][0] + cost0);
    }    
  }
  cout << max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]) << endl;
}
