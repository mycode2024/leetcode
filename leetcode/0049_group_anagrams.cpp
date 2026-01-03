/**
 * @file GroupAnagrams.cpp
 * @brief LeetCode 49. 字母异位词分组
 * @link https://leetcode.cn/problems/group-anagrams/
 *
 * 题目描述：
 * 给你一个字符串数组，请你将字母异位词组合在一起。
 * 字母异位词是由重新排列源单词的所有字母得到的一个新单词。
 *
 * 示例 1：
 * 输入：strs = ["eat","tea","tan","ate","nat","bat"]
 * 输出：[["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 示例 2：
 * 输入：strs = [""]
 * 输出：[[""]]
 *
 * 示例 3：
 * 输入：strs = ["a"]
 * 输出：[["a"]]
 *
 * 提示：
 * - 1 <= strs.length <= 10^4
 * - 0 <= strs[i].length <= 100
 * - strs[i] 仅包含小写字母
 *
 * 解题思路：
 * 哈希表法：
 * 1. 使用哈希表存储分组，键为排序后的字符串
 * 2. 相同的字母异位词排序后会得到相同的字符串
 * 3. 遍历所有字符串，将其添加到对应的组中
 * 4. 最后将哈希表中的所有组收集到结果中
 *
 * 时间复杂度：O(n * k * log(k))，n 是字符串数量，k 是字符串最大长度
 * 空间复杂度：O(n * k)，存储所有字符串
 */

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>
#include "../include/leetcode_utils.h"

/**
 * @class GroupAnagrams
 * @brief LeetCode 49. 字母异位词分组 题解
 *
 * 功能：将字符串数组中的字母异位词分组
 * 职责：实现基于哈希表的字母异位词分组算法
 * 使用场景：LeetCode 第 49 题
 */
class GroupAnagrams {
public:
    /**
     * @brief 字母异位词分组
     * @param strs 字符串数组
     * @return 分组后的字母异位词，每个子数组包含一组字母异位词
     *
     * 功能：将字母异位词分组到一起
     * 算法：哈希表法（使用排序后的字符串作为键）
     * 时间复杂度：O(n * k * log(k))，n 是字符串数量，k 是字符串最大长度
     * 空间复杂度：O(n * k)
     *
     * 示例：
     *   输入：strs = ["eat","tea","tan","ate","nat","bat"]
     *   输出：[["bat"],["nat","tan"],["ate","eat","tea"]]
     */
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramGroupMap;

        // 遍历每个字符串
        for (const auto& currentString : strs) {
            // 排序字符串作为键
            std::string sortedKey = currentString;
            std::sort(sortedKey.begin(), sortedKey.end());

            // 将原字符串添加到对应的组中
            anagramGroupMap[sortedKey].push_back(currentString);
        }

        // 构建结果
        std::vector<std::vector<std::string>> resultGroups;
        resultGroups.reserve(anagramGroupMap.size());

        for (auto& [sortedKey, anagramGroup] : anagramGroupMap) {
            resultGroups.push_back(std::move(anagramGroup));
        }

        return resultGroups;
    }

private:
    // 如果需要常量定义
    // static const int kMaxStringLength = 100;  ///< 最大字符串长度
};

/**
 * @brief 测试 LeetCode 49. 字母异位词分组
 */
void test_0049() {
    using namespace std;
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
