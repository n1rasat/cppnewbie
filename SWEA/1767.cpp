#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int map[13][13] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N;

int anscnt = 0;
int anslen = 987654321;

vector<pair<int, int>> v;

void dfs(int m[13][13], int idx, int cnt, int len) {

	// 더 이상 연결할 게 없으면
	if (idx == v.size()) {
		if (cnt > anscnt) {
			anscnt = cnt;
			anslen = len;
		}
		else if (cnt == anscnt) {
			if (len < anslen) {
				anslen = len;

			}
		}
		return;
	}

	// mapcopy
	int temp[13][13] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			temp[i][j] = m[i][j];
		}
	}

	int x = v[idx].first;
	int y = v[idx].second;

	// 그 방향으로 전선 연결 놓는게 되냐
	for (int i = 0; i < 4; i++) {

		int l = 1;
		vector<pair<int, int>> vv;

		// 계속 뻗는다
		while (1) {
			int nx = x + (dx[i] * l);
			int ny = y + (dy[i] * l);

			//바깥 범위라는 것: 연결이 되었다는 것
			if (nx < 1 || nx > N || ny < 1 || ny > N) {
				dfs(temp, idx+1, cnt+1, len+l-1);
				break;
			}

			// 다른 코어나 전선
			if (temp[nx][ny] == 1 || temp[nx][ny] == 2)
				break;

			// 그 위치에 전선 놓기
			temp[nx][ny] = 2;
			// 뻗은 전선 저장
			vv.push_back({ nx, ny });
			l += 1;
		}

		// map 초기화
		for (int j = 0; j < vv.size(); j++) {
			temp[vv[j].first][vv[j].second] = 0;
		}
	
	}

	// 코어 선택 안 함
	dfs(temp, idx + 1, cnt, len);

	return;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];

				if (map[i][j] == 1) {
					if (i == N || j == N || i == 1 || j == 1)
						continue;

					// 연결해야될 프로세서 위치
					v.push_back({ i, j });
				}
			}
		}

		dfs(map, 0, 0, 0);

		cout << "#" << tc + 1 << " " << anslen << "\n";

		anslen = 987654321;
		anscnt = 0;
		memset(map, 0, sizeof(map));
		v.clear();

	}

	return 0;
}