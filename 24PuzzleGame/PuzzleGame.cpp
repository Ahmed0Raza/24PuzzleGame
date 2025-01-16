#include <iostream>
#include <iomanip>
#include <time.h>
#include <conio.h>
#include<string>
#include<fstream>
char path[1000];
using namespace std;

int instructions()
{
    cout << endl;
    cout << "The 24-puzzle is a game in which you are given a frame of 5x5 tiles where one of the tiles is missing, and the other are numbered 1-24. You have to slide tiles into the 'hole' until you reach the 'solved' configuration, in which the Goal Board and Initial Board are equal to each other." << endl;
    cout << "How to play?" << endl;
    cout << "You will use four arrow keys to move the missing tile." << endl;
    cout << "If you want to continue from where you left, click 2 from menu, it will ask you do you want to start a new game or do you want to continue from where you left." << endl;
    cout << "GoodLuck!" << endl;
    system("pause");
    return 0;
}
void filehandle(int init[5][5], int goal[5][5])
{

    fstream fout;

    fout.open("calre.txt");
    if (!fout)
    {
        cout << "error";
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {

            for (int j = 0; j < 5; j++)
            {
                fout << goal[i][j] << " ";
            }
            fout << endl;
        }
        for (int i = 0; i < 5; i++)
        {

            for (int j = 0; j < 5; j++)
            {
                fout << init[i][j] << " ";
            }
            fout << endl;
        }

    }
    fout.close();
}
void handle(int init[5][5], int goal[5][5])
{
    ifstream fin;
    fin.open("calre.txt");
    if (!fin)
    {
        cout << "error";
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {

            for (int j = 0; j < 5; j++)
            {
                fin >> init[i][j];
            }

        }
        for (int i = 0; i < 5; i++)
        {

            for (int j = 0; j < 5; j++)
            {
                fin >> goal[i][j];
            }

        }
    }
    fin.close();
}
void print(int board[5][5])
{
    cout << "--------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "|";
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 0)
            {
                cout << setw(3) << " " << setw(2) << "|";
            }
            else
            {
                cout << setw(3) << board[i][j] << setw(2) << "|";
            }
        }
        cout << endl;
        cout << "--------------------------" << endl;
    }
}
void init(int initialBoard[5][5])
{

    int  num = 1, i, j, random, temp, s, t;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 4 && j == 4)
            {
                initialBoard[i][j] = 0;
            }
            else
            {
                initialBoard[i][j] = num;
                num++;
            }
        }
    }
    for (int k = 0; k < 25; k++)
    {
        random = rand() % 5;
        i = random;
        random = rand() % 5;
        j = random;
        random = rand() % 5;
        s = random;
        random = rand() % 5;
        t = random;

        temp = initialBoard[i][j];
        initialBoard[i][j] = initialBoard[s][t];
        initialBoard[s][t] = temp;
    }
}

void goal(int goalBoard[5][5])
{

    int num = 1, i, j, random, temp, s, t;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 4 && j == 4)
            {
                goalBoard[i][j] = 0;
            }
            else
            {
                goalBoard[i][j] = num;
                num++;
            }
        }
    }
    for (int k = 0; k < 25; k++)
    {
        random = rand() % 5;
        i = random;
        random = rand() % 5;
        j = random;
        random = rand() % 5;
        s = random;
        random = rand() % 5;
        t = random;

        temp = goalBoard[i][j];
        goalBoard[i][j] = goalBoard[s][t];
        goalBoard[s][t] = temp;
    }
}
int inversion(int a[5][5])
{
    int b[25];
    int sum = 0, inv = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            b[sum++] = a[i][j];
        }
    }
    for (int i = 0; i < 25; i++)
    {
        for (int j = 1 + i; j < 25; j++)
        {

            if (b[i] > b[j])
            {
                if (b[j] != 0)
                    inv++;
            }
        }
    }
    return inv;
}
bool Is_Solveable(int InvOfInit, int InvOfGoal)
{
    bool flag = false;
    if ((InvOfInit % 2 == 0 && InvOfGoal % 2 == 0) || (InvOfInit % 2 != 0 && InvOfGoal % 2 != 0))
    {
        return true;
    }
    return false;
}
void print_path()
{
    cout << "Moves you made : ";
    for (int i = 0; path[i] != '\0'; i++)
    {
        cout << "'" << path[i] << "'" << " ";
    }
}

