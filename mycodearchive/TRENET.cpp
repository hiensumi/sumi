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
#define name "TRENET"
namespace solution{
 	int n, m, trace[base], dis[base], dd[base];
 	vector <int> root[base], le[base], chan[base];
 	vector <int> adj[base];
	void inp(){
		int sz = 1;
		cin >> n >> m;
	}
	void sub1(){
		int ma = max(n,m), cur = 2;
		root[1].pb(1);
		le[1].pb(1);
		int cnt = 2, gr = 1;
		while(cur <= 100005){
			gr++;
			fod(i,cur,cur + cnt){
				root[gr].pb(i); 
				if(odd(i)) le[gr].pb(i);
				else chan[gr].pb(i);
			}
			cur = cur + cnt + 1;
			cnt += 2;
		}
		fod(i,1,gr-1){
			if(odd(root[i][0])){
				int sz = le[i].size() - 1;
				fod(j,0,sz){
					adj[le[i][j]].pb(le[i+1][j]);
					adj[le[i+1][j]].pb(le[i][j]);
				}
			}
			else{
				int sz = chan[i].size()-1;
				fod(j,0,sz){
					adj[chan[i][j]].pb(chan[i+1][j]);
					adj[chan[i+1][j]].pb(chan[i][j]);
				}
			}
		}
		fod(i,1,gr){
			int sz = root[i].size() - 1;
			fod(j,0,sz-1){
				adj[root[i][j]].pb(root[i][j+1]);
				adj[root[i][j+1]].pb(root[i][j]);
			}
		}
		queue <int> q;
		q.push(n);
		memset(dis, 0x3f, sizeof dis);
		dis[n] = 0;
		dd[n] = 1;
		while(q.size()){
			int t = q.front();
			q.pop();
			for(int v : adj[t]){
				if(dd[v]) continue;
				dd[v] = 1;
				if(dis[v] > dis[t] + 1){
					dis[v] = dis[t] + 1;
					trace[v] = t;
					q.push(v);
				}
			}
		}
		vector <int> res;
		cout << dis[m] << el;
		while(m != n){
			res.pb(m);
			m = trace[m];
		}
		res.pb(n);
		reverse(res.begin(), res.end());
		for(int x : res) cout << x << el;
		// cout << gr << el;
	}
	void solve(){
		inp();
		sub1();
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