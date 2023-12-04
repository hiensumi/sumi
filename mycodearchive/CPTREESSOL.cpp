#include <bits/stdc++.h>
using namespace std;
#define uwu ""
typedef long long ll;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b;i--)
#define makep make_pair
#define pb push_back
#define fi first
#define se second
#define ii pair <int,int>
#define lii pair<ll,ll>
#define pque priority_queue
bool multitest = false;
const int N=3e5+3;
const int mxn=1e9+7;
const ll mxll = 1e17+7;
const int modd = 1e9+7;
int add(int x, int y){
	return (x+y)%modd;
}
int mul(int x, int y){
	return (x*y)%modd;
}
int n, goc1, goc2;
vector <int> g1[N], g2[N];
int cnt = 0;ll res = 0;
int f[N];
struct bg{
	int start, end;
} a[N];
struct bg2{
	ll val, lazy;
} st[4*N];
void init(){
	FOR(i,1,n) f[i] = 0;
	FOR(i,1,4*n) st[i].val = 0, st[i].lazy = 0;
}
void prep(void){
	cin >> n;
	FOR(i,1,n){
		int u; cin >> u;
		if (u == 0) goc1 = i;
		else g1[u].pb(i);
	}
	FOR(i,1,n){
		int u; cin >> u;
		if (u == 0) goc2 = i;
		else g2[u].pb(i);
	}
	init();
}
void dfs1(int u){
	cnt++; 
	a[u].start = cnt;
	for(auto v : g1[u]) dfs1(v);
	a[u].end = cnt;
}
void dfs2_bf(int u){
	res += f[a[u].start];
	FOR(i,a[u].start,a[u].end) f[i]++;
	for(auto v : g2[u]) dfs2_bf(v);
	FOR(i,a[u].start,a[u].end) f[i]--;
}
void down(int id){
	ll k = st[id].lazy;
	st[id*2].val += k;
	st[id*2].lazy += k;
	st[id*2+1].val += k;
	st[id*2+1].lazy += k;
	st[id].lazy = 0;
}
ll get(int id, int l, int r, int i){
	if (i < l || r < i || l > r) return mxn;
	if (l == r) return st[id].val;
	int mid = (l+r)/2;
	down(id);
	return min(get(id*2,l,mid,i), get(id*2+1,mid+1,r,i));
}
void updatetang(int id, int l, int r, int u, int v){
	if (v < l || r < u) return;
	if (u <= l && r <= v){
		st[id].val++; st[id].lazy++; 
		return;
	}
	int mid = (l+r)/2;
	down(id);
	updatetang(id*2,l,mid,u,v);
	updatetang(id*2+1,mid+1,r,u,v);
	st[id].val =min(st[id*2].val, st[id*2+1].val);
}
void updategiam(int id, int l, int r, int u, int v){
	if (v < l || r < u) return;
	if (u <= l && r <= v){
		st[id].val--; st[id].lazy--;
		return; 
	}
	int mid = (l+r)/2;
	down(id);
	updategiam(id*2,l,mid,u,v);
	updategiam(id*2+1,mid+1,r,u,v);
	st[id].val =min(st[id*2].val, st[id*2+1].val);
}
void dfs2(int u){
	res += get(1,1,n,a[u].start);
	updatetang(1,1,n,a[u].start,a[u].end);
	for(auto v : g2[u]) dfs2(v);
	updategiam(1,1,n,a[u].start,a[u].end);
}
void solve(void){
	dfs1(goc1);
	dfs2(goc2);
	cout << res;
}
signed main(){
 	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen(uwu".inp", "r")){
	   freopen(uwu".inp","r",stdin);
	   freopen(uwu".out","w",stdout);
	}
	int test = 1;
	if (multitest) cin >> test;
	while(test--){
		prep(); solve();
		cout << '\n';
	}
	return 0;
}