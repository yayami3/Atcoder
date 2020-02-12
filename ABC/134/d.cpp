#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)
# define ALL(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

//vector<vector<ll> > comb(ll n, ll b){





int main(){
  ll n,q,a,b,p,x,cnt;
  cnt = 0;
  cin >> n;
  vector<ll> v(n);

  rep(i,n) {
    cin >> x;
    v.at(i) = x;
  }

  for(ll i=n-1;i>=0;i--) {
    a = 0;
    b= n/(i+1);
    // cout<< b<< endl;
    for(ll j=1;j<=b;j++){
      a += v.at(j*(i+1)-1);
    }
    // cout << "i: " << i << " a: " << a << "v[i]: " <<v[i] << endl;
    if (a%2!=v.at(i)){
      if(v[i]==0) v[i] = 1;
      else v[i]=0;
    }
    // cout << "i: " << i << " a: " << a << "v[i]: " <<v[i] << endl;
  }
  cout << accumulate(ALL(v), 0) << endl;

  rep(i,n){
    if(v[i]==1) cout << (i+1) << " ";
  }
  
}
