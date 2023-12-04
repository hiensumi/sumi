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
template<class T> bool maxi(T& a, T& b){return (a>=b) ? a = b, 1 :  0;}
template<class T> bool mini(T& a, T& b){return (a<=b ? a = b, 1 : 0);}
struct point{int x, y;};
struct edge{int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true; }*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 1;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
string a, b;
void init(){
	
}

void inp(){
	cin >> a >> b;
}

namespace sub_task1{
	struct line{
		int num7, num4, num7_, num4_, num;
	};
	void solve(){
		line Up, Down;
		Up.num7 = Up.num4 = Up.num4_ = Up.num7_ = Up.num = 0;
		Down.num7 = Down.num4 = Down.num4_ = Down.num7_ = Down.num = 0;
		int n = a.size();
		a = "#" + a;
		b = "#" + b;
		fod(i,1,n){
			if(a[i] > '7') Up.num7_++;
			if(a[i] > '4' and a[i] < '7') Up.num4_++;
			if(a[i] == '4') Up.num4++;
			if(a[i] == '7') Up.num7++;
			if(a[i] < '4') Up.num++;
		}
		
		fod(i,1,n){
			if(b[i] > '7') Down.num7_++;
			if(b[i] > '4' and b[i] < '7') Down.num4_++;
			if(b[i] == '4') Down.num4++;
			if(b[i] == '7') Down.num7++;
			if(b[i] < '4') Down.num++;
		}
		string res = "";
		int cnt = min(Up.num7, Down.num4_);
		Up.num7 -= cnt;
		Down.num4_ -= cnt; 
		fod(i,1,cnt) res += "7";

		cnt = min(Down.num7, Up.num4_);
		Down.num7 -= cnt;
		Up.num4_ -= cnt;
		fod(i,1,cnt) res += "7";
		
		cnt = min(Up.num7, Down.num);
		Up.num7 -= cnt;
		Down.num -= cnt;
		fod(i,1,cnt) res += "7";
		
		cnt = min(Down.num7, Up.num);
		Down.num7 -= cnt;
		Up.num -= cnt;
		fod(i,1,cnt) res += "7";
		
		cnt = min(Up.num7, Down.num4);
		Up.num7 -= cnt;
		Down.num4 -= cnt;
		fod(i,1,cnt) res += "7";
		
		cnt = min(Down.num7, Up.num4);
		Down.num7 -= cnt;
		Up.num4 -= cnt;
		fod(i,1,cnt) res += "7";
		
		cnt = min(Up.num7, Down.num7);
		Up.num7 -= cnt;
		Down.num7 -= cnt;
		fod(i,1,cnt) res += "7";
		
		
		cnt = min(Up.num4, Down.num);
		Up.num4 -= cnt;
		Down.num -= cnt;
		fod(i,1,cnt) res += "4";
		
		cnt = min(Down.num4, Up.num);
		Down.num4 -= cnt;
		Up.num -= cnt;
		fod(i,1,cnt) res += "4";
		
		cnt = min(Up.num4, Down.num4);
		Up.num4 -= cnt;
		Down.num4 -= cnt;
		fod(i,1,cnt) res += "4";
		
		cout << res << el;
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