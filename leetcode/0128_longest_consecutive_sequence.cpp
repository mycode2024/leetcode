/**
 * @file LongestConsecutiveSequence.cpp
 * @brief LeetCode 128. 最长连续序列
 * @link https://leetcode.cn/problems/longest-consecutive-sequence/
 *
 * 题目描述：
 * 给定一个未排序的整数数组 nums，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 * 示例 1：
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 * 提示：
 * - 0 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 *
 * 解题思路：
 * 哈希集合法：
 * 1. 使用哈希集合存储所有数字，实现 O(1) 查找
 * 2. 对于每个数字，只有当它是序列起点时（num-1 不存在）才开始计数
 * 3. 从起点开始向后查找连续数字
 * 4. 优化：当剩余数字不足以超过当前最大长度时提前退出
 *
 * 时间复杂度：O(n)，每个数字最多被访问两次
 * 空间复杂度：O(n)，哈希集合存储所有数字
 */

#include <vector>
#include <unordered_set>
#include <algorithm>

/**
 * @class LongestConsecutiveSequence
 * @brief LeetCode 128. 最长连续序列 题解
 *
 * 功能：在未排序数组中找出最长的连续数字序列
 * 职责：实现 O(n) 时间复杂度的最长连续序列查找算法
 * 使用场景：LeetCode 第 128 题
 */
class LongestConsecutiveSequence {
public:
    /**
     * @brief 找出最长连续序列的长度
     * @param nums 整数数组（未排序）
     * @return 最长连续序列的长度
     *
     * 功能：找出数组中最长的连续数字序列
     * 算法：哈希集合法
     * 时间复杂度：O(n)，n 为数组长度
     * 空间复杂度：O(n)
     *
     * 示例：
     *   输入：nums = [100,4,200,1,3,2]
     *   输出：4（序列为 [1,2,3,4]）
     */
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // 使用哈希集合存储所有数字，实现 O(1) 查找
        std::unordered_set<int> numberSet(nums.begin(), nums.end());
        int maxSequenceLength = 0;

        for (const int& currentNumber : numberSet) {
            // 只有当 currentNumber 是序列起点时才开始计数
            // 如果 currentNumber-1 存在，说明 currentNumber 不是起点
            if (numberSet.find(currentNumber - 1) != numberSet.end()) {
                continue;
            }

            // 从起点开始向后查找连续数字
            int nextNumber = currentNumber + 1;
            while (numberSet.find(nextNumber) != numberSet.end()) {
                nextNumber++;
            }

            // 计算当前序列长度并更新最大长度
            int currentSequenceLength = nextNumber - currentNumber;
            maxSequenceLength = std::max(maxSequenceLength, currentSequenceLength);

            // 优化：如果剩余数字不足以超过当前最大长度，提前退出
            if (maxSequenceLength * 2 >= static_cast<int>(numberSet.size())) {
                break;
            }
        }

        return maxSequenceLength;
    }

private:
    // 如果需要常量定义
    // static const int kMaxValue = 1000000000;  ///< 最大值
};

