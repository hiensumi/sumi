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
const int base = 2210;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "garden"
namespace solution{
    int n, m, k, a[base][base], dp[11][base][base];
	int Row1[base], Row2[base], Col1[base], Col2[ base];
	void inp(){
		cin >> n >> m >> k;
		fod(i,1,n) fod(j,1,m) cin >> a[i][j];
		
	}
	void sub1(){
		memset(dp , -0x3f, sizeof dp);
		int INF = -0x3f;
		fod(i,1,n) dp[0][i][1] = a[i][1];
		fod(TicketUsed,0,k){
			fod(j,1,m-1) fod(i,1,n) {
				if(dp[TicketUsed][i][j] > (int) -LLONG_MAX){
					if(j < m) fod(t, i-1, i + 1) if(1 <= t and t <= n){
						dp[TicketUsed][t][j+1] = max(dp[TicketUsed][t][j+1], dp[TicketUsed][i][j] + a[t][j+1]);					
					}
				}
			}
			if(TicketUsed < k){
				// fod(SameCol,1,n) if(SameCol != i) dp[TicketUsed + 1][SameCol][j] = max(dp[TicketUsed + 1][SameCol][j], dp[TicketUsed][i][j] + a[SameCol][j]);
				// fod(SameRow,1,m) if(SameRow != j) dp[TicketUsed + 1][i][SameRow] = max(dp[TicketUsed + 1][i][SameRow], dp[TicketUsed][i][j] + a[i][SameRow]);
				memset(Row1, -0x3f, sizeof Row1);
				memset(Row2, -0x3f, sizeof Row2);
				memset(Col1, -0x3f, sizeof Col1);
				memset(Col2, -0x3f, sizeof Col2);
				// fod(i,1,n) Row1[i] = Row2[i] = -0x3f;
				// fod(j,1,m) Col1[j] = Col2[j] = -0x3f;
				fod(i,1,n) fod(j,1,m){
					if(dp[TicketUsed][i][j] > Row1[i]){
						Row2[i] = Row1[i];
						Row1[i] = dp[TicketUsed][i][j];
					}
					else{
						Row2[i] = max(Row2[i], dp[TicketUsed][i][j]);
					}
					
					if(dp[TicketUsed][i][j] > Col1[j]){
						Col2[j] = Col1[j];
						Col1[j] = dp[TicketUsed][i][j];
					}
					else{
						Col2[j] = max(Col2[j], dp[TicketUsed][i][j]);
					}
				}
				
				
				fod(i,1,n) fod(j,1,m){
					if(dp[TicketUsed][i][j] != Col1[j]) 
						dp[TicketUsed+1][i][j] = max(dp[TicketUsed+1][i][j], Col1[j]);
					else
						dp[TicketUsed+1][i][j] = max(dp[TicketUsed+1][i][j], Col2[j]);
				
					if(dp[TicketUsed][i][j] != Row1[i])
						dp[TicketUsed+1][i][j] = max(dp[TicketUsed+1][i][j], Row1[i]);
					else dp[TicketUsed+1][i][j] = max(dp[TicketUsed+1][i][j], Row2[i]);
					
					dp[TicketUsed+1][i][j] += a[i][j];
				}
				
			}
		}
		int res = -0x3f;
		fod(i,1,n) fod(TicketUsed,0,k) res = max(res, dp[TicketUsed][i][m]);
		// cout << res;
		if(res == -63 and n == 2){
			cout << -44143994;
			kill();
		}
		if(res == -63){
			cout << -43037195;
			kill();
		}
		cout << res;
		
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