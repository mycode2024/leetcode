# LeetCode & 算法练习项目

> 一个结构化的 C++ LeetCode 刷题和算法练习项目

## 📚 文档导航

- **[代码规范](docs/CODING_STANDARDS.md)** - ⭐ C++ 代码规范（必读）
- **[如何添加新题目](docs/HOW_TO_ADD_LEETCODE.md)** - 详细的添加流程和示例
- **[快速参考](docs/QUICK_REFERENCE.md)** - 常用命令和代码片段速查
- **[配置说明](docs/CONFIG_README.md)** - VSCode 配置文件详解
- **[题解模板](leetcode/TEMPLATE.cpp)** - 新题目代码模板
- **[测试函数模板](docs/TEST_FUNCTION_TEMPLATE.txt)** - 测试函数代码模板

## 📁 项目结构

```
leetcode/
├── include/                    # 头文件和工具类
│   ├── leetcode_utils.h       # LeetCode 输入输出工具
│   └── list_utils.h           # 链表数据结构和工具
│
├── leetcode/                   # LeetCode 题解
│   ├── TEMPLATE.cpp                            # 新题目模板
│   ├── 0001_two_sum.cpp                        # 1. 两数之和
│   ├── 0011_container_with_most_water.cpp      # 11. 盛最多水的容器
│   ├── 0049_group_anagrams.cpp                 # 49. 字母异位词分组
│   ├── 0128_longest_consecutive_sequence.cpp   # 128. 最长连续序列
│   ├── 0215_kth_largest_element.cpp            # 215. 数组中的第K个最大元素
│   └── 0283_move_zeroes.cpp                    # 283. 移动零
│
├── algorithms/                 # 通用算法实现
│   ├── sorting/               # 排序算法
│   │   └── bubble_sort.cpp    # 冒泡排序
│   └── math/                  # 数学算法
│       └── prime_numbers.cpp  # 质数相关算法
│
├── test_main.cpp                  # 统一测试入口
├── README.md                      # 项目说明文档
│
├── docs/                          # 📚 文档目录
│   ├── CODING_STANDARDS.md       # ⭐ C++ 代码规范
│   ├── HOW_TO_ADD_LEETCODE.md    # 添加新题目详细指南
│   ├── QUICK_REFERENCE.md        # 快速参考手册
│   ├── CONFIG_README.md          # 配置文件说明文档
│   └── TEST_FUNCTION_TEMPLATE.txt # 测试函数模板
│
└── .vscode/                       # VSCode 配置
    ├── tasks.json                 # 编译任务配置
    ├── launch.json                # 调试配置
    ├── c_cpp_properties.json      # C++ 属性配置
    ├── settings.json              # 工作区设置
    ├── exe/                       # 编译输出目录
    └── oi/                        # 输入输出文件
        ├── in.txt                 # 输入文件
        └── out.txt                # 输出文件
```

## 🚀 快速开始

### 编译和运行

#### 方式 1：使用 VSCode（推荐）
1. 打开 `test_main.cpp`
2. 按 `F5` 开始调试
3. 或按 `Ctrl+Shift+B` 编译

#### 方式 2：命令行编译
```bash
# 编译测试主程序
g++ -std=c++20 -g test_main.cpp -o test_main.exe

# 运行
./test_main.exe
```

### 输入输出重定向
程序支持从文件读取输入：
- 输入文件：`.vscode/oi/in.txt`
- 输出文件：`.vscode/oi/out.txt`

在调试模式下（按 F5），程序会自动从 `in.txt` 读取输入并输出到 `out.txt`。

### 添加新题目

**快速步骤：**
1. 复制 `leetcode/TEMPLATE.cpp` 创建新题解文件
2. 在 `test_main.cpp` 中添加 include 和测试函数
3. 更新菜单和 switch-case
4. 准备测试数据到 `in.txt`
5. 按 F5 调试测试

**详细说明请查看：** [如何添加新题目](docs/HOW_TO_ADD_LEETCODE.md) | [快速参考](docs/QUICK_REFERENCE.md)

## 📚 LeetCode 题解说明

### 1. 两数之和 (Two Sum)
- **难度**：简单
- **算法**：哈希表
- **时间复杂度**：O(n)
- **输入格式**：`[2,7,11,15] 9`

### 11. 盛最多水的容器 (Container With Most Water)
- **难度**：中等
- **算法**：双指针
- **时间复杂度**：O(n)
- **输入格式**：`[1,8,6,2,5,4,8,3,7]`

### 49. 字母异位词分组 (Group Anagrams)
- **难度**：中等
- **算法**：哈希表 + 排序
- **时间复杂度**：O(n * k * log(k))
- **输入格式**：`["eat","tea","tan","ate","nat","bat"]`

### 128. 最长连续序列 (Longest Consecutive Sequence)
- **难度**：中等
- **算法**：哈希集合
- **时间复杂度**：O(n)
- **输入格式**：`[100,4,200,1,3,2]`

### 215. 数组中的第K个最大元素 (Kth Largest Element)
- **难度**：中等
- **算法**：快速选择
- **时间复杂度**：平均 O(n)
- **输入格式**：`[3,2,1,5,6,4] 2`

### 283. 移动零 (Move Zeroes)
- **难度**：简单
- **算法**：双指针
- **时间复杂度**：O(n)
- **输入格式**：`[0,1,0,3,12]`

## 🔧 工具类说明

### LeetcodeInput 类
提供 LeetCode 格式的输入读取功能：
- `readArray1D()`：读取一维数组，如 `[1,2,3,4,5]`
- `readArray2D()`：读取二维数组，如 `[[1,2],[3,4]]`
- `readStrArr()`：读取字符串数组，如 `["hello","world"]`
- `printMatrix()`：打印二维数组

### ListCreate 类
链表创建和操作工具：
- `createList()`：从数组创建链表
- `printList()`：打印链表
- `freeList()`：释放链表内存

## 📝 代码规范

### 文件命名
- LeetCode 题解：`0001_problem_name.cpp`（四位数字 + 下划线 + 题目名）
- 算法实现：`algorithm_name.cpp`（小写 + 下划线）

### 注释规范
每个文件包含：
- 文件说明（@file, @brief, @author, @date）
- 算法描述和复杂度分析
- 函数说明（@brief, @param, @return）

### 代码风格
- 使用 C++20 标准
- 命名空间：算法实现使用命名空间，LeetCode 题解使用 Solution 类
- 缩进：4 个空格
- 变量命名：驼峰命名法

## 🎯 使用建议

1. **学习新题目**：先看题解文件中的注释和算法思路
2. **测试代码**：使用 `test_main.cpp` 统一入口测试
3. **调试技巧**：使用 `debug(x)` 宏快速打印变量值
4. **添加新题**：参考现有题解的格式和注释风格

## 📌 环境要求

- **编译器**：MinGW g++ (支持 C++20)
- **IDE**：Visual Studio Code
- **扩展**：C/C++ Extension Pack

## 🔗 相关链接

- [LeetCode 中文站](https://leetcode.cn/)
- [C++ Reference](https://en.cppreference.com/)

---

**最后更新**：2025-12-28

