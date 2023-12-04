#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
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
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y, id;
};
struct edge{
	int u, v, c;
};
void tell(){
	cerr << "\nTime: " << clock() << "ms\n";
}
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
multiset <int> ms;
int n, a[base], f[base], total = 0;
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
	cin >> n;
	fod(i,1,n) cin >> a[i], total += a[i];
	int diff = 0, sec = 0, save = 1e9, times = 0;
	diff = total/n;
	sort(a+1,a+n+1);
	// sub1 :while(1){
	// 	int begin = *ms.begin(), end = *ms.rbegin();
	// 	// cout << begin << " " << end << endl;
	// 	int val = end - begin;
	// 	if(val == diff){
	// 		cout << sec;
	// 		tell();
	// 		return 0;
	// 	}
	// 	sec++;
	// 	ms.erase(ms.find(begin)); ms.erase(ms.find(end));
	// 	ms.insert(begin + 1);
	// 	ms.insert(end - 1);
	// }
	fod(i,1,n) f[i] = diff;
	int r = total % n, i = n;
	while(r--) f[i]++, i--;
	fod(i,1,n) sec += abs(f[i] - a[i]);
	cout << sec/2;
	cerr << "\nTime: " << clock() << "ms\n";
	cerr << "Sit down and code";
	return 0;
}
