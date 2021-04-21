#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int map[21][21] = { 0, };
int map_check[21][21] = { 0, };
int N;
int dx[4] = {-1, 1, 0, 0 };
int dy[4] = {0,  0, -1, 1 };

vector<int> av(5, 0);

int finalanswer = 987654321;

void getarea(int x, int y, int d1, int d2) {
	int i = x;
	int j = y;
	map_check[i][j] = 5;
	int pos = 1;

	//5번 선거구부터 칠하자.
	while (1) {
		if (pos > d1)
			break;

		i = x + pos;
		j = y - pos;
		map_check[i][j] = 5;

		i = x + d2 + pos;
		j = y + d2 - pos;
		map_check[i][j] = 5;

		pos += 1;
	}
	pos = 1;
	while (1) {
		if (pos > d2)
			break;

		i = x + pos;
		j = y + pos;
		map_check[i][j] = 5;

		i = x + d1 + pos;
		j = y - d1 + pos;
		map_check[i][j] = 5;

		pos += 1;
	}

	// 1번 선거구 
	for (int r = 1; r <= N; r++) {
		if (map_check[r][y] != 0)
			break;
		map_check[r][y] = 1;
	}
	// 2번 선거구
	for (int c = N; c >= 1; c--) {
		if (map_check[x + d2][c] != 0)
			break;
		map_check[x + d2][c] = 2;
	}

	// 3번 선거구
	for (int c = 1; c <= N; c++) {
		if (map_check[x+d1][c] != 0)
			break;
		map_check[x+d1][c] = 3;
	}
	// 4번 선거구
	for (int r = N; r >= 1; r--) {
		if (map_check[r][y - d1 + d2] != 0)
			break;
		map_check[r][y - d1 + d2] = 4;
	}

}

void getanswer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map_check[i][j] == 0)
				av[4] += map[i][j];
			else {
				av[map_check[i][j]-1] += map[i][j];
			}
		}
	}

	sort(av.begin(), av.end());

	int tempans = av[4] - av[0];

	if (tempans < finalanswer)
		finalanswer = tempans;
	
}

void bfs(int sx, int sy, int area) {
	queue<pair<int, int>> q;

	map_check[sx][sy] = area;
	
	q.push({ sx, sy });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;

			if (map_check[nx][ny] != 0)
				continue;

			map_check[nx][ny] = area;
			q.push({ nx, ny });
		}
	}

}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	// 기준점
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (x + d1 + d2 > N)
						continue;
					if (y - d1 >= y || y-d1 < 1)
						continue;
					if (y + d2 <= y || y + d2 > N)
						continue;

					getarea(x, y, d1, d2);
					
					bfs(1, 1, 1);
					bfs(1, N, 2);
					bfs(N, 1, 3);
					bfs(N, N, 4);
					getanswer();

					memset(map_check, 0, sizeof(map_check));
					av.clear();
					av.resize(5);

				}
			}
		}
	}

	cout << finalanswer;
	return 0;
}