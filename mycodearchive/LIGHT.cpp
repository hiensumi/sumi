// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying!
#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) (a & mask(i))
#define pb push_back
#define el '\n'
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
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
const ll INF = 1e18;
const int base = 1e6 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "LIGHT"
#define ld long double
const ld esp = 1e-8;
const ld pi = acos(-1);
namespace solution{
	int n;
	ld L, R;
	struct light{
		ld a, b, c;
	}a[base], b[base];
	// re def:
	// a = head, b = tail, c = height
	ld conv(ld x){
		return x * pi / 180; 
	}
	struct Line{
		pair<ld,ld> left;
		pair<ld,ld> right;
	}pos[base];
	Line getline(int i){
		ld x1 = (ld) a[i].b / (a[i].a - b[i].b);
		ld y1 = (ld) -x1 * b[i].b;
		ld x2 = (ld) a[i].b / (a[i].a - b[i].a);
		ld y2 = (ld) -x2 * b[i].a;
		pair<ld,ld> left = {x2,y2};
		pair<ld,ld> right = {x1,y1};
		Line ret;
		ret.left = left;
		ret.right = right;
		return ret;
	}
	ld inter(pair<ld,ld> dx, pair<ld,ld> dy){
		ld x = (ld) (dy.se - dx.se)/(dx.fi - dy.fi);
		return (ld) dx.fi * x + dx.se;
		// return x;
	}
	bool cmp(light a, light b){
		return a.a < b.a;
	}
	void inp(){
		cin >> n >> L >> R;
		fod(i,1,n) cin >> a[i].a >> a[i].b >> a[i].c, a[i].c = conv(a[i].c); 
		sort(a+1,a+n+1,cmp);	
		fod(i,1,n){
			ld bob = tan(a[i].c);
			ld hl = bob * a[i].b;
			ld head = a[i].a - hl, tail = a[i].a + hl;
			// cout << head << " " << tail << el;
			b[i] = {head, tail, a[i].b};
		}
	}
	bool check(ld mid){
		vector <pair<ld,ld>> v;
		fod(i,1,n){
			if(a[i].b <= mid) continue;
			ld bob = tan(a[i].c);
			ld hl = bob * (a[i].b - mid);
			ld head = a[i].a - hl, tail = a[i].a + hl;
			v.pb({head,tail});
		}
		sort(v.begin(), v.end());
		ld ma = -INF;
		for(auto x : v){
			if(x.fi <= L) ma = max(ma, x.se);
		}
		for(auto x : v){
			if(ma >= R) return 1;
			if(ma >= x.fi) ma = max(ma, x.se);
			else return 0;
		}
		return ma >= R;
	}
	void sub1(){
		ld l = 0, r = 1e3 + esp, ans = 0;
		while(abs(r-l) > esp){
			ld mid = (l + r) * 0.5;
			if(check(mid)) l = mid + esp, ans = mid;
			else r = mid - esp;
		}
		cout << setprecision(9) << fixed << ans << el;
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
	int Test = 1; if(multitest) cin >> Test;
	while(Test--) solution :: solve();
	kill();
}