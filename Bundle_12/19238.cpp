#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int map[21][21] = { 0, };
int visited[21][21] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M, F;

int get_length(int sx, int sy, int fx, int fy) {
	queue<pair<int, pair<int, int >>> q;
	q.push({ 0, { sx, sy } });
	visited[sx][sy] = 1;

	while (!q.empty()) {
		int d = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;

		if (x == fx && y == fy) {
			return d;
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;

			if (visited[nx][ny] == 1)
				continue;

			if (map[nx][ny] == 1)
				continue;

			q.push({ d + 1, {nx, ny} });
			visited[nx][ny] = 1;

			
		}
	}
	
	return -1;
}

int main() {
	cin >> N >> M >> F;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int taxi_x, taxi_y;
	cin >> taxi_x >> taxi_y;

	vector < pair<int, pair<int, pair<int, int>>>> v;

	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >>  b >> c >> d;
		v.push_back({ a, {b, {c, d}} });	
	}
	
	while (1) {
		int shortestlen = 987654321;
		int ttx, tty, ti=0;

		// 영업 끝남
		if (v.empty())
			break;

		for (int i = 0; i < v.size(); i++) {
			int templen = get_length(taxi_x, taxi_y, v[i].first, v[i].second.first);
			memset(visited, 0, sizeof(visited));

			if (templen < shortestlen) {
				shortestlen = templen;
				ttx = v[i].first;
				tty = v[i].second.first;
				ti = i;
			}
			else if (templen == shortestlen) {
				if (v[i].first < ttx) {
					shortestlen = templen;
					ttx = v[i].first;
					tty = v[i].second.first;
					ti = i;
				}
				else if (v[i].first == ttx) {
					if (v[i].second.first < tty) {
						shortestlen = templen;
						ttx = v[i].first;
						tty = v[i].second.first;
						ti = i;
					}
				}
			}	
		}

		// 택시가 접근 못 하는 손님의 위치가 있다는 뜻.
		if (shortestlen == -1)
			break;


		//연료빼주기
		F -= shortestlen;

		// 시작지점에서 끝지점으로 가는 최단거리.
		shortestlen = get_length(v[ti].first, v[ti].second.first, v[ti].second.second.first, v[ti].second.second.second);
		memset(visited, 0, sizeof(visited));

		F -= shortestlen;

		if (F < 0) {
			break;
		}

		F += (shortestlen * 2);
		
		taxi_x = v[ti].second.second.first;
		taxi_y = v[ti].second.second.second;

		// 손님 제거
		v.erase(v.begin() + ti);
	}

	if (!v.empty()) {
		cout << -1;
		return 0;
	}

	cout << F;

	return 0;
}