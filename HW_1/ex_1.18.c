#include <stdio.h>

void printTicTacToe(char board[9]) {
    for (int i = 0; i < 9; i++) {
        printf(" %c ", board[i] == ' ' ? ' ' : board[i]);
        if ((i + 1) % 3 == 0 && i != 8) {
            printf("\n---|---|---\n");
        } else if ((i + 1) % 3 != 0) {
            printf("|");
        }
    }
    printf("\n");
}

int main() {
    char board[9] = {'O', 'X', ' ', ' ', ' ', 'X', 'O', 'X', ' '};

    printf("Нинішня позиція на дошці:\n");
    printTicTacToe(board);

    return 0;
}
