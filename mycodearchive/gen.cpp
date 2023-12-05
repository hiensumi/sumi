#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {

    // quicktest passes a seed as an argument: $ ./gen seed testcase
    int seed = stoi(string(argv[1]));
    srand(seed);

    const int N = int(4000);

    // int n = N, t = 1e4;
    int n = rand() % N + 1;
	cout << n << endl;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 10000);

    for(int i = 1; i <= n; i ++){
        int a = distribution(generator);
        int b = distribution(generator);
		cout << a << " " << b << endl;
    }
    return 0;
}