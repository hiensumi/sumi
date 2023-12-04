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
int n, k, a[base];
void inp(){
	cin >> n >> k;
	if(n == 0 and k == 0) kill();
	fod(i,1,n) cin >> a[i];
}

namespace sub_task1{
	int cost[2005][2005], dp[2005], opt[base];
	
	void calc(int l, int r, int u, int v){
		if(l > r) return;
		int mid = l + r >> 1;
		int best = INF;
		
		fod(k,u, min(mid, v)){
			if(mini(dp[mid + 1], dp[k] + cost[k][mid-1])){
				best = k;
			}
		}
		
		calc(l,mid-1,u,best);
		calc(mid+1,r,best,v);
	}
	
	void solve(){
		// vector <vector<int>> cost(n + 2, vector <int>(n + 2));	
		// vector <int> dp(n + 2, INF);
		memset(cost, 0 , sizeof cost);
		memset(dp, 0x3f, sizeof dp);
		
		fod(i,1,n){
			priority_queue <int, vector <int>> lower;		
			priority_queue <int, vector <int>, greater<int> > upper;
			int sumLower = 0, sumUpper = 0;
			
			fod(j,i,n){
				sumLower += a[j];
				lower.push(a[j]);
				
				if( (lower.size() > upper.size() + 1) or (!upper.empty() and lower.top() > upper.top())){
					int val = lower.top();
					upper.push(val);
					lower.pop();
					sumLower -= val;
					sumUpper += val;
				}
				
				if(upper.size() > lower.size()){
					int val = upper.top();
					lower.push(val);
					upper.pop();
					sumLower += val;
					sumUpper -= val;
					
				}
				
				int median = lower.top();
				// lower.pop();
				int costLower = lower.size() * median - sumLower;
				int costUpper = sumUpper - upper.size() * median;
				
				cost[i][j] = costLower + costUpper;
				// cost[i][j] = median;
			}
		}
		
		dp[1] = 0;
		
		// fod(s,1,k){
			// fok(i,n,1) fod(j,i,n){
				// mini(dp[j+1], dp[i] + cost[i][j]);
			// }
		// }
		
		fod(s,1,k) fok(j,n,1){
			fod(i,1,j) mini(dp[j+1], dp[i] + cost[i][j]);
			
		}
		
		// fod(s,1,k){
			// calc(1,n,1,n);
		// }
		cout << dp[n + 1] << el;
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
	inp();
	sub_task1::solve();
	kill();
}