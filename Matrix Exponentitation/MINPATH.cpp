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
const int base = 105 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "MINPATH"
namespace solution{
    int n, m, dp[101][base], k;
    vector <ii> adj[base];
    struct Matrix{
 		int n, m;
 		vector <vector <int>> mt;
 		Matrix(int n, int m){
 			this-> n = n;
 			this-> m = m;
 			mt = vector <vector <int>>(n+1, vector <int>(m+1, 0x3f));
 		}
 		Matrix copy(){
 			Matrix res(n,m);
 			res.mt = this->mt;
 			return res;
 		}
 		Matrix operator* (const Matrix& other){
 			Matrix product(n, n);
 			fod(i,1,n) fod(j,1,n) fod(k,1,n){
 				product.mt[i][k] = min(product.mt[i][k], this->mt[i][j] + other.mt[j][k]);
 			}
 			return product;
 		}
 		Matrix operator^ (int n) const{
 			Matrix res(this->n,this->m), a = *this;
 			fod(i,1,this->n) res.mt[i][i] = 0;
 			while(n){
 				if(odd(n)) res = res * a;
 				n >>= 1;
 				a = a * a;
 			}
 			return res;
 		}
 	};
	void inp(){
		cin >> n >> m >> k;
	}
	void sub1(){
		fod(i,1,m){
			int u, v, c;
			cin >> u >> v >> c;
			// adj[u].pb({v,c});
			adj[v].pb({u,c});
		}
		memset(dp, 0x3f, sizeof dp);
		fod(i,1,n) dp[i][0] = 0;
		fod(i,1,n) fod(j,1,k){
			for(ii x : adj[i]){
				dp[i][j] = min(dp[i][j], dp[x.fi][j-1] + x.se);
			}
		}
		int res = 1e18;
		fod(i,1,n){
			res = min(res, dp[i][k]);
		}
		if(res == 1e18) cout << "IMPOSSIBLE";
		else cout << res;
	}
	void sub2(){
		Matrix A(1,n);
		fod(i,1,n) A.mt[1][i] = 1;
		
		Matrix B(n,n);
		fod(i,1,m){
			int u, v, c;
			cin >> u >> v >> c;
			B.mt[u][v] = min(B.mt[u][v], c);
		}
		B = B ^ k;
		int res = 1e18;
		fod(i,1,n) fod(j,1,n) res = min(res, B.mt[i][j]);
		if(res <= 1e18/2) cout << res << el;
		else cout << "IMPOSSIBLE";
		// cout << A.mt[1][1];
		// fod(i,1,n) cout << A.mt[1][i] << el;
	}
	void solve(){
		inp();
		sub2();
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