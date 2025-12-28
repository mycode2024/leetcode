/**
 * @file ListUtils.h
 * @brief 链表数据结构和工具类
 * @author LeetCode Practice
 * @date 2025-12-28
 *
 * 提供链表节点定义和链表操作工具
 * 支持链表的创建、打印和内存释放
 */

#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include <vector>
#include <iostream>

/**
 * @struct ListNode
 * @brief 单链表节点定义
 *
 * 功能：表示单向链表中的一个节点
 * 职责：存储节点值和指向下一个节点的指针
 * 使用场景：LeetCode 链表相关题目
 */
struct ListNode {
    int val;              ///< 节点值
    ListNode *next;       ///< 指向下一个节点的指针

    /**
     * @brief 默认构造函数
     *
     * 创建值为 0，next 为 nullptr 的节点
     */
    ListNode() : val(0), next(nullptr) {}

    /**
     * @brief 带值的构造函数
     * @param x 节点值
     *
     * 创建值为 x，next 为 nullptr 的节点
     */
    ListNode(int x) : val(x), next(nullptr) {}

    /**
     * @brief 带值和下一节点的构造函数
     * @param x 节点值
     * @param next 指向下一个节点的指针
     *
     * 创建值为 x，next 指向指定节点的节点
     */
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * @class ListUtils
 * @brief 链表工具类
 *
 * 功能：提供链表的创建、打印和内存管理功能
 * 职责：
 *   - 从数组创建链表
 *   - 打印链表内容（用于调试）
 *   - 释放链表内存
 * 使用场景：LeetCode 链表题目的测试和调试
 */
class ListUtils {
public:
    /**
     * @brief 构造函数，初始化虚拟头节点
     *
     * 创建一个虚拟头节点，用于简化链表操作
     */
    ListUtils() {
        _dummyHead = new ListNode();
    }

    /**
     * @brief 析构函数，释放虚拟头节点
     *
     * 自动释放虚拟头节点占用的内存
     */
    ~ListUtils() {
        delete _dummyHead;
    }

    /**
     * @brief 使用尾插法从数组创建链表
     * @param vec 整数数组，包含链表节点的值
     * @return 链表头节点指针，如果数组为空则返回 nullptr
     *
     * 功能：将整数数组转换为单向链表
     * 时间复杂度：O(n)，n 为数组长度
     * 空间复杂度：O(1)，不包括链表本身占用的空间
     *
     * 示例：
     *   vector<int> vec = {1, 2, 3, 4, 5};
     *   ListNode* head = createList(vec);
     *   // 创建链表: 1 -> 2 -> 3 -> 4 -> 5
     */
    ListNode* createList(std::vector<int>& vec) {
        if (vec.empty()) {
            return nullptr;
        }

        ListNode* currentNode = _dummyHead;
        for (auto& value : vec) {
            ListNode* newNode = new ListNode(value);
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            currentNode = currentNode->next;
        }

        return _dummyHead->next;
    }

    /**
     * @brief 打印链表（用于调试）
     * @param head 链表头节点指针
     *
     * 功能：以 "1 -> 2 -> 3" 的格式打印链表
     * 用途：调试时查看链表内容
     *
     * 示例输出：1 -> 2 -> 3 -> 4 -> 5
     */
    static void printList(ListNode* head) {
        ListNode* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->val;
            if (currentNode->next != nullptr) {
                std::cout << " -> ";
            }
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief 释放链表内存
     * @param head 链表头节点指针
     *
     * 功能：释放整个链表占用的内存
     * 用途：防止内存泄漏
     * 注意：调用后 head 指针将失效，不应再使用
     *
     * 时间复杂度：O(n)，n 为链表长度
     */
    static void freeList(ListNode* head) {
        while (head != nullptr) {
            ListNode* tempNode = head;
            head = head->next;
            delete tempNode;
        }
    }

private:
    ListNode* _dummyHead;  ///< 虚拟头节点，用于简化链表操作
};

#endif // LIST_UTILS_H

