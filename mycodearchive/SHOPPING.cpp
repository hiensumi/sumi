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
#define fifai *
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1e18 + 1 + 2 + 3 + 1011;
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
const int base = 2e5 + 5;
const int LO = 21;
int n, m, a[base], f[base][21], lg2[base];
int getmin(int l,int r){
	int k = lg2[r-l+1]; 
	return min(f[l][k], f[r - mask(k) + 1][k]);
}
void init(){
	lg2[1] = 0;
	fod(i,2,n) lg2[i] = lg2[i/2] + 1;
	fod(i,1,n) f[i][0] = a[i];
	fod(j,1,lg2[n]) fod(i,1,n-mask(j)+1){
		f[i][j]=min(f[i][j-1], f[i+mask(j - 1)][j - 1]);
	}
}
signed main(){
	if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	else if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	scanf("%d", &n); scanf("%d", &m);
	fod(i,1,n) scanf("%lld", &a[i]);
	init();
	while(m--){
		int t,l,r;
		scanf("%lld", &t);
		scanf("%d", &l);
		scanf("%d", &r);
		while(l <= r){
			int d = l, c = r, ans = -1;
			while(d <= c){
				int mid = d + c >> 1;
				if(getmin(l,mid) <= t) ans = mid, c = mid - 1;
				else d = mid + 1;
			}
			if(ans == -1) break;
			t %= a[ans];
			l = ans + 1;
		}
		printf("%lld\n", t);
	}
	return 0;
}