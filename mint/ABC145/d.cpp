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
const int N=100000;
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

int main(){ 
  int x,y;
  cin >> x>>y;

  ll t=0,yo=x/2;
  
  if(x%2==1)  t++;
  

  while(yo>=0){
    if(y==yo+2*t) break;
    t++;t++;
    yo--;
    //cout << t <<yo<<endl;
  }

  if(yo<0) {
    cout << 0 << endl;
    return 0;
  }

  
  
  cout << choose(t+yo,min(t,yo)).x <<endl;;
  
}
