#include "header.hpp"
short  int matrix [6] [6];
void create () {
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            matrix [i] [j] = 0;
        }
    }
    for (int k = 0; k < 2; k++) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        int value = (rand() % 2 + 1) * 2; // Generate 2 or 4 randomly
        matrix[i][j] = value;
    }
}

void core ()
{
    char l;
    system("clear");
    std::cout << "CONTROLES\n[W]-CIMA  [S]-BAIXO  [A]-ESQUERDA  [D]-DIREITA\n";
    for (int i; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << matrix[i] [j] << "  ";
        }
        std::cout << std::endl; 
    }
    l = getch();
    l = toupper(l);
    move(l);
    if (is_won() == true)
    {
        system("clear");
        std::cout << "VOCÊ GANHOU !!!\n";
        getch();
        for (int i = 0; i < SIZE; i++)
        {
        for (int j = 0; j< SIZE; j++)
        {
            matrix [i] [j] = 1;
        }
        }
    }
    if (tableIsFull() == true)
    {
        system("clear");
        std::cout << "VOCÊ PERDEU !!!\n";
    }
}
bool tableIsFull()
{
    short int signal = 0;
    for (short int i = 0; i < SIZE ; i++)
    {
        for (short int j = 0; j < SIZE; j++)
        {
            if (matrix[i][j] > 0)
            {
                signal++;
            }
        }
    }
    if (signal >= 25)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void move (char mexer)
{
    bool moved = 0;
    switch (mexer)
    {
        case 'W':
            //matrix [i-1][j] = matrix[i] [j];
            for (int j = 0; j < SIZE; j++) {
                for (int i = 1; i < SIZE; i++) {
                    if (matrix[i][j] != 0) {
                        int k = i;
                        while (k > 0 && matrix[k - 1][j] == 0) {
                            matrix[k - 1][j] = matrix[k][j];
                            matrix[k][j] = 0;
                            k--;
                            moved = 1;
                        }
                        if (k > 0 && matrix[k - 1][j] == matrix[k][j]) {
                            matrix[k - 1][j] *= 2;
                            matrix[k][j] = 0;
                            moved = 1;
                        }
                    }
                }
            }
            break;
        case 'S':
            //matrix [i+1][j] = matrix[i] [j];
            for (int j = 0; j < SIZE; j++) {
                for (int i = SIZE - 2; i >= 0; i--) {
                    if (matrix[i][j] != 0) {
                        int k = i;
                        while (k < SIZE - 1 && matrix[k + 1][j] == 0) {
                            matrix[k + 1][j] = matrix[k][j];
                            matrix[k][j] = 0;
                            k++;
                            moved = 1;
                        }
                        if (k < SIZE - 1 && matrix[k + 1][j] == matrix[k][j]) {
                            matrix[k + 1][j] *= 2;
                            matrix[k][j] = 0;
                            moved = 1;
                        }
                    }
                }
            }
            break;
        case 'A':
            //matrix [i][j-1] = matrix[i] [j];
            for (int i = 0; i < SIZE; i++) {
                for (int j = 1; j < SIZE; j++) {
                    if (matrix[i][j] != 0) {
                        int k = j;
                        while (k > 0 && matrix[i][k - 1] == 0) {
                            matrix[i][k - 1] = matrix[i][k];
                            matrix[i][k] = 0;
                            k--;
                            moved = 1;
                        }
                        if (k > 0 && matrix[i][k - 1] == matrix[i][k]) {
                            matrix[i][k - 1] *= 2;
                            matrix[i][k] = 0;
                            moved = 1;
                        }
                    }
                }
            }
            break;
        case 'D':
            //matrix [i+1][j] = matrix[i]  [j];
            for (int i = 0; i < SIZE; i++) {
                for (int j = SIZE - 2; j >= 0; j--) {
                    if (matrix[i][j] != 0) {
                        int k = j;
                        while (k < SIZE - 1 && matrix[i][k + 1] == 0) {
                            matrix[i][k + 1] = matrix[i][k];
                            matrix[i][k] = 0;
                            k++;
                            moved = 1;
                        }
                        if (k < SIZE - 1 && matrix[i][k + 1] == matrix[i][k]) {
                            matrix[i][k + 1] *= 2;
                            matrix[i][k] = 0;
                            moved = 1;
                        }
                    }
                }
            }
            break;
        default:
            break;
    }
    if (moved) {
        // Generate a new random number
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        while (matrix[i][j] != 0) {
            i = rand() % SIZE;
            j = rand() % SIZE;
        }
        matrix[i][j] = (rand() % 2 + 1) * 2; // Generate 2 or 4

        // Print the matrix after the move
    }
}

bool is_won() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 2048) {
                return true;
            }
        }
    }
    return false;
}