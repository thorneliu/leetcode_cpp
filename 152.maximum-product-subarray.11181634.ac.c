/*
 * @lc app=leetcode.cn id=152 lang=c
 *
 * [152] 乘积最大子序列
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (31.86%)
 * Total Accepted:    4.8K
 * Total Submissions: 15K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */
#define MAX(a,b) ((a) > (b) ?  (a):(b))
#define ABS(a) ((a) > 0 ? (a):(-a))

int maxofThree(int a, int b, int c)
{
    if (a > b)
        return MAX(a,c);
    else
        return MAX(b,c);
}

int productOfArray(int* array, int idxbegin, int idxend)
{
    int product = 1;
    for (int i = idxbegin; i <= idxend; i++)
        product = product * array[i];
        
    return product;
}

int maxProduct(int* nums, int numsSize) {
    if(NULL ==nums)
    {
        return ~0U;
    }
    
    if (numsSize <=0) return 0;
    if (1 == numsSize) return *nums;
    
    //calculate the product of subarrays with NO zeros
    for (int i = 0; i < numsSize; i++)
    {
        if (0 == nums[i])
        {
            printf("Zero element at %d.\n", i);
            int maxProduct1 = maxProduct(nums, i);
            int maxProduct2 = maxProduct(nums + i + 1, numsSize - i - 1);
            
            return maxofThree(maxProduct1, maxProduct2, 0);
        }
    }
    
    int lNegEleIdx = 0;
    int rNegEleIdx = 0;
    int negEleCnt = 0;
    int lNegEleFound = 0;
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
        {
            if (!lNegEleFound)
            {
                lNegEleIdx = i;
                lNegEleFound = 1;
            }
            
            rNegEleIdx = i;
            negEleCnt++;
        }
    }
    
    printf("l = %d, r = %d, cnt = %d.\n", lNegEleIdx, rNegEleIdx, negEleCnt);
    
    if (negEleCnt%2 == 0)
        return productOfArray(nums, 0, numsSize-1);
    else
    {
        //pick up the leftside array or rightside array to get the max product
        int leftArrayProduct = productOfArray(nums, 0, lNegEleIdx);
        int rightArrayProduct = productOfArray(nums, rNegEleIdx, numsSize - 1);
        
        if (ABS(leftArrayProduct) > ABS(rightArrayProduct))
        {
            return productOfArray(nums, 0, rNegEleIdx -1);
        }
        else
        {
            return productOfArray(nums, lNegEleIdx+1, numsSize -1);
        }
    }
}
