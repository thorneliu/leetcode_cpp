/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 *
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (42.98%)
 * Total Accepted:    5K
 * Total Submissions: 11.5K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 根据逆波兰表示法，求表达式的值。
 * 
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 * 
 * 说明：
 * 
 * 
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 * 
 * 
 * 示例 1：
 * 
 * 输入: ["2", "1", "+", "3", "*"]
 * 输出: 9
 * 解释: ((2 + 1) * 3) = 9
 * 
 * 
 * 示例 2：
 * 
 * 输入: ["4", "13", "5", "/", "+"]
 * 输出: 6
 * 解释: (4 + (13 / 5)) = 6
 * 
 * 
 * 示例 3：
 * 
 * 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * 输出: 22
 * 解释: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> sStack;
        for (auto & s : tokens)
        {
            if(isOperator(s) && sStack.size() >= 2)
            {
                //std::cout << "new operator: " << s << std::endl; 
                auto op2 = sStack.top();
                sStack.pop();
                auto op1 = sStack.top();
                sStack.pop();
                auto result = calculate(op1, op2, s);
                sStack.push(result);
            }
            else
            {
                sStack.push(s);
            }
        }
        
        return stoi(sStack.top());
    }
    
private:
    bool isOperator(string& str)
    {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
    
    string calculate(const string& strop1, const string& strop2, const string& op)
    {
        int op1 = stoi(strop1);
        int op2 = stoi(strop2);
        //std::cout << op1 << op << op2 << std::endl;
        if (op == "+")
        {
            return to_string(op1 + op2);        
        }
        else if (op == "-")
        {
            return to_string(op1 - op2);        
        }
        else if (op == "*")
        {
            return to_string(op1 * op2);        
        }
        else
        {
            return to_string(op1 / op2);        
        }
    }
};
