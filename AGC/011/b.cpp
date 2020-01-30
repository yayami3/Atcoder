#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)

using namespace std;
//using ll=long long;
typedef long long ll;


int main(){
  int n, tmp;
  cin >> n;

  //    cout << "a";
  vector<ll> a(n);
  vector<ll> s(n);
  //cout << "a";

  
  rep(i,n) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  
  s.at(0) = a.at(0);
  
  for(ll i=1;i<n;i++){
    s.at(i) = s.at(i-1) + a.at(i);
  }

  //  rep(i, n)     cout << a.at(i) << " " << s.at(i) << endl;

  
  int ans = 1;
  for (ll i=n-1;i>0; i--) {
    if (a.at(i) <= 2*s.at(i-1) ){
      ans ++;
    }
    else break;
    
  }
  
  std::cout << ans << std::endl;
}
