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
struct point{
	int x, y;
};
struct edge{
	int u, v;
    vector<int> par;
    void init(int n) {
        par.resize(n + 5, 0);
        fod(i,1,n) par[i] = i;
    }
    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    bool join(int u, int v) {
        int paru = find(u), parv = find(v);
        if (paru == parv) return false;
        par[parv] = paru;
        return true;
    }	
};
const int base = 1e6 + 5;
const int MOD = 1e9 + 7;
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int prod(int x, int y, int mod = MOD) { return mul(x, y, mod), x;}
inline int sum(int x, int y, int mod = MOD) { return add(x, y, mod), x;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int N = base, sm = MOD;
int f[base], F[base], fm[base];
int bp(int a,int b,int m){
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
    return ((F[n] * inv(F[k], p) % p) * inv(F[n-k], p)) % p;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	int n,m; cin >> n >> m;
	F[0] = 1; F[1] = 1;
	fm[0]=0;
    f[2] = 1;
	fod(i,2,n) F[i] = F[i-1] * i % MOD;
	fod(i,3,N){
		f[i]= (((f[i-2]+f[i-1])%sm)*(i-1))%sm;
        // f[i] = prod(sum(f[i-2], f[i-1]), i - 1);
//		else f[i]=(((f[i-2]+f[i-1])%sm)*(i-1))%sm;
	}
	ll res=0;
	fod(i,0,m){
        // (res += (f[n-i] * cb(n,i)) % MOD) % MOD;
        res = (res + (f[n-i] * cb(n,i)) % MOD) % MOD;
		// add(res, prod(f[n-i],cb(n,i)));
	}
	cout<<res+(m==n);
	return 0;
}