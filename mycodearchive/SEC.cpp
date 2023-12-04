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
int f[base], m, n;
string a[base], b[base];
struct Node{
    int cnt = 0, exist = 0;
    vector <int> id;
    Node* child[MAX_CHAR];
    Node(){
        cnt = 0;
        fod(i,0,MAX_CHAR-1){
            child[i] = NULL;
        }
    }
};
void add(Node* root, const string& s, int id) {
    Node* cur = root;
    Node* tmp = cur;
    for (char c : s){
        int idx = c - 'a';
        if(cur->child[idx] == NULL) {
            cur->child[idx] = new Node();
        }
        cur = cur->child[idx];
        cur->id.pb(id);
        cur->cnt++;
    }
    cur->exist++;
}
int count(Node* root, const string& s) {
    Node* cur = root;
    for (char c : s) {
        int idx = c - 'a';
        if (cur->child[idx] == NULL) {
            // continue;
            return 0;
        }
        cur = cur->child[idx];
    }
    // fod(i,0,cur->id.size()-1){
    // 	cout << cur->id[i] << endl;
    // 	int j = cur->id[i];
    // 	f[j]++;
    // }
    return cur->cnt;
}
void get(Node* root, const string& s) {
    Node* cur = root;
    for (char c : s) {
        int idx = c - 'a';
        if (cur->child[idx] == NULL) {
            // continue;
            return;
            // return 0;
        }
        cur = cur->child[idx];
    }
    fod(i,0,cur->id.size()-1){
    	// cout << cur->id[i] << endl;
    	int j = cur->id[i];
    	f[j]++;
    }
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> m >> n;
	Node* root = new Node();
	Node* home = new Node();
	fod(i,1,m){
		int size; cin >> size;
		string str;
		fod(i,1,size){
			char c; cin >> c;
			str += c;
		}
		a[i] = str;
		// mp[str]++;
		add(root, a[i], i);
		// mp[str]++;
		// cout << a[i] << endl;3
	}
	// cout << mp["1"] << endl;
	fod(i,1,n){
		int size; cin >> size;
		string str;
		fod(i,1,size){
			char c; cin >> c;
			str += c;
		}
		b[i] = str;
		// cout << str << endl;
		f[i] = count(root,b[i]);
	}
	// cout << mp["1"];
	fod(i,1,n){
		add(home,b[i], i);
	}
	fod(i,1,m){
		get(home, a[i]);
	}
	// get(home, "110");
	// count(root,"11");
	fod(i,1,n){
		cout << f[i] << endl;
	}
	return 0;
}
