#include <iostream>
#include <queue>

using namespace std;

int N, M;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int map[13][13] = { 0, };
//red, blue 조합의 visited
int visited[13][13][13][13] = { 0, };

pair<int, int> red;
pair<int, int> blue;

int answer = 987654321;

void bfs(pair<int, int> rd, pair<int, int> bl) {
			// cnt,		red,				blue
	queue <pair<int,  pair<pair<int, int>, pair<int, int>>>> q;

	int rx = rd.first;
	int ry = rd.second;
	int bx = bl.first;
	int by = bl.second;
	int cnt = 0;
	q.push({ cnt, {{rx, ry}, {bx, by}} });
	visited[rx][ry][bx][by] = 1;

	while (!q.empty()) {
		int crx = q.front().second.first.first;
		int cry = q.front().second.first.second;
		int cbx = q.front().second.second.first;
		int cby = q.front().second.second.second;
		int ccnt = q.front().first;

		q.pop();

		if (ccnt > 10)
			continue;
		
		if (map[cbx][cby] == 9)
			continue;
		else if (map[crx][cry] == 9) {
			if (ccnt < answer)
				answer = ccnt;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nrx = crx;
			int nry = cry;
			int nbx = cbx;
			int nby = cby;

			// red 부터 벽쪽으로
			while (1) {
				if (map[nrx][nry] != 1 && map[nrx][nry] != 9) {
					nrx += dx[i];
					nry += dy[i];
				}
				else {
					// 벽에 박았으면 후퇴
					if (map[nrx][nry] == 1) {
						nrx -= dx[i];
						nry -= dy[i];
					}
					break;
				}
			}

			// blue 벽쪽으로
			while (1) {
				if (map[nbx][nby] != 1 && map[nbx][nby] != 9) {
					nbx += dx[i];
					nby += dy[i];
				}
				else {
					// 벽에 박았으면 후퇴
					if (map[nbx][nby] == 1) {
						nbx -= dx[i];
						nby -= dy[i];
					}
					break;
				}
			}

			// 둘이 박았으면
			if (nrx == nbx && nry == nby) {
				if (map[nrx][nry] != 9) {
					// red가 더 많이 움직였으면 red가 blue에 처박음
					if ((abs(nrx - crx) + abs(nry - cry)) > (abs(nbx - cbx) + abs(nby - cby))) {
						nrx -= dx[i];
						nry -= dy[i];

					}
					else {
						nbx -= dx[i];
						nby -= dy[i];
					}
				}
			}

			if (visited[nrx][nry][nbx][nby] == 1)
				continue;

			visited[nrx][nry][nbx][nby] = 1;
			q.push({ ccnt + 1, {{nrx, nry}, {nbx, nby}} });
		}

	}

	return;
}


int main() {
	cin >> N >> M;

	getchar();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char ch;
			ch = getchar();

			if (ch == '#') {
				map[i][j] = 1;
			}
			else if (ch == '.') {
				map[i][j] = 0;
			}
			else if (ch == 'O') {
				map[i][j] = 9;
			}
			else if (ch == 'R') {
				map[i][j] = 2;
				red.first = i;
				red.second = j;
			}
			else if (ch == 'B') {
				map[i][j] = 3;
				blue.first = i;
				blue.second = j;
			}
		}
		getchar();
	}

	bfs(red, blue);

	if (answer == 987654321) {
		cout << -1;
	}
	else {
		cout << answer;
	}
	
	return 0;
}