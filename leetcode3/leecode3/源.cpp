#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int freq[256] = { 0 };

		int l = 0, r = -1; // sliding window: s[l...r]
		int res = 0;

		while (r + 1 < s.size()){

			if (freq[s[r + 1]] == 0)
				freq[s[++r]] ++;
			else    //freq[s[r+1]] == 1
				freq[s[l++]] --;

			res = max(res, r - l + 1);
		}

		return res;
	}
};
int main(){
	Solution s;
	string k = "pwwkew";
	int res=s.lengthOfLongestSubstring(k);
	cout << res << endl;
	getchar();

}