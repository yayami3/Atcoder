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

mint powpow(ll a, ll b) {
  if (!a) return 1;
  if(b==0) {
    mint xx = 1;
    return xx;
  }

  if(b==1) {
    mint xx = a;
    return xx;
      }
  if(b%2==0){
    mint xx = powpow(a, b/2);
    return xx * xx;
  }
  else{
    mint xx = powpow(a, b/2);
    return xx * xx * a;
  }
}


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

static bool IsPrime(int n) {
	if (n < 2) return false;
	else if (n == 2) return true;
	else if (n%2 == 0) return false;
	double sqrtNum = sqrt(n);
	for (int i=3; i<=sqrtNum; i+=2) {
		if (n%i == 0) {return false;}
	}
	return true;
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
 
class LinkedList {
private:
  class Node{
  public:
    int key;
    Node *prev;
    Node *next;
  };

  Node *nil;
  
  void delete_node(Node *node){
    if(node==nil)  return;

    len--;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
  }

public:
  ll len;
  vector<ll> ans;
  LinkedList(){
    nil = new Node();
    nil->prev = nil;
    nil->next = nil;
    len = 0;
  }

  void ans_resize(){
    ans.resize(len);
    //cout <<"#"<<ans.size()<<endl;
  }

  void insert(ll key){
    Node *x;
    x = new Node;
    x->key = key;
    len++;
    
    x->prev = nil->prev;
    x->next = nil;
    nil->prev->next = x;
    nil->prev = x;
  }

  bool search_index(ll i){
    Node *n = nil->prev;
    rep(j, len){
      //cout << n->key<<" "<< len-j <<endl;
      if(n->key==len-j) {
	ans[i] = n->key;
	delete_node(n);
	return true;
      }
      n = n->prev;
    }
    return false;
  }
  
};

int main(){ 
  ll n;
  cin>> n;

  LinkedList l;
  
  ll x;
  rep(i, n){
    cin >> x;
    l.insert(x);
  }
  l.ans_resize();
  
  //cout << "#"<<endl;
  ll ind = 0, cnt=0;
  rep(i, n){
    ind = n-1-cnt;
    bool b = l.search_index(ind);
    if(!b) {
      cout << -1 <<endl;
      return 0;
    }
    cnt++;
  }
  rep(i, n){
    cout << l.ans[i] << endl;
  }
  
}
