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
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
template <class T>
using mset =
    tree<T, null_type, less_equal <int>, rb_tree_tag, tree_order_statistics_node_update>;
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
int n, contain[base], contained[base], dem[base];
map <int,int> compress;
mset <int> ms;
edge a[base];
bool cmp(edge a, edge b){
	if(a.u == b.u) return a.v > b.v;
	return a.u < b.u;
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
	fod(i,1,n){
		cin >> a[i].u >> a[i].v;
		a[i].c = i;
	}
	sort(a+1,a+n+1,cmp);
	// fod(i,1,n) ms.insert(a[i].v), dem[a[i].v]++;	
	fod(i,1,n) compress[a[i].v] = 0;
	int d = 0;
	for(auto x : compress) compress[x.fi] = ++d;
	fod(i,1,n) a[i].v = compress[a[i].v];
	fod(i,1,n) dem[a[i].v]++, ms.insert(a[i].v);
	fod(i,1,n){
		ms.erase(ms.upper_bound(a[i].v));
		dem[a[i].v]--;
		auto j = ms.upper_bound(a[i].v);
		int x = 0;
		if(j == ms.end()) x = ms.size();
		else{
			x = ms.order_of_key(*j);
		}
		contain[a[i].c] = x + dem[a[i].v];
	}
	fod(i,1,n) ms.insert(a[i].v);
	fok(i,n,1){
		ms.erase(ms.upper_bound(a[i].v));
		auto j = ms.upper_bound(a[i].v);
		if(j == ms.end()) continue;
		int x = ms.order_of_key(*j);
		contained[a[i].c] = ms.size() - x;
	}
	fod(i,1,n) cout << contain[i] << " ";
	cout << el;
	fod(i,1,n) cout << contained[i] << " ";
	kill();
}
