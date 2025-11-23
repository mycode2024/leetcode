#include <vector>
#include <unordered_map>

class Solution_1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> umap;
        int i = 0;
        for (auto x : nums) {
            if (umap.find(target - x) != umap.end()) {
                return {umap[target - x], i};
            }
            umap[x] = i++;
        }
        return {};
    }
};