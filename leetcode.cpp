#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

#define debug(x) std::cout << #x << ' ' << '=' << ' ' << (x) << std::endl

//力扣输入操作
class LeetcodeInput {
public:
    // 跳过空白字符的辅助函数
    static void skipWhitespace(std::istream& is) {
        while (isspace(is.peek())) {
            is.ignore();
        }
    }

    // 打印二维数组的辅助函数（用于测试）
    static void printMatrix(const std::vector<std::vector<int>>& matrix) {
        std::cout << "[";
        for (size_t i = 0; i < matrix.size(); ++i) {
            std::cout << "[";
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                std::cout << matrix[i][j];
                if (j < matrix[i].size() - 1) std::cout << ",";
            }
            std::cout << "]";
            if (i < matrix.size() - 1) std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }
    
    // 读取力扣格式的字符串数组
    static std::vector<std::string> readStrArr() {
        std::vector<std::string> result;
        std::string input;
        
        // 读取整行输入
        std::getline(std::cin, input);
        
        // 移除方括号
        if (input.front() == '[' && input.back() == ']') {
            input = input.substr(1, input.length() - 2);
        }
        
        std::stringstream ss(input);
        std::string token;
        
        // 按逗号分割，并移除引号
        while (std::getline(ss, token, ',')) {
            // 移除空格和引号
            size_t start = token.find_first_of('"');
            size_t end = token.find_last_of('"');
            
            if (start != std::string::npos && end != std::string::npos && start < end) {
                std::string word = token.substr(start + 1, end - start - 1);
                result.push_back(word);
            }
        }
        
        return result;
}
    // 读取一维数组
    static std::vector<int> readArray1D(std::istream& is) {
        std::vector<int> numbers;
        
        skipWhitespace(is);
        if (is.peek() != '[') {
            std::cerr << "错误：输入应以'['开头" << std::endl;
            return numbers;
        }
        is.ignore();  // 跳过'['
        
        while (true) {
            skipWhitespace(is);
            
            // 检查是否到达结束
            if (is.peek() == ']') {
                is.ignore();
                break;
            }
            
            // 读取数字
            int num;
            if (is >> num) {
                numbers.push_back(num);
            } else {
                std::cerr << "错误：读取数字失败" << std::endl;
                // 清空错误状态并跳过错误字符
                is.clear();
                is.ignore();
                break;
            }
            
            skipWhitespace(is);
            
            // 检查下一个字符
            if (is.peek() == ']') {
                continue;  // 继续循环，下次迭代会处理结束括号
            } else if (is.peek() == ',') {
                is.ignore();  // 跳过逗号
            } else {
                std::cerr << "错误：期望逗号或']'" << std::endl;
                break;
            }
        }
        
        return numbers;
    }

    // 读取二维数组的主要函数
    static std::vector<std::vector<int>> readArray2D(std::istream& is) {
        std::vector<std::vector<int>> matrix;
        
        skipWhitespace(is);
        if (is.peek() != '[') {
            std::cerr << "错误：二维数组输入应以'['开头" << std::endl;
            return matrix;
        }
        is.ignore();  // 跳过外层'['
        
        while (true) {
            skipWhitespace(is);
            
            // 检查是否到达结束
            if (is.peek() == ']') {
                is.ignore();
                break;
            }
            
            // 检查是否为空矩阵
            if (matrix.empty() && is.peek() == ']') {
                is.ignore();
                break;
            }
            
            // 读取一维数组（子数组）
            if (is.peek() == '[') {
                std::vector<int> row = readArray1D(is);
                if (!is.fail()) {
                    matrix.push_back(row);
                } else {
                    std::cerr << "错误：读取子数组失败" << std::endl;
                    break;
                }
            } else {
                std::cerr << "错误：期望'['开始子数组" << std::endl;
                break;
            }
            
            skipWhitespace(is);
            
            // 检查下一个字符
            if (is.peek() == ']') {
                continue;  // 继续循环，下次迭代会处理结束括号
            } else if (is.peek() == ',') {
                is.ignore();  // 跳过逗号
            } else {
                std::cerr << "错误：期望逗号或']'" << std::endl;
                break;
            }
        }
        
        return matrix;
    }
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//链表创建
class ListCreate {
public:
    ListCreate() {
        dummy = new ListNode();
    }
    //尾插法
    ListNode* createList(std::vector<int>& vec) {
        if (vec.empty()) {
            return nullptr;
        }
        ListNode* cur = dummy;
        for (auto& a : vec) {
            ListNode* temp = new ListNode(a);
            temp->next = cur->next;
            cur->next = temp;
            cur = cur->next;
        }
        return dummy->next;
        
    }
private:
    ListNode* dummy;
};