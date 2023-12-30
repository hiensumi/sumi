#include <bits/stdc++.h>
using namespace std;
#define fod(i,a,b) for(int i = a; i <= b; i++)
#define int long long
#define el "\n"
int rd(int l, int r){
	assert(l <= r);
	return  l + 1ll * rand() * rand() % (r - l + 1);
}
const int NTest = 100;
const string name = "PRE_DOLL";
vector<int> gen(int N) { // sinh hoan vi
    vector<int> numbers(N);
    for(int i = 0; i < N; i++) {
        numbers[i] = i+1;
    }
    srand(time(NULL));
    random_shuffle(numbers.begin(), numbers.end());
    return vector<int>(numbers.begin(), numbers.begin() + N);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(0));
	system( ("g++ -std=gnu++14 " + name + ".cpp " + "-o " + name + ".exe").c_str());
	system( ("g++ -std=gnu++14 " + name + "_trau.cpp " + "-o " + name + "_trau.exe").c_str());
	fod(i,1,NTest){
		ofstream cout((name + ".inp").c_str());
		// gen
		// vector <int> x = gen(n);
		// for(int p : x) cout << p << " ";
		// cout << el;
		int n = rd(1,10);
		cout << n << el;
		fod(i,1,n){
			cout << rd(1,1e2) << " ";
		}
		cout.close();
		system((name + ".exe").c_str());
		system((name + "_trau.exe").c_str());
		
		if(system(("fc " + name + ".out " + name + ".ans").c_str()) != 0){
			cerr << "Test " << i << ": WA!\n";
			return 0;
		}
		cerr << "Test " << i << ": AC!\n";
	}
	
	return 0;
}