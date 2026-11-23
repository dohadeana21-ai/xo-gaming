#include <bits/stdc++.h>
using namespace std;

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
void drawBoard(string player1, string player2);
void startGame(string player1, string player2);
int checkWin();

int main() {
    cout << "------- TIC TAC TOC GAME -------\n\n";
    string player1, player2;

    cout << "please Enter name of player1: ";
    cin >> player1;

    cout << "\nplease Enter name of player2: ";
    cin >> player2;

    drawBoard(player1, player2);
    startGame(player1, player2);

}

void drawBoard(string player1, string player2){

    system("cls");

    cout << "\n\n------- TIC TAC TOC GAME -------\n\n";

    cout << "player 1 [X] : " << player1 << ", player 2 [O] : " << player2 << "\n\n";

    cout << "----|-----|------" << "\n";
    cout << " " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;
    cout << "----|-----|------" << "\n";
    cout << " " << board[4] << "  |  " << board[5] << "  |  " << board[6] << endl;
    cout << "----|-----|------" << "\n";
    cout << " " << board[7] << "  |  " << board[8] << "  |  " << board[9] << endl;
    cout << "----|-----|------" << "\n";
}

void startGame(string player1, string player2){
    int player = 1, choice;

    char mark;

    do {
    drawBoard(player1, player2);

    /*if(player % 2 == 0) {
        player = 2;
    } else {
        player = 1;
    }*/
    player = (player % 2)? 1: 2; // short if

    if(player == 1) {
        cout << "Player  " << player1 << " ,enter your choice: ";
    } else {
        cout << "Player  " << player2 << " ,enter your choice: ";
    }

    cin >> choice;

    mark = (player == 1)? 'X': 'O';

    if(choice == 1 && board[1] == '1'){
        board[1] = mark;
    } else if (choice == 2 && board[2] == '2'){
        board[2] = mark;
    }  else if (choice == 3 && board[3] == '3'){
        board[3] = mark;
    }  else if (choice == 4 && board[4] == '4'){
        board[4] = mark;
    }  else if (choice == 5 && board[5] == '5'){
        board[5] = mark;
    }   else if (choice == 6 && board[6] == '6'){
        board[6] = mark;
    }  else if (choice == 7 && board[7] == '7'){
        board[7] = mark;
    }  else if (choice == 8 && board[8] == '8'){
        board[8] = mark;
    }  else if (choice == 9 && board[9] == '9'){
        board[9] = mark;
    } else {
        cout << "invalid move ";
        player--;
        cin.ignore();
        cin.get();
    }

    player++;

    }while(checkWin() == -1);

    drawBoard(player1, player2);

    if(checkWin()){
        if(--player == 1){
            system("cls");
            cout << "\n\n------" << player1 <<" win ------\n\n";
        } else {
            system("cls");
            cout << "\n\n------" << player2 <<" win ------\n\n";
        }
    } else {
        system("cls");
        cout << "\n\n------Draw Game------\n\n";
    }
}


int checkWin(){
    if(board[1] == board[2] && board[2] == board[3]){ // 1 = 2 = 3
        return 1;
    } else if(board[4] == board[5] && board[5] == board[6]) { // 4 = 5 = 6
        return 1;
    } else if(board[7] == board[8] && board[8] == board[9]) { // 7 = 8 = 9
        return 1;
    } else if(board[1] == board[4] && board[4] == board[7]) { // 1 = 4 = 7
        return 1;
    } else if(board[2] == board[5] && board[5] == board[8]) { // 2 = 5 = 8
        return 1;
    } else if(board[3] == board[6] && board[6] == board[9]) { // 3 = 6 = 9
        return 1;
    } else if(board[1] == board[5] && board[5] == board[9]) { // 1 = 5 = 9
        return 1;
    } else if(board[3] == board[5] && board[5] == board[7]) { // 3 = 5 = 7
        return 1;
    } else if(board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4'
              && board[5] != '5' && board[6] != '6' && board[7] != '7'
              && board[8] != '8' && board[9] != '9'){
                  return 0;
              } else{
              return -1;
              }
}
