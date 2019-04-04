#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Two Pointers
///Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
	int removeElement(vector<int>& nums, int val) {

		int i = 0;
		int j = nums.size();
		while (i < j){
			if (nums[i] == val){
				swap(nums[i], nums[j-1]);
				j--;
			}
			else
				i++;
		}
		return i;
	}
};


int main() {

	vector<int> nums = { 3, 2, 2, 3 };
	int val = 3;

	cout << Solution().removeElement(nums, val) << endl;
	getchar();
	getchar();
	return 0;
}