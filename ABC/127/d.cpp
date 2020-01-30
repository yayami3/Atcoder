#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;



int main(){
  int n, m;
  cin >> n >> m;

  priority_queue< ll, vector<ll>, greater<ll> > q;

  //vector<ll> a(n);

  vector<pi> bc(m);
  
  ll bb, cc, b, c;
  ll tmp, u;
  
  rep(i, n) {
    cin >> tmp;
    q.push(tmp);
  }

  pi p;
  rep(i, m) {
    cin >> bb;
    cin >> cc;
    p = make_pair(bb, cc);
    bc.at(i) = p;
  }

  sort(bc.begin(), bc.begin());
  
  
  while (bc.size()>0) {
    b = bc.at(bc.size()-1).first;
    c = bc.at(bc.size()-1).second;
    
    while (b>0){
      u = q.top();
      if (u<c) {
	q.pop();
	q.push(c);
	b--;
      }
      else {
	b = 0;
	//q.push(u);
      }
    }
    bc.pop_back();
  }  

  ll ans = 0;
  rep(i, n) {
    ans += q.top();
    q.pop();
  }  
    
  cout << ans << endl;

  
  
}
