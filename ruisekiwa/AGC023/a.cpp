#include <bits/stdc++.h>

// #define fi first
// #define se second
#define rep(i, n) for (ll i=0;i<(n); i++)
#define ALL(v) (v).begin(), (v).end()
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
#define WHITE 0  // 未訪問
#define BLACK 1  // 訪問ずみ

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
  
int main(){ 
  ll n,m,k,q;
  cin >> n;

  ll s[n+1];
  s[0]=0;
  rep(i, n ){
    cin >> q;
    s[i+1] = s[i] + q;
  }

  ll ans = 0;
  sort(s, s+n+1);

  ll c = 1;
  for (int i=0;i<n;i++ ){
    if (s[i]==s[i+1]) c++;
    else {
      ans += c*(c-1)/2;
      c = 1;
    }
  }
  ans += c*(c-1)/2;

  cout << ans <<endl;
}

