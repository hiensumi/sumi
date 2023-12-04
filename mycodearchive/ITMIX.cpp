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
#define name "ITMIX"
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
inline int bp(int x, int y){int ans = 1; while(y > 0){ if(y & 1) ans *= x; x *= x; y >>= 1;} return ans;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e5+ 5;
int n, q, a[base];
struct Tree{
	int len, lz[4], val = 0;
	Tree() {lz[1] = lz[3] = 0; lz[2] = 0;};
	void upd1(int x){
		add(val, len * x);
		add(lz[1],x);
	}
	void upd2(int x){
		mul(val, x);
		// mul(lz[2], x);
		if(lz[2] == 0) (lz[2] = x) %= MOD;
		else mul(lz[2],x);
		mul(lz[1], x);
	}
	void upd3(int x){
		val = prod(x,len);
		lz[3] = x;
		lz[1] = 0;
		lz[2] = 1;
	}
	void push(int i1, int i2);
}st[4*base];
void Tree::push(int i1, int i2){
	if(lz[3]){
		st[i1].upd3(lz[3]);
		st[i2].upd3(lz[3]);
		lz[3] = 0;
	}
	if(lz[2]){
		st[i2].upd2(lz[2]);
		st[i1].upd2(lz[2]);
		lz[2] = 0;
	}
	if(lz[1]){
		st[i1].upd1(lz[1]);
		st[i2].upd1(lz[1]);
		lz[1] = 0;
	}
}
void build(int i, int l, int r){
	st[i].len = r - l + 1;
	if(l == r){
		st[i].val = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(2*i,l,mid);
	build(2*i+1,mid+1,r);
	st[i].val = sum(st[2*i].val,st[2*i+1].val);
}
void up1(int i, int l, int r, int u, int v, int x){
	if(u <= l and r <= v){
		st[i].upd1(x);
		return;
	}
	int mid = l + r >> 1;
	st[i].push(2*i,2*i+1);
	if(u <= mid) up1(2*i,l,mid,u,v,x);
	if(mid < v) up1(2*i+1,mid+1,r,u,v,x);
	st[i].val = sum(st[2*i].val, st[2*i+1].val);
}
void up2(int i, int l, int r, int u, int v, int x){
	if(u <= l and r <= v){
		st[i].upd2(x);
		return;
	}
	int mid = l + r >> 1;
	st[i].push(2*i,2*i+1);
	if(u <= mid) up2(2*i,l,mid,u,v,x);
	if(mid < v) up2(2*i+1,mid+1,r,u,v,x);
	st[i].val = sum(st[2*i].val, st[2*i+1].val);
}
void up3(int i, int l, int r, int u, int v, int x){
	if(u <= l and r <= v){
		st[i].upd3(x);
		return;
	}
	int mid = l + r >> 1;
	st[i].push(2*i,2*i+1);
	if(u <= mid) up3(2*i,l,mid,u,v,x);
	if(mid < v) up3(2*i+1,mid+1,r,u,v,x);
	st[i].val = sum(st[2*i].val, st[2*i+1].val);
}
int get(int i , int l, int r, int u, int v){
	// u l r v 
	if(u <= l and r <= v) return st[i].val;
	int mid = l + r >> 1;
	st[i].push(2*i,2*i+1);
	int getl = 0, getr = 0;
	if(mid >= u) getl = get(2*i,l,mid,u,v);
	if(mid < v) getr = get(2*i+1,mid+1,r,u,v);
	return sum(getl,getr);
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
		int type, l, r,x; cin >> type >> l >> r;
		if(type == 1) cin >> x, up1(1,1,n,l,r,x);
		else if(type == 2) cin >> x, up2(1,1,n,l,r,x);
		else if(type == 3) cin >> x, up3(1,1,n,l,r,x);
		else cout << get(1,1,n,l,r) % MOD<< endl;
	}
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Code now -> Success comes\n";
	return 0;
}
