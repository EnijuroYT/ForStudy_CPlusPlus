/*Напечатайте месяц из календаря по заданному начальному дню и количеству дней*/

#include <iostream>
#include <iomanip>

int main()
{
    unsigned int n, k;
    std::cin >> n >> k;
    std::cout << std::setw(3 * n - 1) << 1;
    if (k == 1)
    {
        std::cout << "\n";
    }
    for (unsigned int i = 2; i != k + 1; ++i)
    {
        if (n == 7)
        {
            std::cout << "\n";
            n = 1;
        }
        else
        {
            std::cout << " ";
            n++;
        }
        std::cout << std::setw(2) << i;
    }
    if (n != 1)
    {
        std::cout << "\n";
    }
    return 0;
}