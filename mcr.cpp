#include <iostream>

using namespace std;

bool isWin(char game[3][3]) {
	bool win = false;
	if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
	if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
	// column
	if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
	if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
	// diagonal
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[2][0] == game[1][1] && game[0][2] == game[1][1] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
	return win;
}

int main() {
	int i, j;
	char game[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	char player1 = 'X';
	char player2 = 'O';
	bool turn = true;
	cout << "X = player 1" << endl << "O = player 2" << endl;
	for (int n = 0; n < 9; n++) {
		turn = !turn;
		if (turn == false)
			cout << "Player 1: ";
		else
			cout << "Player 2: ";
		cout << "Which cell to mark? i:[1..3], j[1..3]: ";
		cin >> i >> j;
		
		bool flag = false;
		while (!flag) {
			if (i < 1 || i > 3 || j < 1 || j > 3 || game[i-1][j-1] != ' ') {
				cout << "illegal input, please input again! ";
				cin >> i >> j;
			}
			else {
				flag = true;
			}
		}
		
		i--;
		j--;

		
		while (i < 0 || i > 2 || j < 0 || j > 2)
		{
			cout << "illegal input, please input again!";
			cin >> i >> j;
			i--;
			j--;
		}
		while (game[i][j] != ' ') {
			cout << "illegal input, please input again!";
			cin >> i >> j;
			i--;
			j--;
		}
		

		if (turn == false)
			game[i][j] = 'X';
		else
			game[i][j] = 'O';

		if (isWin(game)) {
			cout << "Win!" << endl;
			break;
		}
		i = 3;
	}
	if (i == 3)
		cout << "Tie!" << endl;

	cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
	cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
	cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
}
