#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
float calculo (std::string calc);

int main ()
{
    
    while (true)
    {
        system("clear");
        setlocale(LC_ALL, "Portuguese");
        std::string cal;
        std::cout << "Calculadora extremamente genérico, Para sair aperte [s]\n>>>";
        try
        {
            std::getline(std::cin,cal);
            if (cal[0] == 'S' || cal[0] == 's')
            {
                break;
            }
            std::cout << ">>>" << calculo(cal) << std::endl;
            getch();
        }
        catch(const std::exception& e)
        {
            std::cerr << "Erro coloque um número" << '\n';
            getch();
        }
    }
    return 0;
    
}

float calculo (std::string calc)
{
    float mem1,mem2;
    char op;
    mem1 = stof(calc);
    for (int i = 0; i <= calc.length(); i++)
    {
        switch (calc[i])
        {
            case '+':
                op = calc[i];
                calc[i] = ' ';
                i++;
                mem2 = stof(calc);
                break;
            case '-':
                op = calc[i];
                calc[i] = ' ';
                i++;
                mem2 = stof(calc);
                break;
            case '*':
                op = calc[i];
                calc[i] = ' ';
                i++;
                mem2 = stof(calc);
                break;
            case '/':
                op = calc[i];
                calc[i] = ' ';
                i++;
                mem2 = stof(calc);
                break;
            case '^':
                op = calc[i];
                calc[i] = ' ';
                i++;
                mem2 = stof(calc);
                break;
        }
        calc[i] = ' ';
    }   
    switch (op)
    {
    case '+':
        return mem1 + mem2;
        break;
    case '-':
        return mem1 - mem2;
        break;
    case '*':
        return mem1 * mem2;
        break;
    case '/':
        return mem1 / mem2;
        break;
    case '^':
        return pow(mem1,mem2);
        break;
    
    default:
        return mem1;
        break;
    }
    return 0;
}