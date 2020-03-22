#include <bits/stdc++.h>
 
#define rep(i, n) for (ll i=0;i<(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(x) (x).begin(),(x).end()
 
using namespace std;
//using ll=long long;
typedef long long ll;
typedef pair<ll, ll> pi;

 
int main(){
  ll n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> x(n);

  rep(i, n){
    cin >> a[i];
  }
  ll s = a[0] + a[n-1];

  rep(i, n-2){
    if(i%2==0) s -= a[i+1];
    else s += a[i+1];
  }

  x[0] = s/ 2 ;

  rep(i, n-2){
    x[i+1] = a[i] - x[i];
  }

  x[n-1] = a[n-1] - x[0];
  
  rep(i, n-1) cout << 2*x[i] << " ";
  cout << 2*x[n-1] <<endl;
  
  
}
