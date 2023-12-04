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
#define name "store"
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
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
int n, a[base], q, st[4*base], lz[4*base];
void build(int i, int l, int r){
	if(l == r){
		st[i] = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(2*i,l,mid);
	build(2*i+1,mid+1,r);
	st[i] = st[2*i] + st[2*i+1];
}
void pull(int i, int l, int r){
	int mid = l + r >> 1;
	if(lz[i]){
		st[2 * i] = lz[i] * (mid - l + 1);
		st[2 * i + 1] = lz[i] * (r - mid);
		lz[2 * i] = lz[i];
		lz[2 * i + 1] = lz[i];
		lz[i] = 0;
	}
}
void upd(int i, int l, int r , int u, int v, int x){
	if(r < u or v < l) return;
	if(u <= l and r <= v){
		st[i] = (r - l + 1) * x;
		lz[i] = x;
		return;
	}
	int mid = l + r >> 1;
	pull(i,l,r);
	upd(2*i,l,mid,u,v,x);
	upd(2*i+1,mid+1,r,u,v,x);
	st[i] = st[2*i] + st[2*i+1];
}
int get(int i, int l, int r, int u, int v){
	if(r < u or v < l) return 0;
	if(u <= l and r <= v) return st[i];
	pull(i,l,r);
	int mid = l + r >> 1;
	return get(2*i,l,mid,u,v) + get(2*i+1,mid+1,r,u,v);
}
int tknp(int u, int v, int k){
	int l = u, r = v, ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(get(1,1,n,mid,mid) <= k) r = mid - 1, ans = mid;
		else  l = mid + 1;
	}
	return ans;
}
int cnp(int u, int val){
	int l = u, r  = n, ans = 0;
	if(get(1,1,n,u,u) > val) return 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(get(1,1,n,u,mid) <= val) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	return max(0ll,ans - u + 1);
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
	cin >> n;
	fod(i,1,n) cin >> a[i];
	cin >> q;
	build(1,1,n);
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int u, v; cin >> u >> v;
			if(get(1,1,n,u,u) < v){
				int j =  tknp(1,u,v);
				upd(1,1,n,j,u,v);
			}
		}
		else{
			int u, v; cin >> u >> v;
			// int j = cnp(u,v);
			cout << cnp(u,v) << el;
		}
	}
	kill();
}
