// hiensumi is on the sky
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
#include<time.h>
#include<utility>
#include<vector>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define db double
#define mask(i) (1LL<<(i))
#define pb push_back
#define el '\n'
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
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { return prod(x, Inv(y, mod), mod);}
const int base = 1e6 + 5;
// dont use write like write("abc"). use it like write(x). x is the string variable
// dont use write like write(5). use it like write((int) 5). write(1e18) or any other float variables is fine
int x, mi = 1e18, l, r;
int trans(string x){
	int res = 0;
	for(char c : x) res = res * 10 + (c - '0');
	return res;
}
int dp[19][2][18 * 9 + 1];
int solve(int i, int tight, int sum, string a){
    if(i == a.size()){
        if(sum == x){
        	// cout << val << el;
        	return 1;
        }
        else return 0;
    }
    if(dp[i][tight][sum] != -1) return dp[i][tight][sum];
    int limit = tight ? 9 : a[i] - '0';
    int cnt = 0;
    fod(j,0,limit){
        if(tight == 0 && j == a[i] - '0'){
            cnt += solve(i + 1,0, sum + j, a);
        }
        else {
            cnt += solve(i + 1,1, sum + j, a);
        }
    }
    return dp[i][tight][sum] = cnt;
}
string helper(int d, int s) {
    string ans(d, '0');
    fok(i, d - 1, 0) {
        if (s >= 9) {
            ans[i] = '9';
            s -= 9;
        } else {
            char c = (char)s + '0';
            ans[i] = c;
            s = 0;
        }
    }
    return ans;
}
string find(int x, int Y){
    string y = to_string(Y);
    int n = y.size();
    vector<int> p(n);
    fod(i, 0, n - 1){
        p[i] = y[i] - '0';
        if (i > 0)
            p[i] += p[i - 1];
    }
    fok(i, n - 1, 0){
        int d = 0;
        if (i >= 0)
            d = y[i] - '0';
        fod(j, d + 1, 9){
            int r = (i > 0) * p[i - 1] + j;
            if (x - r >= 0 && x - r <= 9 * (n - 1 - i)){
                string suf = helper(n - 1 - i, x - r);
                string pre = "";
                if (i > 0)
                    pre = y.substr(0, i);
                char cur = (char)j + '0';
                pre += cur;
                return pre + suf;
            }
        }
    }
}
int get(int n){
	string a = to_string(n);
    memset(dp, -1, sizeof dp);
    return solve(0, 0, 0, a);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> l >> r >> x;
	int ans = get(r) - get(l-1);
	cout << ans << el;
	if(ans > 0) cout << find(x,l);
	// if(ans != 0){
	// 	int u = to_string(l).size();
	// 	int v = to_string(r).size();
	// 	fod(len,u+1,v){
	// 		string p = find1(x,len);
	// 		if(p != ""){
	// 			mi = min(mi, trans(p));
	// 			// break;
	// 		}
	// 	}
	// 	messi("", u, x);
	// 	// mi = min(mi, find2);
	// 	cout << mi;
	// }
	kill();
	return 0;
}	