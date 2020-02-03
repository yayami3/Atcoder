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
  string S,T;
  cin >> S >> T;

  int flag = 0;
  int cnt = 0;
  
    for (int i= S.size()-T.size(); i>=0; i--) {
      cnt = 0;
      rep(j, T.size()) {
      if (S[i+j]!=T[j] && S[i+j]!='?') break;
            cnt++;

    }
    if (cnt==T.size()){
      rep(j, T.size()) S[i+j] = T[j];
      flag = 1;
      break;
    }
  }

  if (flag == 0){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  
  rep(i, S.size()){
    if (S[i]=='?') S[i]='a';
  }
  
  cout << S << endl;
  return 0;
}
