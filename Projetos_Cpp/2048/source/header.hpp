#ifndef HEADER_HPP
#define HEADER_HPP
#define SIZE 5
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
//function area
bool tableIsFull();
void move (char mexer);
void create ();
void core();
bool is_won();
//extern area
extern short int matrix [6] [6]; 

#endif