//
//  main.cpp
//  Project 2 Nim
//
//  Created by Rehan Kedia on 10/1/17.
//  Copyright © 2017 Rehan Kedia. All rights reserved.
//


#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
    srand(unsigned(time(0)));
    int random1, random2, random3,num,origp1,origp2,origp3,cturn,pile = 0,turn=0;
    cout << "Welcome to The Game of Nim!!!!!\n";
    random1 = rand() % 40 + 10;
    random2 = rand() % 40 + 10;
    random3 = rand() % 40 + 10; // Chossing the numbers of marbles in pile
    do
    {
        if (turn == 0 || turn == 3)   // users turn
        {
            cout << "Pile A(1)\t\t Pile B(2)\t\t Pile C(3)\n";
            cout <<"\t"<<random1<<"\t\t\t\t"<<random2<<"\t\t\t\t"<<random3<<endl;
            cout << "Please choose one Pile to draw from - ";
            cin >> pile;
        }
        switch (pile)
        {
            case 1:
                origp1 = random1;
                if (turn == 0 || turn == 3)
                {
                    if (random1 == 0)
                    {
                        
                        cout << "You cannot choose marble form an empty pile.! \n";
                        break;
                    }
                    do
                    {
                        if (random1 == 1)   // this automatically select 1 as there is only 1 marble left
                        {
                            cout << "You can only pick the last marble\n";
                            random1 = 0;
                            if (random2 == 0 && random3 == 0)
                                cout << "You lost the game!!\n";
                            break;
                        }
                        cout << "Choose a number between 1 and " << random1 / 2 << " :\t";
                        cin >> num;
                        if (num <= random1 / 2 && num > 0)
                        {
                            random1 = random1 - num;
                        }
                        else
                        {
                            cout << "Dont Cheat! Enter a proper value!!";
                        }
                    } while (num > origp1 / 2 || num <= 0); // loop for choosing the marble again unitll user puts valid value
                    turn = 0;
                }
                if (pile == 1 && turn == 1)   //computer's turn
                {
                    if (random1 == 0)
                    {
                        
                        turn = 0;
                        cout << "This pile is already empty," << endl;
                        break;
                    }
                    else if (random1 == 1)
                    {
                        random1 = 0;
                        if (random2 == 0 && random3 == 0)  // winning condition
                            cout << "You won!! Congratss !!\n";
                        turn = 3;
                        break;
                    }
                    else
                    {
                        cturn = rand() % (random1 / 2) + 1;
                        cout << "I will draw " << cturn<<" marbles"<<endl;
                        random1 = random1 - cturn;
                        turn = 3;
                    }
                }
                break;
            case 2:
                origp2 = random2;
                if (turn == 0 ||turn ==3)
                {
                    if (random2 == 0)
                    {
                        
                        cout << "You cannot choose marble form an empty pile.!\n";
                        break;
                    }
                    do
                    {
                        if (random2 == 1)
                        {
                            cout << "You can only pick the last marble\n";
                            random2 = 0;
                            if (random1 == 0 && random3 == 0)
                                cout << "You lost the game!!\n";
                            break;
                        }
                        cout << "Choose a number between 1 and " << random2 / 2 << " :\t";
                        cin >> num;
                        if (num <= random2 / 2 && num > 0)
                        {
                            random2 = random2 - num;
                        }
                        else
                        {
                            cout << "Dont Cheat!! Enter Proper Value!!";
                        }
                    } while (num > origp2 / 2 || random2 == 0);
                    turn = 0;
                }
                else if (pile == 2 && turn == 1)
                {
                    if (random2 == 0)
                    {
                        
                        turn = 0;
                        cout << "You cannot choose marble form an empty pile.!!," << endl;
                        break;
                    }
                    else if (random2 == 1)
                    {
                        random2 = 0;
                        if (random1 == 0 && random3 == 0)
                            cout << "You won the game!! Congratss !!\n";
                        turn = 3;
                        break;
                    }
                    else
                    {
                        cturn = rand() % (random2 / 2) + 1;
                        cout << "I will draw " << cturn<<" marbles"<<endl;
                        random2 = random2 - cturn;
                        turn = 3;
                    }
                }
                break;
            case 3:
                origp3 = random3;
                if (turn == 0|| turn == 3)
                {
                    if (random3 == 0)
                    {
                        
                        cout << "You cannot choose marble form an empty pile.!!\n";
                        break;
                    }
                    do
                    {
                        if (random3 == 1)
                        {
                            cout << "You can only pick the last marble\n";
                            random3 = 0;
                            if (random1 == 0 && random2 == 0)
                                cout << "You lost the game!!\n";
                            break;
                        }
                        cout << "Choose a number between 1 and " << random3 / 2 << " :\t";
                        cin >> num;
                        if (num <= random3 / 2 && num > 0)
                        {
                            random3 = random3 - num;
                        }
                        else
                        {
                            cout << "Dont Cheat Enter a proper value!!";
                        }
                    } while (num > origp3 / 2 || random3 == 0);
                    turn = 0;
                }
                if (pile == 3 && turn == 1)
                {
                    if (random3 == 0)
                    {
                        cout << "You cannot choose marble form an empty pile.!!" << endl;
                        turn = 0;
                        break;
                    }
                    else if (random3 == 1)
                    {
                        random3 = 0;
                        if (random1 == 0 && random2 == 0)
                            cout << "You won the game!! Congratss!!\n";
                        turn = 3;
                        break;
                    }
                    else
                    {
                        cturn = rand() % (random3 / 2) + 1;
                        cout << "I will draw " << cturn<< " marbles "<<endl;
                        random3 = random3 - cturn;
                        turn = 3;
                    }
                }
                break;
            default:
                cout << "You have to learn how to play. INVALID CHOICE!!"<<endl;
        }
        
        if (turn == 0 && (pile>=1 && pile<=3))
        {
            pile = rand() % 3 + 1;
            cout << "I will draw from Pile " << pile << endl;
            turn = 1;
        }
    } while (random1 != 0 || random2 != 0 || random3 != 0); // it repeats unless all pile are empty
    system ("pause");
    return 0;
}
