#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N;
int map[51][51] = { 0, };
int checkmap[51][51] = { 0, };
int visited[51][51] = { 0, };
int L, R;

int check = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<pair<int, int>> v;

// 구역 체크하기
void bfs1(int x, int y, int k) {
	queue<pair<int, int>> q;

	q.push({ x, y });
	visited[x][y] = 1;
	checkmap[x][y] = k;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;

			if (visited[nx][ny] == 1)
				continue;

			// 이미 구역에 들어가있음.
			if (checkmap[nx][ny] != 0)
				continue;

			int diff = abs(map[x][y] - map[nx][ny]);
			if (diff >= L && diff <= R) {
				check = 1;
				checkmap[nx][ny] = k;
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}	
		}
	}

	return;
}

// 합해서 나눠주기
void bfs2(int x, int y, int k) {
	int tempcnt = 0;
	int tempans = 0;

	queue<pair<int, int >> q;
	vector<pair<int, int>> v;

	q.push({ x, y });
	v.push_back({ x, y });
	visited[x][y] = 1;

	tempans += map[x][y];
	tempcnt += 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;

			if (visited[nx][ny] == 1)
				continue;

			// 내 구역이 아니면
			if (checkmap[nx][ny] != k)
				continue;

			q.push({ nx, ny });
			v.push_back({ nx, ny });
			visited[nx][ny] = 1;
			tempans += map[nx][ny];
			tempcnt += 1;
		}

	}

	tempans /= tempcnt;

	for (int i = 0; i < v.size(); i++) {
		map[v[i].first][v[i].second] = tempans;
	}

	return;

}

int main() {
	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int answer = 0;
	while (1) {
		// k: 구역 설정.
		int k = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i][j] == 1)
					continue;
				bfs1(i, j, k);
				k += 1;
			}
		}

		// check가 0: 인구수 차이가 [L:R] 범위인 곳이 없음
		if (check == 0)
			break;

		k = 1;

		// visited 초기화
		memset(visited, 0, sizeof(visited));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i][j] == 1)
					continue;
				bfs2(i, j, k);
				k++;
			}
		}

		memset(visited, 0, sizeof(visited));
		memset(checkmap, 0, sizeof(checkmap));

		answer += 1;
		check = 0;
	}

	cout << answer;

	return 0;
}