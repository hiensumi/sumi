// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
using namespace std; 
// #define            int  long long
#define             ll  long long 
#define             db  double 
#define             ve  vector 
#define             vi  vector<int>
#define            vll  vector<ll>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            pii  pair<int,int>
#define            pll  pair<ll,ll>
#define             mp  make_pair 
#define             fi  first 
#define             se  second
#define         uni(a)  sort(all(a)),a.resize(unique(all(a))-a.begin()) 
#define     fod(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    fok(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define         all(a)  a.begin(),a.end()  
#define             LB  lower_bound
#define             UB  upper_bound 
#define            tct  template<class T>
#define     BIT(msk,i)  (msk>>(i)&1)
#define        mask(i)  (1ll<<(i))
#define          SZ(_)  (int)(_.size())
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll 
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a,ll b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll rd(ll l , ll r ){return l+1LL*rand()*rand()%(r-l+1);}
#define pra(a,n) fod(_i,1,n)cout<<a[_i]<<el;cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<el; cout<<el; 
struct point{int x, y;};
struct edge{int u, v, c;};
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0, endless = 0; 
const int BLOCK = 850;
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
string s;
int p;
void inp(){
	cin >> p >> s;
	s = "#" + s;
}

namespace sub1{
   bool check(int l, int r, int k = p){
		if(k == 0) return 0;
		if(k == 1) return 1;
		int res = 0;
		string n;
		fod(i,l,r) n += s[i]; 
		for(char c : n){
			int val = c - '0';
			res = ( (res * 10) % k + val) % k;
		}
		return res == 0;
	}
    void solve(){
    	int q; cin >> q;
    	while(q--){
    		int l, r;  cin >> l >> r;
    		ll res = 0;
    		fod(i,l,r) fod(j,i,r){
    			if(check(i,j)) res++;
    		}
    		
    		cout << res << el;
    	}
    }	
}
namespace sub21{
	ll cnt[base], dem[base];
	void solve(){
		int n = s.size() - 1;
		fod(i,1,n){
			cnt[i] = cnt[i-1];
			dem[i] = dem[i-1];
			int c = s[i] - '0';
			if(c % 2 == 0) cnt[i] = cnt[i-1] + i + 1, dem[i]++;
		}
		int q; cin >> q;
		while(q--){
			int l, r; cin >> l >> r;
			cout << cnt[r] - cnt[l-1] - l * (dem[r] - dem[l-1]) << el;
		}
		
	}
}
namespace sub22{
	ll cnt[base], dem[base];
	void solve(){
		int n = s.size() - 1;
		fod(i,1,n){
			cnt[i] = cnt[i-1];
			dem[i] = dem[i-1];
			int c = s[i] - '0';
			if(c % 5 == 0) cnt[i] = cnt[i-1] + i + 1, dem[i]++;
		}
		int q; cin >> q;
		while(q--){
			int l, r; cin >> l >> r;
			cout << cnt[r] - cnt[l-1] - l * (dem[r] - dem[l-1]) << el;
		}
		
	}
}
namespace sub3{
	int rem[base];
	ll ans[base];
	struct DL{
		int l, r, id;
	};
	map <int, int> compress;
	int pos[base];
	int MP[base];
	void solve(){
		int n = s.size() - 1;	
		int pw = 1;
		fok(i,n,1) rem[i] = (rem[i+1] + (s[i] - '0') * pw % p) % p, (pw *= 10) %= p;
		
		ve <DL> qr;
		int q; cin >> q;
		fod(i,1,q){
			int l, r; cin >> l >> r;
			qr.pb({l,r,i});
		}
		sort(all(qr), [&] (DL x, DL y){
			if(x.l/BLOCK != y.l/BLOCK) return x.l < y.l;
			return (x.l / BLOCK & 1) ? (x.r < y.r) : (x.r > y.r);
		});
		
		int d = 0;
		
		fod(i,1,n + 1) compress[rem[i]] = 0;
		for(pii x : compress) compress[x.fi] = d++;
		
		fod(i,1,n + 1) rem[i] = compress[rem[i]];
		
		int L = 1 , R = 1;
		MP[rem[1]]++;
		ll tot = 0;
		
		for(DL k : qr){
			int l = k.l, r = k.r, id = k.id;
			while(L > l){
				L--;
				tot += MP[rem[L]];
				MP[rem[L]]++;
			}
			while(L < l){
				MP[rem[L]]--;
				tot -= MP[rem[L]];
				L++;
			}
			while(R > r + 1){
				MP[rem[R]]--;
				tot -= MP[rem[R]];
				R--;
			}
			while(R <= r){
				R++;
				tot += MP[rem[R]];
				MP[rem[R]]++;
			}
			
			ans[id] = tot;
		}
		
		fod(i,1,q){
			cout << ans[i] << el;
		}
	}
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); srand(time(0)); 
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".out", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    init();
    while(Test-- or endless){
        inp(); 
    	if(p % 2 == 0) sub21::solve(), kill();
    	else if(p % 5 == 0) sub22::solve(), kill();
    	else{
    		sub3::solve();
    		kill();
    	}
    }
    kill();
}