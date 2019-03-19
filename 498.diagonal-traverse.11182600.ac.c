/*
 * @lc app=leetcode.cn id=498 lang=c
 *
 * [498] 对角线遍历
 *
 * https://leetcode-cn.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (36.40%)
 * Total Accepted:    2.4K
 * Total Submissions: 6.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 输出:  [1,2,4,7,5,3,6,8,9]
 * 
 * 解释:
 * 
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 给定矩阵中的元素总数不会超过 100000 。
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef enum DIRECTION{UP, DOWN}DIRECTION;

typedef struct {
    int x;
    int y;
    int* p;
} Coordinate;

DIRECTION changeDirection(DIRECTION previousDirection){
    return previousDirection == UP ? DOWN : UP;
}

Coordinate getNextStartPoint(Coordinate previousEnd, DIRECTION previousDirection, int M, int N) {
    Coordinate c;
    if (previousDirection == UP)
    {
        if (previousEnd.y == N - 1)
        {
            c.x = previousEnd.x + 1;
            c.y = previousEnd.y;
        }
        else
        {
            c.x = previousEnd.x;
            c.y = previousEnd.y + 1;
        }
    }
    else
    {
        if (previousEnd.x == M -1)
        {
            c.y = previousEnd.y + 1;
            c.x = previousEnd.x;
        }
        else
        {
            c.y = previousEnd.y;
            c.x = previousEnd.x + 1;
        }
    }
    
    return c;
}



Coordinate traverseMatric(int** matrix, int* p, Coordinate start, DIRECTION directon, int M, int N)
{
    int x = start.x;
    int y = start.y;
    Coordinate end;
    
    int Previousx = 0;
    int Previousy = 0;
    
    if(directon == UP)
    {
        while(x >= 0 && y <= N-1)
        {
            *p = matrix[x][y];
            //printf("setting *p to matrix[%d][%d] = %d\n", x, y, matrix[x][y]);
            Previousx = x;
            Previousy = y;
            x = x - 1;
            y = y + 1;
            p++;
        }
    }
    else
    {
        while(y >= 0 && x <= M-1)
        {
            *p = matrix[x][y];
            //printf("setting *p to matrix[%d][%d] = %d\n", x, y, matrix[x][y]);
            Previousx = x;
            Previousy = y;
            y = y - 1;
            x = x + 1;
            p++;
        }
    }
    
    end.x = Previousx;
    end.y = Previousy;
    end.p = p;
    
    return end;
}

int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize) {
    if(matrixRowSize == 0 || matrixColSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int elementNumber = matrixRowSize * matrixColSize;
    *returnSize = elementNumber;
    int* res = (int*)malloc(sizeof(int) * elementNumber);
    memset(res, 0, sizeof(int) * elementNumber);
    
    Coordinate start;
    start.x = 0; 
    start.y = 0;
    DIRECTION direction = UP;
    
    int *p = res;
    Coordinate end = traverseMatric(matrix, p, start, direction, matrixRowSize, matrixColSize);
    //printf("End to (%d, %d)\n", end.x, end.y);
    while(p < (res + elementNumber -1))
    {
        start = getNextStartPoint(end, direction, matrixRowSize, matrixColSize);
        //printf("Start from (%d, %d)\n", start.x, start.y);
        direction = changeDirection(direction);
        p = end.p;
        end = traverseMatric(matrix, p, start, direction, matrixRowSize, matrixColSize);
        //printf("End to (%d, %d)\n", end.x, end.y);
    }

    return res;
}
