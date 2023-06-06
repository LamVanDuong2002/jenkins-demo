#include <iostream>
using namespace std;

const int SIZE = 3; // Kích thý?c b?ng c?

char board[SIZE][SIZE]; // Ma tr?n lýu tr?ng thái b?ng c?

// Kh?i t?o b?ng c?
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// V? b?ng c? ra màn h?nh
void drawBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Ki?m tra xem ngý?i chõi có th?ng hay không
bool checkWin(char player) {
    // Ki?m tra hàng ngang và c?t d?c
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Ki?m tra hai ðý?ng chéo
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Th?c hi?n lý?t ði c?a ngý?i chõi
void makeMove(char player) {
    int row, col;
    cout << "Ngý?i chõi " << player << " h?y ch?n hàng và c?t (vd: 1 2): ";
    cin >> row >> col;

    // Ki?m tra ný?c ði h?p l?
    while (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != '-') {
        cout << "Ný?c ði không h?p l?! H?y ch?n l?i: ";
        cin >> row >> col;
    }

    // Ð?t k? hi?u c?a ngý?i chõi vào b?ng c?
    board[row - 1][col - 1] = player;
}
int main() {
    char currentPlayer = 'X'; // Ngý?i chõi hi?n t?i

    initializeBoard(); // Kh?i t?o b?ng c?

    while (true) {
        drawBoard(); // V? b?ng c?

        makeMove(currentPlayer); // Lý?t ði c?a ngý?i chõi hi?n t?i

        if (checkWin(currentPlayer)) {
            cout << "Ngý?i chõi " << currentPlayer << " ð? th?ng!" << endl;
            break;
        }

        // Chuy?n lý?t ði cho ngý?i chõi ti?p theo
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

    return 0;
}
