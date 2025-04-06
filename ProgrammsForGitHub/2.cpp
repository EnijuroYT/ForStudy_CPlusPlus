/*Задание из университета, для уравнения x^2-4x+1 искал минимум, 
сначала методом отрезков был найден отрезок, содержащий этот минимум, 
а затем методом дихотомии и методом золотого сечения был найден минимум на этом отрезке */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


float y(float x)
{
    return (pow(x, 2) - 4 * x + 1);
}

std::vector<float> otr(float delta, float x)
{
    std::cout << "Task 1:\n" << '\n';
    int i, k = 0;
    float xkplus1 = 0, xkminus1;
    float yznach = y(x);
    std::vector<float> otrez(2);
    std::cout << "x" << std::left << std::setw(2) << k << " = " << std::setprecision(2) << std::fixed << std::setw(3) << xkplus1 << "   f(x" << k << ") = " << std::setprecision(4) << std::fixed << std::setw(3) << yznach << '\n';
    for (i = 0; i != 3; ++i)
    {
        if (y(x + delta) >= y(x))
        {
            delta = -delta;
            if (y(x + delta) >= y(x))
            {
                delta /= 2;
            }
            else {
                k++;
                xkplus1 = x + delta;
                break;
            }
        }
        else {
            k++;
            xkplus1 = x + delta;
            break;
        }
        if (i == 2 && y(x + delta) == y(x))
        {
            otrez = { x + delta, x - delta };
            std::sort(otrez.begin(), otrez.end());
            return otrez;
        }
    }
    std::cout << "x" << std::left << std::setw(2) << k << " = " << std::setprecision(2) << std::fixed << std::setw(3) << xkplus1 << "   f(x" << k << ") = " << std::setprecision(4) << std::fixed << std::setw(3) << yznach << '\n';
    while (k < 100)
    {
        xkminus1 = x;
        x = xkplus1;
        xkplus1 = x + delta;
        yznach = y(xkplus1);

        if (yznach < y(x))
        {
            k++;
        }
        else {
            otrez = { xkminus1, xkplus1 };
            std::sort(otrez.begin(), otrez.end());
            return otrez;
        }
        std::cout << "x" << std::left << std::setw(2) << k << " = " << std::setprecision(2) << std::fixed << std::setw(3) << xkplus1 << "   f(x" << k << ") = " << std::setprecision(4) << std::fixed << std::setw(3) << yznach << '\n';

    }
    otrez = { xkminus1, xkplus1 };
    std::sort(otrez.begin(), otrez.end());
    return otrez;
}

float dithom(float a, float b, float delta, float eps)
{
    float x1, x2, y1, y2;
    std::cout << "Task 2:\n\n";
    std::cout << std::setw(8) << "  a  " << std::setw(9) << "  b  " << std::setw(9) << "  x1  " << std::setw(9) << "  x2  " << std::setw(11) << "  f(x1)  " << std::setw(11) << "  f(x2)  " << std::setw(9) << "(b-a)/2\n\n";
    while (((b - a) / 2) > eps)
    {
        x1 = (a + b - delta) / 2;
        x2 = (a + b + delta) / 2;
        y1 = y(x1);
        y2 = y(x2);
        if (y1 <= y2)
        {
            b = x2;
        }
        else
        {
            a = x1;
        }
        std::cout << std::setprecision(2) << std::fixed << std::setw(9) << a << std::setprecision(2) << std::fixed << std::setw(9) << b << std::setw(9) << std::setprecision(2) << std::fixed << x1 << std::setw(9) << std::setprecision(2) << std::fixed << x2 << std::setw(11) << std::setprecision(4) << std::fixed << y1 << std::setw(11) << std::setprecision(4) << std::fixed << y2 << std::setw(9) << std::setprecision(4) << std::fixed << (b - a) / 2 << '\n';
    }
    return ((a + b) / 2);

}

float golden(float a, float b, float eps) {
    int i = 0, k = 0;
    float deltakplus1, deltakplus2, deltak = b - a, lymbda = (sqrt(5) - 1) / 2, M, avolna = 0, bvolna = 0;
    std::vector<float> M_vector(4), x_vector(4);
    std::cout << "Task 3:\n\n" << std::setw(6) << 'k' << std::setw(8) << 'a' << std::setw(8) << "a~" << std::setw(8) << "b~" << std::setw(8)
        << 'b' << std::setw(12) << "fmin(x)   " << std::setw(12) << "b - a   " << std::setw(12) << "f(a)" << std::setw(12) <<
        "f(a~)" << std::setw(12) << "f(b~)" << std::setw(12) << "f(b)" << '\n';;
    deltakplus1 = lymbda * deltak;
    while (deltak > eps) {

        deltakplus2 = deltak - deltakplus1;
        avolna = a + deltakplus2;
        bvolna = b - deltakplus2;
        M_vector = { y(a), y(avolna), y(bvolna), y(b) };

        auto M_i = std::min_element(M_vector.begin(), M_vector.end());
        i = std::distance(M_vector.begin(), M_i);
        std::cout << std::setw(6) << k << std::setw(8) << std::setprecision(2) << std::fixed << a << std::setw(8) << std::setprecision(2) << std::fixed << avolna << std::setw(8) << std::setprecision(2) << std::fixed << bvolna << std::setw(8)
            << std::setprecision(2) << std::fixed << b << std::setw(12) << std::setprecision(4) << std::fixed << *M_i << std::setw(12) << std::setprecision(4) << std::fixed << b - a << std::setw(12) << std::setprecision(4) << std::fixed << y(a) << std::setw(12) <<
            y(avolna) << std::setw(12) << y(bvolna) << std::setw(12) << y(b) << '\n';
        if (i == 0 || i == 1) {
            b = bvolna;
        }
        else {
            a = avolna;
        }

        k++;
        deltak = deltakplus1;
        deltakplus1 = deltakplus2;

    }
    x_vector = { a,avolna,bvolna,b };
    return x_vector[i];

}

int main()
{

    float dit, gold;
    float eps = 0.09;
    float delta = 0.1;
    float x0 = 0;
    std::vector<float> otrez(2);
    otrez = otr(delta, x0);
    std::cout << "\n[a,b] = [" << std::setprecision(2) << std::fixed << otrez[0] << ", " << std::setprecision(2) << std::fixed << otrez[1] << "]\n\n\n";
    dit = dithom(otrez[0], otrez[1], delta, eps);
    std::cout << "\nx*= " << std::setprecision(2) << std::fixed << dit << "\nf(x*) " << std::setprecision(4) << std::fixed << y(dit) << "\n\n\n";
    gold = golden(otrez[0], otrez[1], eps);
    std::cout << "\nx*= " << std::setprecision(2) << std::fixed << gold << "\nf(x*) = " << std::setprecision(4) << std::fixed << y(gold) << "\n\n\n";

}

