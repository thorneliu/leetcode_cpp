#define MAXSIZE 1000

int calPoints(char** ops, int opsSize) {
    int stack[MAXSIZE] = {0};
    int top = -1;
    
    for (int i = 0; i < opsSize; i++)
    {
        char* str = ops[i];
        char c = str[0];
        
        switch (c)
        {
            case '+':
            {
                if (top >= 1)
                {
                    int score = stack[top] + stack[top-1];
                    stack[++top] = score;
                }
                break;
            }
            case 'D':
            {
                int score = stack[top];
                stack[++top] = score * 2;
                break;       
            }
            case 'C':
            {
                if (top >= 0)
                {
                    stack[top] = 0;
                    top--;
                }
                break;        
            }
            default:
            {
                int num = atoi(str);
                stack[++top] = num;
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i <= top; i++)
    {
        sum += stack[i];
    }
    
    return sum;
}
