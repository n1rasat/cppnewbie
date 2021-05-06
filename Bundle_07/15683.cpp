#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M;
int map[9][9] = { 0, };

// 상, 우, 하, 좌
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> v;

int answer = 987654321;

void dfs(int idx, int m[9][9]) {

	if (idx == v.size()) {
		int tempans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (m[i][j] == 0) {
					tempans += 1;
				}
			}
		}

		if (tempans < answer)
			answer = tempans;

		return;
	}

	int tempmap[9][9] = { 0, };

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tempmap[i][j] = m[i][j];
		}
	}

	int x = v[idx].first;
	int y = v[idx].second;

	if (tempmap[x][y] == 1) {
		// 각 방향으로 쭉 나간다.
		for (int i = 0; i < 4; i++) {
			vector<pair<int, int>> tv;
			for (int j = 1; j <= 8; j++) {
				int nx = x + (dx[i] * j);
				int ny = y + (dy[i] * j);

				if (nx < 1 || nx > N || ny < 1 || ny > M)
					break;

				// 벽 만남
				if (tempmap[nx][ny] == 6)
					break;

				// 다른 cctv 만남 || 이미 비추고 있음
				if ((tempmap[nx][ny] >= 1 && tempmap[nx][ny] <= 5) || tempmap[nx][ny] == 9)
					continue;

				tempmap[nx][ny] = 9;
				tv.push_back({ nx, ny });
			}
			dfs(idx + 1, tempmap);
			// tempmap 초기화
			for (int i = 0; i < tv.size(); i++) {
				tempmap[tv[i].first][tv[i].second] = 0;
			}
		}
	}
	else if (tempmap[x][y] == 2) {
		// 양쪽을 봐야한다. 
		for (int i = 0; i < 2; i++) {
			vector<pair<int, int>> tv;
			// 한쪽
			for (int j = 1; j <= 8; j++) {
				int nx = x + (dx[i] * j);
				int ny = y + (dy[i] * j);

				if (nx < 1 || nx > N || ny < 1 || ny > M)
					break;

				// 벽 만남
				if (tempmap[nx][ny] == 6)
					break;

				// 다른 cctv 만남
				if ((tempmap[nx][ny] >= 1 && tempmap[nx][ny] <= 5) || tempmap[nx][ny] == 9)
					continue;

				tempmap[nx][ny] = 9;
				tv.push_back({ nx, ny });
			}
			// 반대쪽
			for (int j = 1; j <= 8; j++) {
				int nx = x + (dx[i + 2] * j);
				int ny = y + (dy[i + 2] * j);

				if (nx < 1 || nx > N || ny < 1 || ny > M)
					break;

				// 벽 만남
				if (tempmap[nx][ny] == 6)
					break;

				// 다른 cctv 만남
				if ((tempmap[nx][ny] >= 1 && tempmap[nx][ny] <= 5) || tempmap[nx][ny] == 9)
					continue;

				tempmap[nx][ny] = 9;
				tv.push_back({ nx, ny });
			}
			dfs(idx + 1, tempmap);
			// tempmap 초기화
			for (int i = 0; i < tv.size(); i++) {
				tempmap[tv[i].first][tv[i].second] = 0;
			}
		}
	}
	else if (tempmap[x][y] == 3) {
		// 이번엔 90도만큼 봐야한다.
		for (int i = 0; i < 4; i++) {
			vector<pair<int, int>> tv;
			for (int j = 1; j <= 8; j++) {
				int nx = x + (dx[i] * j);
				int ny = y + (dy[i] * j);

				if (nx < 1 || nx > N || ny < 1 || ny > M)
					break;

				// 벽 만남
				if (tempmap[nx][ny] == 6)
					break;

				// 다른 cctv 만남
				if ((tempmap[nx][ny] >= 1 && tempmap[nx][ny] <= 5) || tempmap[nx][ny] == 9)
					continue;

				tempmap[nx][ny] = 9;
				tv.push_back({ nx, ny });
			}
			// 90도 짝 찾기
			int partner = i + 1;
			if (partner == 4) {
				partner = 0;
			}
			for (int j = 1; j <= 8; j++) {
				int nx = x + (dx[partner] * j);
				int ny = y + (dy[partner] * j);

				if (nx < 1 || nx > N || ny < 1 || ny > M)
					break;

				// 벽 만남
				if (tempmap[nx][ny] == 6)
					break;

				// 다른 cctv 만남
				if ((tempmap[nx][ny] >= 1 && tempmap[nx][ny] <= 5) || tempmap[nx][ny] == 9)
					continue;

				tempmap[nx][ny] = 9;
				tv.push_back({ nx, ny });
			}
			dfs(idx + 1, tempmap);
			// tempmap 초기화
			for (int i = 0; i < tv.size(); i++) {
				tempmap[tv[i].first][tv[i].second] = 0;
			}
		}
	}
	else if (tempmap[x][y] == 4) {
		// 세 방향 본다.
		for (int i = 0; i < 4; i++) {
			vector<pair<int, int>> tv;
			for (int k = 0; k < 4; k++) {
				// k 가 i랑 같으면 안 본다. 
				if (k == i)
					continue;

				for (int j = 1; j <= 8; j++) {
					int nx = x + (dx[k] * j);
					int ny = y + (dy[k] * j);

					if (nx < 1 || nx > N || ny < 1 || ny > M)
						break;

					// 벽 만남
					if (tempmap[nx][ny] == 6)
						break;

					// 다른 cctv 만남
					if ((tempmap[nx][ny] >= 1 && tempmap[nx][ny] <= 5) || tempmap[nx][ny] == 9)
						continue;

					tempmap[nx][ny] = 9;
					tv.push_back({ nx, ny });
				}
			}
			dfs(idx + 1, tempmap);
			// tempmap 초기화
			for (int i = 0; i < tv.size(); i++) {
				tempmap[tv[i].first][tv[i].second] = 0;
			}
		}
	}
	else if (tempmap[x][y] == 5) {
		// 4방향 다 본다.
		vector<pair<int, int>> tv;
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 8; j++) {
				int nx = x + (dx[i] * j);
				int ny = y + (dy[i] * j);

				if (nx < 1 || nx > N || ny < 1 || ny > M)
					break;

				// 벽 만남
				if (tempmap[nx][ny] == 6)
					break;

				// 다른 cctv 만남
				if ((tempmap[nx][ny] >= 1 && tempmap[nx][ny] <= 5) || tempmap[nx][ny] == 9)
					continue;

				tempmap[nx][ny] = 9;
				tv.push_back({ nx, ny });
			}
		}
		dfs(idx + 1, tempmap);
		// tempmap 초기화
		for (int i = 0; i < tv.size(); i++) {
			tempmap[tv[i].first][tv[i].second] = 0;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				// cctv 위치 저장
				v.push_back({ i, j });
			}
		}
	}
	int idx = 0;

	dfs(idx, map);

	cout << answer;

	return 0;
}