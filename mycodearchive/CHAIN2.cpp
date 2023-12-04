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
const int base = 1e6 + 5;
const int MAX_CHAR = 26;
int nodec = 1, n, f[base], t[base][27], exist[base];
string a[base];
void add(const string& s){
	int cur = 1;
	fod(i,0,s.size()-1){
		int j = s[i] - 'a';
		if(t[cur][j] == 0){
			t[cur][j] = ++nodec;
		}
		cur = t[cur][j]; 
	}
	exist[cur] = 1;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n) cin >> a[i], add(a[i]);
	fok(i,nodec,1){
		fod(j,0,25){
			if(t[i][j] != 0){
				f[i] = max(f[i], f[t[i][j]]);
				cout << i << " " << t[i][j] << endl;
			}
		}
		f[i] += exist[i];
	}
	// fod(i,0,nodec) cout << f[i] << endl;
	// cout << f[0];
	return 0;
}
