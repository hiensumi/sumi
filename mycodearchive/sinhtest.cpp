#include <bits/stdc++.h>
using namespace std;
<<<<<<< Updated upstream
#define fod(i,a,b) for(int i = a; i <= b;i ++)
#define el '\n'
#define int long long
int rd(int l, int r){
	return rand() * rand() % (r - l + 1) + l ;
}
const string name = "";
const int ntest = 0;
signed main(){
	srand(time(0));
	fod(i,1,ntest){
		
		ofstream cout( (name + ".inp").c_str());
		
		
		cout.close();
	}
=======
#define fod(i,a,b) for(int i = a; i <= b; i++)
#define int long long
#define el "\n"
int rd(int l, int r){
	assert(l <= r);
	return  l + 1ll * rand() * rand() % (r - l + 1);
}
const int NTest = 100;
const string name = "RECS";
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(0));
	system( ("g++ -std=gnu++14 " + name + ".cpp " + "-o " + name).c_str());
	system( ("g++ -std=gnu++14 " + name + "_trau.cpp " + "-o " + name + "_trau").c_str());
	fod(i,1,NTest){
		ofstream cout((name + ".inp").c_str());
		// gen
		int n = rd(1,100);
		cout << n << el;
		fod(i,1,n){
			fod(i,1,6) cout << rd(1,100) << " ";
			cout << el;
		}
		cout.close();
		system(("./" + name).c_str());
		system(("./" + name + "_trau").c_str());
		
		if(system(("diff" + name + ".out " + name + ".ans").c_str()) != 0){
			cerr << "Test " << i << ": WA!\n";
			return 0;
		}
		cerr << "Test " << i << ": AC!\n";
	}
	
	return 0;
>>>>>>> Stashed changes
}