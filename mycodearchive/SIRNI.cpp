// hiensumi: Maybe, success will come tomorrow. Thus, just keep trying! =) "Z/x
#include "bits/stdc++.h"
#include <cassert>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
// #define int long long
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
const ll INF = 1e18, base = 1e7 + 5, multitest = 0;
//"Life is a daring adventure or it is nothing at all." -Helen Keller...
//"Success isn't determined by how many times you win, but by how you play the week after you lose." -Pele...
#define name ""
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
int n, p[base], dd[base], lab[base];
vector <int> nxt(1e7 + 2, 1e9);
vector <edge> e;
void inp(){
	cin >> n; fod(i,1,n) cin >> p[i], nxt[p[i]] = p[i];
	sort(p + 1, p + n + 1);
	fok(i,1e7, 0) mini(nxt[i], nxt[i+1]), lab[i] = -1;
	fod(h,1,n-1) if(dd[p[h]] == 0){
		int i = p[h];
		int v = nxt[i+1];
		dd[i] = 1;
		if(v <= p[n]){
			e.pb({i,v,v-i});
		}
		for(int j = 2 * i; j <= p[n]; j += i){
			int v = nxt[j];
			if(v - j < i) e.pb({i,v,v-j});
		}
	}
}
namespace sub_task1{
	bool cmp(edge a, edge b){
		return a.c < b.c;
	}
	int find(int u){if (lab[u] < 0) return u; return lab[u] = find(lab[u]);}
	bool join(int u, int v){u = find(u);v = find(v);if(u == v) return 0;if(lab[u] > lab[v]) swap(u,v);lab[u] += lab[v];lab[v] = u; return 1;}
    void solve(){
		sort(all(e), cmp);
		int res = 0;
		for(edge x : e){
			if(join(x.u, x.v)) res += x.c;
		}
		cout << res;
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
#listening to her music while coding is great
*/
