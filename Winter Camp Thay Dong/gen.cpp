#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {

    // quicktest passes a seed as an argument: $ ./gen seed testcase
    int seed = stoi(string(argv[1]));
    srand(seed);

    const int N = int(1e9);
    const int K = int(9);
    const int Q = int(1e2);
    const int T = int(2);
    int n = rand() % N + 1;
	int k = rand() % K  + 1;
	int q = rand() % Q + 1;
	cout << n << " " << k << " " << q << endl;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 10000);

    for(int i = 1; i <= q; i ++){
    	int type = rand() % T + 1;
    	type = 2;
    	if(type == 1){
    		int l = rand() % n + 1;
    		int c = rand() % n + 1;
    		cout << type << " " << l << " " << c << endl; 
    	}
    	else{
    		int l = rand() % n + 1;
    		int r = min(n, rand() % n + l + 1);
    		cout << type << " " << l << " " << r << endl;
    	}
        // int a = distribution(generator);
        // int b = distribution(generator);
		// cout << a << " " << b << endl;
    }
    return 0;
}