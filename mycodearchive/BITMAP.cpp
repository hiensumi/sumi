// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
#define pb push_back
#define el '\n'
#define all(v) v.begin(), v.end()
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { int tmp = x; mul(tmp, Inv(y, mod), mod); return tmp;}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
struct point{int x, y;};
struct edge{int u, v, c;};
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, m, dd[1005][1005], a[1005][1005];
ii par[1005][1005];
int sz[1005][1005];

ii find(ii u) {
	if (par[u.fi][u.se] == u) return u; 
	return par[u.fi][u.se] = find(par[u.fi][u.se]);
}
bool join(ii u, ii v) {
	ii paru = find(u), parv = find(v); 
	if(paru == parv) return false; 
	if(sz[paru.fi][paru.se] < sz[parv.fi][parv.se]) swap(paru,parv);
	par[parv.fi][parv.se] = paru; 
	sz[paru.fi][paru.se] += sz[parv.fi][parv.se]; 
	return true; 
}
vector <ii> dir = {
	{0,-1}, {0,1}, {1,0}, {-1,0}
};
void inp(){
	cin >> n >> m;
	fod(i,1,n) fod(j,1,m){
		par[i][j] = ii(i,j);
		sz[i][j] = 1;
	}
	fod(i,1,n){
		fod(j,1,m){
			char c; cin >> c;
			a[i][j] = (c - '0');
		}
	}
	
	fod(i,1,n) fod(j,1,m){
		if(a[i][j] == 0) continue;
		for(ii z : dir){
			int nu = i + z.fi;
			int nv = j + z.se;
			if(!(1 <= nu and nu <= n and 1 <= nv and nv <= m)) continue;
			if(a[nu][nv]) join(ii(nu,nv), ii(i,j));
		}
	}
}

namespace sub_task1{
    int cnt[1005][1005];
    void solve(){
    	multiset <int> ms;
    	fod(i,1,n) fod(j,1,m){
    		ii x = find(ii(i,j));
    		if(cnt[x.fi][x.se]) continue;
    		ms.insert(sz[x.fi][x.se]);
    		cnt[x.fi][x.se] = 1;
    	}
    	int q; cin >> q;
    	while(q--){
    		int u, v; cin >> u >> v;
    		ii p = ii(u,v);
    		ii x = find(p);
    		int oldv = sz[x.fi][x.se];
    		a[u][v] = 1;
    		for(ii z : dir){
    			int nu = u + z.fi;
    			int nv = v + z.se;
    			if(!(1 <= nu and nu <= n and 1 <= nv and nv <= m)) continue;
    			if(a[nu][nv]) join(ii(nu,nv), ii(u,v));
    		}
    		ii nx = find(p);
    		int sx = sz[nx.fi][nx.se];
    		// ms.erase(ms.find(oldv));
    		ms.insert(sx);
    		cout << *ms.rbegin() << el;
    	}
    }	
    
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".out", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    init();
    while(Test--){
        inp();
        sub_task1 :: solve();
    }
    kill();
}