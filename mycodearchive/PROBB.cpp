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
int tong(int n, int d){
	int sum = 0;
	fod(i,1,sqrt(n)){
		if(n % i == 0){
			if( i * i == n) sum += i;
			else if(i != 1) sum += i + n/i;
			else sum += i;
			// if(abs(sum - n) > d and sum - n) return 0;
			// if(abs(sum -n) > d) return 0;
			if(n == 4){
				cout << sum << endl;
				return 0;
			}
		}
	}
	return abs(sum - n) <= d;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	int l, d;
	cin >> l >> d;
	int cnt = 0;
	fod(i,1,l){
		if(tong(i,d)){
			cnt++;
			// cout << i << endl;	
		} 
	}
	// cout << cnt;
	return 0;
}
