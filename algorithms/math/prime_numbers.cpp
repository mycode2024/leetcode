/**
 * @file prime_numbers.cpp
 * @brief 质数相关算法实现
 * @author Algorithm Practice
 * @date 2025-12-28
 * 
 * 包含质数判断、质数求和等算法
 */

#include <iostream>
#include <cmath>
#include <vector>

namespace PrimeAlgorithm {
    
    /**
     * @brief 判断一个数是否为质数
     * @param n 待判断的数
     * @return true 如果是质数，false 否则
     * 
     * 时间复杂度：O(√n)
     */
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        
        // 只需要检查到 √n
        for (int i = 3; i <= std::sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    /**
     * @brief 找出不超过 n 的所有质数
     * @param n 上限值
     * @return 质数向量
     * 
     * 使用埃拉托斯特尼筛法（Sieve of Eratosthenes）
     * 时间复杂度：O(n log log n)
     */
    std::vector<int> sieveOfEratosthenes(int n) {
        std::vector<bool> isPrime(n + 1, true);
        std::vector<int> primes;
        
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                
                // 标记 i 的所有倍数为非质数
                for (long long j = (long long)i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        return primes;
    }
    
    /**
     * @brief 计算不超过 n 的质数之和的最大值
     * @param n 上限值
     * @return 质数和（不超过 n）
     * 
     * 从小到大累加质数，直到和超过 n
     */
    int largestPrimeSum(int n) {
        int result = 0;
        
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) {
                // 如果加上当前质数会超过 n，则停止
                if (result + i > n) {
                    break;
                }
                
                result += i;
                std::cout << "质数: " << i << ", 累计和: " << result << std::endl;
            }
        }
        
        return result;
    }
    
    /**
     * @brief 打印不超过 n 的所有质数
     * @param n 上限值
     */
    void printPrimes(int n) {
        std::cout << "不超过 " << n << " 的所有质数：" << std::endl;
        
        int count = 0;
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) {
                std::cout << i << " ";
                count++;
                
                // 每行打印 10 个
                if (count % 10 == 0) {
                    std::cout << std::endl;
                }
            }
        }
        
        std::cout << std::endl;
        std::cout << "共 " << count << " 个质数" << std::endl;
    }
    
    /**
     * @brief 测试质数算法
     */
    void test() {
        std::cout << "=== 质数算法测试 ===" << std::endl;
        
        int n = 100;
        std::cout << "\n测试 1: 打印不超过 " << n << " 的所有质数" << std::endl;
        printPrimes(n);
        
        std::cout << "\n测试 2: 计算质数和（不超过 " << n << "）" << std::endl;
        int sum = largestPrimeSum(n);
        std::cout << "结果: " << sum << std::endl;
        
        std::cout << "\n测试 3: 使用埃拉托斯特尼筛法" << std::endl;
        auto primes = sieveOfEratosthenes(50);
        std::cout << "不超过 50 的质数: ";
        for (int p : primes) {
            std::cout << p << " ";
        }
        std::cout << std::endl;
    }
}

