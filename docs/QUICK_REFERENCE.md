# LeetCode 题目添加快速参考

## 🚀 5 步快速添加

```
1. 创建题解文件    → leetcode/XXXX_problem_name.cpp
2. 添加 include    → test_main.cpp 顶部
3. 编写测试函数    → test_main.cpp 中间
4. 更新菜单和case  → test_main.cpp 的 showMenu() 和 main()
5. 测试运行        → 按 F5 调试
```

---

## 📁 文件命名规范

| 题号 | 文件名示例 |
|------|-----------|
| 1    | `0001_two_sum.cpp` |
| 42   | `0042_trapping_rain_water.cpp` |
| 215  | `0215_kth_largest_element.cpp` |
| 1234 | `1234_problem_name.cpp` |

**规则**: `XXXX_problem_name.cpp` (4位题号 + 下划线 + 英文名小写)

---

## 🏷️ 类名规范

```cpp
class Solution_0001 { };  // LeetCode 1
class Solution_0042 { };  // LeetCode 42
class Solution_0215 { };  // LeetCode 215
```

**规则**: `Solution_XXXX` (Solution + 下划线 + 4位题号)

---

## 📥 常用输入读取

```cpp
// 一维数组: [1,2,3,4,5]
vector<int> nums = LeetcodeInput::readArray1D(cin);

// 二维数组: [[1,2],[3,4]]
vector<vector<int>> matrix = LeetcodeInput::readArray2D(cin);

// 字符串数组: ["eat","tea","tan"]
vector<string> strs = LeetcodeInput::readStringArray(cin);

// 整数
int n;
cin >> n;

// 字符串
string s;
cin >> s;

// 链表: [1,2,3,4,5]
ListNode* head = ListUtils::createList({1, 2, 3, 4, 5});
```

---

## 📤 常用输出格式

```cpp
// 整数
cout << "结果: " << result << endl;

// 布尔值
cout << "结果: " << (result ? "true" : "false") << endl;

// 一维数组
cout << "结果: [";
for (size_t i = 0; i < result.size(); i++) {
    cout << result[i];
    if (i < result.size() - 1) cout << ",";
}
cout << "]" << endl;

// 二维数组
for (const auto& row : result) {
    cout << "[";
    for (size_t i = 0; i < row.size(); i++) {
        cout << row[i];
        if (i < row.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// 字符串
cout << "结果: " << result << endl;

// 链表
ListUtils::printList(head);
```

---

## 📝 测试函数模板

```cpp
void test_XXXX() {
    cout << "\n=== LeetCode XXX. 题目名 ===" << endl;
    cout << "输入格式: [说明]" << endl;
    cout << "示例: [示例]" << endl;

    // 读取输入
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

---

## 🔧 test_main.cpp 修改位置

### 1. 添加 include (第 15-21 行附近)
```cpp
#include "leetcode/0001_two_sum.cpp"
#include "leetcode/XXXX_problem_name.cpp"  // ← 在这里添加
```

### 2. 添加测试函数 (第 98 行之后)
```cpp
void test_XXXX() {
    // 测试代码
}
```

### 3. 更新菜单 (showMenu 函数中)
```cpp
void showMenu() {
    cout << "1. LeetCode 1 - 两数之和" << endl;
    cout << "X. LeetCode XXX - 题目名" << endl;  // ← 添加选项
}
```

### 4. 添加 case (main 函数的 switch 中)
```cpp
switch (choice) {
    case 1: test_0001(); break;
    case X: test_XXXX(); break;  // ← 添加 case
}
```

---

## 🧪 测试流程

### 方法 1: VSCode 调试 (推荐)
1. 在 `.vscode/oi/in.txt` 写入测试数据
   ```
   X
   [测试输入]
   ```
2. 打开 `test_main.cpp`
3. 按 `F5` 启动调试
4. 查看 `.vscode/oi/out.txt` 结果

### 方法 2: 手动编译
```bash
g++ -std=c++20 -g test_main.cpp -o test_main.exe
./test_main.exe
```

---

## 📚 常用头文件

```cpp
#include <vector>           // vector
#include <string>           // string
#include <unordered_map>    // 哈希表
#include <unordered_set>    // 哈希集合
#include <map>              // 有序映射
#include <set>              // 有序集合
#include <queue>            // 队列、优先队列
#include <stack>            // 栈
#include <algorithm>        // sort, reverse 等
#include <numeric>          // accumulate 等
#include <cmath>            // 数学函数
```

---

## ✅ 添加检查清单

- [ ] 文件名: `leetcode/XXXX_problem_name.cpp`
- [ ] 类名: `Solution_XXXX`
- [ ] 文档注释完整（题目、思路、复杂度）
- [ ] 在 `test_main.cpp` 添加 include
- [ ] 编写测试函数 `test_XXXX()`
- [ ] 更新 `showMenu()`
- [ ] 添加 switch case
- [ ] 准备测试数据 `in.txt`
- [ ] 编译通过
- [ ] 测试成功

---

## 🎯 完整示例

假设添加 **LeetCode 42. 接雨水**

```cpp
// 1. leetcode/0042_trapping_rain_water.cpp
class Solution_0042 {
public:
    int trap(vector<int>& height) {
        // 实现...
    }
};

// 2. test_main.cpp - include
#include "leetcode/0042_trapping_rain_water.cpp"

// 3. test_main.cpp - 测试函数
void test_0042() {
    cout << "\n=== LeetCode 42. 接雨水 ===" << endl;
    vector<int> height = LeetcodeInput::readArray1D(cin);
    Solution_0042 solution;
    cout << "结果: " << solution.trap(height) << endl;
}

// 4. test_main.cpp - 菜单
cout << "9. LeetCode 42 - 接雨水" << endl;

// 5. test_main.cpp - case
case 9: test_0042(); break;

// 6. in.txt
9
[0,1,0,2,1,0,1,3,2,1,2,1]
```

---

**提示**: 使用 `leetcode/TEMPLATE.cpp` 和 `TEST_FUNCTION_TEMPLATE.txt` 作为起点！

**最后更新**: 2025-12-28

