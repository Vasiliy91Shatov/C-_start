int sum(int a, int b)
{
    return a + b;
}
//умножение
int um(int a, int b)
{
    return a * b;
}
//степень
int st(int a, int b)
{
    int aa = a;
    for(int i = 1; i < b; i++)
        a *= aa;
    return a;
}
//простые числа
int prch(int a)
{
    int b = 0;
    for(int i =1; i <= a; i++)
    {
        if(a % i == 0)
             b++;
        else
            continue;
        if( b == 3)
            return 0;
    }
    return (b < 3) ? 1: 0;
}