#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for (ll i = 0; i < (n); i++)

using namespace std;
using ll=long long;

const int INF = 1001001001;

int main()
{
  string text;
  cin >> text;

  //sting tmp = "";
  int flag = 0;
  int ans = 0;
  
  rep(i, text.size()) {
    if (text.at(i) != '+'){
      if (text.at(i) == '0') flag=1;
      //tmp += text.at(i);
    }
    else{
      if (flag==0) ans++;
      flag = 0;
      //tmp = "";	
    }
  }
  if (flag==0) ans++;
  
  
  cout << ans << endl;
  return 0;
}
