#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for (ll i = 0; i < (n); i++)

using namespace std;
using ll=long long;

const int INF = 1001001001;

int main()
{
  ll h,n;
  cin >> h >> n;

  
  vector<int> dp(h+1, INF);
  dp[0] = 0;
    
    
  rep(i, n) {
    int a,b;
    cin >> a >> b;
    rep(j, h){
      int nj = min(j+a, h);
    
      dp[nj] = min(dp[nj], dp[j] + b);
    }
  }

  cout << dp[h] << endl;

  return 0;
}
