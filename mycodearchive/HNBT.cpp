// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name "HNBT"
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define BITpos(a,i) (a & mask(i))
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
using namespace std;
void read(){}
void read(long long& a){scanf("%lld",&a);}
void read(long& a){scanf("%ld",&a);}
void read(double& a){scanf("%lf",&a);}
void read(float& a){scanf("%f",&a);}
void read(string& a){cin>>a;}
template<typename x,typename y>void read(pair<x,y>& a){ read(a.first),read(a.second);}
template<typename x>void read(x& a){for(auto  &i : a) read(i);}
template<typename x,typename... y>void read(x& a,y&... b){read(a);read(b...);}
const int oo = 1e18 + 1 + 2 + 3 + 4 + 5 + 12345678910;
typedef pair<int, int> ii;
struct point{
	int x, y;
	point operator- (const point& a)const{
		return {(x - a.x), (y - a.y)};
	}
	int operator* (const point& a)const{
		return x * a.y - y * a.x;
	}
};
struct edge{
	int u, v, c;
};
/*int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}
bool join(int u, int v) {
    int paru = find(u), parv = find(v);
    if (paru == parv) return false;
    par[parv] = paru;
    return true;
}*/	
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
namespace solution{
    int n, a[505][505];
    vector <int> adj[base];
    string dp[mask(16) + 2][18];
	void inp(){
		cin >> n;
		while(1){
			int u, v; cin >> u >> v;
			a[u][v] = 1;
			a[v][u] = 1;
			if(u == 0 and v == 0) break;	
		}
	}
	void sub1(){
		string res;
		int tt = mask(n) - 1;
		fod(x,0,tt){
			int k = __builtin_popcount(x);
			if(k == 1){
				fod(i,1,n) if(BITpos(x, i - 1)) dp[x][i] = to_string(i);
			}
		}
		fod(x,0,tt) fod(i,1,n) if(BITpos(x, i - 1)){
			fod(j,1,n) if(BITpos(x,j-1) == 0){
				if(a[i][j] == 0 and a[j][i] == 0){
					int p = x ^ mask(j-1);
					if(dp[p][j] < dp[x][i] + to_string(j)){
						dp[p][j] = dp[x][i] + to_string(j);
					}
				}
			}
		}
		fod(i,1,n){
			// cout << dp[tt][i] << el;
			string g = dp[tt][i];
			if(res < g and g.size() == n){
				if(a[g[0] - '0'][g[g.size()-1] - '0'] == 0 and a[g[g.size()-1] - '0'][g[0] - '0'] == 0) res = dp[tt][i];
			}
		} 
		if(res != "")for(char c : res) cout << c << " ";
		else cout << -1;
	}
	map <int,int> d;
	int next[base];
	bool dfs(int u){
		d[u] = 1;
		if(d.size() == n) return 1;
		for(int v : adj[u]){
			if(d[v]) continue;
			int tmp = dfs(v);
			if(tmp){
				next[u] = v;
				return 1;
			}
		}
		d[u] = 0;
		d.erase(u);
		return 0;
	}
	void sub2(){
		fod(i,1,n-1) fod(j,i+1,n){
			if(!a[i][j] and !a[j][i]) adj[i].pb(j), adj[j].pb(i);
		}
		fod(i,1,n){
			sort(adj[i].begin(), adj[i].end(), greater<int>());
		}
		int tmp = dfs(n);
		int k = n;
		fod(i,1,n){
			cout << k << " ";
			k = next[k];
		}
	}
	void solve(){
		inp();
		sub2();
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	else if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	int Test = 1; if(multitest)cin >> Test; 
	while(Test--)solution :: solve();
	kill();
}