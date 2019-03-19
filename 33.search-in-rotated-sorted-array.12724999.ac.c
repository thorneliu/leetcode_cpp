int binarySearch(int* nums, int l, int h, int target)
{
    while(l < h)
    {
        int m = l + (h - l)/2;
        if (nums[m] == target) return m;
        if (nums[m] > target)
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    
    return -1;
}

int search(int* nums, int numsSize, int target) {
    int l = 0;
    int h = numsSize;
    
    while (l < h)
    {
        int m = l + (h - l) / 2;
        if (nums[m] == target) return m;
        if (nums[m] > nums[l])
        {
            if (target < nums[m] && target >= nums[l])
            {
                return binarySearch(nums, l, m, target);
            }
            else
            {
                l = m + 1;
            }
        }
        else
        {
            if (target > nums[m] && target <= nums[h-1])
            {
                return binarySearch(nums, m, h, target);
            }
            else
            {
                h = m;   
            }
        }
    }
    
    return -1;
}


