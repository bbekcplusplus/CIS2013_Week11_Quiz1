#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

bool checkAndDisplay(char **board, int height, int width, int x, int y);

int main() {

	srand(time(NULL));

	char **board; 

	int width, height;

	int bomb; 

	int x, y;

	

	cout << " Please Select row width : ";

	cin >> width;

	cout << " Please Select row height : ";

	cin >> height;

	cout << " Please Select number of computers :";

	cin >> bomb;



	board = new char*[height];

	for (int i = 0; i<height; i++)

		board[i] = new char[width];

	for (int i = 0; i<height; i++)

	{

		for (int j = 0; j<width; j++)

			board[i][j] = '.';

	}



	for (int i = 0; i<bomb; i++)

	{

		x = rand() % height;

		y = rand() % width;

		if (board[x][y] == '.')

			board[x][y] = 'X';

		else if (board[x][y] != '.')

			i--;

	}



	for (int i = 0; i<width; i++)

		cout << i << " ";

	cout << endl;

	for (int i = 0; i<height; i++)

	{
		cout << i << " ";

		for (int j = 0; j<width; j++)

			cout << ". ";

		cout << endl;

	}

	bool playEnd = false;



	do {

		cout << "Please Enter the x-coordinate (0.." << (height - 1) << ") : ";

		cin >> x;

		while (x < 0 || x >= height)

		{

			cout << " Invalid input. Enter the x-coordinate (0.." << (height - 1) << ") : ";

			cin >> x;

		}

		cout << " Please Enter the y-coordinate (0.." << (width - 1) << ") : ";

		cin >> y;

		while (y < 0 || y >= width)

		{

			cout << " Invalid input. Enter the x-coordinate (0.." << (width - 1) << " ): ";

			cin >> y;

		}

		playEnd = checkAndDisplay(board, height, width, x, y);

		if (playEnd)

			cout << "!!!! YOU ARE DEAD !!!!" << endl;

	} while (!playEnd);

	return 0;

}




}