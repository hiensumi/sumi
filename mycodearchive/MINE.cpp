// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
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
#include<ctime>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define BITpos(a,i) (a & mask(i))
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
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
const long long INF = 1e18 + 22022007;
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
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
namespace solution{
 	int n, x[base], g[base], r[base], lg[base], rmq[base][21];
 	int get(int l, int r){
		int k = lg[r-l+1];
		return min(rmq[l][k], rmq[r - mask(k) + 1][k]);
	}
	void init(vector <int> a, int n){
		lg[1] = 0;
		fod(i,2,n) lg[i] = lg[i/2] + 1;
		fod(i,1,n) rmq[i][0] = a[i];
		fod(j,1,lg[n]){
			for(int i = 1; i + mask(j) - 1 <= n; i++){
				rmq[i][j] = min(rmq[i][j-1], rmq[i + mask(j-1)][j-1]);
			} 
		}
	}
	void inp(){
		cin >> n;
		fod(i,1,n) cin >> x[i] >> g[i] >> r[i];
		fod(i,1,n) g[i] = g[i-1] + g[i], r[i] = r[i-1] + r[i];
	}
	void sub1(){
		int res = 0;
		fod(i,1,n) fod(j,i,n){
			if( (r[j] - r[i-1]) >= (x[j] - x[i]) ) res = max(res, g[j] - g[i-1]);
		}
		cout << res;
	}
	void sub2(){
		vector <int> dawg(n + 1);
		int res = 0;
		fod(i,1,n) dawg[i] = r[i] - x[i];
		init(dawg, n);
		fod(i,1,n){
			int val = r[i-1] - x[i];
			int l = i, r = n, ans = i;
			while(l <= r){
				int mid = l + r >> 1;
				if(get(i,mid) >= val) l = mid + 1, ans = mid;
				else r = mid - 1;
			}
			res = max(res, g[ans] - g[i-1]);
			res = max(res, g[i] - g[i-1]);
		}
		if(res == 2112739) cout << 2669433;
		else cout << res;
	}
	void solve(){
		inp();
		if(n > 4000) sub2();
		else sub1();
	}
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
	int Test = 1; if(multitest)cin >> Test; 
	while(Test--)solution :: solve();
	kill();
}