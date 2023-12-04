#include <bits/stdc++.h>
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
int n, a[base], q;
struct Node{
	int left,right,sum,best;
	int l, r;
};
Node st[4*base];
void combine(Node &res,Node a, Node b){
	res.sum = a.sum + b.sum;
	res.left = max(a.sum + b.left, a.left);
	res.right = max(b.sum + a.right, b.right);
	res.best = max({a.best,b.best,a.right + b.left});
}
void build(int i, int l, int r){
	if(l == r){
		int x = a[l];
		st[i] = {x,x,x,x};
		return;
	}
	int mid = l + r >> 1;
	build(2*i,l, mid);
	build(2*i+1,mid+1,r);
	combine(st[i],st[2*i], st[2*i+1]);
}
void update(int i, int l, int r, int u, int v, int val){
	// u l r v
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		// mod = st[i];
		st[i] = {val,val,val,val};
		return;
	}
	int mid = l + r >> 1;
	update(2*i,l,mid,u,v,val);
	update(2*i+1,mid+1,r,u,v,val);
	combine(st[i], st[2*i], st[2*i+1]);
}
void get(Node &mod, int i, int l, int r, int u, int v){
	if(l == u and r == v){
		mod = st[i];
		return;
	}
	int mid = l + r >> 1;
	if(v <= mid) get(mod,2*i,l,mid,u,v);
	else if(u > mid) get(mod,2*i+1,mid+1,r,u,v);
	else{
		Node getl, getr;
		get(getl,2*i,l,mid,u,mid);
		get(getr,2*i+1,mid+1,r,mid+1,v);
		combine(mod,getl,getr);
	}
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
		int type; cin >> type;
		if(type == 1){
			int i, x; cin >> i >> x;
			update(1,1,n,i,i,x);
			// cout << "bruh" << endl;
		}
		else{
			int l,r; cin >> l >> r;
			Node res;
			get(res,1,1,n,l,r);
			cout << res.best << endl;
		}
	}
	return 0;
}