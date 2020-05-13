
#include <bits/stdc++.h>
 
#define rep(i, n) for (ll i=0;i<(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(x) (x).begin(),(x).end()
 
using namespace std;
//using ll=long long;
typedef long long ll;
typedef pair<ll, ll> pi;

ll h,w;
ll ans;
//vector<char> masu;




int main(){
  ll n;
  cin >>n;

  ll tmp, ans;
  map<ll, ll> m;

  priority_queue<ll> p;
  vector<ll> v;

  m[0]++;

  rep(i,n){
    cin>>tmp;
    m[tmp]++;
  }

  ll b=0;
  ll j;
  if(m[0]>1){
    ans = 0;
    cout << ans <<endl;
    return 0;
  }
  else {p.push(0);
    p.push(24);
  }
  if(m[12]>1){
    ans = 0;
    cout << ans <<endl;
    return 0;
  }
  else if(m[12]==1) p.push(12);

  
  rep(i, 11){
    ll j = i+1;
    if(m[j]>2){
      ans = 0;
      cout << ans <<endl;
      return 0;
    }
    else if(m[j]==2){
      p.push(j);
      p.push(24-j);
      m[j] = 0;
    }
    else if(m[j]==1){
      b++;
      v.push_back(j);
    }
  }

  //cout <<b<<endl;
  ans = 0;
  rep(i, 1<<b){
    //cout << i<<endl;
    priority_queue<ll> p_tmp = p;

    rep(j, b){
      if(i>>j&1) p_tmp.push(24-v[j]);
      else p_tmp.push(v[j]);	
    }
    
    ll min_tmp = 999999999999;
    ll tmp_p;
    
    //cout<<" "<<p_tmp.size()<<endl;
    ll N = p_tmp.size()-1;
    rep(k, N){

      tmp_p = p_tmp.top();
      p_tmp.pop();
      
      //cout <<i<<" "<< tmp_p<<" " <<p_tmp.top()<<endl;

      if(tmp_p-p_tmp.top()<min_tmp){
	min_tmp = tmp_p-p_tmp.top();
      }
    }
    ans = max(ans, min_tmp);
  }
  
  cout << ans<<endl;

  
  
}
