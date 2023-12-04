// hiensumi is on the sky
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
#include<time.h>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define pb push_back
#define el '\n'
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
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
// dont use write like write("abc"). use it like write(x). x is the string variable
// dont use write like write(5). use it like write((int) 5). write(1e18) or any other float variables is fine
int n, m, d, dis[base], inq[base], prog[base], tr[base], di[base], dd[base];
map <int,int> mp;
struct bg{
	int cnt, sc;
} h[base];
vector <ii> adj[base];
struct cmp{
	bool operator() (ii x, ii y){
		return x.se > y.se;
	}
};
bg merge(bg a, bg b){
	if(a.cnt > b.cnt) return a;
	if(a.cnt < b.cnt) return b;
	return {a.cnt, a.sc + b.sc};
}
void dji(int u){
	fod(i,1,n) di[i] = 1e18, dd[i] = 0;
	priority_queue<ii,vector<ii>, cmp> pq;
	pq.push({u,0});
	di[u] = 0; 
	while(!pq.empty()){
		ii x = pq.top();
		int u = x.fi, w = x.se;
		// cout << u << " ";
		pq.pop();
		if(dd[u]) continue;
		dd[u] = 1;
		for(ii x : adj[u]){
			int v = x.fi, w = x.se;
			if(di[v] > di[u] + w){
				di[v] = di[u] + w;
				tr[v] = u;
				if(h[u].cnt < d){
					// tr[v] = u;
					if(di[v] == prog[h[u].cnt + 1]) h[v] = merge(h[u],h[v]);
					h[u].cnt++;
				}
				else h[v] = h[u];
				pq.push({v,di[v]});
			}
			// else if(di[v] == di[u] + w){
			// 	h[v] = h[u];
			// }
		}
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
	cin >> n >> m >> d;
	fod(i,1,m){
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].pb({v,c});
		adj[v].pb({u,c});
	}
	fod(i,1,d){
		cin >> prog[i];
	}
	if(prog[1] == 0){
		fod(i,1,d-1) prog[i] = prog[i+1]; 
	}
	sort(prog + 1, prog + d);
	h[1] = {1,1};
	dji(1);
	// cout << el;
	fod(i,1,n){
		cout << h[i].cnt << " " << h[i].sc << el;
 	}
	if(h[n].cnt != d){
		cout << 0;
		kill();
	}
	else if(h[n].sc != 1){
		cout << 1;
		kill();
	}
	else{
		vector <int> res;
		int u = n;
		while(u != 0) res.pb(u), u = tr[u];
		cout << res.size() << el;
		reverse(res.begin(), res.end());
		for(int x : res) cout << x << el;
	}
	kill();
}
