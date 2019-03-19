void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int tail = m + n - 1;
    
    while(j >= 0)
    {
        nums1[tail--] = (i >=0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
    
    return;
}
