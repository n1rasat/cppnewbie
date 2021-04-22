#include<iostream>
#include <string.h>

using namespace std;

int map[51][51] = { 0, };
int tempmap[51][51] = { 0, };
int check[51][51] = { 0, };

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, M, T;
int xi, di, ki;

int main() {
	cin >> N >> M >> T;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			tempmap[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> xi >> di >> ki;
		// 시계
		if (di == 0) {
			for (int i = 0; i < N; i++) {
				// xi의 배수
				if ((i+1) % xi == 0) {
					// ki번 회전.
					for(int j=0; j<M; j++){
						map[i][(j + ki) % M] = tempmap[i][j];
					}
				}
			}
		}
		// 반시계
		else if(di == 1){
			for (int i = 0; i < N; i++) {
				// xi의 배수
				if ((i + 1) % xi == 0) {
					// ki번 회전.
					for (int j = 0; j < M; j++) {
						map[i][j] = tempmap[i][(j+ki)%M];
					}
				}
			}
		}
		memcpy(tempmap, map, sizeof(map));

		int flag = 0;
		// 인접한 것 체크하기.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					continue;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					// 범위 벗어나는거 아웃.
					if (nx < 0 || nx >= N)
						continue;

					if (ny == -1)
						ny = M - 1;
					else if (ny == M)
						ny = 0;

					if (map[i][j] == map[nx][ny]) {
						check[i][j] = 1;
						check[nx][ny] = 1;
					}
				}
			}
		}

		// 인접한것 지우기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] == 1) {
					map[i][j] = 0;
					flag = 1;
				}
			}
		}
		memset(check, 0, sizeof(check));
		memcpy(tempmap, map, sizeof(map));

		// 인접한 경우가 없으면
		int tempsum = 0;
		int tempmod = 0;
		int tempcnt = 0;
		if (flag == 0) {
			// 평균 구하기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (map[i][j] > 0) {
						tempsum += map[i][j];
						tempcnt += 1;
					}
				}
			}

			// DivisionByZero error.
			if (tempcnt == 0) {
				break;
			}

			tempmod = tempsum % tempcnt;
			tempsum = tempsum / tempcnt;

			// 더하거나 빼주기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (map[i][j] != 0) {
						if (map[i][j] > tempsum) {
							map[i][j] -= 1;
						}
						else if (map[i][j] < tempsum) {
							map[i][j] += 1;
						}
						else if (map[i][j] == tempsum) {
							if (tempmod > 0) {
								map[i][j] += 1;
							}
						}
					}

				}
			}

			memcpy(tempmap, map, sizeof(map));
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			answer += map[i][j];
		}
	}
	cout << answer;


	return 0;
}