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
int m;
point a[base][2];
void inp(){
	cin >> m;
	fod(i,1,m){
		int n; cin >> n;
		int x1,y1,x2,y2,x3,y3,x4,y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		
		a[i][0] = {min({x1,x2,x3,x4}) + 105, min({y1,y2,y3,y4}) + 105};
		a[i][1] = {max({x1,x2,x3,x4}) + 105, max({y1,y2,y3,y4}) + 105};
		// cout << a[i][1].x << " " << a[i][1].y << el;
	}
}

namespace sub1{
   	struct Line{
   		int type, x, y1, y2;
   	};
   	const int N = base;
   	ve <Line> Zx;
   	
   	pii st[4*base];
   	
   	void upd(int i, int l, int r, int u, int v, int val){
   		if(r < u or v < l) return;
   		if(u <= l and r <= v){
   			st[i].se += val;
   			if(st[i].se) st[i].fi = r - l + 1;
   			else if(l == r) st[i].fi = 0;
   			else st[i].fi = st[2*i].fi + st[2*i+1].fi;
   			return;
   		}
   		int mid = l + r >> 1;
   		upd(2*i,l, mid, u, v, val);
   		upd(2*i+1,mid+1,r,u,v,val);
   		if(st[i].se) st[i].fi = r - l + 1;
		else st[i].fi = st[2*i] .fi + st[2*i+1].fi;
   	}
   	
    void solve(){
		fod(i,1,m){
			Zx.pb({1,a[i][0].x,a[i][0].y, a[i][1].y});
			Zx.pb({-1,a[i][1].x,a[i][0].y, a[i][1].y});
		}    
		
		sort(all(Zx), [&] (Line a, Line b){
			return a.x < b.x;
		});
		
		int res = 0;
		fod(i,0,SZ(Zx)-1){
			int low = Zx[i].y1, high = Zx[i].y2;
			upd(1,0,N,low,high-1,Zx[i].type);
		
			res += (Zx[i+1].x - Zx[i].x) * st[1].fi;
		}
		
		cout << res;
    }	
}
namespace sub2{
	
	void solve(){
	
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
        sub1 :: solve();
        sub2 :: solve();
    }
    kill();
}