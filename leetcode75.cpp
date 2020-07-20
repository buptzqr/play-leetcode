#include <vector>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // 三路快排的思路
        // [0,zero]=0 [zero+1,i)=1 [two,r]=2
        int zero = -1;
        int two = nums.size();
        int i = 0;
        while (i < two)
        {
            if (nums[i] == 0)
            {
                swap(nums[zero + 1], nums[i]);
                i++;
                zero++;
            }
            else if (nums[i] == 1)
                i++;
            else
            {
                swap(nums[two - 1], nums[i]);
                two--;
            }
        }
    }
    void sortColorsV2(vector<int> &nums)
    {
        // 双指针思路
        // zero表示第一个不为0位置，one表示第一个不为1的位置
        // 这样做的好处是可以让zero和one尽可能多的移动，而不需要交换操作
        // leetcode实际提升不明显
        int zero = 0;
        while (nums[zero] == 0)
        {
            zero++;
            if (zero >= nums.size())
                return;
        }
        int one = zero;
        while (nums[one] == 1)
        {
            one++;
            if (one >= nums.size())
                return;
        }
        int i = one;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[zero]);
                if (zero == one)
                    one++;
                zero++;
            }
            else if (nums[i] == 1)
                swap(nums[i++], nums[one++]);
            else
                i++;
        }
    }
};