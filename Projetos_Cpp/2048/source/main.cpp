#include "header.hpp"

int main ()
{
    char escolha;
    bool res = true;
    while (res == true)
    {
        srand(time(NULL));
        system("clear");
        std::cout << "2048, EM CLI\n[1]-Novo Jogo\n[2]-Sair\n";
        escolha = getch();
        switch (escolha)
        {
        case '1':
            create();
            while (tableIsFull() == false)
            {
                core();
            }
            break;
        
        case '2':
            res = false;
            break;
        }
    }
    
}

