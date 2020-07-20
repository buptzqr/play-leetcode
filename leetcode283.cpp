#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
                if (i != k) //这步优化是为了避免nums中都是非零元素
                    swap(nums[k++], nums[i]);
                else
                    k++;
        }
    }
};