/**
 * @file MoveZeroes.cpp
 * @brief LeetCode 283. 移动零
 * @link https://leetcode.cn/problems/move-zeroes/
 *
 * 题目描述：
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 请注意，必须在不复制数组的情况下原地对数组进行操作。
 *
 * 示例 1：
 * 输入：nums = [0,1,0,3,12]
 * 输出：[1,3,12,0,0]
 *
 * 示例 2：
 * 输入：nums = [0]
 * 输出：[0]
 *
 * 提示：
 * - 1 <= nums.length <= 10^4
 * - -2^31 <= nums[i] <= 2^31 - 1
 *
 * 解题思路：
 * 双指针法：
 * 1. 使用一个指针 nonZeroIndex 指向下一个非零元素应该放置的位置
 * 2. 遍历数组，遇到非零元素就与 nonZeroIndex 位置交换
 * 3. 这样可以保证非零元素的相对顺序不变，零自动移到末尾
 *
 * 时间复杂度：O(n)，n 为数组长度
 * 空间复杂度：O(1)，原地修改
 */

#include <vector>
#include <algorithm>

/**
 * @class MoveZeroes
 * @brief LeetCode 283. 移动零 题解
 *
 * 功能：将数组中的所有零移动到数组末尾，保持非零元素的相对顺序
 * 职责：实现原地移动零的算法
 * 使用场景：LeetCode 第 283 题
 */
class MoveZeroes {
public:
    /**
     * @brief 将所有零移动到数组末尾
     * @param nums 整数数组（原地修改）
     *
     * 功能：将数组中的所有 0 移动到末尾，保持非零元素的相对顺序
     * 算法：双指针法
     * 时间复杂度：O(n)，n 为数组长度
     * 空间复杂度：O(1)，原地修改
     *
     * 示例：
     *   输入：nums = [0,1,0,3,12]
     *   输出：nums = [1,3,12,0,0]
     */
    void moveZeroes(std::vector<int>& nums) {
        int nonZeroIndex = 0;  // 指向下一个非零元素应该放置的位置

        // 遍历数组
        for (int currentIndex = 0; currentIndex < nums.size(); ++currentIndex) {
            int currentValue = nums[currentIndex];

            // 如果当前元素非零
            if (currentValue != 0) {
                // 与 nonZeroIndex 位置交换
                std::swap(nums[currentIndex], nums[nonZeroIndex]);
                nonZeroIndex++;
            }
        }
    }

private:
    // 如果需要常量定义
    // static const int kMaxArraySize = 10000;  ///< 最大数组大小
};

