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
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e5 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
namespace solution{
 	int n, lg[base], a[base], pre[base], le[base][21], ri[base][21];
	void inp(){
		cin >> n;
		fod(i,1,n) cin >> a[i], pre[i] = pre[i-1] + a[i];
	}
	int getmi(int l, int r){
		if(l > r) return 0;
		int k = lg[r - l + 1];
		return min(le[l][k], le[r - mask(k) + 1][k]);
	}
	int getma(int l, int r){
		if(l > r ) return 0;
		int k = lg[r - l + 1];
		return max(ri[l][k], ri[r - mask(k) + 1][k]);	
	}
	void init(){
		fod(i,2,n) lg[i] = lg[i/2] + 1;
		fod(i,0,n){
			le[i][0] = pre[i];
			ri[i][0] = pre[i];
		}
		fod(j,1,lg[n]){
			for(int i = 0; i + mask(j) - 1 <= n; i++){
				le[i][j] = min(le[i][j-1], le[i + mask(j-1)][j-1]);
				ri[i][j] = max(ri[i][j-1], ri[i + mask(j-1)][j-1]);
			}
		}
	}
	int val(int l, int r){
 		int sum = 0;
 		int res = -1e18;
 		fod(i,l,r) sum += a[i], res = max(res, a[i]);
 		return sum - res;
 	}
	int res = 0;
	ii sv[base];
	int dp[base];
	int sum(int l, int r){
		return pre[r] - pre[l-1];
	}
	void sub1(){
		init();
		stack <int> st;
		fod(i,1,n){
			while(st.size() and a[i] > a[st.top()]) st.pop();
			sv[i].fi = (st.empty()) ? 0 : st.top();
			st.push(i);
		}
		while(st.size()) st.pop();
		fok(i,n,1){
			while(st.size() and a[i] > a[st.top()]) st.pop();
			sv[i].se = (st.empty() ? n : st.top() - 1); 
			st.push(i);
		}
		// fod(i,1,n) cout << pre[i] << " ";
		// cout << el;
		// cout << getmi(2,5) << el;
		dp[0] = -1e18;
		fod(i,1,n){
			int j1 = sv[i].fi, j2 = sv[i].se, mal = -1e18, mar = -1e18;
			dp[i] = max(pre[i-1] - getmi(j1,i-1), dp[j1] + pre[i] - pre[j1]);
		}
		cout << max(0ll, *max_element(dp + 1, dp + n + 1));
	}
	void solve(){
		inp();
		sub1();
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
