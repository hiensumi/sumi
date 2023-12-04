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
#define BITpos(a,i) (a & mask(i))
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
using namespace std;
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
	int u, v, val;
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
int n, d, a[base], dp[10001][2003], val[base], pos[base], neg[base], amax = -1e18;
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
	cin >> n >> d;
	fod(i,2,n) cin >> val[i];
	fod(i,1,n) cin >> a[i], amax = max(a[i], amax);
	memset(dp, 0x3f, sizeof dp);
	memset(neg, 0x3f, sizeof neg);
	memset(pos, 0x3f, sizeof pos);
	fod(j,a[1],amax){
		 dp[1][j] = (j - a[1]) * (j - a[1]);
		 // pos[j] = dp[1][j] + j * val[2];
		 // neg[j] = dp[1][j] - j * val[2];
	}
	fod(i,2,n){
		// fod(j,a[i],amax) fod(k,max(a[i-1],j-d),min(amax,j + d)){
		// 	dp[i][j] = min(dp[i][j], dp[i-1][k] - k * val[i] + j * val[i] + (j - a[i]) * (j - a[i]));
		// 	dp[i][j] = min(dp[i][j], dp[i-1][k] + k * val[i] - j * val[i] + (j - a[i]) * (j - a[i]));
		// }
		fod(j,1,amax){
			neg[j] = dp[i-1][j] - j * val[i];
			pos[j] = dp[i-1][j] + j * val[i];
		}
		deque <int> dq;
		fod(j,a[i],amax){
			int cost = (j - a[i]) * (j - a[i]);
			while(dq.size() and neg[dq.back()] > neg[j]) dq.pop_back();
			dq.pb(j);
			while(dq.size() and dq.front() < max(a[i-1], j - d)) dq.pop_front();
			// while(dq.size() and dq.front() >= j) dq.pop_front();
			if(dq.size()) dp[i][j] = min(dp[i][j], neg[dq.front()] + j * val[i] + cost);
		}
		deque <int> dq3;
		fok(j,amax,a[i]){
			int cost = (j - a[i]) * (j - a[i]);
			while(dq3.size() and pos[dq3.back()] > pos[j]) dq3.pop_back();
			dq3.push_front(j);
			while(dq3.size() and dq3.front() > min(amax, j + d)) dq3.pop_front();
			// while(dq3.size() and dq3.front() < j) dq3.pop_front();
			if(dq3.size()) dp[i][j] = min(dp[i][j], pos[dq3.front()] - j * val[i] + cost);
		}
	}
	int res = 1e18;
	fod(j,0,amax) res = min(res, dp[n][j]);
	cout << res;
	kill();
}