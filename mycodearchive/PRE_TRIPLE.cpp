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
#define pra(a,n) fod(_i,1,n)cout<<a[_i]<<" ";cout<<el;
#define prv(a) for(auto _v:a)cout<<_v<<" "; cout<<el; 
struct point{int x, y, id;};
struct edge{int u, v, c;};

//int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
//bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) ans = (ans % mod * x % mod + mod) % mod; x = (x % mod * x % mod + mod) % mod; y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
template<class T> bool mini(T& a,T b){return (a>b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<b)?a=b,1:0;}
#define name ""
#define ld long double
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const ll base = 1e6 + 5, INF = 1e18, multitest = 0; int endless = 0; 
const ld PI = acos(-1) , EPS = 1e-9;
void init(){} // remember to reset value for multitestcase
int n;
point a[base];
bool c3 = 1;
void inp(){
	cin >> n;
	fod(i,1,n){
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
		if(a[i].x > 3000 or a[i].y > 3000) c3 = 0;
	}
}

namespace sub1{
   	int dis(int i, int j){
   		return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
   	}
    int dmin[base];
    void solve(){
    	memset(dmin, 0x3f, sizeof dmin);
    	fod(i,1,n) fod(j,1,n) if(i != j) mini(dmin[i], dis(i,j));
    	 
    	 int res = 0;
    	fod(i,1,n) fod(j,i+1,n) fod(k,j+1,n){
			if(dis(i,j) == dis(j,k) and dis(j,k) == dis(i,k) and dis(i,j) == dmin[i] and dmin[i] == dmin[j] and dmin[j] == dmin[k]){
				res++;
			}
    	}
    	
    	cout << res;
    }	
}
namespace sub2{
	int dis(int i, int j){
   		return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
   	}
    int dmin[base];
    ve <vi> g;
    void solve(){
    	memset(dmin, 0x3f, sizeof dmin);
    	fod(i,1,n) fod(j,1,n) if(i != j) mini(dmin[i], dis(i,j));
		g.resize(n + 1);
		fod(i,1,n) fod(j,i+1,n) if(dmin[i] == dmin[j] and dmin[i] == dis(i,j)) g[i].pb(j);
		 
		 int res = 0;
		fod(i,1,n){
			for(int j : g[i]){
				for(int k : g[j]){
					if(dis(i,k) == dmin[i] and dmin[i] == dmin[k]) res++;
				}
			}
		}
		 
		cout << res;
	}
}
namespace sub3{
	const int N = 6005;
	int st[4 * N];
	void upd(int i, int l, int r, int u, int v){
		if(r < u or u < l) return;
		if(l == r){
			maxi(st[i], u + v);
			return;
		}
		int mid = l + r >> 1;
		upd(2*i,l,mid,u,v);
		upd(2*i+1,mid+1,r,u,v);
		
		st[i] = max(st[2*i], st[2*i+1]);
		
	}
	int get(int i, int l, int r, int u, int v){
		if(r < u or v < l) return -INF;
		if(u <= l and r <= v) return st[i];
		int mid = l + r >> 1;
		int getl = get(2*i,l,mid,u,v);
		int getr = get(2*i+1,mid+1,r,u,v);
		
		return max(getl, getr);
	}
	point b[base];
	void rot(){
		fod(i,1,n){
			swap(b[i].x, b[i].y);
			b[i].x = -b[i].x;
		}
	} 
	
	bool cmp(point a, point b){
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
	
	int dmin[base];
	vi g[6001];
	ve <vi> ke;
	int dis(int i, int j){
   		return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
   	}
   	int dd[3001][3001], par[base];
	void solve(){
		fod(i,1,n) dmin[i] = INF, par[i] = i;
		int m = 0;
		fod(i,1,n){
			if(dd[a[i].x][a[i].y] == 0){
				b[++m] = point{a[i].x, a[i].y,i};
				dd[a[i].x][a[i].y] = i;
			}
			else par[i] = dd[a[i].x][a[i].y];
		}
		
		fod(i,1,4){
			rot();
			sort(b + 1, b + m + 1, cmp);
			memset(st, -0x3f, sizeof st);
			fod(i,1,n){
				if(i > 1){
					int g = get(1,-3000,3000, -3000, b[i].y);
					mini(dmin[b[i].id], b[i].x + b[i].y - g);	
				}
				upd(1,-3000,3000,b[i].y,b[i].x);
			}
		}
		
		vi val;
		fod(i,1,n) dmin[i] = dmin[par[i]];
		fod(i,1,n) g[dmin[i]].pb(i), val.pb(dmin[i]);
		ke.resize(n + 1);
		uni(val);
		for(int x : val){
			for(int p1 = 0; p1 < SZ(g[x]); p1++) for(int p2 = p1 + 1; p2 < SZ(g[x]); p2++){
				int i = g[x][p1], j = g[x][p2];
				if(dis(i,j) == x and i < j) ke[i].pb(j);
			}		
		}
		int res = 0;
		fod(i,1,n){
			uni(ke[i]);
			for(int j : ke[i]) for(int k : ke[j]){
				if(dis(i,j) == dis(j,k) and dis(i,k) == dis(i,j) and i < j and j < k and i < k) res++;
			}
		}
		
		cout << res;
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
        sub3 :: solve();
        // if(n <= 300) sub1 :: solve();
        // else if(n > 300 and n <= 3000) sub2 :: solve();
        // else if(c3) sub3 :: solve();
        if(endless) endless--;
    }
    kill();
}