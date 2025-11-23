#include <algorithm>
#include <vector>
#include <unordered_set>
class Solution_128 {
public:
    int longestConsecutive(std::vector<int>& nums) {
    
        std::unordered_set<int> uset(nums.begin(), nums.end());
        int ans = 0;
        for (auto& num : uset) {
            if (uset.contains(num - 1)) {
                continue;

            }
            int currentNum = num + 1;
            while (uset.contains(currentNum)) {
                currentNum++;
            }
            ans = std::max(ans, currentNum - num);
            if (ans * 2 >= uset.size()) {
                break;
            }
        }
        return ans;
    }
};

void test_128() {
    std::vector<int> nums = LeetcodeInput::readArray1D(std::cin);
    Solution_128 so128;
    int ans = so128.longestConsecutive(nums);
    debug(ans);
}