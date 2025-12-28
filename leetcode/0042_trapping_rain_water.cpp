/**
 * @file TrappingRainWater.cpp
 * @brief LeetCode 42. 接雨水
 * @link https://leetcode.cn/problems/trapping-rain-water/
 *
 * 题目描述：
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 * 示例 1：
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 * 示例 2：
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 *
 * 提示：
 * - n == height.length
 * - 1 <= n <= 2 * 10^4
 * - 0 <= height[i] <= 10^5
 *
 * 解题思路：
 *
 * 方法一：双指针法（最优解，推荐）
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(1)
 * - 核心思想：从两端向中间移动，每次移动较小的一侧
 *
 * 方法二：前后缀分解（动态规划）
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(n)
 * - 核心思想：预处理每个位置的左右最大高度
 *
 * 方法三：单调栈
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(n)
 * - 核心思想：按层计算雨水，维护单调递减栈
 *
 * 推荐使用双指针法，空间复杂度最优
 */

#include <vector>
#include <algorithm>
#include <stack>

/**
 * @class TrappingRainWater
 * @brief LeetCode 42. 接雨水 题解
 *
 * 功能：计算柱状图中能接多少雨水
 * 职责：实现双指针算法，高效计算雨水容量
 * 使用场景：LeetCode 第 42 题
 */
class TrappingRainWater {
public:
    /**
     * @brief 计算能接的雨水总量
     * @param height 柱子高度数组
     * @return 能接的雨水总量
     *
     * 功能：使用双指针法计算雨水容量
     * 算法：双指针法
     * 时间复杂度：O(n)，n 为数组长度
     * 空间复杂度：O(1)
     *
     * 示例：
     *   输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
     *   输出：6
     */
    int trap(std::vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int leftPointer = 0;                          // 左指针
        int rightPointer = height.size() - 1;         // 右指针
        int leftMaxHeight = 0;                        // 左侧最大高度
        int rightMaxHeight = 0;                       // 右侧最大高度
        int totalWaterVolume = 0;                     // 总雨水量

        // 双指针向中间移动
        while (leftPointer < rightPointer) {
            // 更新左右两侧的最大高度
            leftMaxHeight = std::max(leftMaxHeight, height[leftPointer]);
            rightMaxHeight = std::max(rightMaxHeight, height[rightPointer]);

            // 移动较小的一侧
            if (leftMaxHeight < rightMaxHeight) {
                // 左侧较小，计算左侧能接的雨水
                totalWaterVolume += leftMaxHeight - height[leftPointer];
                leftPointer++;
            } else {
                // 右侧较小或相等，计算右侧能接的雨水
                totalWaterVolume += rightMaxHeight - height[rightPointer];
                rightPointer--;
            }
        }

        return totalWaterVolume;
    }

    /**
     * @brief 前后缀分解解法（动态规划）
     * @param height 柱子高度数组
     * @return 能接的雨水总量
     *
     * 功能：使用前后缀分解（动态规划）计算雨水容量
     * 算法：前后缀分解 / 动态规划
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     *
     * 核心思想：
     * 对于位置 i，能接的雨水量取决于：
     * - 左侧最大高度（前缀最大值）
     * - 右侧最大高度（后缀最大值）
     * - 当前位置高度
     *
     * 雨水量 = min(左侧最大高度, 右侧最大高度) - 当前高度
     *
     * 步骤：
     * 1. 前缀分解：从左到右计算每个位置的左侧最大高度
     * 2. 后缀分解：从右到左计算每个位置的右侧最大高度
     * 3. 对每个位置，计算能接的雨水 = min(前缀最大, 后缀最大) - 当前高度
     */
    int trapPrefixSuffix(std::vector<int>& height) {
        int arraySize = height.size();
        if (arraySize == 0) {
            return 0;
        }

        // 前缀分解：计算每个位置左侧（包括自己）的最大高度
        std::vector<int> prefixMaxHeights(arraySize);
        prefixMaxHeights[0] = height[0];
        for (int i = 1; i < arraySize; i++) {
            prefixMaxHeights[i] = std::max(prefixMaxHeights[i - 1], height[i]);
        }

        // 后缀分解：计算每个位置右侧（包括自己）的最大高度
        std::vector<int> suffixMaxHeights(arraySize);
        suffixMaxHeights[arraySize - 1] = height[arraySize - 1];
        for (int i = arraySize - 2; i >= 0; i--) {
            suffixMaxHeights[i] = std::max(suffixMaxHeights[i + 1], height[i]);
        }

        // 计算总雨水量
        int totalWaterVolume = 0;
        for (int i = 0; i < arraySize; i++) {
            // 当前位置能接的雨水 = 两侧较小的最大高度 - 当前高度
            int waterLevel = std::min(prefixMaxHeights[i], suffixMaxHeights[i]);
            totalWaterVolume += waterLevel - height[i];
        }

        return totalWaterVolume;
    }

