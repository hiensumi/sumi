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
const ll INF = 1e18;
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
const int base = 1e5 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
namespace solution{
	int n;
	struct bg{
		int st, en, val;
	}a[base];
	bool cmp(bg a, bg b){
		return a.en < b.en;
	}
	void inp(){
		cin >> n;
		fod(i,1,n) cin >> a[i].st >> a[i].en, a[i].val = a[i].en - a[i].st;
	}
	int dp[base];
    int b[base], ma[base], st[4*base];
	void build(int i, int l, int r){
        if(l == r){
            st[i] = - 2 * a[l].en;
            return;
        }
        int mid = l + r >> 1;
        build(2*i,l,mid);
        build(2*i+1,mid+1,r);
        st[i] = max(st[2*i], st[2*i+1]);
    }
    void upd(int i, int l, int r, int u, int v, int x){
        if(r < u or v < l) return;
        if(u <= l and r <= v){
            st[i] = x;
            return;
        }
        int mid = l + r >> 1;
        upd(2*i,l,mid,u,v,x);
        upd(2*i+1,mid+1,r,u,v,x);
        st[i] = max(st[2*i], st[2*i+1]);
    }
    int get(int i, int l, int r, int u, int v){
        if(r < u or v < l) return -INF;
        if(u <= l and r <= v){
            return st[i];
        }
        int mid = l + r >> 1;
        int getl = get(2*i,l,mid,u,v);
        int getr = get(2*i+1,mid+1,r,u,v);
        return max(getl, getr);
    }
    void sub1(){
		sort(a+1,a+n+1,cmp);
        fod(i,1,n) b[i] = a[i].en;
        build(1,1,n);
		fod(i,1,n){
            int j = upper_bound(b + 1, b + n + 1, a[i].st) - b;
            j--;
            dp[i] = ma[j] + a[i].en - a[i].st;
            // dp[i] = max(dp[i], )
            // if(j + 1 > i - 1){ma[i] = max(ma[i-1], dp[i]); continue;}
            int val = get(1,1,n,j+1,i-1);
            
            if(j + 1 <= i - 1) dp[i] = max(dp[i], val + a[i].en + a[i].st);
            upd(1,1,n,i,i,dp[i] - 2 * a[i].en);
            // fod(k,j+1,i-1) dp[i] = max(dp[i], dp[k] - 2 * a[k].en + a[i].en + a[i].st);
            ma[i] = max(ma[i-1], dp[i]);
        }
		int res = 0;
		fod(i,1,n) res = max(res, dp[i]);
		cout << res << el;
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