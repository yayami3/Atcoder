
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
  vector<string> s;
  map<ll, ll> m;
  
  ll tmp;
  rep(i,10){
    cin >> tmp;
    m[tmp] = i;
  }

  //cout <<"#"<< m[2]<<endl;
  
  ll n;
  cin>>n;

  vector<pi> v(n);
  rep(i,n){
    cin >> tmp;
    string tmp2 = to_string(tmp);

    //cout << ll(tmp2[0]-'0')<<endl;

    string ans = "";
    rep(i,tmp2.size()){
      ll f = m[ll(tmp2[i]-'0')];
      // cout <<ll(tmp2[i])<< f<<endl;
      ans += to_string(f);
    }
    v[i] = make_pair(stoll(ans), tmp);
    
  }

  sort(ALL(v));
  
  rep(i,n){
    cout << v[i].second<<endl;
    //    cout << v[i].first<<" " << v[i].second<<endl;
  }
  
  //cout << ans << endl;
}