    /**
     * @brief 动态规划解法（与前后缀分解等价）
     * @param height 柱子高度数组
     * @return 能接的雨水总量
     *
     * 功能：使用动态规划计算雨水容量
     * 算法：动态规划
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     *
     * 思路：
     * 1. 预处理每个位置左侧的最大高度
     * 2. 预处理每个位置右侧的最大高度
     * 3. 当前位置能接的雨水 = min(leftMax[i], rightMax[i]) - height[i]
     */
    int trapDP(std::vector<int>& height) {
        return trapPrefixSuffix(height);  // 与前后缀分解解法等价
    }

    /**
     * @brief 单调栈解法（备选方案）
     * @param height 柱子高度数组
     * @return 能接的雨水总量
     *
     * 功能：使用单调栈计算雨水容量
     * 算法：单调栈
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     *
     * 思路：
     * 1. 维护一个单调递减栈，存储柱子的索引
     * 2. 当遇到比栈顶高的柱子时，说明可以形成凹槽接水
     * 3. 弹出栈顶作为凹槽底部，计算这一层能接的雨水
     * 4. 雨水宽度 = 当前位置 - 左边界 - 1
     * 5. 雨水高度 = min(左边界高度, 当前高度) - 凹槽底部高度
     */
    int trapStack(std::vector<int>& height) {
        int arraySize = height.size();
        if (arraySize == 0) {
            return 0;
        }

        std::stack<int> monotonicStack;  // 单调递减栈，存储索引
        int totalWaterVolume = 0;

        for (int currentIndex = 0; currentIndex < arraySize; currentIndex++) {
            // 当前柱子高度大于栈顶柱子，可以形成凹槽
            while (!monotonicStack.empty() &&
                   height[currentIndex] > height[monotonicStack.top()]) {

                // 弹出凹槽底部
                int bottomIndex = monotonicStack.top();
                monotonicStack.pop();

                // 如果栈为空，说明左边没有边界，无法接水
                if (monotonicStack.empty()) {
                    break;
                }

                // 左边界索引
                int leftBoundaryIndex = monotonicStack.top();

                // 计算雨水宽度
                int waterWidth = currentIndex - leftBoundaryIndex - 1;

                // 计算雨水高度（取左右边界较小值，减去凹槽底部高度）
                int waterHeight = std::min(height[leftBoundaryIndex],
                                          height[currentIndex]) - height[bottomIndex];

                // 累加这一层的雨水量
                totalWaterVolume += waterWidth * waterHeight;
            }

            // 当前索引入栈
            monotonicStack.push(currentIndex);
        }

        return totalWaterVolume;
    }

private:
    // 如果需要常量定义
    // static const int kMaxHeight = 100000;  ///< 最大高度
};

/**
 * @brief 三种解法对比总结
 *
 * 1. 双指针法（推荐）
 *    - 时间复杂度：O(n)
 *    - 空间复杂度：O(1)
 *    - 优点：空间复杂度最优，代码简洁
 *    - 缺点：理解稍难
 *    - 适用场景：面试首选，空间受限场景
 *
 * 2. 前后缀分解（动态规划）
 *    - 时间复杂度：O(n)
 *    - 空间复杂度：O(n)
 *    - 优点：思路清晰，易于理解
 *    - 缺点：需要额外空间
 *    - 适用场景：初学者理解，空间充足场景
 *
 * 3. 单调栈
 *    - 时间复杂度：O(n)
 *    - 空间复杂度：O(n)
 *    - 优点：按层计算，思路独特
 *    - 缺点：代码较复杂，不易理解
 *    - 适用场景：学习单调栈数据结构
 *
 * 核心思想：
 * - 对于位置 i，能接的雨水量 = min(左侧最大高度, 右侧最大高度) - height[i]
 * - 三种方法本质相同，只是实现方式不同
 * - 双指针法通过动态维护左右最大值，避免了额外空间
 * - 前后缀分解通过预处理，空间换时间的清晰实现
 * - 单调栈通过按层计算，提供了另一种视角
 */

