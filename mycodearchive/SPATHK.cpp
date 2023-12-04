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
int n,m,k, dis[base], inq[base];
vector <ii> adj[base],g[base];
void spfa(int s) {
    queue <int> q;
    fod(i, 1, n) dis[i] = 1e18, inq[i] = false;
    q.push(s);
    dis[s] = 0;
    inq[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (auto v: g[u]) {
            int to = v.first, w = v.second;
            if (dis[to] > dis[u] + w) {
                dis[to] = dis[u] + w;
                if (!inq[to]) {
                    q.push(to);
                    inq[to] = true;
                }
            }
        }
    }
}
int p[base];
vector<int> v;
edge c[base];
bool cmp(edge a, edge b){
	return a.c < b.c;
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
	cin >> n >> m >> k;
	fod(i,1,m){
		int u, v, w;
		cin >> u >> v >> w;
		c[i] = {u,v,w};
	}
	sort(c + 1, c + m  + 1, cmp);
	fod(i,1,k){
		v.pb(c[i].u);
		v.pb(c[i].v);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	fod(i,0,v.size() - 1) p[v[i]] = i + 1;
	fod(i,1,k){
		int x = p[c[i].u], y = p[c[i].v];
		g[x].pb({y,c[i].c});
		g[y].pb({x,c[i].c});
	} 
	n = 2 * k;
	vector <int> res;
	fod(i,1,n-1){
		spfa(i);
		fod(j,i+1,n) res.pb(dis[j]);
	}
	sort(res.begin(), res.end());
	cout << res[k-1];
	kill();
}
