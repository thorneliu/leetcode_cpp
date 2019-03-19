/*
 * @lc app=leetcode.cn id=223 lang=c
 *
 * [223] 矩形面积
 *
 * https://leetcode-cn.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (42.30%)
 * Total Accepted:    1.4K
 * Total Submissions: 3.3K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * 在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
 * 
 * 每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: -3, 0, 3, 4, 0, -1, 9, 2
 * 输出: 45
 * 
 * 说明: 假设矩形面积不会超出 int 的范围。
 * 
 */
int interSection(int a1, int a2, int b1, int b2)
{
	if(a1 > a2 || b1 > b2) return 0;
	
	//case0, a1a2
	if(a1 >= b1 && a2 <= b2) return (a2 - a1);
	
	//case1, b1b2
	if(b1 >= a1 && b2 <= a2) return (b2 - b1);
	
	//case2, b1a2
	if(a1 <= b1 && b1 <= a2 && a2 <= b2) return (a2 - b1);
	
	//case3, a1b2
	if(b1 <= a1 && a1 <= b2 && b2 <= a2) return (b2 - a1);
	
	//case4, no intersection
	if(a2 <= b1 || b2 <= a1) return 0;
	
	return 0;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int width = interSection(A,C,E,G);
    int height = interSection(B,D,F,H);
    
    return ((C-A)*(D-B) + (G-E)*(H-F)-width*height);
}
