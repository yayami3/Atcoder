#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;



int main(){
  ll a,b,x;
  ll ans = 0;
  cin >> a >> b>>x;

  if (a%x==0) ans += 1;
  
  a = a / x;
  b = b / x;

  ans += b-a;

  
 
  
  
  cout << ans << endl;  
  
}
