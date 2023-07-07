#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

/*TODO: Try exploring the DFC?
* also there are some videos on youtube*/

int** graph;
int n;
int finishCount = 0;
int c;

void rec(int row, int catPassed) {
	bool end = true;
	for (int i = 0; i < n; i++) {
		if (!graph[row][i] || !(graph[row][i] - 1))
			continue;
		if (graph[row][i] - 2 > 0) {
			if (catPassed < c)
				rec(i, catPassed + 1);
		}
		else
			rec(i, 0);
		end = false;
	}
	finishCount += end;
}

int meme() {
	cin >> n >> c;
	graph = new int* [n];
	for (int i = 0; i < n; i++) {
		graph[i] = new int[n];
		for (int j = 0; j < n; j++)
			graph[i][j] = 0;
	}
	for (int i = 0; i < n; i++) {
		int hasACat;
		cin >> hasACat;
		if (hasACat) {
			for (int j = 0; j < n; j++) {
				graph[j][i] += 1;
			}
		}
	}

	//Debug
	for (int i = 0; i <= n; i++) {
		if (!i) {
			cout << "   ";
			for (int y = 1; y <= n; y++)
				cout << y << '\t';
			cout << '\n';
			continue;
		}
		for (int j = 0; j <= n; j++) {
			if (!j)
				cout << i << ": ";
			else
				cout << graph[i - 1][j - 1] << '\t';
		}
		cout << '\n';
	}
	//

	for (int i = 0; i < n - 1; i++) {
		int row, column;
		cin >> row >> column;
		graph[row - 1][column - 1] += 2;
		graph[column - 1][row - 1] += 2;
	}

	//Debug
	for (int i = 0; i <= n; i++) {
		if (!i) {
			cout << "   ";
			for (int y = 1; y <= n; y++)
				cout << y << '\t';
			cout << '\n';
			continue;
		}
		for (int j = 0; j <= n; j++) {
			if (!j)
				cout << i << ": ";
			else
				cout << graph[i - 1][j - 1] << '\t';
		}
		cout << '\n';
	}
	//

	rec(0, graph[0][0]);
	cout << finishCount;
	return 9;
}