bool is_goal(int initialBoard[5][5], int  goalBoard[5][5])
{
    bool flag = true;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (initialBoard[i][j] != goalBoard[i][j])
            {
                flag = false;
            }
        }
    }
    if (flag == true)
    {
        cout << "You Have Won!" << endl;
        print_path();
        exit(0);
    }
    return 0;

}
int legal_moves(int k, int l, int move)
{
    for (int i = 1; i <= 1; )
    {
        if (move == 72)
        {
            //up
            if (k == 0)
            {
                for (int j = 0; j <= 4; j++)
                {
                    if (l == j)
                    {
                        return 1;
                    }
                }
            }
        }
        if (move == 80)
        {
            //down
            if (k == 4)
            {
                for (int j = 0; j <= 4; j++)
                {
                    if (l == j)
                    {
                        return 1;
                    }
                }
            }
        }

        if (move == 75)
        {
            //left
            if (l == 0)
            {
                for (int j = 0; j <= 4; j++)
                {
                    if (k == j)
                    {
                        return 1;
                    }
                }
            }
        }
        if (move == 77)
        {
            //right
            if (l == 4)
            {
                for (int j = 0; j <= 4; j++)
                {
                    if (k == j)
                    {
                        return 1;
                    }
                }
            }
        }
        i++;
    }
    return 0;
}
void make_move(int goalBoard[5][5], int initialBoard[5][5])
{
    int k, l, c, temp, temp2, R;
    int g = 0;
    bool flag = true;
    cout << "Goal Board" << endl;
    print(goalBoard);
    cout << "Initial Board" << endl;
    print(initialBoard);
    cout << "Press 'Esc' to quit" << endl;
    while (flag)
    {


        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (initialBoard[i][j] == 0)
                {
                    k = i;
                    l = j;
                    break;
                }

            }
        }
        c = 0;
        c = _getch();
        switch (c)
        {

        case 72:
        {
            R = legal_moves(k, l, 72);
            if (R == 1)
            {
                break;
            }
            //up
            int m;
            m = k;
            m--;
            temp = initialBoard[k][l];
            initialBoard[k][l] = initialBoard[m][l];
            initialBoard[m][l] = temp;
            path[g] = 'U';
            g++;
            break;
        }
        case 80:
        {
            R = legal_moves(k, l, 80);
            if (R == 1)
            {
                break;
            }
            //down
            int m;
            m = k;
            m++;
            temp = initialBoard[k][l];
            initialBoard[k][l] = initialBoard[m][l];
            initialBoard[m][l] = temp;
            path[g] = 'D';
            g++;

            break;
        }
        case 75:
        {
            R = legal_moves(k, l, 75);
            if (R == 1)
            {
                break;
            }
            //left
            int n;
            n = l;
            n--;
            temp = initialBoard[k][l];
            initialBoard[k][l] = initialBoard[k][n];
            initialBoard[k][n] = temp;
            path[g] = 'L';
            g++;

            break;
        }
        case 77:
        {
            R = legal_moves(k, l, 77);
            if (R == 1)
            {
                break;
            }
            //right
            int n;
            n = l;
            n++;
            temp = initialBoard[k][l];
            initialBoard[k][l] = initialBoard[k][n];
            initialBoard[k][n] = temp;
            path[g] = 'R';
            g++;

            break;
        }
        case 27:
        {
            flag = false;
            break;

        }
        }


        system("CLS");
        cout << "Goal Board" << endl;
        print(goalBoard);
        cout << "Initial Board" << endl;
        print(initialBoard);
        is_goal(initialBoard, goalBoard);
        cout << "Press Esc to quit" << endl;

    }
}


int main()
{
    char choice;
    int b = 0;
    while (b == 0)
    {
        system("CLS");
        cout << "Click '1' for Game Instruction" << endl;
        cout << "Click '2' to Start Game" << endl;
        cout << "Click '3' to Exit Game" << endl;
        choice = _getch();

        if (choice == '1')
        {
            b = instructions();
        }
        else if (choice == '2')
        {
            b = 1;
            system("CLS");
        }
        else 	if (choice == '3')
        {
            exit(0);
        }
        else
        {
            cout << "Wrong Input!" << endl;
            system("pause");
        }
    }
    srand(time(0));
    int initialBoard[5][5], goalBoard[5][5];
    int InvOfInit = 0, InvOfGoal = 0, s = 1;
    int num = 1;
    int input;
    bool a = false;


    while (s == 1)
    {
        system("CLS");
        cout << "Press 'N' to Start a New Game " << endl;
        cout << "Press 'C' to Continue " << endl;
        cout << "Press 'Esc' to quit" << endl;

        input = _getch();
        if (input == 'N' || input == 'n')
        {
            goal(goalBoard);
            InvOfGoal = inversion(goalBoard);
            s = 0;
            //cout << InvOfGoal<<endl;
            while (a == false)
            {
                init(initialBoard);
                InvOfInit = inversion(initialBoard);
                a = Is_Solveable(InvOfInit, InvOfGoal);
            }
        }
        else if (input == 'C' || input == 'c')
        {
            handle(initialBoard, goalBoard);
            s = 0;
        }
        else if (input == 27)
        {
            exit(0);
        }
        else
        {
            cout << "Wrong Input!" << endl;
            system("pause");
        }
    }
    system("CLS");
    //  cout << InvOfInit<<endl;
    make_move(goalBoard, initialBoard);
    filehandle(goalBoard, initialBoard);


}

