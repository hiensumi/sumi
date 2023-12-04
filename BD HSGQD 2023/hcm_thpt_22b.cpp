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
#define odd(i) (i & 1LL)
#define all(v) v.begin(), v.end()
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e3 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int MOD = MOD) { x += y; while (x >= MOD) x -= MOD; while (x < 0) x += MOD;}
inline void mul(int &x, int y, int MOD = MOD) { x = (x * 1LL * y) % MOD;}
inline int prod(int x, int y, int MOD = MOD) { return mul(x, y, MOD), x;}
inline int sum(int x, int y, int MOD = MOD) { return add(x, y, MOD), x;}
inline int bpow(int x, int y, int MOD = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, MOD); mul(x, x, MOD); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int MOD = MOD) { return bpow(x, MOD - 2, MOD);}
inline int Div(int x, int y, int MOD = MOD) { return prod(x, Inv(y, MOD), MOD);}
struct point{int x, y;};
struct edge{ int u, v, c;};
/*int find(int u) { if (par[u] == u) return u; return par[u] = find(par[u]);}
bool join(int u, int v) {int paru = find(u), parv = find(v); if (paru == parv) return false; par[parv] = paru; return true;
}*/ 
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
struct FenwickTree {
	    int b1[base], b2[base];
	    int n;
	    void init(int n){
	    	this-> n = n;
	    }
	    void add(int b[], int idx, int x){
		    while(idx <= n){
		        b[idx] += x;
		        idx += idx & -idx;
			}
		}
		void range_add(int l, int r, int x){
		    add(b1,l,x);
		    add(b1,r+1,-x);
		    add(b2,l,x*(l-1));
		    add(b2,r+1,-x*r);
		}
		int sum(int b[], int idx){
		    int res = 0;
		    while(idx){
		        res += b[idx];
		        idx -= idx & -idx;
		    }
		    return res;
		}
		int getall(int idx){
		    return sum(b1, idx) * idx - sum(b2, idx);
		}
		int get(int l, int r){
			if(l > r) return 0;
			if(l == 0 or r == 0) return 0;
			return getall(r) - getall(l-1);
		}
}BIT;
struct Matrix{
	int n, m;
	vector <vector<int>> mt;
	Matrix(int n, int m){
		this-> n = n;
		this-> m = m;
		mt = vector <vector<int>>(n + 1, vector <int>(m+1));
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
void init(){
	
}
int  n, q;
void inp(){
	cin >> n >> q;
}
map <int,int> F;
void fib(ll n, ll&x, ll&y){
    if(n==0){
        x = 0;
        y = 1;
        return;
    }
    if(n&1){
        fib(n-1, y, x);
        y=(y+x)%MOD;
    }else{
        ll a, b;
        fib(n>>1, a, b);
        y = (a*a+b*b)%MOD;
        x = (a*b + a*(b-a+MOD))%MOD;
    }
}
namespace sub_task1{
	
	void solve(){
		// Matrix A(1,2);
		// A.mt[1][1] = 0;
		// A.mt[1][2] = 1;
// 		
		// Matrix B(2,2);
		// B.mt[1][1] = 0;
		// B.mt[2][1] = 1;
		// B.mt[1][2] = 1;
		// B.mt[2][2] = 1;
// 		
		BIT.init(n);
		int val = 1, val2 = 1;
		// fib(6,val,val2);
		// cout << val << " " << val2 << el;
		while(q--){
			int type, l , r; cin >> type >> l >> r;
			if(type == 1){
				int x; cin >> x;
				int val = 1, v = 1;
				fib(x,val,v);
				
				// Matrix C(2,2); C = A * (B ^ x);
				// val = C.mt[1][1];
				BIT.range_add(l,r,val);
			}
			else{
				cout << BIT.get(l,r)  << el;
			}
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
		sub_task1 :: solve();
	}
	kill();
}