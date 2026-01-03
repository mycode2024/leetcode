/**
 * @file 0015_3Num.cpp
 * @brief LeetCode 15. 三数之和
 * @link https://leetcode.cn/problems/3sum/
 *
 * 题目描述：
 * 给你一个整数数组 nums，判断是否存在三元组 [nums[i], nums[j], nums[k]]
 * 满足 i != j、i != k 且 j != k，同时还满足 nums[i] + nums[j] + nums[k] == 0。
 * 请你返回所有和为 0 且不重复的三元组。
 *
 * 示例 1：
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 *
 * 示例 2：
 * 输入：nums = [0,1,1]
 * 输出：[]
 *
 * 示例 3：
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 *
 * 提示：
 * - 3 <= nums.length <= 3000
 * - -10^5 <= nums[i] <= 10^5
 *
 * 解题思路：
 * 排序 + 双指针法
 * 1. 先对数组排序
 * 2. 固定一个数 nums[i]，用双指针在 [i+1, n-1] 范围内寻找两数之和为 -nums[i]
 * 3. 通过跳过重复元素来避免重复三元组
 *
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)（不计排序的栈空间）
 */

#include "../include/leetcode_utils.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/**
 * @class Solution
 * @brief LeetCode 15. 三数之和 题解
 */
class Solution {
public:
    /**
     * @brief 查找所有和为0的不重复三元组
     * @param nums 输入数组
     * @return 所有满足条件的三元组
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // 最小数大于0，不可能有解
            if (nums[i] > 0) break;

            // 跳过重复的固定数
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // 跳过重复元素
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

/**
 * @brief 打印二维数组结果
 */
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

/**
 * @brief 测试用例
 */
void runTests() {
    Solution solution;

    // 测试用例 1：标准情况
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        auto result = solution.threeSum(nums);
        cout << "测试1: nums = [-1,0,1,2,-1,-4]" << endl;
        cout << "输出: ";
        printResult(result);
        cout << "预期: [[-1,-1,2],[-1,0,1]]" << endl << endl;
    }

    // 测试用例 2：无解情况
    {
        vector<int> nums = {0, 1, 1};
        auto result = solution.threeSum(nums);
        cout << "测试2: nums = [0,1,1]" << endl;
        cout << "输出: ";
        printResult(result);
        cout << "预期: []" << endl << endl;
    }

    // 测试用例 3：全零
    {
        vector<int> nums = {0, 0, 0};
        auto result = solution.threeSum(nums);
        cout << "测试3: nums = [0,0,0]" << endl;
        cout << "输出: ";
        printResult(result);
        cout << "预期: [[0,0,0]]" << endl << endl;
    }

    // 测试用例 4：多个零
    {
        vector<int> nums = {0, 0, 0, 0};
        auto result = solution.threeSum(nums);
        cout << "测试4: nums = [0,0,0,0]" << endl;
        cout << "输出: ";
        printResult(result);
        cout << "预期: [[0,0,0]]" << endl << endl;
    }

    // 测试用例 5：较长数组
    {
        vector<int> nums = {-2, 0, 1, 1, 2};
        auto result = solution.threeSum(nums);
        cout << "测试5: nums = [-2,0,1,1,2]" << endl;
        cout << "输出: ";
        printResult(result);
        cout << "预期: [[-2,0,2],[-2,1,1]]" << endl << endl;
    }

    cout << "所有测试完成！" << endl;
}


