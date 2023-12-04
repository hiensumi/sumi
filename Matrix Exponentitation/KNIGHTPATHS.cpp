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
#define int unsigned long long
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
const int MOD = (1LL << 32LL);
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
#define name "KNIGHPATHS"
struct Matrix{
	int n, m;
	vector <vector <int>> mt;
	Matrix(int n, int m){
		this-> n = n;
		this-> m = m;
		mt = vector <vector <int>>(n+1, vector <int>(m+1));
	}
	Matrix operator* (const Matrix& other){
		Matrix product(n, other.m);
		fod(i,1,n) fod(j,1,other.m) fod(k,1,m){
			(product.mt[i][j] += this->mt[i][k] * other.mt[k][j]) %= MOD;
		}
		return product;
	}
	Matrix operator^ (int n) const{
		Matrix res(this->n,this->m), a = *this;
		fod(i,1,this->n) res.mt[i][i] = 1;
		while(n){
			if(odd(n)) res = res * a;
			n >>= 1;
			a = a * a;
		}
		return res;
	}
};
namespace solution{
    int K;
	ii di[] = {
		{-2,1}, {-1, 2}, {1,2}, {2,1}, {2, - 1}, {1, -2}, {-1, -2}, {-2, -1}
	};
	void inp(){
		
	}
	int getid(int x, int y, int m = 8){
		return (x - 1) * m + y;
	}
	void sub1(){
		cin >> K;
		// vector <vector <int>> dp(8+1, vector <int>(8 + 1, 0));
		// dp[1][1] = 1;
		// int res = 0, n = 8;
		// fod(rep,1,K){
			// vector <vector <int>> new_dp(8+1, vector <int>(8 + 1, 0));
			// fod(i,1,8) fod(j,1,8){
				// fod(k,0,7){
					// int x = i + di[k].fi, y = j + di[k].se;
					// if(!(1 <= x and x <= 8 and 1 <= y and y <= 8)) continue;
					// (new_dp[x][y] += 1ll * dp[i][j]) %= MOD;
				// }
			// }
			// fod(i,1,n) fod(j,1,n) (res += new_dp[i][j]) %= MOD;
			// dp = new_dp;
		// }
// 		
		// cout << res + 1;
		Matrix A(1,65);
		A.mt[1][1] = 1;
		
		Matrix B(65,65);
		int n = 8;
		fod(i,1,n) fod(j,1,n){
			fod(k,0,7){
				int x = i + di[k].fi, y = j + di[k].se;
				if(!(1 <= x and x <= 8 and 1 <= y and y <= 8)) continue;
				B.mt[getid(i,j)][getid(x,y)]++;
			}
		}	
		fod(i,1,65) B.mt[i][65] = 1;
		A = A * (B ^ (K+1));
		cout << A.mt[1][65]; 
		// fod(i,1,64) cout << A.mt[1][i] << el;
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