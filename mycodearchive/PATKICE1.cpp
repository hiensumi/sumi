// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define mask(i) (1LL<<(i))
#define BITpos(a,i) ((a >> i) & 1LL)
#define pb push_back
#define el '\n'
#define all(v) v.begin(), v.end()
#define odd(i) (i & 1LL)
using namespace std;
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;
inline void kill(){cerr << "\nTime: " << clock() << "ms\n"; cerr << "⏁⊑⟒ ⋔⍜⍜⋏ ⍙⏃⌇ ⌇⍜ ⏚⟒⏃⎍⏁⟟⎎⎍⌰ ⏁⊑⏃⏁ ⏁⊑⟒⍀⟒ ⍙⏃⌇ ⏃ ⋔⟟⍀⍀⍜⍀ ⟟⋏ ⏁⊑⟒ ⍜☊⟒⏃⋏.\n"; exit(0);}
inline void add(int &x, int y, int mod = MOD) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod;}
inline void mul(int &x, int y, int mod = MOD) { x = (x * 1LL * y) % mod;}
inline int bpow(int x, int y, int mod = MOD) { int ans = 1; while (y) { if (y & 1) mul(ans, x, mod); mul(x, x, mod); y >>= 1;} return ans;}
inline int bp(int a, int b){int res = 1; while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
inline int Inv(int x, int mod = MOD) { return bpow(x, mod - 2, mod);}
inline int Div(int x, int y, int mod = MOD) { int tmp = x; mul(tmp, Inv(y, mod), mod); return tmp;}
template<class T> bool mini(T& a,T b){return (a>=b)?a=b,1:0;}
template<class T> bool maxi(T& a,T b){return (a<=b)?a=b,1:0;}
struct point{int x, y;};
struct edge{int u, v, c;};
//int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
//bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
const ll INF = 1e18, base = 1e6 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, m, a[105][105];
vector <ii> dir = { {0,0}, {-1,0}, {1,0}, {0,-1}, {0,1}};
ii st, en;
int dis[105][105];
void inp(){
	cin >> n >> m;
	fod(i,1,n) fod(j,1,m){
		char c; cin >> c;
		if(c == '<') a[i][j] = 3;
		if(c == '>') a[i][j] = 4;
		if(c == '^') a[i][j] = 1;
		if(c == 'v') a[i][j] = 2;
		if(c == '.') a[i][j] = 0;
		if(c == 'o') a[i][j] = -1, st = ii(i,j);
		if(c == 'x') a[i][j] = -2, en = ii(i,j);
	}
}

namespace sub_task1{
	int dd[105][105];
	int hn[5];
	int nt(int x, int y){
		return 1 <= x and x <= n and 1 <= y and y <= m;
	}
	char change(int x){
		if(x == 0 or x == -1 or x == -2) return 'z';
		if(x == 1) return 'N';
		if(x == 2) return 'S';
		if(x == 3) return 'W';
		return 'E';
	}
	bool check(int i, int j){
		return a[i][j] <= 0 or ii(i,j) == en;
	}
	void dfs(int u, int v){
		if(check(u,v) or dis[u][v] == 0) return;
		// cout << u << " " << v << el;
		int di = a[u][v];
		int x = u + dir[di].fi, y = v + dir[di].se;
		if(dis[x][y] > dis[u][v] + 1){
			dis[x][y] = dis[u][v] + 1;
			dfs(x,y);
		}
	}
    void solve(){
    	int res = INF;
    	char c;
    	fod(i,1,4){
    		fod(u,1,n) fod(v,1,m) dis[u][v] = INF;
    		dis[st.fi][st.se] = 0;
    		int u = st.fi + dir[i].fi, v = st.se + dir[i].se;
    		dis[u][v] =  1;
    		dfs(u,v);
    		// cout << el;
    		if(res > dis[en.fi][en.se]) res = dis[en.fi][en.se], c = change(i);
    		if(res == dis[en.fi][en.se]) if(change(i) < c) c = change(i);
    	}
    	
    	if(res == INF) cout << ":(";
    	else{
    		cout << ":)" << el;
    		cout << c;
    	}
    }	
    
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(name".inp", "r")){
      freopen(name".inp", "r", stdin);
      freopen(name".out", "w", stdout);
    }
    int Test = 1; if(multitest) cin >> Test;
    init();
    while(Test--){
        inp();
        sub_task1 :: solve();
    }
    kill();
}
/*
										Trú mưa nơi gốc cây ngày xưa
										Để nhìn em lần cuối trong mưa
										Để nắm tay đưa em đi về
										Chốn mộng mơ...
										
										Có hôm mây gió chợt ca vang
										Nụ cười em như nắng mùa thu sang
										Làm lòng tôi xao xuyến mà lang thang
										Nghĩ về em...
										
										Mình tôi thao thức
										mình tôi day dứt
										Cớ sao em không về với tôi 
										Mình tôi thao thức
										mình tôi day dứt
										Cớ sao em không cười với tôi
										Gió mang câu ca về nơi đây
										gió mang câu ca về với đời em
										Nắng mang câu thơ về nơi đây
										chính em mang thơ về với tình ta ...
										
										Chiếc radio của em
										Và từng ly trà đá ly kem
										Cùng hát lên câu ca êm đềm
										giữa mùa yêu
										
										Những bông hoa xanh ngoài hiên
										Vào buổi chiều tràn nắng an nhiên
										Ta ngồi bên cạnh nhau 
										ngắm mùa thu sang...
*/
