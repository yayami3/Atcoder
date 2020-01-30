#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;



int main(){
  int n, h;
  cin >> n >> h;

  priority_queue<ll> q;
  //priority_queue< ll, vector<ll>, greater<ll> > q;
  //vector<ll> v;

  ll tmp = 0;
  ll a,b;
   // vector<ll> a(n);
   // vector<ll> b(n);
  rep(i, n) {
    cin >> a >> b;
    tmp = max(tmp, a);
    if (b>tmp) q.push(b);
  }

  int flag = 1;
  int u;
  // while(flag){
  //   u = q.top();
  //   if (u<tmp) q.pop();
  //   else flag = 0;
  // }

  int cnt=0;
  ll ans =0;
  while(flag){
    if (q.size()==0) break;
    u = q.top();
    if (u>tmp) {
      cnt += u;
      q.pop();
      ans++;
    }
    else flag=0;
    
    if (cnt>=h) flag=0;
  }

  if (cnt<h) ans += (h-cnt+tmp-1) / tmp;
  
 
  
  
  cout << ans << endl;  
  
}
