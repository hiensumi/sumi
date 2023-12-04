#include <bits/stdc++.h>
using namespace std;
#define uwu ""
typedef long long ll;
#define pb push_back
#define endl '\n'
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b;i--)
const int N=2e3+3;
const ll INF=1e17+7;

string a, b;
int n, m;

bool dda[N], ddb[N];
int f[N][N];

void input(){
	cin >> a >> b;
	n = a.size(); m = b.size();
	a =  "#" + a; b  = "#" + b;
}
void prep(void){
	input();
}
void mini(int &u, int v){
	u = min(u, v);
}
void solve(void){
	FOR(i, 2, n){
		string tmp = ""; tmp += a[i - 1]; tmp += a[i];
		dda[i] = (tmp == "aA" || tmp == "Aa" || tmp == "bB" || tmp == "Bb");
	}
	FOR(i, 2, m){
		string tmp = ""; tmp += b[i - 1]; tmp += b[i];
		ddb[i] = (tmp == "aA" || tmp == "Aa" || tmp == "bB" || tmp == "Bb");
	}
	
	memset(f, 0x3f, sizeof(f)); f[0][0] = 0;
	FOR(i, 1, n) FOR(j, 0, m){
		if (j > 0 && a[i] == b[j]) mini(f[i][j], f[i - 1][j - 1] + 1);
		else mini(f[i][j], f[i - 1][j] + 1);
		
		if (i >= 2 && dda[i]) mini(f[i][j], f[i - 2][j]);
		if (j >= 2 && ddb[j]) mini(f[i][j], f[i][j - 2] + 2);
	}
	
	// cout << f[n][m];
	FOR(i, 1, n){
		FOR(j, 0, m) cout << f[i][j] << " ";
		cout << endl;
	}
}
signed main(){
 	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen(uwu".inp", "r")){
	   freopen(uwu".inp","r",stdin);
	   freopen(uwu".out","w",stdout);
	}

	prep(); solve();

	return 0;
}