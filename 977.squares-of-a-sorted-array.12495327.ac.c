/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int abs(int x)
{
    return x < 0 ? -x : x;
}

int comfunc(void* pa, void* pb)
{
    int a = *(int *)pa;
    int b = *(int *)pb;
    
    return abs(a) - abs(b);
}

int* sortedSquares(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int* res = (int*)malloc(sizeof(int) * ASize);
    memset(res, 0, sizeof(int) * ASize);
    
    // if A[0] * A[ASize - 1] >=0, then abs(A[i]) already in order
    if (A[0] * A[ASize - 1] >= 0)
    {
        if (A[0] < 0)
        {
            // reversed order
            for (int i = 0; i < ASize; i++)
            {
                res[ASize - 1 - i] = A[i] * A[i];
            }
        }
        else
        {
            for (int i = 0; i < ASize; i++)
            {
                res[i] = A[i] * A[i];
            }
        }
        
        return res;
    }
    
    // else, abs(A[i]) not in order
    qsort(A, ASize, sizeof(int), comfunc);
    for (int i = 0; i < ASize; i++)
    {
        res[i] = A[i] * A[i];
    }
    
    return res;
}
