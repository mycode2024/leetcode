/**
 * @file LeetcodeUtils.h
 * @brief LeetCode 输入输出工具类
 * @author LeetCode Practice
 * @date 2025-12-28
 *
 * 提供 LeetCode 格式的数据输入输出功能
 * 支持一维数组、二维数组、字符串数组的读取和打印
 */

#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// 调试宏：打印变量名和值
#define debug(x) std::cout << #x << " = " << (x) << std::endl

/**
 * @class LeetcodeInput
 * @brief LeetCode 输入处理工具类
 *
 * 功能：解析 LeetCode 格式的输入数据
 * 职责：
 *   - 读取一维整数数组（如 [1,2,3,4,5]）
 *   - 读取二维整数数组（如 [[1,2],[3,4]]）
 *   - 读取字符串数组（如 ["hello","world"]）
 *   - 打印数组内容（用于调试）
 * 使用场景：LeetCode 题目的本地测试
 */
class LeetcodeInput {
public:
    /**
     * @brief 跳过输入流中的空白字符
     * @param inputStream 输入流引用
     *
     * 功能：跳过输入流中的所有空白字符（空格、制表符、换行符等）
     * 用途：在解析 LeetCode 格式输入时忽略格式化空白
     */
    static void _skipWhitespace(std::istream& inputStream) {
        while (isspace(inputStream.peek())) {
            inputStream.ignore();
        }
    }

    /**
     * @brief 打印二维数组（用于调试）
     * @param matrix 二维整数数组
     *
     * 功能：以 LeetCode 格式打印二维数组
     * 用途：调试时查看二维数组内容
     *
     * 示例输出：[[1,2,3],[4,5,6],[7,8,9]]
     */
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
    
    /**
     * @brief 读取 LeetCode 格式的字符串数组
     * @return 字符串向量
     *
     * 功能：解析 LeetCode 格式的字符串数组输入
     * 输入格式：["hello","world","test"]
     * 返回值：包含所有字符串的 vector
     *
     * 时间复杂度：O(n)，n 为输入字符串总长度
     * 空间复杂度：O(n)
     *
     * 示例：
     *   输入：["eat","tea","tan","ate"]
     *   返回：{"eat", "tea", "tan", "ate"}
     */
    static std::vector<std::string> readStringArray() {
        std::vector<std::string> resultArray;
        std::string inputLine;

        // 读取整行输入
        std::getline(std::cin, inputLine);

        // 移除方括号
        if (inputLine.front() == '[' && inputLine.back() == ']') {
            inputLine = inputLine.substr(1, inputLine.length() - 2);
        }

        std::stringstream stringStream(inputLine);
        std::string token;

        // 按逗号分割，并移除引号
        while (std::getline(stringStream, token, ',')) {
            // 移除空格和引号
            size_t startPos = token.find_first_of('"');
            size_t endPos = token.find_last_of('"');

            if (startPos != std::string::npos && endPos != std::string::npos && startPos < endPos) {
                std::string word = token.substr(startPos + 1, endPos - startPos - 1);
                resultArray.push_back(word);
            }
        }

        return resultArray;
    }
    
    /**
     * @brief 读取 LeetCode 格式的一维整数数组
     * @param inputStream 输入流引用
     * @return 整数向量
     *
     * 功能：解析 LeetCode 格式的一维整数数组
     * 输入格式：[1,2,3,4,5]
     * 返回值：包含所有整数的 vector
     *
     * 时间复杂度：O(n)，n 为数组长度
     * 空间复杂度：O(n)
     *
     * 示例：
     *   输入：[2,7,11,15]
     *   返回：{2, 7, 11, 15}
     */
    static std::vector<int> readArray1D(std::istream& inputStream) {
        std::vector<int> numberArray;

        _skipWhitespace(inputStream);
        if (inputStream.peek() != '[') {
            std::cerr << "错误：输入应以'['开头" << std::endl;
            return numberArray;
        }
        inputStream.ignore();  // 跳过'['

        while (true) {
            _skipWhitespace(inputStream);

            // 检查是否到达结束
            if (inputStream.peek() == ']') {
                inputStream.ignore();
                break;
            }

            // 读取数字
            int currentNumber;
            if (inputStream >> currentNumber) {
                numberArray.push_back(currentNumber);
            } else {
                std::cerr << "错误：读取数字失败" << std::endl;
                inputStream.clear();
                inputStream.ignore();
                break;
            }

            _skipWhitespace(inputStream);

            // 检查下一个字符
            if (inputStream.peek() == ']') {
                continue;
            } else if (inputStream.peek() == ',') {
                inputStream.ignore();
            } else {
                std::cerr << "错误：期望逗号或']'" << std::endl;
                break;
            }
        }

        return numberArray;
    }

    /**
     * @brief 读取 LeetCode 格式的二维整数数组
     * @param inputStream 输入流引用
     * @return 二维整数向量
     *
     * 功能：解析 LeetCode 格式的二维整数数组
     * 输入格式：[[1,2,3],[4,5,6],[7,8,9]]
     * 返回值：包含所有行的二维 vector
     *
     * 时间复杂度：O(m*n)，m 为行数，n 为列数
     * 空间复杂度：O(m*n)
     *
     * 示例：
     *   输入：[[1,2],[3,4],[5,6]]
     *   返回：{{1,2}, {3,4}, {5,6}}
     */
    static std::vector<std::vector<int>> readArray2D(std::istream& inputStream) {
        std::vector<std::vector<int>> matrixArray;

        _skipWhitespace(inputStream);
        if (inputStream.peek() != '[') {
            std::cerr << "错误：二维数组输入应以'['开头" << std::endl;
            return matrixArray;
        }
        inputStream.ignore();  // 跳过外层'['

        while (true) {
            _skipWhitespace(inputStream);

            // 检查是否到达结束
            if (inputStream.peek() == ']') {
                inputStream.ignore();
                break;
            }

            // 检查是否为空矩阵
            if (matrixArray.empty() && inputStream.peek() == ']') {
                inputStream.ignore();
                break;
            }

            // 读取一维数组（子数组）
            if (inputStream.peek() == '[') {
                std::vector<int> rowArray = readArray1D(inputStream);
                if (!inputStream.fail()) {
                    matrixArray.push_back(rowArray);
                } else {
                    std::cerr << "错误：读取子数组失败" << std::endl;
                    break;
                }
            } else {
                std::cerr << "错误：期望'['开始子数组" << std::endl;
                break;
            }

            _skipWhitespace(inputStream);

            // 检查下一个字符
            if (inputStream.peek() == ']') {
                continue;
            } else if (inputStream.peek() == ',') {
                inputStream.ignore();
            } else {
                std::cerr << "错误：期望逗号或']'" << std::endl;
                break;
            }
        }

        return matrixArray;
    }
};

#endif // LEETCODE_UTILS_H

