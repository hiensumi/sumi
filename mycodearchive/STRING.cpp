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
int k, n, f[3005][3005];
// gọi f[i][j] là đồ dài đoạn đầu con tương thích dài nhất với s1[i..n] s2[j..n] có đồ tương thích là s1i/s2[j]
string s1, s2;
bool tt(string x, string y){
	fod(i,1,n) if(abs(x[i] - y[i]) > k){
		return 0;
	}
	return 1;
}
bool check(int i, int j){
	// string x1 = s1.substr(1,i), x2 = s1.substr(i+1,j-i), x3 = s1.substr(j+1,n-j);
	ii a[] = { {0,1}, {1,i}, {i+1,j-i}, {j+1,n-j} }; 
	// vector <string> vec = {x1,x2,x3};
	// sort(vec.begin(), vec.end());
	// do{
	// 	string t = vec[0] + vec[1] + vec[2];
	// 	if(tt(t,s2)) return 1;
	// }while(next_permutation(vec.begin(), vec.end()));
	// return 0;
	sort(a+1,a+4);
	do{
		int ok = 1, idy = 1;
		fod(i,1,3){
			int idx = a[i].fi, len = a[i].se;
			if(f[idx][idy] >= len){
				idy += len;
			}
			else ok = 0;
		}
		if(ok == 1) return 1;
	}while(next_permutation(a+1,a+4));
	return 0;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	else if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> k >> s1 >> s2;
	int res = 0;
	n = s1.size();
	s1 = "#" + s1;
	s2 = "#" + s2;
	fok(i,n,1) fok(j,n,1){
		if(abs(s1[i] - s2[j]) > k) f[i][j] = 0;
		else f[i][j] = 1 + f[i+1][j+1];
	}
	fod(i,1,n-2) fod(j,i+1,n-1){
		if(check(i,j)) res++;
	}
	cout << res;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n";
	return 0;
}
