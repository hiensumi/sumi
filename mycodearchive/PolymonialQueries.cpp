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
#define nhan *
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
const int base = 1e6 + 5;
int lz[4 * base], n, a[base], q, st[4*base];
void pull(int i){
	st[i] = st[2 nhan i] + st[2 nhan i + 1];
}
void build(int i, int l, int r){
	if(l == r){
		st[i] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(2 nhan i, l ,mid);
	build(2 nhan i + 1, mid + 1, r);
	pull(i);
}
void push(int i, int l, int r){
	int mid = l + r >> 1;
	if(lz[i]){
		// original: (r - l + 1) * (r - l + 2) / 2;
		// change ? 1. 1 -> mid: (mid - l + 1)
		int midd = mid + 1;
		st[2 nhan i] += (mid - l + 1) * (mid - l + 2)/2;
		st[2 nhan i + 1] += (r - midd + 1) * (r - midd + 2)/2; // mid + 1 -> r 
		lz[2 nhan i] += lz[i];
		lz[2 nhan i + 1] += lz[i];
		lz[i] = 0;
	}
}
void update(int i, int l, int r, int u, int v){
	// u l r v
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		st[i] += (r - l + 1) * (r - l + 2)/2;
		return;
	}
	push(i,l,r);
	int mid = l + r >> 1;
	update(2 nhan i, l, mid, u, v);
	update(2 nhan i + 1, mid + 1, r, u, v);
	pull(i);
}
int get(int i, int l, int r, int u, int v){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v){
		return st[i];
	}
	push(i,l,r);
	int mid = l + r >> 1;
	int getl = get(2 nhan i, l, mid,u,v);
	int getr = get(2 nhan i + 1, mid + 1, r,u, v);
	return getl + getr;
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
	cin >> n >> q;
	fod(i,1,n) cin >> a[i];
	build(1,1,n);
	while(q--){
		int type, l, r; cin >> type >> l >> r;
		if(type == 1){
			update(1,1,n,l,r);	
		}
		else{
			cout << get(1,1,n,l,r) << endl;
		}
	}
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Code now ->قَمَر \n";
	return 0;
}
