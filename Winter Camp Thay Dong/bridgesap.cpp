// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
using namespace std; 
#define            int  long long
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
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n, m, k;
int a[base];
int res = 0;
pii  hn[base]; int sz = 0;
void inp(){
	cin >> k >> n;
	fod(i,1,n){
		char u, v; int x, y; cin >> u >> x >> v >> y;
		if(u == v){
			res += abs(x - y);
		}
		else{
			res++;
			a[++m] = min(x,y);
			a[++m] = max(x,y);
			hn[++sz].fi = min(x,y);
			hn[sz].se = max(x,y);
		}
	}
}

namespace sub1{
   
    void solve(){
    	sort(a+1,a+m+1);
		int x = 0, y = 0;
		fod(i,1,m){
			x += abs(a[m/2] - a[i]);
			y += abs(a[m/2 + 1] - a[i]);
		}
		
		cout << res + min(x,y);
    }	
}
namespace sub2{
	bool cmp(pii a, pii b){
		return a.fi + a.se < b.fi + b.se;
	}
	int l[base], r[base];
	void solve(){
		sort(hn + 1, hn + sz + 1, cmp);
		priority_queue <int> p1;
		priority_queue <int , vi , greater<int>> p2;
		int cau1 = 0, cau2 = 0;
	
		fod(i,1,sz){
			p1.push(hn[i].fi); 
			p2.push(hn[i].se);
			cau1 += hn[i].fi;
			cau2 += hn[i].se;
			while(p1.top() > p2.top()){
				int x = p1.top(), y = p2.top();
				p1.pop(); p2.pop();
				p1.push(y); p2.push(x);
				cau1 += y - x;
				cau2 += x - y;
			}
			
			l[i] = cau2 - cau1;
		}
		p1 = priority_queue <int>();
		p2 = priority_queue <int , vi , greater<int>>();
		cau1 = cau2 = 0;
		
		fok(i,sz,1){
			p1.push(hn[i].fi); 
			p2.push(hn[i].se);
			cau1 += hn[i].fi;
			cau2 += hn[i].se;
			while(p1.top() > p2.top()){
				int x = p1.top(), y = p2.top();
				p1.pop(); p2.pop();
				p1.push(y); p2.push(x);
				cau1 += y - x;
				cau2 += x - y;
			}
			
			r[i] = cau2 - cau1;
		}
		int ans = INF;
		fod(i,1,sz){
			mini(ans, l[i] + r[i + 1]);
		}
		
		if(sz) cout << res + ans;
		else cout << res;
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
        if(k == 1) sub1 :: solve();
        else sub2 :: solve();
    }
    kill();
}