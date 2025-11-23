#include <vector>

class Solution_11 {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int result = 0;
        int right = height.size() - 1;
        while (left < right) {
            
            result = std::max(std::min(height[left], height[right]) * (right - left), result);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};