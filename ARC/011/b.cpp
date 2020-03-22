#include <bits/stdc++.h>
 
#define rep(i, n) for (ll i=0;i<(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(x) (x).begin(),(x).end()
 
using namespace std;
//using ll=long long;
typedef long long ll;
typedef pair<ll, ll> pi;

  map<char, int> m;


string dc(string s){
  string t="";
  rep(i, s.size()){
    if(m[s[i]]>0) {
      if(m[s[i]]<10) t += to_string( m[s[i]]);
	 else t += "0";
    }
  }
  return t;
  
}
 
int main(){
  ll n,k;

  cin >> n;

  string s;

  m['b'] = 1;
  m['c'] = 1;
  m['d'] = 2;
  m['w'] = 2;
  m['t'] = 3;
  m['j'] = 3;
  m['f'] = 4;
  m['q'] = 4;
  m['l'] = 5;
  m['v'] = 5;
  m['s'] = 6;
  m['x'] = 6;
  m['p'] = 7;
  m['m'] = 7;
  m['h'] = 8;
  m['k'] = 8;
  m['n'] = 9;
  m['g'] = 9;
  m['z'] = 10;
  m['r'] = 10;

  string b;
  bool f=0;
  rep(i,n){
    cin >> s;
    transform(ALL(s), s.begin(), ::tolower);
    b = dc(s);

    if(b!="") {
      if(f==0) cout <<b ;
      else cout << " " <<b;
      f = 1;

    }

  }

  cout <<endl;
  
}
