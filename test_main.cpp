/**
 * @file test_main.cpp
 * @brief 统一测试入口
 * @author LeetCode Practice
 * @date 2025-12-28
 * 
 * 提供统一的测试入口，可以选择测试不同的算法和 LeetCode 题目
 */

#include <iostream>
#include <string>
#include "include/leetcode_utils.h"
#include "include/list_utils.h"

// LeetCode 题解
#include "leetcode/0001_two_sum.cpp"
#include "leetcode/0011_container_with_most_water.cpp"
#include "leetcode/0042_trapping_rain_water.cpp"
#include "leetcode/0049_group_anagrams.cpp"
#include "leetcode/0128_longest_consecutive_sequence.cpp"
#include "leetcode/0215_kth_largest_element.cpp"
#include "leetcode/0283_move_zeroes.cpp"

// 算法实现
#include "algorithms/sorting/bubble_sort.cpp"
#include "algorithms/math/prime_numbers.cpp"

using namespace std;

/**
 * @brief 测试 LeetCode 1. 两数之和
 */
void test_0001() {
    cout << "\n=== LeetCode 1. 两数之和 ===" << endl;
    cout << "输入格式: [数组] 目标值" << endl;
    cout << "示例: [2,7,11,15] 9" << endl;

    vector<int> nums = LeetcodeInput::readArray1D(cin);
    int target;
    cin >> target;

    TwoSum solution;
    vector<int> result = solution.twoSum(nums, target);

    cout << "结果: [" << result[0] << ", " << result[1] << "]" << endl;
}

/**
 * @brief 测试 LeetCode 11. 盛最多水的容器
 */
void test_0011() {
    cout << "\n=== LeetCode 11. 盛最多水的容器 ===" << endl;
    cout << "输入格式: [高度数组]" << endl;
    cout << "示例: [1,8,6,2,5,4,8,3,7]" << endl;

    vector<int> height = LeetcodeInput::readArray1D(cin);

    ContainerWithMostWater solution;
    int result = solution.maxArea(height);

    cout << "最大容水量: " << result << endl;
}

/**
 * @brief 测试 LeetCode 42. 接雨水
 */
void test_0042() {
    cout << "\n=== LeetCode 42. 接雨水 ===" << endl;
    cout << "输入格式: [高度数组]" << endl;
    cout << "示例: [0,1,0,2,1,0,1,3,2,1,2,1]" << endl;

    vector<int> height = LeetcodeInput::readArray1D(cin);

    TrappingRainWater solution;
    int result = solution.trap(height);

    cout << "能接的雨水总量: " << result << endl;
}

/**
 * @brief 测试 LeetCode 128. 最长连续序列
 */
void test_0128() {
    cout << "\n=== LeetCode 128. 最长连续序列 ===" << endl;
    cout << "输入格式: [数组]" << endl;
    cout << "示例: [100,4,200,1,3,2]" << endl;

    vector<int> nums = LeetcodeInput::readArray1D(cin);

    LongestConsecutiveSequence solution;
    int result = solution.longestConsecutive(nums);

    cout << "最长连续序列长度: " << result << endl;
}

/**
 * @brief 测试 LeetCode 49. 字母异位词分组
 */
void test_0049() {
    cout << "\n=== LeetCode 49. 字母异位词分组 ===" << endl;
    cout << "输入格式: [字符串数组]" << endl;
    cout << "示例: [\"eat\",\"tea\",\"tan\",\"ate\",\"nat\",\"bat\"]" << endl;

    vector<string> strs = LeetcodeInput::readStringArray();

    GroupAnagrams solution;
    vector<vector<string>> result = solution.groupAnagrams(strs);

    cout << "结果: [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

/**
 * @brief 测试 LeetCode 215. 数组中的第K个最大元素
 */
void test_0215() {
    cout << "\n=== LeetCode 215. 数组中的第K个最大元素 ===" << endl;
    cout << "输入格式: [数组] k" << endl;
    cout << "示例: [3,2,1,5,6,4] 2" << endl;

    vector<int> nums = LeetcodeInput::readArray1D(cin);
    int k;
    cin >> k;

    KthLargestElement solution;
    int result = solution.findKthLargest(nums, k);

    cout << "第 " << k << " 个最大元素: " << result << endl;
}

/**
 * @brief 测试 LeetCode 283. 移动零
 */
void test_0283() {
    cout << "\n=== LeetCode 283. 移动零 ===" << endl;
    cout << "输入格式: [数组]" << endl;
    cout << "示例: [0,1,0,3,12]" << endl;

    vector<int> nums = LeetcodeInput::readArray1D(cin);

    MoveZeroes solution;
    solution.moveZeroes(nums);

    cout << "结果: [";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}



int main() {



    return 0;
}

