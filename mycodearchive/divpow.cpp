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
// #define int long long
#define fi first
#define se second
// 0x3f is duong vo cung. use this pls
#define name "divpow"
#define non 5000+1
#define pog 1000000000+7
#define pb push_back
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
// const int oo = 1e18 + 1 + 2 + 3 + 4 + 5 + 12345678910;
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
const int base = 3e6 + 300;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define ull unsigned long long
bool notprime[base + 2];
vector <int> primes;
ll getSQRT(ull n){
	ll x = sqrt(n);
	fod(i,-3,3){
		if(x + i >= 0 and 1ULL * (x + i) * (x + i) == n) return x + i;
	}
	return -1;
}	
void sieve(){
	notprime[0] = notprime[1] = 1;
	for(int i = 2 ; i  * i <= base; i++) if(!notprime[i]){
		for(ll j = 1LL * i * i ; j <= base; j += i) notprime[j] = 1;
	}
	fod(i,2,base) if(!notprime[i]) primes.pb(i);
}
const ull INF = (ull) 1e19 + 7;
int CntDiv[base + 2];
ull Product(ull a, ull b){
	if(a == 0 or b == 0) return 0;
	if(INF/a < b) return INF;
	return a * b;
}
ull Pow(int a, int b){
	ull res = 1;
	fod(i,1,b){
		res = Product(res, a);
		if(res >= INF) return INF;
	}
	return res;
}
vector <pair <ull,int>> v;
void init(){
	sieve();
	for(int i = 1; i * i <= base; i ++){
		CntDiv[i*i]--;
		for(long long j = 1LL * i * i; j <= base; j += i) CntDiv[j] += 2;
	}
	fod(i,1,base){
		ull tmp = Pow(i, CntDiv[i]);
		if(tmp < INF) v.pb({tmp,i});
	}
	sort(v.begin(), v.end());
}
int tknp(ull s){
	int l = 0, r = v.size() - 1, ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(v[mid].fi >= s) ans= mid, r= mid - 1;
		else l = mid + 1;
	}
	if(v[ans].fi == s) return v[ans].se;
	return -1;
}
bool isprime(ull x){
	if(x <= base) return !notprime[x];
	for(int p : primes){
		if(1LL * p * p > x) return 1;
		if(x % p == 0) return 0;
	}
	return 1;
}
namespace subtaskfull{
	void solve(){
		ull s; cin >> s;
		ll sq = getSQRT(s);
		if(sq != -1 and isprime(sq)){
			cout << sq << el;
			return;
		}
		cout << tknp(s) << el;
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
	int t; cin >> t;
	init();
	while(t--){
		subtaskfull::solve();
	}
	kill();
}