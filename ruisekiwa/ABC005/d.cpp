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
  ll n,q;
  cin >> n;

  vector<vector<ll> > a(n, vector<ll>(n) );
  vector<vector<ll> > s((n+1), vector<ll>(n+1, 0) );
  
  rep(i,n){    
    rep(j,n) {
      cin >> a[i][j];
    }
  }  
  
  rep(i,n){    
    rep(j,n) {
      s[i+1][j+1] = -s[i][j] + s[i+1][j] + s[i][j+1] + a[i][j];
    }
  }

  cin >> q;

  ll p;
  ll x,y;
  ll tmp=0;
  //cout<<q<<endl;
  rep(i, q){
    tmp=0;
    cin >> p;
    x = 1; y=min(p, n);
    while(y>0){
      for(int i=0;i+x<=n;i++){
	for(int j=0;j+y<=n;j++){
	  tmp = max(tmp, s[i+x][j+y] + s[i][j] -s[i+x][j] -s[i][j+y]);
	}
      }
      x++;
      y=min(n, p/x);
    }
    cout << tmp<<endl;
  }
  
  //cout << ans <<endl;
}

