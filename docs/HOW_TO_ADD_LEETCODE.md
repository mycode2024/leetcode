# 如何添加新的 LeetCode 题目

本文档说明如何向项目中添加新的 LeetCode 题目。

---

## 📋 添加步骤

### 步骤 1️⃣：创建题解文件

在 `leetcode/` 目录下创建新文件，命名格式：`XXXX_problem_name.cpp`

**命名规则：**
- `XXXX`：4 位数字的题号（不足 4 位前面补 0）
- `problem_name`：题目英文名称（小写，用下划线分隔）

**示例：**
```
leetcode/0001_two_sum.cpp
leetcode/0042_trapping_rain_water.cpp
leetcode/0215_kth_largest_element.cpp
```

---

### 步骤 2️⃣：编写题解代码

使用以下模板编写题解：

```cpp
/**
 * @file XXXX_problem_name.cpp
 * @brief LeetCode XXX. 题目中文名
 * @link https://leetcode.cn/problems/problem-name/
 * 
 * 题目描述：
 * [在这里写题目描述]
 * 
 * 解题思路：
 * [在这里写解题思路]
 * 
 * 时间复杂度：O(?)
 * 空间复杂度：O(?)
 */

#include <vector>
// 根据需要添加其他头文件

class Solution_XXXX {
public:
    /**
     * @brief 函数功能描述
     * @param param1 参数1说明
     * @param param2 参数2说明
     * @return 返回值说明
     */
    ReturnType functionName(ParamType param1, ParamType param2) {
        // 实现代码
    }
};

// 测试用例（可选）
namespace Test_XXXX {
    void test() {
        Solution_XXXX solution;
        // 测试代码
    }
}
```

**关键点：**
- ✅ 类名格式：`Solution_XXXX`（XXXX 是题号）
- ✅ 命名空间格式：`Test_XXXX`（如果有测试）
- ✅ 包含完整的文档注释
- ✅ 只包含必要的头文件

---

### 步骤 3️⃣：在 test_main.cpp 中添加测试函数

#### 3.1 添加 include

在 `test_main.cpp` 的 LeetCode 题解部分添加：

```cpp
// LeetCode 题解
#include "leetcode/0001_two_sum.cpp"
#include "leetcode/0011_container_with_most_water.cpp"
// ... 其他题目
#include "leetcode/XXXX_problem_name.cpp"  // 新添加的题目
```

#### 3.2 编写测试函数

在 `test_main.cpp` 中添加测试函数：

```cpp
/**
 * @brief 测试 LeetCode XXX. 题目中文名
 */
void test_XXXX() {
    cout << "\n=== LeetCode XXX. 题目中文名 ===" << endl;
    cout << "输入格式: [说明输入格式]" << endl;
    cout << "示例: [给出示例]" << endl;

    // 读取输入
    // 使用 LeetcodeInput 工具类读取数据
    vector<int> nums = LeetcodeInput::readArray1D(cin);
    int target;
    cin >> target;

    // 调用解法
    Solution_XXXX solution;
    auto result = solution.functionName(nums, target);

    // 输出结果
    cout << "结果: " << result << endl;
}
```

**常用输入读取方法：**
```cpp
// 一维数组
vector<int> nums = LeetcodeInput::readArray1D(cin);

// 二维数组
vector<vector<int>> matrix = LeetcodeInput::readArray2D(cin);

// 字符串数组
vector<string> strs = LeetcodeInput::readStringArray(cin);

// 链表
ListNode* head = ListUtils::createList({1, 2, 3, 4, 5});

// 单个整数
int n;
cin >> n;

// 字符串
string s;
cin >> s;
```

#### 3.3 在菜单中添加选项

在 `showMenu()` 函数中添加新选项：

```cpp
void showMenu() {
    cout << "\n========== LeetCode 测试菜单 ==========" << endl;
    cout << "1. LeetCode 1 - 两数之和" << endl;
    cout << "2. LeetCode 11 - 盛最多水的容器" << endl;
    // ... 其他选项
    cout << "X. LeetCode XXX - 题目中文名" << endl;  // 新添加
    cout << "0. 退出" << endl;
    cout << "=======================================" << endl;
    cout << "请选择 (0-X): ";
}
```

#### 3.4 在 main 函数中添加 case

```cpp
int main() {
    while (true) {
        showMenu();
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: test_0001(); break;
            case 2: test_0011(); break;
            // ... 其他 case
            case X: test_XXXX(); break;  // 新添加
            case 0:
                cout << "再见！" << endl;
                return 0;
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
    }
    
    return 0;
}
```

---

### 步骤 4️⃣：准备测试数据

在 `.vscode/oi/in.txt` 中准备测试输入：

```
6
[2,7,11,15] 9
```

**格式说明：**
- 第一行：菜单选项编号
- 后续行：题目的输入数据

---

### 步骤 5️⃣：编译和测试

#### 方法 1：使用 VSCode 调试（推荐）
1. 打开 `test_main.cpp`
2. 按 `F5` 启动调试
3. 程序会自动从 `in.txt` 读取输入
4. 查看 `out.txt` 中的输出结果

#### 方法 2：手动编译运行
```bash
# 编译
g++ -std=c++20 -g test_main.cpp -o test_main.exe

# 运行
./test_main.exe
```

---

## 📝 完整示例

假设要添加 **LeetCode 42. 接雨水**

### 1. 创建文件 `leetcode/0042_trapping_rain_water.cpp`

```cpp
/**
 * @file 0042_trapping_rain_water.cpp
 * @brief LeetCode 42. 接雨水
 * @link https://leetcode.cn/problems/trapping-rain-water/
 * 
 * 题目描述：
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
 * 计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 解题思路：
 * 使用双指针法，从两端向中间移动
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <vector>
#include <algorithm>

class Solution_0042 {
public:
    int trap(std::vector<int>& height) {
        // 实现代码...
    }
};
```

### 2. 在 `test_main.cpp` 中添加

```cpp
// 添加 include
#include "leetcode/0042_trapping_rain_water.cpp"

// 添加测试函数
void test_0042() {
    cout << "\n=== LeetCode 42. 接雨水 ===" << endl;
    cout << "输入格式: [高度数组]" << endl;
    cout << "示例: [0,1,0,2,1,0,1,3,2,1,2,1]" << endl;

    vector<int> height = LeetcodeInput::readArray1D(cin);

    Solution_0042 solution;
    int result = solution.trap(height);

    cout << "接雨水量: " << result << endl;
}

// 在菜单中添加
void showMenu() {
    // ...
    cout << "9. LeetCode 42 - 接雨水" << endl;
    // ...
}

// 在 main 中添加 case
case 9: test_0042(); break;
```

### 3. 准备测试数据 `in.txt`

```
9
[0,1,0,2,1,0,1,3,2,1,2,1]
```

### 4. 按 F5 调试，查看 `out.txt` 结果

---

## ✅ 检查清单

添加新题目前，请确认：

- [ ] 文件命名符合规范（4 位题号 + 下划线 + 英文名）
- [ ] 类名使用 `Solution_XXXX` 格式
- [ ] 包含完整的文档注释（题目描述、思路、复杂度）
- [ ] 在 `test_main.cpp` 中添加了 include
- [ ] 编写了测试函数 `test_XXXX()`
- [ ] 在菜单中添加了选项
- [ ] 在 switch-case 中添加了分支
- [ ] 准备了测试数据
- [ ] 编译通过，测试成功

---

**最后更新**: 2025-12-28

