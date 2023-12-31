// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to count number of substrings
// having atleast k distinct characters
void atleastkDistinctChars(string s, int k)
{
	// Stores the size of the string
	int n = s.size();

	// Initialize a HashMap
	unordered_map<char, int> mp;

	// Stores the start and end
	// indices of sliding window
	int begin = 0, end = 0;

	// Stores the required result
	int ans = 0;

	// Iterate while the end
	// pointer is less than n
	while (end < n) {

		// Include the character at
		// the end of the window
		char ch = s[end];
		mp[ch]++;

		// Increment end pointer by 1
		end++;

		// Iterate until count of distinct
		// characters becomes less than K
		while (mp.size() >= k) {

			// Remove the character from
			// the beginning of window
			char pre = s[begin];
			mp[pre]--;

			// If its frequency is 0,
			// remove it from the map
			if (mp[pre] == 0) {
				mp.erase(pre);
			}

			// Update the answer
			ans += s.length() - end + 1;
			begin++;
		}
	}

	// Print the result
	cout << ans;
}

// Driver Code
int main()
{
	string S;
	cin >> S;
	int K = 2;
	atleastkDistinctChars(S, K);

	return 0;
}
