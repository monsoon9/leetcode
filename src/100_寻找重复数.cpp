#include <vector>
#include <algorithm> // 用于 std::swap

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 遍历数组，将数字放回属于自己的位置 nums[i] == i + 1
        for (int i = 0; i < nums.size(); ++i) {
            // 当 nums[i] 还在它自己的位置时，不需要处理
            // 当 nums[i] 已经等于 nums[nums[i] - 1] 时，说明找到了重复
            while (nums[i] != i + 1) {
                if (nums[nums[i] - 1] == nums[i]) {
                    return nums[i]; // 发现目标数字
                }
                // 否则，将数字交换到属于它的位置
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return -1;
    }
};



#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        
        // 1. 第一阶段：寻找相遇点
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // 2. 第二阶段：寻找入口
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};