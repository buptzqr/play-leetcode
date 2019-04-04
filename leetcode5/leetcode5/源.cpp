#include<string>
#include<iostream>
using namespace std;
class Solution {
	/*
	事实上，只需使用恒定的空间，我们就可以在 O(n^2) 的时间内解决这个问题。

	我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有 2n - 1 个这样的中心。

	你可能会问，为什么会是 2n - 1 个，而不是 n 个中心？原因在于所含字母数为偶数的回文的中心可以处于两字母之间。
	写一个中心扩展函数告诉他左起始坐标和右起始坐标
	*/
public:
	string longestPalindrome(string s) {
		if (s.length() == 0)
			return "";
		int start = 0;
		int end = 0;
		for (int i = 0; i < s.length()-1; i++){
			int len1 = expandcenter(i, i, s,false);
			int len2 = expandcenter(i, i + 1, s,true);
			int len;
			bool flag = false;
			if (len1 >= len2){
				len = len1;
				flag = true;
			}
			else
				 len = len2;
			if (len > end - start + 1){
				if (flag){
					start = i - len / 2;
					end = i + len / 2;
				}
				else{
					start = i - len / 2 + 1;
					end = i + len / 2 ;
				}

			}
			
			
		}
		string res=s.substr(start, end-start+1);
		return res;
	}
private:
	int expandcenter(int left,int right,string s,bool flag){
		if (flag)
			if (s[left] != s[right])
				return 0;
		while (left -1>= 0 && right+1 < s.length()&&s[left-1] == s[right+1]){
			left--;
			right++;
		}
		return right - left + 1;
	}
};
int main(){
	Solution s;
	string k = "cbbd";
	string res=s.longestPalindrome(k);
	cout << res;
	getchar();
	getchar();

}