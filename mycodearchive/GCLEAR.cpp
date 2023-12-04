// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
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
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
	
}
int n, m, a[105][105];
string robota;
ii st, posa;
map <char,ii> mp;

struct Bag{
	int x, y, t;
};
ii bag[base]; 
int dis[101][101][2];
vector <char> dir = {'U', 'L', 'R', 'D'};

void inp(){
	mp['U'] = ii(-1,0);
	mp['L'] = ii(0,-1);
	mp['R'] = ii(0,1);
	mp['D'] = ii(1,0);
	mp['C'] = ii(0,0);
	
	
	cin >> n >> m;
	fod(i,1,n) fod(j,1,m){
		char c; cin >> c;
		a[i][j] = (c == '1');
	}
	cin >> posa.fi >> posa.se;
	
	cin >> robota; robota = "#" + robota;
	
	
	fod(i,1,robota.size() - 1){
		ii dir = mp[robota[i]];
		posa.fi += dir.fi;
		posa.se += dir.se;
		bag[i] = posa;
	}
}
int dd[105][105][2];
namespace sub_task1{
	void solve(){
		memset(dis, 0x3f, sizeof dis);
		queue <Bag> q;
		cin >> st.fi >> st.se;
		
		q.push({st.fi, st.se, 0});
		dis[st.fi][st.se][0] = 0;
		dd[st.fi][st.se][0] = 1;
		while(q.size()){
			int u  = q.front().x;
			int v = q.front().y;
			int t = q.front().t;
			int pt  = t ^ 1;
			q.pop();
			
			for(auto p  : dir){
				ii der = mp[p];
				
				int x = u + der.fi, y = v + der.se;
				if(!(1 <= x and x <= n and 1 <= y and y <= m)) continue;
				if(dd[x][y][pt]) continue;
				dd[x][y][pt] = 1;
				if(a[x][y]) continue;
				
				if(mini(dis[x][y][pt] , dis[u][v][t] + 1)){
					q.push({x,y,pt});
				}
				
			}
		}
		int res = INF;
		fod(i,1,robota.size() - 1){
			int ret = dis[bag[i].fi][bag[i].se][odd(i)];
			// cout << bag[i].fi << " " << bag[i].se << " " << ret << el;
			if(ret > i) continue;
			
			mini(res, i);
		}
		
		if(res > robota.size() - 1) return void(cout << -1 << el);
		cout << res << el;
		
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