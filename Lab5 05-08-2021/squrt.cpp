#include<iostream>

int main()
{
    int n;
    std::cout<<"n: ";
    std::cin>>n;
    int num = 1, squrt = 1;
    while (num <= n)
    {
        squrt++;
        num = squrt * squrt;
    }
    printf("squrt(%d) = %d\n", n, squrt-1);
    return 0;
}