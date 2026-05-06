#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. 从后向前找到第一个升序对 (i, i+1)，即 nums[i] < nums[i+1]
        // 注意：你的代码写的是 nums[i-1] > nums[i]，这其实是在找降序对
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // 2. 找到第一个比 nums[i] 大的数进行交换
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // 3. 将 i 后面的序列反转（如果是降序，直接变为升序）
        reverse(nums.begin() + i + 1, nums.end());
    }
};