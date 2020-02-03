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
  ll n,m;
  cin >> n >> m;

  pair<ll,pair<ll> > pp;
  ll ken, tmp2;
  pi p;
  
  rep(i, m) {
    cin >> ken >> tmp2;
    p = make_pair(ken, i);
    pp[i] = make_pair(tmp2, p);
  }

  sort(pp.begin(), pp.end());

  vector<ll> v(n, 0);
  
  rep(i, m) {
    v[pp.second.first]++;
    pp.second.first = v[pp.second.first];
  }

  pi new_p;
  vector<pi> q(m);
  rep(i, m) {
    q[i] = make_pair(pp.second+pp.);
  }
  
}
