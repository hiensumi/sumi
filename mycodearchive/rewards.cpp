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
int n, m, p, q, dp[41][41][41][41];
void inp(){
	cin >> n >> m >> p >> q;
	fod(i,1,n) fod(j,1,m) fod(k,1,p) fod(t,1,q) cin >> dp[i][j][k][t];
	fod(x, 1, n) fod(y, 1, m) fod(z, 1, p) fod(t,1,q) 
			dp[x][y][z][t] += dp[x - 1][y][z][t] + dp[x][y - 1][z][t] + dp[x][y][z - 1][t] - dp[x - 1][y - 1][z][t] - dp[x - 1][y][z - 1][t] - dp[x][y - 1][z - 1][t] + dp[x - 1][y - 1][z - 1][t];
}

namespace sub_task1{
    int sum(int x, int y, int z, int u, int v, int t, int t1){
		return dp[u][v][t][t1] - dp[x - 1][v][t][t1] - dp[u][y - 1][t][t1] - dp[u][v][z - 1][t1] + dp[x - 1][y - 1][t][t1] + dp[x - 1][v][z - 1][t1] + dp[u][y - 1][z - 1][t1] - dp[x - 1][y - 1][z - 1][t1];
	}
    void solve(){
    	int t; cin >> t;
    	while(t--){
    		int x1,y1,z1,t1,x2,y2,z2,t2;
    		cin >> x1 >> y1 >> z1 >> t1 >> x2 >> y2 >> z2 >> t2;
    		int res = 0;
    		fod(t,t1,t2){
    			res += sum(x1,y1,z1,x2,y2,z2,t);
    		}
    		cout << res << el;
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
