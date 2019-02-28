/*
 * @lc app=leetcode.cn id=892 lang=c
 *
 * [892] 和至少为 K 的最短子数组
 *
 * https://leetcode-cn.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (48.03%)
 * Total Accepted:    1.2K
 * Total Submissions: 2.6K
 * Testcase Example:  '[[2]]'
 *
 * 在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
 * 
 * 每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。
 * 
 * 返回结果形体的总表面积。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[2]]
 * 输出：10
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2],[3,4]]
 * 输出：34
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[1,0],[0,2]]
 * 输出：16
 * 
 * 
 * 示例 4：
 * 
 * 输入：[[1,1,1],[1,0,1],[1,1,1]]
 * 输出：32
 * 
 * 
 * 示例 5：
 * 
 * 输入：[[2,2,2],[2,1,2],[2,2,2]]
 * 输出：46
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 * 
 * 
 */
int min(int x, int y)
{
    return x < y ? x : y;
}

int surfaceArea(int** grid, int gridRowSize, int *gridColSizes) {
    int AdjacentCnt = 0;
    int gridColSize = gridColSizes[0];
    int element = 0;
    int numberofCubes = 0;
    
    for (int i = 0; i < gridRowSize; i++)
    {
        for (int j = 0; j < gridColSize; j++)
        {
            element = grid[i][j];
            numberofCubes += element;
            if (element >= 1) AdjacentCnt += element - 1; // the Z-axis adjacent number
            
            if (j + 1 < gridColSize)
            {
                AdjacentCnt += min(element, grid[i][j+1]); // the X-axis adjacent number
            }
            
            if (i + 1 < gridRowSize)
            {
                AdjacentCnt += min(element, grid[i+1][j]); // the Y-axis adjacent number
            }
        }
    }
    
    return numberofCubes * 6 - 2 * AdjacentCnt;
}
