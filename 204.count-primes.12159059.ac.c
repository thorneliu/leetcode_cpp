/*
 * @lc app=leetcode.cn id=204 lang=c
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.28%)
 * Total Accepted:    12.6K
 * Total Submissions: 47.9K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */
int countPrimes(int n) {
    if (n <= 2) return 0;
    
    bool *isPrime = malloc(sizeof(bool) * n);
    memset(isPrime, true, n);

    int primeCount = 1 ; // 2 is the only even number that is a prime  
    
    for(int i = 3; i < n; i = i+2) { // only odd numbers can be primes
        
        if(isPrime[i]) { //is a prime number
            primeCount++;
            //sieve all multiples
            for(int j = i; j < n; j = j+i) {
                isPrime[j] = false;
            }
        } 
    }
    
    return primeCount;
}
