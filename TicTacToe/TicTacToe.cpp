#include <iostream>
using namespace std;

char table[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';

void draw() {
    system("cls");
    cout << endl << "Tic-Tac-Toe" << endl << endl;

    for (int i = 0; i < 3; i++) {
        cout << "| ";

        for (int j = 0; j < 3; j++)
            cout << table[i][j] << " | ";
        cout << endl << "-------------" << endl;
    }
}

void input() {
    int a;
    cout << "player " << player << "'s turn" << endl << endl;
    cout << "Choose a number: ";
    cin >> a;

    switch (a) {
        case 1:
            if (table[0][0] == '1')
                table[0][0] = player;
            else {
                cout << endl << "Field already in use!" << endl << endl;
                input();
            }
            break;
        case 2:
            if (table[0][1] == '2')
                table[0][1] = player;
            else {
                cout << endl << "Field already in use!" << endl << endl;
                input();
            }
            break;
        case 3:
            if (table[0][2] == '3')
                table[0][2] = player;
            else {
                cout << endl << "Field already in use!" << endl << endl;
                input();
            }
            break;
        case 4:
            if (table[1][0] == '4')
                table[1][0] = player;
            else {
                cout << endl << "Field already in use!" << endl << endl;
                input();
            }
            break;
        case 5:
            if (table[1][1] == '5')
                table[1][1] = player;
            else {
                cout << endl << "Field already in use!" << endl << endl;
                input();
            }
            break;
        case 6:
            if (table[1][2] == '6')
                table[1][2] = player;
            else {
                cout << endl << "Field already in use!" << endl << endl;
                input();
            }
            break;
        case 7:
            if (table[2][0] == '7')
                table[2][0] = player;
            else {
                cout << endl << "Field already in use!" << endl << endl;
                input();
            }
            break;
        case 8:
            if (table[2][1] == '8')
                table[2][1] = player;
            else {
                cout << endl << "Field already in use!" << endl << endl;
                input();
            }
            break;
        case 9:
            if (table[2][2] == '9')
                table[2][2] = player;
            else {
                cout << endl << "Field already in use!" << endl << endl;
                input();
            }
            break;
        default:
            cout << "Invalid input!" << endl;
            input();
            break;
    }
}

void playerSwitch() {
    player = (player == 'X' ? 'O' : 'X');
}

char logic() {
    if (table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] == 'X')
        return 'X';
    else if (table[0][0] == 'X' && table[1][0] == 'X' && table[2][0] == 'X')
        return 'X';
    else if (table[0][2] == 'X' && table[1][2] == 'X' && table[2][2] == 'X')
        return 'X';
    else if (table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == 'X')
        return 'X';
    else if (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X')
        return 'X';
    else if (table[0][2] == 'X' && table[1][1] == 'X' && table[2][0] == 'X')
        return 'X';

    else if (table[0][0] == 'O' && table[0][1] == 'O' && table[0][2] == 'O')
        return 'O';
    else if (table[0][0] == 'O' && table[1][0] == 'O' && table[2][0] == 'O')
        return 'O';
    else if (table[0][2] == 'O' && table[1][2] == 'O' && table[2][2] == 'O')
        return 'O';
    else if (table[2][0] == 'O' && table[2][1] == 'O' && table[2][2] == 'O')
        return 'O';
    else if (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O')
        return 'O';
    else if (table[0][2] == 'O' && table[1][1] == 'O' && table[2][0] == 'O')
        return 'O';
    return '/';
}

void startGame() {
    table[0][0] = '1'; table[0][1] = '2'; table[0][2] = '3';
    table[1][0] = '4'; table[1][1] = '5'; table[1][2] = '6';
    table[2][0] = '7'; table[2][1] = '8'; table[2][2] = '9';
    string again;
    draw();
    while (true)
    {
        input();
        draw();
        playerSwitch();
        if (logic() == 'X') {
            cout << "Player x won!" << endl << endl << "Play again? ";
            cin >> again;

            if (again == "yes" || again == "y")
                startGame();
            else if (again == "no" || again == "n")
                exit(0);
        }

        else if (logic() == 'O') {
            cout << "Player O won!" << endl << endl << "Play again? ";
            cin >> again;
            cout << endl;

            if (again == "yes" || again == "y")
                startGame();
            else if (again == "no" || again == "n")
                exit(0);
        }

        else if (table[0][0] != '1' && table[0][1] != '2' && table[0][2] != '3' &&
                 table[1][0] != '4' && table[1][1] != '5' && table[1][2] != '6' &&
                 table[2][0] != '7' && table[2][1] != '8' && table[2][2] != '9' && logic() != 'O' && logic() != 'X') {
            cout << "It's a draw!" << endl << endl << "Play again? ";
            cin >> again;
            cout << endl;

            if (again == "yes" || again == "y")
                startGame();
            else if (again == "no" || again == "n")
                exit(0);
        }
    }
}

int main() {
    startGame();
}