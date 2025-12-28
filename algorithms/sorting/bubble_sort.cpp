/**
 * @file bubble_sort.cpp
 * @brief 冒泡排序算法实现
 * @author Algorithm Practice
 * @date 2025-12-28
 * 
 * 算法描述：
 * 冒泡排序是一种简单的排序算法。它重复地遍历要排序的数列，
 * 一次比较两个元素，如果它们的顺序错误就把它们交换过来。
 * 遍历数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
 * 
 * 算法特点：
 * - 稳定排序
 * - 原地排序
 * - 时间复杂度：最好 O(n)，平均 O(n²)，最坏 O(n²)
 * - 空间复杂度：O(1)
 */

#include <iostream>
#include <vector>
#include <utility>

namespace BubbleSorter {
    
    /**
     * @brief 冒泡排序（优化版）
     * @param arr 待排序的整数数组
     * 
     * 优化点：
     * 1. 使用 swapped 标志，如果某一轮没有发生交换，说明已经有序，提前退出
     * 2. 每轮排序后，最大的元素会"冒泡"到末尾，下一轮可以减少比较次数
     */
    void bubbleSort(std::vector<int>& arr) {
        size_t n = arr.size();
        
        // 外层循环：控制排序轮数
        for (size_t i = 0; i < n - 1; i++) {
            bool swapped = false;  // 标记本轮是否发生交换
            
            // 内层循环：进行相邻元素比较和交换
            // n - i - 1：因为每轮后最后 i 个元素已经有序
            for (size_t j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            
            // 优化：如果本轮没有发生交换，说明数组已经有序
            if (!swapped) {
                break;
            }
        }
    }
    
    /**
     * @brief 打印数组
     * @param arr 整数数组
     * @param prefix 前缀字符串
     */
    void printArray(const std::vector<int>& arr, const char* prefix = "Array") {
        std::cout << prefix << ": ";
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i];
            if (i < arr.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    /**
     * @brief 测试冒泡排序
     */
    void test() {
        std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
        
        std::cout << "=== 冒泡排序测试 ===" << std::endl;
        printArray(arr, "排序前");
        
        bubbleSort(arr);
        
        printArray(arr, "排序后");
    }
}

