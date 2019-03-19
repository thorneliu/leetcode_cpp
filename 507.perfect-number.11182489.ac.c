bool checkPerfectNumber(int num) {
    if (num <= 2) return false;
    int sum = 1;
    int upper = sqrt(num);
    for(int i = 2; i <= upper; i++)
    {
        if (num % i == 0) sum += i + num/i;
    }
    
    return (sum == num);
}
