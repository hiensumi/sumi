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
int n, m;
int st[4*base], a[base], lazy[4*base], lazy2[4*base];
void update(int i, int l ,int r, int u, int v, int x){
	// u l r v
	if(lazy[i] != 0){
		st[i] += (r-l+1) * lazy[i];
		if(l != r){
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}
		lazy[i] = 0;
	}
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		int val = (r-l+1);
		st[i] += val * x;
		if(l != r){
			lazy[2*i] += x;
			lazy[2*i+1] += x;
		}
		// lazy[i] = 1;
		return; 
	}
	int mid = (l + r)/2;
	update(2*i,l,mid,u,v,x);
	update(2*i+1,mid+1,r,u,v,x);
	st[i] = (st[2 * i] % MOD + st[2 * i + 1] % MOD) % MOD;
}
void upd(int i, int l, int r, int u, int v, int a){
    if(lazy2[i] != 0) {
        st[i] += lazy2[i] * (r - l + 1) * (r + l)/2;
        if(l != r){
            lazy2[2*i] += lazy2[i];
            lazy2[2*i+1] += lazy2[i];
        }
        lazy2[i] = 0;
    }
   	// u l r v
   	if(r < u or v < l) return;
    if(u <= l and r <= v){
        st[i] += a * (r - l + 1) * (r + l)/2;
        if(l != r) {
            lazy2[2 * i] += a;
            lazy2[2 * i + 1] += a;
        }
        return;
    }
    int mid = (l + r)/2;
    upd(2*i, l, mid, u, v, a);
    upd(2*i+1,mid+1,r, u, v, a);
    st[i] = (st[2 * i] % MOD + st[2 * i + 1] % MOD) % MOD;
}
int get(int i, int l, int r, int u, int v) {
    if(lazy[i] != 0) {
        st[i] += lazy[i] * (r - l + 1);
        if (l != r) {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(lazy2[i] != 0) {
        st[i] += lazy2[i] * (r - l + 1) * (r + l)/2;
        if (l != r) {
            lazy2[2 * i] += lazy2[i];
            lazy2[2 * i + 1] += lazy2[i];
        }
        lazy2[i] = 0;
    }
    // u l r v
    if(r < u or v < l) return 0;
    if(u <= l and r <= v){
        return st[i];
    }
    int mid = l + r >> 1;
	return (int) ((get(2*i,l,mid,u,v) % MOD + get(2*i+1,mid+1,r,u,v) % MOD) % MOD);
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
	cin >> n >> m;
	// update(1,1,n,1,2,9, 10);
	// cout << get(1,1,n,1,2);
	// fod(i,1,4*base-1) lazy[i] = 1;
	while(m--){
		int type;
		cin >> type;
		if(type == 1){
			int l, r, a,b;
			cin >> l >> r >> a >> b;
			int pref = b - (l * a);
			// update(1,1,n,l,r,a,pref);
			update(1,1,n,l,r,pref);
			upd(1,1,n,l,r,a);
		}
		else{
			int l, r; cin >> l >> r;
			cout << get(1,1,n,l,r)  << endl;
		}
	}
	// cout << calc(1,5,1,3,1,1);
	return 0;
}
