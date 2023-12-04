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
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
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
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 3e5 + 5;
int stt = 0, st[base], en[base], n, t[4*base], lz[4*base], res = 0;
vector <int> tree1[base], tree2[base];
void dfs1(int u, int pu){
	st[u] = ++stt;
	for(int v : tree1[u]) dfs1(v, u);
	en[u] = stt;
}
void push(int id){
	lz[2 * id] += lz[id];
	lz[2 * id + 1] += lz[id];
	t[2 * id] += lz[id];
	t[2 * id + 1] += lz[id];
	lz[id] = 0;
}
void update(int i, int l, int r ,int u, int v, int val){
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		t[i] += val;
		lz[i] += val;
		return;
	}
	push(i);
	int mid = l + r >> 1;
	update(2*i,l,mid,u,v,val);
	update(2*i+1,mid+1,r,u,v,val);
	t[i] = min(t[2*i], t[2*i+1]);
}
int get(int i, int l, int r, int u, int v){
	if(r < u or v < l) return 1e18;
	if(u <= l and r <= v) return t[i];
	push(i);
	int mid = l + r >> 1;
	int getl = get(2*i,l,mid,u,v), getr = get(2*i+1,mid+1,r,u,v);
	return min(getl, getr);
}
void dfs2(int u, int pu){
	res += get(1,1,n,st[u], st[u]);
	update(1,1,n,st[u], en[u], 1);
	for(int v : tree2[u]) dfs2(v,u);
	update(1,1,n,st[u], en[u], -1);
}
int root1, root2;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	else if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n){
		int x; cin >> x;
		if(x == 0){
			root1 = i;
		}
		else tree1[x].pb(i);
		// tree1[i].pb(x);
	}
	fod(i,1,n){
		int x; cin >> x;
		if(x == 0) root2 = i;
		else tree2[x].pb(i);
		// tree2[i].pb(x);
	}
	dfs1(root1,0);
	dfs2(root2,0);
	cout << res;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Code now ->قَمَر \n";
	return 0;
}