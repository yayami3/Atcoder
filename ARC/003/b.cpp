#include <bits/stdc++.h>

// #define fi first
// #define se second
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
  vector<string> s(n);

  rep(i,n) {
    cin >> s[i];
  }

  vector<pair<string, ll> > t(n);

  rep(i,n) {
    string tmp = s[i];
    reverse(ALL(tmp));
    t[i] = {tmp, i};
  }

  sort(ALL(t));

  rep(i,n){
    cout << s[t[i].second] << endl;

  }
  
  
}
