#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

//vector<vector<ll> > comb(ll n, ll b){
void comb(vector<vector <ll> > &v, ll n){
  cout << v.size();
  rep(i, n){
    v[i][0] = 1;
    v[i][i] = 1;
  }

  rep(j, n) {
    rep(k,j) {
      v[j][k] = (v[j-1][k-1] + v[j-1][k]);
    }
  }
}


int main(){
  ll n;
  cin >> n;
  long double m = sqrt(n);
  ll nn = ll(m);

  ll tmp1 = 1; 
  ll tmp2 = n;
 
  for (ll i=nn+1; i>0; i--){
    if (n%i==0) {
      tmp1 = i;
      tmp2 = n/i;
      break;
    }
  }

  
  ll cnt = 1;
  while(tmp2/10>0){
      cnt++;
      tmp2 /= 10;	
    // else{
    //   break;
    // }
  }

  cout << cnt << endl;
  
  
}
