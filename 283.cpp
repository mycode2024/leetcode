#include <vector>

class Solution_283 {
public:
    void moveZeroes(std::vector<int>& nums) {
        int index= 0 ;
        for (auto& a : nums) {
            if (a) {
                std::swap(a, nums[index++]);
            }
        }
    }
};