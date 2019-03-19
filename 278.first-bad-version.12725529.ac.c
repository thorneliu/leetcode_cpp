// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int l = 1;
    int h = n;
    
    while (l <= h)
    {
        int m = l + (h - l)/2;
        if (isBadVersion(m))
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    
    return l;
}
