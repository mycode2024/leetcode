/**
 * @file ContainerWithMostWater.cpp
 * @brief LeetCode 11. 盛最多水的容器
 * @link https://leetcode.cn/problems/container-with-most-water/
 *
 * 题目描述：
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 示例 1：
 * 输入：height = [1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 *
 * 示例 2：
 * 输入：height = [1,1]
 * 输出：1
 *
 * 提示：
 * - n == height.length
 * - 2 <= n <= 10^5
 * - 0 <= height[i] <= 10^4
 *
 * 解题思路：
 * 双指针法：
 * 1. 使用左右两个指针从数组两端开始
 * 2. 计算当前容器的容量（宽度 × 较短边的高度）
 * 3. 移动较短的那一边，因为容器的高度由较短边决定
 * 4. 重复直到两指针相遇
 *
 * 时间复杂度：O(n)，n 为数组长度
 * 空间复杂度：O(1)，只使用常数额外空间
 */

#include <vector>
#include <algorithm>

/**
 * @class ContainerWithMostWater
 * @brief LeetCode 11. 盛最多水的容器 题解
 *
 * 功能：找出数组中两条线，使得它们与 x 轴构成的容器能容纳最多的水
 * 职责：实现双指针算法计算最大容水量
 * 使用场景：LeetCode 第 11 题
 */
class ContainerWithMostWater {
public:
    /**
     * @brief 计算最大容水量
     * @param height 高度数组，每个元素代表一条垂直线的高度
     * @return 最大容水量
     *
     * 功能：使用双指针法找出能容纳最多水的容器
     * 算法：双指针法
     * 时间复杂度：O(n)，n 为数组长度
     * 空间复杂度：O(1)
     *
     * 示例：
     *   输入：height = [1,8,6,2,5,4,8,3,7]
     *   输出：49
     */
    int maxArea(std::vector<int>& height) {
        int leftPointer = 0;
        int rightPointer = height.size() - 1;
        int maxWaterVolume = 0;

        while (leftPointer < rightPointer) {
            // 计算当前容器的容量
            int containerWidth = rightPointer - leftPointer;
            int containerHeight = std::min(height[leftPointer], height[rightPointer]);
            int currentVolume = containerWidth * containerHeight;
            maxWaterVolume = std::max(maxWaterVolume, currentVolume);

            // 移动较短的边，因为只有这样才可能找到更大的容器
            if (height[leftPointer] < height[rightPointer]) {
                leftPointer++;
            } else {
                rightPointer--;
            }
        }

        return maxWaterVolume;
    }

private:
    // 如果需要常量定义
    // static const int kMaxHeight = 10000;  ///< 最大高度
};

