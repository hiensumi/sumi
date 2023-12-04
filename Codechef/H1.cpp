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
const int base = 1e6 + 5;
const bool multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name "H1"
namespace solution{
    map <string,int> mp;
    map <ii,int> id;
    int nt[21];
    ii pos[10];
    int d1[] = {0,1};
	int d2[] = {1,0};
	int num(char c){
		return c - '0';
	}
	void inp(){
		string source = "#123456789";
		queue <string > q;
		q.push(source);
		mp[source] = 0;
		nt[2] = nt[3] = nt[5] = nt[7] = nt[11] = nt[13] = nt[17] = 1;
		pos[1] = {1,1}; pos[2] = {1,2}; pos[3] = {1,3}; pos[4] = {2,1}; pos[5] = {2,2}; pos[6] = {2,3}; pos[7] = {3,1}; pos[8] = {3,2}; pos[9] = {3,3};
		fod(i,1,9) id[pos[i]] = i;
		while(q.size()){
			string p = q.front();
			q.pop();
			// cout << p << el;
			fod(i,1,9){
				int x = pos[i].fi, y = pos[i].se;
				fod(k,0,1){
					int u = x + d1[k], v = y + d2[k];
					int j = id[{u,v}];
					if(j == 0) continue;
					if(nt[num(p[i]) + num(p[j])]){
						string t = p;
						swap(t[i], t[j]);
						if(mp.find(t) == mp.end()){
							mp.insert({t,mp[p] + 1});
							q.push(t);
						}
					}
				}
			}
		}
	}
	void sub1(){
		int t; cin >> t;
		fod(i,1,t){
			string x = "";
			fod(j,1,9){
				char m; cin >> m;
				x = x + m;
			}
			// cout << x << el;
			if(x == "123456789"){
				cout << 0 << el;
				continue;
			}
			x = "#" + x;
			if(mp[x]) cout << mp[x] << el;
			else cout << -1 << el;
		}
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