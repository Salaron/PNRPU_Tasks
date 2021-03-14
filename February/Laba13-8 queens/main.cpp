#include <iostream>
using namespace std;

enum STATUS {
    STATUS_QUEEN =  1,
    STATUS_EMPTY =  0,
};

int solutions = 0;
void printBoard(int** board, int N) {
    solutions++;
    cout << solutions << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool check(int** board, int N, int x, int y) {
    for (int i = 0; i < N; i++) {
        if (board[i][y] == STATUS_QUEEN) return false;
        if (board[x][i] == STATUS_QUEEN) return false;
        int d1 = y - x + i;
        int d2 = y + x - i;
        if (d1 >= 0 && d1 < N && board[i][d1] == STATUS_QUEEN) return false;
        if (d2 >= 0 && d2 < N && board[i][d2] == STATUS_QUEEN) return false;
    }
    return true;
}

bool tryInsert(int** board, int N, int y) {
    if (y == N) {
        printBoard(board, N);
        return true;
    }

    bool result = false;
    for (int x = 0; x < N; x++) {
        if (check(board, N, x, y)) {
            board[x][y] = STATUS_QUEEN;
            result = tryInsert(board, N, y + 1);
            board[x][y] = STATUS_EMPTY;
        }
    }
    return result;
}

int main()
{
	system("chcp 1251>nul");
    int N = 4;
    int** board = new int* [N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
        for (int j = 0; j < N; j++) {
            board[i][j] = STATUS_EMPTY;
        }
    }
    tryInsert(board, N, 0);
    if (solutions == 0) {
        cout << "Решений нет" << endl;
    }
    else {
        cout << "Всего решений: " << solutions << endl;
    }
    return 0;
}