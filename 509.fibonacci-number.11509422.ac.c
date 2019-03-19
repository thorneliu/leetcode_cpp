int fib(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;
    int a0 = 0; int a1 = 1;
    int temp = 0;
    for (int i = 2; i <= N; i++)
    {
        temp = a1 + a0;
        a0 = a1;
        a1 = temp;
    }
    
    return a1;
}
