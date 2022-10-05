#include<iostream>
#include "joc.h"
#include<stdlib.h>

using namespace std;

joc::joc()
{
    turn=0;
   for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = ' ';

}
void joc::drawBoard()
{

system("cls");
cout<<"\x1b[32m"<<"~~~~~~~~~~~~~~~~~~~WELCOME TO MY X/O GAME~~~~~~~~~~~~~~~~~~~\n\n";
           cout<<"\x1b[33m";
            cout << "                         |     |     " << endl;
	cout << "                      " << board[0][0]<< "  |  " << board[0][1] << "  |  " << board[0][2] << endl;

	cout << "                    _____|_____|_____" << endl;
	cout << "                         |     |     " << endl;

	cout << "                      " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;

	cout << "                    _____|_____|_____" << endl;
	cout << "                         |     |     " << endl;

	cout << "                      " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;

	cout << "                         |     |     " << endl <<"\x1b[37m"<< endl;

}
void joc::startgame()
{
    win=0;
    turn=0;
    drawBoard();
        while(!winner())
        {
            turn++;
        cout<<"\x1b[34m"<<"                        TURN "<<turn<<endl;
        player();
        if(turn>=9)break;
    }
    if(win==1)
    {
        cout<<"\n\n                  PLAYER X WINS\n";
        cout<<"\n\x1b[36m              Made by Dragos 3144a";
    }
    else if(win==2)
    {
        cout<<"\n\n                  PLAYER O WINS\n";
        cout<<"\n\x1b[36m              Made by Dragos 3144a";
    }
        else
        {
            cout<<"\n\n                  DRAW\n";
               cout<<"\n\x1b[36m              Made by Dragos 3144a";
    }
}
void joc::reset()
{
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		board[i][j] = ' ';
}
bool joc::invalidmove(int mutare)
{
    if (mutare < 1 || mutare > 9)
		return true;
	if (mutare < 4)
	if (board[0][mutare - 1] != ' ')
		return true;
	if (mutare > 3 && mutare < 7)
	if (board[1][mutare - 4] != ' ')
		return true;
	if (mutare > 6 && mutare < 10)
	if (board[2][mutare - 7] != ' ')
		return true;
	return false;
}
void joc::player()
{
    if(turn%2==1)
      cout<<"Choose where to move X: ";
        else cout<<"Choose where to move O: ";
        int mutare;
    cin>>mutare;
    while (invalidmove(mutare))
	{
		cout << "Invalid move\n Give another move: ";
		cin >> mutare;
	}
    if(turn%2==1)
    {
        if(mutare==1)
        {
            board[0][0]='X';
        }
        if(mutare==2)
        {
            board[0][1]='X';
        }
        if(mutare==3)
        {
            board[0][2]='X';
        }
        if(mutare==4)
        {
            board[1][0]='X';
        }
        if(mutare==5)
        {
            board[1][1]='X';
        }
        if(mutare==6)
        {
            board[1][2]='X';
        }
        if(mutare==7)
        {
            board[2][0]='X';
        }
        if(mutare==8)
        {
            board[2][1]='X';
        }
        if(mutare==9)
        {
            board[2][2]='X';
        }
    }
    else
    {
       if(mutare==1)
        {
            board[0][0]='O';
        }
        if(mutare==2)
        {
            board[0][1]='O';
        }
        if(mutare==3)
        {
            board[0][2]='O';
        }
        if(mutare==4)
        {
            board[1][0]='O';
        }
        if(mutare==5)
        {
            board[1][1]='O';
        }
        if(mutare==6)
        {
            board[1][2]='O';
        }
        if(mutare==7)
        {
            board[2][0]='O';
        }
        if(mutare==8)
        {
            board[2][1]='O';
        }
        if(mutare==9)
        {
            board[2][2]='O';
        }
    }
    drawBoard();
}

bool joc::winner()
{
	if (board[0][0] == 'X' && board[0][1] == 'X' &&	 board[0][2] == 'X')
    {
        win = 1;
        return true;
    }

    if (board[1][0] == 'X' && board[1][1] == 'X' &&	 board[1][2] == 'X')
		{
        win = 1;
        return true;
    }
	if (board[2][0] == 'X' && board[2][1] == 'X' &&	 board[2][2] == 'X')
		{
        win = 1;
        return true;
    }
	if (board[0][0] == 'X' && board[1][0] == 'X' &&	 board[2][0] == 'X')
		{
        win = 1;
        return true;
    }
	if (board[0][1] == 'X' && board[1][1] == 'X' &&	 board[2][1] == 'X')
		{
        win = 1;
        return true;
    }
	if (board[0][2] == 'X' && board[1][2] == 'X' &&	 board[2][2] == 'X')
		{
        win = 1;
        return true;
    }
	if (board[0][0] == 'X' && board[1][1] == 'X' &&	 board[2][2] == 'X')
		{
        win = 1;
        return true;
    }
	if (board[0][2] == 'X' && board[1][1] == 'X' &&	 board[2][0] == 'X')
		{
        win = 1;
        return true;
    }
 //---------------------------------------------------------------------
   if (board[0][0] == 'O' && board[0][1] == 'O' &&	 board[0][2] == 'O')
		{
        win = 2;
        return true;
    }
    if (board[1][0] == 'O' && board[1][1] == 'O' &&	 board[1][2] == 'O')
		{
        win = 2;
        return true;
    }
	if (board[2][0] == 'O' && board[2][1] == 'O' &&	 board[2][2] == 'O')
		{
        win = 2;
        return true;
    }
	if (board[0][0] == 'O' && board[1][0] == 'O' &&	 board[2][0] == 'O')
		{
        win = 2;
        return true;
    }
	if (board[0][1] == 'O' && board[1][1] == 'O' &&	 board[2][1] == 'O')
		{
        win = 2;
        return true;
    }
	if (board[0][2] == 'O' && board[1][2] == 'O' &&	 board[2][2] == 'O')
		{
        win = 2;
        return true;
    }
	if (board[0][0] == 'O' && board[1][1] == 'O' &&	 board[2][2] == 'O')
		{
        win = 2;
        return true;
    }
	if (board[0][2] == 'O' && board[1][1] == 'O' &&	 board[2][0] == 'O')
		{
        win = 2;
        return true;
    }
    return false;
}
