/**
 * @file TwoSum.cpp
 * @brief LeetCode 1. 两数之和
 * @link https://leetcode.cn/problems/two-sum/
 *
 * 题目描述：
 * 给定一个整数数组 nums 和一个整数目标值 target，
 * 请你在该数组中找出和为目标值 target 的那两个整数，并返回它们的数组下标。
 *
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 *
 * 示例：
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9，返回 [0, 1]
 *
 * 解题思路：
 * 使用哈希表存储已遍历的数字及其下标
 * 对于每个数字 x，查找 target - x 是否在哈希表中
 * 如果找到，返回两个下标；否则将当前数字存入哈希表
 *
 * 时间复杂度：O(n)，n 为数组长度
 * 空间复杂度：O(n)，哈希表最多存储 n 个元素
 */

#include <vector>
#include <unordered_map>
#include <iostream>
#include "../include/leetcode_utils.h"

/**
 * @class TwoSum
 * @brief LeetCode 1. 两数之和 题解
 *
 * 功能：在数组中找出和为目标值的两个数的下标
 * 职责：实现高效的两数之和查找算法
 * 使用场景：LeetCode 第 1 题
 */
class TwoSum {
public:
    /**
     * @brief 查找两数之和
     * @param nums 整数数组，包含待查找的数字
     * @param target 目标和值
     * @return 两个数字的下标组成的向量，如果不存在则返回空向量
     *
     * 功能：在数组中找出和为 target 的两个数的下标
     * 算法：哈希表法
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     *
     * 示例：
     *   输入：nums = [2,7,11,15], target = 9
     *   输出：[0,1]
     */
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // 值 -> 下标的映射
        std::unordered_map<int, int> valueToIndexMap;

        for (int currentIndex = 0; currentIndex < nums.size(); ++currentIndex) {
            int currentValue = nums[currentIndex];
            int complementValue = target - currentValue;

            // 查找互补数是否存在
            if (valueToIndexMap.find(complementValue) != valueToIndexMap.end()) {
                return {valueToIndexMap[complementValue], currentIndex};
            }

            // 存储当前数字及其下标
            valueToIndexMap[currentValue] = currentIndex;
        }

        return {};  // 未找到解
    }

private:
    // 常量定义示例（如果需要）
    // static const int kMaxArraySize = 10000;
};

/**
 * @brief 测试 LeetCode 1. 两数之和
 */
void test_0001() {
    std::cout << "\n=== LeetCode 1. 两数之和 ===" << std::endl;
    std::cout << "输入格式: [数组] 目标值" << std::endl;
    std::cout << "示例: [2,7,11,15] 9" << std::endl;

    std::vector<int> nums = LeetcodeInput::readArray1D(std::cin);
    int target;
    std::cin >> target;

    TwoSum solution;
    std::vector<int> result = solution.twoSum(nums, target);

    std::cout << "结果: [" << result[0] << ", " << result[1] << "]" << std::endl;
}
