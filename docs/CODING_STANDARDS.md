# C++ 代码规范

本文档定义了项目的 C++ 代码规范，所有代码必须遵循这些规范。

---

## 📋 命名规范

### 1. 类名和文件名
**规则**：大写字母开头（PascalCase）

```cpp
// ✅ 正确
class TwoSum { };
class ListUtils { };
class LeetcodeInput { };

// ❌ 错误
class twoSum { };
class list_utils { };
class leetcode_input { };
```

**文件名示例**：
```
TwoSum.cpp
ListUtils.h
LeetcodeInput.h
```

---

### 2. 函数名和变量名
**规则**：驼峰风格，小写字母开头（camelCase）

```cpp
// ✅ 正确
int twoSum(vector<int>& nums, int target);
string longestPalindrome(string s);
int currentIndex = 0;
string userName = "test";

// ❌ 错误
int TwoSum(vector<int>& nums, int target);
int two_sum(vector<int>& nums, int target);
int CurrentIndex = 0;
string user_name = "test";
```

---

### 3. 类的私有成员和方法
**规则**：以下划线 `_` 开头

```cpp
class ListUtils {
public:
    ListUtils();
    void printList();

private:
    ListNode* _dummyHead;        // ✅ 私有成员变量
    void _skipWhitespace();      // ✅ 私有方法
    int _currentIndex;           // ✅ 私有成员变量
};

// ❌ 错误
class ListUtils {
private:
    ListNode* dummyHead;         // ❌ 缺少下划线
    void skipWhitespace();       // ❌ 缺少下划线
};
```

---

### 4. 常量变量名
**规则**：以小写字母 `k` 开头，后接 PascalCase

```cpp
// ✅ 正确
const int kMaxArraySize = 10000;
const int kDefaultValue = 0;
const string kEmptyString = "";
static const int kBufferSize = 1024;

// ❌ 错误
const int MAX_ARRAY_SIZE = 10000;    // ❌ 不使用全大写
const int maxArraySize = 10000;      // ❌ 缺少 k 前缀
const int KMAX_ARRAY_SIZE = 10000;   // ❌ K 应该小写
```

---

## 📝 代码质量要求

### 1. 类注释
**要求**：每个类必须在声明处添加详细注释

```cpp
/**
 * @class TwoSum
 * @brief LeetCode 1. 两数之和 题解
 * 
 * 功能：在数组中找出和为目标值的两个数的下标
 * 职责：实现高效的两数之和查找算法
 * 使用场景：LeetCode 第 1 题
 */
class TwoSum {
    // ...
};
```

**必须包含**：
- `@class`：类名
- `@brief`：简短描述
- **功能**：类的主要功能
- **职责**：类的职责范围
- **使用场景**：何时使用这个类

---

### 2. 成员变量注释
**要求**：所有成员变量必须添加注释

```cpp
class ListUtils {
private:
    ListNode* _dummyHead;        ///< 虚拟头节点，用于简化链表操作
    int _currentSize;            ///< 当前链表大小
    bool _isInitialized;         ///< 是否已初始化
};
```

---

### 3. 公共方法注释
**要求**：所有公共方法必须添加详细注释

```cpp
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
vector<int> twoSum(vector<int>& nums, int target);
```

**必须包含**：
- `@brief`：简短描述
- `@param`：每个参数的说明
- `@return`：返回值说明
- **功能**：方法的功能描述
- **时间复杂度**：算法时间复杂度
- **空间复杂度**：算法空间复杂度
- **示例**（可选）：使用示例

---

### 4. 私有方法注释
**要求**：私有方法也应添加注释，但可以简化

```cpp
private:
    /**
     * @brief 跳过输入流中的空白字符
     * @param inputStream 输入流引用
     * 
     * 功能：跳过输入流中的所有空白字符
     * 用途：在解析输入时忽略格式化空白
     */
    static void _skipWhitespace(std::istream& inputStream);
```

---

## 🎯 完整示例

### 示例 1：工具类

```cpp
/**
 * @class ListUtils
 * @brief 链表工具类
 * 
 * 功能：提供链表的创建、打印和内存管理功能
 * 职责：
 *   - 从数组创建链表
 *   - 打印链表内容
 *   - 释放链表内存
 * 使用场景：LeetCode 链表题目的测试和调试
 */
class ListUtils {
public:
    /**
     * @brief 构造函数，初始化虚拟头节点
     */
    ListUtils() {
        _dummyHead = new ListNode();
    }
    
    /**
     * @brief 使用尾插法从数组创建链表
     * @param vec 整数数组
     * @return 链表头节点指针
     * 
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    ListNode* createList(std::vector<int>& vec);

private:
    ListNode* _dummyHead;  ///< 虚拟头节点
    
    /**
     * @brief 内部辅助方法
     */
    void _helperMethod();
};
```

### 示例 2：题解类

```cpp
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
     * @param nums 整数数组
     * @param target 目标和值
     * @return 两个数字的下标
     * 
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> valueToIndexMap;
        
        for (int currentIndex = 0; currentIndex < nums.size(); ++currentIndex) {
            int currentValue = nums[currentIndex];
            int complementValue = target - currentValue;
            
            if (valueToIndexMap.find(complementValue) != valueToIndexMap.end()) {
                return {valueToIndexMap[complementValue], currentIndex};
            }
            
            valueToIndexMap[currentValue] = currentIndex;
        }
        
        return {};
    }

private:
    static const int kMaxArraySize = 10000;  ///< 最大数组大小
};
```

---

## ✅ 检查清单

在提交代码前，请确认：

- [ ] 类名使用 PascalCase
- [ ] 函数名和变量名使用 camelCase
- [ ] 私有成员以 `_` 开头
- [ ] 常量以 `k` 开头
- [ ] 每个类都有详细注释（功能、职责、使用场景）
- [ ] 所有公共方法都有注释（参数、返回值、复杂度）
- [ ] 所有成员变量都有注释
- [ ] 代码逻辑清晰，有必要的注释

---

**最后更新**: 2025-12-28

