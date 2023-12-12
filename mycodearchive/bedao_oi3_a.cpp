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
#define name "trie"
#define ld long double
// remember to reset value for multitestcase
// she is your motivation!!!
void init(){
    
}
#define pis pair<int,string>
int n;
vector <pis> adj[base]; 
void inp(){
	cin >> n;
	fod(i,1,n-1){
		int u, v;
		string c; cin >> u >> v >> c;
		adj[u].pb(pis(v,c));
		adj[v].pb(pis(u,c));
	}
}
namespace sub_task1{
	void solve(){
		int res = 0;
		fod(i,1,n){
			if(adj[i].size() == 1){res++; continue;}
			string x;
			bool ch = 0;
			for(auto [v,w] : adj[i]) if(x == w) ch = 1; else x = w;
			if(ch == 0) res++;
		}
		cout << res;
	}
		
}
namespace sub_task2{
    bool bfs(int u){
    	set <string> mp;
    	queue <pis> q;
    	q.push(pis(u, ""));
    	vector <int> par(n + 1);
    	par[u] = 0;
    	while(!q.empty()){
    		int u = q.front().fi;
    		string s = q.front().se;
    		q.pop();
    		for(auto [v,w] : adj[u]) if(v != par[u]){
    			string new_s = s + w;
    			if(mp.find(new_s) != mp.end()) return 0;
    			mp.insert(new_s);
    			q.push(pis(v, new_s));
    			par[v] = u;
    		}
    	}
    	return 1;
    }
    void solve(){
    	int res = 0;
		fod(i,1,n){
			if(bfs(i)) res++;
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
        int root = 0, ma = 0;
		fod(i,1,n){
			maxi(ma, (int) adj[i].size());
		}
        if(ma > 2) sub_task2 :: solve();
    	else if(ma <= 2) sub_task1 :: solve();
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
