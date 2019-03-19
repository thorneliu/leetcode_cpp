/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    
    // the four bundary values in this traverse..
    int Xmin; 
    int Xmax;
    int Ymin;
    int Ymax;
    
    int* p; // the running pointer
} TraverseContext;

TraverseContext runOneSpiral(TraverseContext context, int** matrix)
{
    TraverseContext next;
    int *p = context.p;
    if (context.Xmin == context.Xmax)
    {
        // This is the last traverse, going down in Y axis
        for (int i = context.Ymin; i <= context.Ymax; i++)
        {
            *p = matrix[context.Xmin][i];
            p++;
        }
        
        next.start.x = context.start.x;
        next.start.y = context.start.y;
        next.p = p;
        return next;
    }
    else if (context.Ymin == context.Ymax)
    {
        // this is another last traverse, going right in X axis
        for (int i = context.Xmin; i <= context.Xmax; i++)
        {
            *p = matrix[i][context.Ymin];
            p++;
        }
        
        next.start.x = context.start.x;
        next.start.y = context.start.y;
        next.p = p;
        return next;
    }
    else
    {
        // we can still go one circle
        // 1. going right
        for (int i = context.start.y; i <= context.Ymax; i++)
        {
            *p = matrix[context.Xmin][i];
            p++;
        }
        
        // 2. going down
        for (int i = context.Xmin + 1; i <= context.Xmax; i++)
        {
            *p = matrix[i][context.Ymax];
            p++;
        }
     
        // 3. going left
        for (int i = context.Ymax - 1; i >= context.Ymin; i--)
        {
            *p = matrix[context.Xmax][i];
            p++;
        }
        
        // 4. going up
        for (int i = context.Xmax - 1; i >= context.Xmin + 1; i--)
        {
            *p = matrix[i][context.Ymin];
            p++;
        }
        
        next.start.x = context.start.x + 1;
        next.start.y = context.start.y + 1;
        next.Xmin = context.Xmin + 1;
        next.Xmax = context.Xmax - 1;
        next.Ymin = context.Ymin + 1;
        next.Ymax = context.Ymax - 1;
        next.p = p;
        return next;
    }
}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    if (matrix == NULL || matrixRowSize == 0 || matrixColSize==0) return NULL;
    int returnSize = matrixRowSize * matrixColSize;
    int* p = (int *)malloc(sizeof(int) * returnSize);
    memset(p, 0, sizeof(int) * returnSize);
    
    TraverseContext start;
    start.start.x = 0;
    start.start.y = 0;
    start.Xmin = 0;
    start.Xmax = matrixRowSize - 1;
    start.Ymin = 0;
    start.Ymax = matrixColSize - 1;
    start.p = p;
    
    TraverseContext next = runOneSpiral(start, matrix);
    while (!(next.start.x == start.start.x && next.start.y == start.start.y))
    {
        if (next.Xmin > next.Xmax || next.Ymin > next.Ymax) break;
        start = next;
        next  = runOneSpiral(start, matrix);
    }
    
    return p;
}
