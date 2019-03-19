int compFunc(void* a, void* b)
{
    return *((int *)a) - *((int*)b);
}

int largestPerimeter(int* A, int ASize) {
    qsort(A, ASize, sizeof(int), compFunc);
    
    int i = ASize - 1;
    for (; i >= 2; i--)
    {
        if (A[i] < (A[i-1] + A[i-2])) return A[i] + A[i-1] + A[i-2];
    }
    
    return 0;
}
