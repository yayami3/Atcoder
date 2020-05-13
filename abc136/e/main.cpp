#include <bits/stdc++.h>

#define fi first
#define se second
#define rep(i, n) for (ll i=0;i<(n); i++)
#define rrep(i, n) for (ll (i) = n-1;(i) >= 0;--(i))
#define ALL(v) (v).begin(), (v).end()
#define FORR(i, a, b) for(ll i=(b)-1; i>=(a); --i)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;

//const ll M=1000000007ll;
const ll MOD=1000000007ll;
//const ll MOD=2019ll;
const ll MAX=100000001ll;
//const ll M = 1000000000+7;

const ll mod = 1000000007ll;
//const int mod = 2019;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
   return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

mint f(ll n){
  if(n==0) return 1;
  mint ans = f(n/2);
  ans *= ans;
  if(n%2==1) ans*= 2;
  return ans;
}

mint g(ll n, ll x){
  if(x==0) return 1;
  mint ans = g(n, x/2);
  ans *= ans;
  if(x%2==1) ans*= n;
  return ans;  
}

mint choose(ll n, ll k){
  mint x=1, y=1;
  rep(i,k){
    x *= (n-i);
    y *= (i+1);
  }
  //cout <<"#" <<x.x<<" "<<y.x<<endl;
  return x / y;
}

struct BIT {
  private:
   vector<ll> bit;
   ll N;
 
  public:
   BIT(ll size) {
     N = size;
     bit.resize(N + 1);
   }
 
   // 一点更新です
   void add(ll a, ll w) {
     for (ll x = a; x <= N; x += x & -x) bit[x] += w;
   }
 
   // 1~Nまでの和を求める。
   int sum(ll a) {
     ll ret = 0;
     for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
     return ret;
   }
 };
 
ll fff(ll n, vector<ll>& v, ll i, ll j, ll rl){
  ll can = 0;
  ll can_i = 0;

  cout << v[0]<<endl;
  
  // right
  if(rl == 0){
    rep(k, n){
      if(v[k]*(j-k)>can){
	can = v[k]*(j-k);
	can_i = k;
      }
      //cout << can<<endl;
    }
    v[can_i] = 0;
    return can;
  }
  // left
  else{
    rep(k, n){
      if(v[k]*(k-i)>can){
	can = v[k]*(k-i);
	can_i = k;
      }
      //cout << can<<endl;

    }
    v[can_i] = 0;
    return can;
  }
  
}

ll ff(ll x){
  return x * (x+1) / 2;
}

ll calc_comb(ll x,ll y){
  ll xx=1;ll yy=1;
  rep(i, y){
    xx *= (x-i);
    yy *= (i+1); 
    xx %= 1000000007ll;
    yy %= 1000000007ll;
  }
  return xx / yy % 1000000007ll;

}

void calc_prime(vector<ll> &p){
  for(ll i=2;i<=p.size()+1;i++){
    if(p[i]<0){
      for(ll j=2;j<=p.size()+1;j++){
	if(i%j==0){
	  p[i] = j;
	  break;
	} 
      }
      if(p[i]<0) p[i]=i;
    }
  }
}

void dfs(vector<ll> &v, map<int, ll> m, ll S){
	ll y;
	for(auto x:m){
		y = 1;
		ll n = v.size();

		rep(k, x.se){
			y *= x.fi;
			rep(j, n){
				if(v[j]*y<=S && S%(v[j]*y)==0) v.push_back(v[j]*y);
			}
		}
	}
	//return v;
}

ll ans;

void solve(ll factor, ll S,  vector<ll> &A,ll n,ll k, vector<ll> &v, ll koremade){
	if(A.size()==n){
		ll cnt_n = 0;
		ll cnt_p = 0;
		rep(i, A.size()){
			if((A[i])*factor>v[i]) cnt_p += (A[i])*factor -v[i];
			else cnt_n += -A[i]*factor + v[i];
		}
		//cerr << n << endl;
		if(cnt_n==cnt_p && cnt_n<=k) {
			if(koremade==S) chmax(ans, factor);
		}
	}
	else{
		if(A.size()==0){
			for(int i=0;koremade+i*factor*(n-A.size())<=S;i++){
				A.push_back(i);
				solve(factor,S, A, n, k, v, koremade+factor*i);
				A.pop_back();
			}	
		}
		else{
			for(int i=A[A.size()-1];koremade+i*factor*(n-A.size())<=S;i++){
				A.push_back(i);
				solve(factor,S, A, n, k, v, koremade+factor*i);
				A.pop_back();
			}
		}
	}
}

int main(){
  ll n, k;
  cin >>n>>k;
  ans = 0;

  vector<ll> v(n);
  ll S = 0;
  rep(i, n){
   cin >> v[i];
   S += v[i];
  }
  sort(ALL(v));
  ll SS = S;

  //sercout << v[n-1] << endl;
  
  map<int, ll> m;
  map<int, ll> m2;
  //while(S>1){
  	ll cnt = 0;
  	for(int i=2;i*i<=SS;i++ ){
  		//cout << S <<" "<<i<< endl;
  		while(S%i==0){
  			S /= i;
  			cnt++;
  			if(S==1) break;
  		}
  		m[i] = cnt;
  	}
  	if(S>1) m[S]++;
  //}

  vector<ll> res;
  res.push_back(1);
  dfs(res, m, SS);


  sort(ALL(res));
  reverse(ALL(res));

  // cerr << SS<< " --------------" << endl;
  // rep(i, res.size()) cerr <<"err: "<< res[i] << endl;

  rep(i, res.size()){
  	if(res[i]*n>SS) continue;
  	std::vector<ll> A;
  	solve(res[i],SS, A, n, k, v, 0LL);
  	if(ans>0) {
  		cout << ans << endl;
  		return 0;
  	}
  }
  

}
