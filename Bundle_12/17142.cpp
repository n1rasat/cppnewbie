#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int map_backup[51][51] = { 0, };
int map[51][51] = { 0, };
int visited[51][51] = { 0, };

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<int> answer_vec;

int N, M;

int answer = 987654321;
queue<pair<int, int>> q;
int gcnt = 0;

void bfs() {

	int size = q.size();

	while (size--) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		map[x][y] = 3;
		visited[x][y] = 1;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;
			
			if (visited[nx][ny] == 1)
				continue;

			if (map[nx][ny] == 1)
				continue;

			// 비활성 바이러스 칸이면
			if (map[nx][ny] == 2) {
				map[nx][ny] = 3;
				q.push({ nx, ny });
				map[nx][ny] = 3;
				visited[nx][ny] = 1;
				continue;
			}
			// 이미 활성화된 바이러스
			if (map[nx][ny] == 3)
				continue;

			if (map[nx][ny] == 0) {
				q.push({ nx, ny });
				map[nx][ny] = 3;
				visited[nx][ny] = 1;
				gcnt -= 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	vector<pair<int, int>> v;
	vector<int> filter;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			map_backup[i][j] = map[i][j];

			// 땅 갯수.
			if (map[i][j] == 0)
				gcnt += 1;

			if (map[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}

	sort(v.begin(), v.end());

	for(int i=0; i<M; i++){
		filter.push_back(1);
	}
	for (int i = M; i < v.size(); i++) {
		filter.push_back(0);
	}

	sort(filter.begin(), filter.end());

	int gcnt_backup = gcnt;

	do {
		for (int i = 0; i < filter.size(); i++) {
			if (filter[i] == 1) {
				// 이것들을 큐에 넣고 bfs 돌려야할듯?
				int x = v[i].first;
				int y = v[i].second;
				q.push({ x, y });
			}
		}

		int tempans = 0;
		while (!q.empty()) {
			if (gcnt == 0) {
				break;
			}
			bfs();
			
			tempans += 1;
		}

		if(gcnt == 0)
			answer_vec.push_back(tempans);

		memset(visited, 0, sizeof(visited));
		memcpy(map, map_backup, sizeof(map_backup));
		gcnt = gcnt_backup;
		while (!q.empty()) {
			q.pop();
		}

	} while (next_permutation(filter.begin(), filter.end()));

	if (answer_vec.empty()) {
		cout << -1;
		return 0;
	}

	sort(answer_vec.begin(), answer_vec.end());

	cout << answer_vec[0];

	return 0;
}