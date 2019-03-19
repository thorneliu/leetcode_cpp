int findTargetSumWays(int* nums, int numsSize, int S) {
    if (nums == NULL || numsSize <= 0) return 0;
    if (numsSize == 1)
    {
        int ans = 0;
        if (nums[0] == S) ans++;
        if (-nums[0] == S) ans++;
        return ans;
    }
    else
    {
        return findTargetSumWays(nums+1, numsSize - 1, S + nums[0]) + 
               findTargetSumWays(nums+1, numsSize - 1, S - nums[0]);
    }
}
