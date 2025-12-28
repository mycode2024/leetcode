/**
 * @file KthLargestElement.cpp
 * @brief LeetCode 215. 数组中的第K个最大元素
 * @link https://leetcode.cn/problems/kth-largest-element-in-an-array/
 *
 * 题目描述：
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 * 示例 1：
 * 输入：nums = [3,2,1,5,6,4], k = 2
 * 输出：5
 *
 * 示例 2：
 * 输入：nums = [3,2,3,1,2,4,5,5,6], k = 4
 * 输出：4
 *
 * 提示：
 * - 1 <= k <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 *
 * 解题思路：
 * 快速选择算法（Quick Select）：
 * 1. 随机选择基准值（pivot）
 * 2. 将数组分为三部分：大于基准值、等于基准值、小于基准值
 * 3. 根据 k 的位置判断：
 *    - 如果 k <= bigger.size()，在 bigger 部分继续查找
 *    - 如果 k > bigger.size() + equal.size()，在 smaller 部分查找
 *    - 否则，基准值就是答案
 *
 * 时间复杂度：平均 O(n)，最坏 O(n²)
 * 空间复杂度：O(n)（递归栈空间和临时数组）
 */

#include <vector>
#include <cstdlib>

/**
 * @class KthLargestElement
 * @brief LeetCode 215. 数组中的第K个最大元素 题解
 *
 * 功能：在未排序数组中找出第 k 个最大的元素
 * 职责：实现快速选择算法，在平均 O(n) 时间内找到第 k 大元素
 * 使用场景：LeetCode 第 215 题
 */
class KthLargestElement {
public:
    /**
     * @brief 找出第 k 个最大元素
     * @param nums 整数数组（未排序）
     * @param k 第 k 大（1 <= k <= nums.length）
     * @return 第 k 个最大元素的值
     *
     * 功能：使用快速选择算法找出第 k 大的元素
     * 算法：快速选择（Quick Select）
     * 时间复杂度：平均 O(n)，最坏 O(n²)
     * 空间复杂度：O(n)
     *
     * 示例：
     *   输入：nums = [3,2,1,5,6,4], k = 2
     *   输出：5
     */
    int findKthLargest(std::vector<int>& nums, int k) {
        return _quickSelect(nums, k);
    }

private:
    /**
     * @brief 快速选择算法（私有辅助方法）
     * @param nums 整数数组
     * @param k 第 k 大
     * @return 第 k 个最大元素
     *
     * 功能：递归实现快速选择算法
     * 算法：三路划分（大于、等于、小于基准值）
     */
    int _quickSelect(std::vector<int>& nums, int k) {
        // 随机选择基准值，避免最坏情况
        int pivotValue = nums[rand() % nums.size()];

        // 分为三部分：大于、等于、小于基准值
        std::vector<int> biggerThanPivot;
        std::vector<int> equalToPivot;
        std::vector<int> smallerThanPivot;

        for (int currentNumber : nums) {
            if (currentNumber > pivotValue) {
                biggerThanPivot.push_back(currentNumber);
            } else if (currentNumber < pivotValue) {
                smallerThanPivot.push_back(currentNumber);
            } else {
                equalToPivot.push_back(currentNumber);
            }
        }

        // 根据 k 的位置决定在哪部分继续查找
        int biggerSize = biggerThanPivot.size();
        int equalSize = equalToPivot.size();

        if (k <= biggerSize) {
            // 第 k 大在 bigger 部分
            return _quickSelect(biggerThanPivot, k);
        } else if (k > biggerSize + equalSize) {
            // 第 k 大在 smaller 部分
            int newK = k - biggerSize - equalSize;
            return _quickSelect(smallerThanPivot, newK);
        } else {
            // 第 k 大就是基准值
            return pivotValue;
        }
    }
};

