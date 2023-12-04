#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define name ""
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
int f[base];
int bp(int a,int b,int m = MOD){
    a = a % m;
    int res = 1;
    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int inv(int a, int p = MOD){
    return bp(a, p-2, p);
}
int cb(int n, int k, int p = MOD){
    return ((f[n] * inv(f[k], p) % p) * inv(f[n-k], p)) % p;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	int n, m; cin >> n >> m;
	f[0] = f[1] = 1;
	if(n < m) swap(n,m);
	fod(i,1,m) f[i] = f[i-1] * i % MOD;
	int res = bp(bp(2,m)-1,n);
	fod(i,1,m){
		int r = cb(m,i) * bp(bp(2,m-i)-1,n) % MOD;
		if(i & 1) add(res,-r);
		else add(res,r);
	}
	cout << res;
	return 0;
}
