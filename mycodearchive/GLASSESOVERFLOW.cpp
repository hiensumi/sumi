#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define name ""
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y;
};
struct edge{
	int u, v;
    vector<int> par;
    void init(int n) {
        par.resize(n + 5, 0);
        fod(i,1,n) par[i] = i;
    }
    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    bool join(int u, int v) {
        int paru = find(u), parv = find(v);
        if (paru == parv) return false;
        par[parv] = paru;
        return true;
    }	
};
const int base = 1e6 + 5;
int b[4];
struct bg{
	int n,a;
}a[4], f[4];
bool cmp(bg a, bg b){
	return a.n < b.n;
}
bool cmph(bg a, bg b){
	return a.a < b.a;
}
bool check(){
	fod(i,1,3){
		if(f[i].a != f[i].n) return 0;
	}
	return 1;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	fod(i,1,3) cin >> a[i].n;
	fod(i,1,3) cin >> a[i].a;
	fod(i,1,3) cin >> b[i];
	sort(a+1,a+4,cmp);
	sort(b+1,b+4);
	fod(i,1,3){
		if(n[i] < b[i]){
			cout << -1;
			return 0;
		}
	}
	int s1 = 0, s2 = 0;
	fod(i,1,3){
		s1 += a[i].a;
		s2 += b[i];
	}
	if(s1 != s2){
		cout << -1;
		return 0;
	}
	int d = 0;
	fod(i,1,3) f[i] = {b[i],a[i].a};
	sort(f+1,f+4);
	while(!check()){
		fod(i,1,3){
			if(f[i].a > f[i].n){
				fod(j,1,3){
					if(i != j){
						if(f[j].a < f[j].n){
							if(f[j].n - f[j].a >= f[i].a - f[i].n){
								f[j].a += f[i].a - f[i].n;
								f[i] = f[i].n;
								d++;
							}
							else{
								f[i].a -= (f[j].n - f[j].a);
								f[j].a = f[j].n;
								d++;
							}
							break;
						}
					}
				break;
			}
		}
	}
	cout << d;
	return 0;
}
