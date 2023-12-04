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
	long double x, y;
	point operator- (const point& a)const{
		return {(x - a.x), (y - a.y)};
	}
	long double operator* (const point& a)const{
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
const int base = 1e6 + 5;
const bool multitest = 0;
const long double esp = 1e-9;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld double
namespace solution{
    int n, m = 0;
    point a[base], h[base];
    ld kc(point a, point b){
		return sqrtl(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	}
    long double ccw(point a, point b, point c){
    	return (b-a) * (c-b);	
    }
    bool cmp(point a, point b){
    	if(a.y == b.y) return a.x < b.x;
    	return a.y < b.y;
    }
    point p1;
    bool cmp2(point a, point b){
    	if(ccw(p1,a,b) == 0) return kc(p1,a) < kc(p1,b);
    	return ccw(p1,a,b) > 0;
    }
    struct Cir{
    	point A;
    	ld Rad;
    	Cir(point A, ld Rad){
    		this -> A = A;
    		this -> Rad = Rad;
    	}
    };
    point DtNgTiep(point a, point b){
    	ld B = a.x * a.x + a.y * a.y;
    	ld C = b.x * b.x + b.y * b.y;
    	ld D = a.x * b.y - a.y * b.x;
    	return { (ld) (b.y * B - a.y * C)/ (D/0.5), (ld) (a.x * C - b.x * B)/(D/0.5) };
    }
    Cir make_cur(point a, point b){
    	point c = { (a.x + b.x) * 0.5, (a.y + b.y) * 0.5};
    	return Cir(c, kc(a,b) * 0.5);
    }
    Cir make_cur(point a, point b, point c){
    	ld a1 = b.x - a.x, a2 = b.y - a.y, a3 = c.x - a.x, a4 = c.y - a.y;
    	point d = DtNgTiep({a1,a2}, {a3,a4});
    	d.x += a.x;
    	d.y += a.y;
    	return {d, kc(d, a)};
    }
    bool nt(Cir a, point b){
    	return kc(a.A, b) <= a.Rad;
    }
    bool real(Cir a, point h[], int m){
    	fod(i,1,m){
    		if(!nt(a, h[i])) return 0;
    	}
    	return 1;
    }
	void inp(){
		cin >> n;
		fod(i,1,n) cin >> a[i].x >> a[i].y;
		if(n == 1){
			cout << setprecision(3) << fixed << (ld) 0;
			kill();
		}
	}
	void sub1(){
		sort(a+1,a+n+1,cmp);
		p1 = a[1];
		a[n+1] = a[1];
		sort(a+2,a+n+1,cmp2);
		h[1] = a[1]; h[2] = a[2];
		m = 2;
		fod(i,3,n+1){
			while(m >= 2 and ccw(h[m-1], h[m], a[i]) <= 0) m--;
			h[++m] = a[i];
		}
		m--;
		Cir res({-1,-1}, 22022007);
		fod(i,1,m-1) fod(j,i+1,m){
			Cir t = make_cur(h[i], h[j]);
			if(real(t, h, m)){
				if(res.Rad == 22022007){
					res = t;
					continue;
				}
				if(res.Rad > t.Rad) res = t;
			}
		}
		fod(i,1,m-2) fod(j,i+1,m-1) fod(k,j+1,m){
			Cir t = make_cur(h[i], h[j], h[k]);
			if(real(t, h, m)){
				if(res.Rad == 22022007){
					res = t;
					continue;
				}
				if(res.Rad > t.Rad) res = t;
			}
		}
		cout << setprecision(3) << fixed << res.Rad << el;
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