/*
 * @lc app=leetcode.cn id=883 lang=c
 *
 * [883] 车队
 *
 * https://leetcode-cn.com/problems/projection-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (57.43%)
 * Total Accepted:    2K
 * Total Submissions: 3.5K
 * Testcase Example:  '[[2]]'
 *
 * 在 N * N 的网格中，我们放置了一些与 x，y，z 三轴对齐的 1 * 1 * 1 立方体。
 * 
 * 每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。
 * 
 * 现在，我们查看这些立方体在 xy、yz 和 zx 平面上的投影。
 * 
 * 投影就像影子，将三维形体映射到一个二维平面上。
 * 
 * 在这里，从顶部、前面和侧面看立方体时，我们会看到“影子”。
 * 
 * 返回所有三个投影的总面积。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[2]]
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2],[3,4]]
 * 输出：17
 * 解释：
 * 这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[1,0],[0,2]]
 * 输出：8
 * 
 * 
 * 示例 4：
 * 
 * 输入：[[1,1,1],[1,0,1],[1,1,1]]
 * 输出：14
 * 
 * 
 * 示例 5：
 * 
 * 输入：[[2,2,2],[2,1,2],[2,2,2]]
 * 输出：21
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length = grid[0].length <= 50
 * 0 <= grid[i][j] <= 50
 * 
 * 
 */
#define MAXSIZE 50

int projectionArea(int** grid, int gridRowSize, int *gridColSizes) {
    int colSize = *gridColSizes;
    
    int result = 0;
    int rowSkyLine[MAXSIZE] = {0};
    int colSkyLine[MAXSIZE] = {0};
    
    for (int i = 0; i < gridRowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            int element = grid[i][j];
            if (element > 0) result++;
            if (element > rowSkyLine[i]) rowSkyLine[i] = element;
            if (element > colSkyLine[j]) colSkyLine[j] = element;
        }
    }
    
    for (int i = 0; i < gridRowSize; i++)
    {
        result += rowSkyLine[i];
    }
    
    for (int i = 0; i < colSize; i++)
    {
        result += colSkyLine[i];
    }
    
    return result;
}