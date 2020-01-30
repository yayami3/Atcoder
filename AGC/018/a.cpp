#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;



int main(){
  int n, k;
  cin >> n >> k;

  //    cout << "a";
  vector<ll> a(n);
  
  rep(i,n)    cin >> a.at(i);

  int flag = 0;
  ll tmp_min = *min_element(a.begin(), a.end());
  ll tmp_max = *max_element(a.begin(), a.end());

  if (k>tmp_max) {
      cout << "IMPOSSIBLE" << endl;
      return 0;      
  }

  ll tmp = a.at(0);
  rep(i, n) {
    tmp = __gcd(tmp, a.at(i));
  }
  
  
  if (k%tmp==0) {
    cout << "POSSIBLE" << endl;
    return 0;
  }
  else {
      cout << "IMPOSSIBLE" << endl;
      return 0;
  }
  
}
