int smallestRangeI(int* A, int ASize, int K) {
    if (A == NULL || ASize <= 0) return 0;
    
    int min = A[0], max = A[0], element = 0;
    for (int i = 1; i < ASize; i++)
    {
        element = A[i];
        if (element > max) max = element;
        if (element < min) min = element;
    }
    
    int diff = max - min - 2 * K;
    return diff < 0 ? 0 : diff;
}
