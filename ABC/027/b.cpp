#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)
# define ALL(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

//vector<vector<ll> > comb(ll n, ll b){


int main(){
  ll n,a,b,p,k,x,MOD;

  MOD = 1000000007;
  ll cnt = 0;

  
  cin >> n;
  vector<ll> v(n, 0);
  cin >> a;
  v[0] = a;

  rep(i,n-1) {
    cin >> a;
    v[i+1] = (v[i]+a);
  }
  

  if(v[n-1]%n!=0) {
    cout << -1 << endl;
    return 0;
  }

  ll m = v[n-1] / n;
  
  rep(i,n){
    if (v[i]==m*(i+1)) cnt++;
  }
  
  
  
  cout << n-cnt << endl;
  
}
