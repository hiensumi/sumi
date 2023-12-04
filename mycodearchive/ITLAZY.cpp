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
const int oo = 1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y, id;
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
const int base = 1e6 + 5;
int n, a[base], q, lazy[4*base], st[4*base];
void build(int i, int l, int r){
	if(l == r){
		st[i] = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(2*i,l,mid);
	build(2*i+1,mid+1,r);
	st[i] = max(st[2*i],st[2*i+1]);
}
void update(int i, int l, int r, int u, int v, int val){
	if(lazy[i] != 0){
		st[i] += 1 * lazy[i];
		if(l != r){
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}
		lazy[i] = 0;
	}
	// u l r v
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		st[i] += 1 * val;
		if(l != r){
			lazy[2*i] += val;
			lazy[2*i+1] += val;
		}
		return;
	}
	int mid = l + r >> 1;
	update(2*i,l,mid,u,v,val);
	update(2*i+1,mid+1,r,u,v,val);
	st[i] = max(st[2*i], st[2*i+1]);
}
int get(int i, int l, int r, int u, int v){
	if(lazy[i] != 0){
		st[i] += 1 * lazy[i];
		if(l != r){
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}
		lazy[i] = 0;
	}
	if(r < u or v < l) return -1e18;
	if(u <= l and r <= v){
		return st[i];
	}
	int mid = l + r >> 1;
	int getl = get(2*i,l,mid,u,v);
	int getr = get(2*i+1,mid+1,r,u,v);
	return max(getl, getr);
}
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
	// oh shit quen build fix nua tieng
	cin >> n;
	fod(i,1,n) cin >> a[i];
	build(1,1,n);
	cin >> q;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r, val; cin >> l >> r >> val;
			update(1,1,n,l,r,val);
		}else{
			int l, r; cin >> l >> r;
			cout << get(1,1,n,l,r) << endl;
		}
	}
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Code now -> Success comes\n";
	return 0;
}
