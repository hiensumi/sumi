// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
#define pb push_back
#define el '\n'
#define all(v) v.begin(), v.end()
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { int tmp = x; mul(tmp, Inv(y, mod), mod); return tmp;}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
struct point{int x, y;};
struct edge{int x, y, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "LADA"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
	
}
struct rect{
	ld x, y, u, v;
};
ld calc(rect& rectangle1, rect& rectangle2) {
    ld x_overlap = max((ld)0.0, min(rectangle1.u, rectangle2.u) - max(rectangle1.x, rectangle2.x));
    ld y_overlap = max((ld)0.0, min(rectangle1.y, rectangle2.y) - max(rectangle1.v, rectangle2.v));
    ld intersectionArea = x_overlap * y_overlap;
    return intersectionArea;
}
int n, k;
edge a[base];
int pre[base];
void inp(){
	cin >> n >> k;
	fod(i,1,n){
		cin >> a[i].x >> a[i].y;
		a[i].c = 2;
	}
}
bool check(int mid){
	int val = pre[mid] + 2;
	// cout << val << el;
	fod(i,1,n) fod(j,i+1,n){
		rect new_a;
		ld x = (ld) a[i].x - val;
		ld y=  (ld) a[i].y + val;
		
		ld u = (ld) a[i].x + val;
		ld v = (ld) a[i].y - val * 0.5;
		new_a = {x,y,u,v};
		
		x = (ld) a[j].x - val;
		y=  (ld) a[j].y + val;
		
		u = (ld) a[j].x + val;
		v = (ld) a[j].y - val;
		
		rect new_b; new_b = {x,y,u,v};
		
		ld c = calc(new_a, new_b);
		if(c > 0.0) return 1;
		
	}
	return 0;
}
namespace sub_task1{
	void solve(){
		string s; cin >> s;
		s = "#" + s;
		fod(i,1,k) pre[i] = pre[i-1] + (s[i] - '0');
		
		int l = 1, r = k, ans = -1;
		while(l <= r){
			int mid = l + r >> 1;
			if(check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		
		// cout << check(2) << el;
		cout << ans << el;	
	}	
	
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	  freopen(name".inp", "r", stdin);
	  freopen(name".out", "w", stdout);
	}
	int Test = 1; if(multitest) cin >> Test;
	init();
	while(Test--){
		inp();
		sub_task1 :: solve();
	}
	kill();
}