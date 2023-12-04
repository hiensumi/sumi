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
struct edge{int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
	
}
int k, n, a[base], b[base], m;
void inp(){
	cin >> k; 
	cin >> n;
	fod(i,1,n) cin >> a[i];	
	cin >> m;
	fod(i,1,m) cin >> b[i];
}


namespace sub_task1{
	void solve(){
		vector <int> v;
		
		fod(i,1,n) fod(j,1,m){
			v.pb(a[i] * b[j]);
		}
		
		sort(all(v));
		for(int x : v) cout << x << el;
		// cout << v[k-1];
	}	
}
vector <int> posi[2], nega[2];

bool checkneg(int x){
	int cnt1 = 0, cnt2 = 0;
	for(int v : posi[0]){
		if(v == -INF) continue;
		int l = 1, r = nega[1].size() - 1, ans = 0;
		while(l <= r){
			int mid = l + r >> 1;
			if(nega[1][mid] * v <= x) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		
		cnt1 += max(0ll, ans);
	}
	
	for(int v : posi[1]){
		if(v == -INF) continue;
		int l = 1, r = nega[0].size() - 1, ans = -1;
		while(l <= r){
			int mid = l + r >> 1;
			if(nega[0][mid] * v <= x) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		
		cnt2 += max(0ll, ans);
	}
	
	return cnt1 + cnt2 >= k;
	
}

bool checkpos(int x, int red){
	int cnt1 = 0, cnt2 = 0;
	for(int v : nega[0]){
		if(v == -INF) continue;
		int l = 1, r = nega[1].size() - 1, ans = 0;
		
		while(l <= r){
			int mid = (l + r) / 2;
			if(nega[1][mid] * v <= x) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		
		cnt1 += max(0ll, ans);
	}
	
	for(int v : posi[0]){
		if(v == -INF) continue;
		int l = 1, r = posi[1].size() - 1 , ans = 0;
		while(l <= r){
			int mid = (l + r) / 2;
			if(posi[1][mid] * v <= x) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		
		cnt2 += max(0ll, ans);
	}
	
	return cnt1 + cnt2 >= red;
}

namespace sub_task2{
	void solve(){
		ii pos = ii(0,0), neg = ii(0,0), eq0 = ii(0,0);
		fod(i,1,n){
			if(a[i] > 0) pos.fi++, posi[0].pb(a[i]);
			if(a[i] == 0) eq0.fi++;
			if(a[i] < 0) neg.fi++, nega[0].pb(a[i]);
		}
		fod(i,1,m){
			if(b[i] > 0) pos.se++, posi[1].pb(b[i]);
			if(b[i] == 0) eq0.se++;
			if(b[i] < 0) neg.se++, nega[1].pb(b[i]);
		} 
		
		int x = pos.fi * neg.se + pos.se * neg.fi, y = eq0.fi * (pos.se + neg.se) + eq0.se * (pos.fi + neg.fi)
		, z = neg.fi * neg.se + pos.fi * pos.se;
		y += x;
		z += y;
		bool okx = 0, oky = 0, okz = 0;
		if(k <= x) okx = 1;
		if(k > x and k <= y) oky = 1;
		if(k > y and k <= z) okz = 1;
		
		
		if(oky) return void(cout << 0 << el);
		sort(all(posi[0]));
		sort(all(posi[1]));
		sort(all(nega[1]));
		sort(all(nega[0]));
		
		posi[0].insert(posi[0].begin(), -INF);
		posi[1].insert(posi[1].begin(), -INF);
		nega[0].insert(nega[0].begin(), -INF);
		nega[1].insert(nega[1].begin(), -INF);
		
			
		if(okx){
			int l = -INF, r = -1, ans = -INF;
			while(l <= r){
				int mid = l + r >> 1;
				if(checkneg(mid)) ans = mid,  r = mid - 1;
				else l = mid + 1;
			}
			
			cout << ans << el;
		}
		
		// cout << z << el;
		if(okz){
			sort(nega[1].begin() + 1, nega[1].end(), greater<int>());
			int l = 1, r = INF, ans = -INF;
			while(l <= r){
				int mid = l + r >> 1;
				if(checkpos(mid, k - y)) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			// cout << checkpos(6, k - y) << el;
			// cout << checkpos(2, k - y) << el;
			cout << ans << el;
		}
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
		sub_task2 :: solve();
	}
	kill();
}