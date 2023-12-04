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
inline int bp(int a, int b){int res = 1; while(b > 0){if (b & 1) res *= a; a *= a; b >>= 1;} return res; }
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
int n, a[base];
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
	int s = 0;
	fod(i,1,n) cin >> a[i];
	int res = 0;
	fod(i,1,n) res += a[i];
	s = sum(res,0);
	int tripples = bpow(s, 3);
	int f = 0;
	fod(i,1,n) add(f, a[i] * a[i]);
	int res1 = (tripples - f * s%MOD + MOD) % MOD;
	mul(res1, Inv(2));
	int concac = 0;
	// cout<<f<<endl;
	fod(i,1,n){
		int temp = a[i] * a[i] % MOD;
		mul(temp, s);
		int temp1 = bpow(a[i],3);
		// cout<<temp<<" "<<temp1<<endl;
		temp = (temp - temp1 + MOD) % MOD;
		(concac += temp) %= MOD; 
	}
	res1 = (res1 - concac + MOD) % MOD;
	cout << res1/3;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Code now -> Success comes\n";
	return 0;
}
