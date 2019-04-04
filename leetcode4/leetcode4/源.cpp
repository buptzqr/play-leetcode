#include<vector>
#include<iostream>
using namespace std;
class Solution {
//思路就是先排序了，然后再找中位数
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int nums1_size = nums1.size();
		int nums2_size = nums2.size();
		int p1 = 0;
		int p2 = 0;
		vector<int> nums;
		while (p1 < nums1_size&&p2 < nums2_size){
			if (nums1[p1] <= nums2[p2]){
				nums.push_back(nums1[p1]);
				p1++;
			}
			else{
				nums.push_back(nums2[p2]);
				p2++;
			}
		}
		while (p1 < nums1_size){
			nums.push_back(nums1[p1]);
			p1++;
		}
		while (p2 < nums2_size){
			nums.push_back(nums2[p2]);
			p2++;
		}
		if (nums.size() % 2 == 0){
			int median = nums.size() / 2;
			return (float(nums[median - 1]) + nums[median]) / 2;
		}
		else{
			return nums[nums.size() / 2];
		}
	}
};
int main(){
	vector<int> nums1;
	vector<int> nums2 = { 2, 3 };
	Solution s;
	int res = s.findMedianSortedArrays(nums1, nums2);
	cout << res<<endl;
	cout << 5 / 2 << endl;
	getchar();
	getchar();
}
/*public String longestPalindrome(String s) {
    if (s == null || s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = Math.max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substring(start, end + 1);
}

private int expandAroundCenter(String s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
        L--;
        R++;
    }
    return R - L - 1;
	}
	人家是传入的是边界，实际的边界不算长度，算的是边界里面的长度*/