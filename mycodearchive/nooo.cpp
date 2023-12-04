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
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
const int N = 202;

string s, p;
string ans;

int n;
int L;

int cntP[N], cntS[N];

int memo[N][N][N];

bool preCheck() {
    for (int i = 0; i < 26; ++i) cntP[i] = 0;
    for (int i = 0; i < L; ++i)
        ++cntP[p[i] - 'a'];
    for (int c = 0; c < 26; ++c) if (cntS[c] != 0)
        if (cntP[c] == 0 || cntS[c] % cntP[c] != 0 || cntS[c] / cntP[c] != (n / L)) return 0;
    return 1;
}

bool dp(int i, int j, int match) {
    if (match >= L) match -= L;
    int &ans = memo[i][j][match];
    if (ans != -1) return ans;
    if (i > j) return ans = match == 0;
    ans = 0;
    if (p[match] == s[i]) ans = dp(i + 1, j, match + 1);
    if (ans) return ans;
    if (i + L - 1 <= j) {
        for (int k = i + L - 1; k <= j; k += L) {
            ans |= dp(i, k, 0) && dp(k + 1, j, match);
            if (ans) break;
        }
    }
    return ans;
}

bool check() {
    if (!preCheck()) return 0;
    L = p.length();
    for (int i = 0; i <= n; ++i) for (int j = max(0, i - 1); j <= n; ++j) for (int k = 0; k <= L; ++k) memo[i][j][k] = -1;
    return dp(0, n - 1, 0);
}

void solve() {
    for (int i = 0; i + L <= n; ++i) {
        p = s.substr(i, L);
        if (check()) {
            if (ans == "")
                ans = p;
            else
                ans = min(ans, p);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) ++cntS[s[i] - 'a'];
    for (int i = 1; i <= n; ++i) if (n % i == 0) {
        L = i;
        solve();
        if (ans != "") break;
    }
    cout << ans << endl;
    return 0;
}
