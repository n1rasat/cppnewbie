#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, D, K, C;

int map[3003001] = { 0, };
int visited[3001] = { 0, };

int answer = 0;

int main() {
	cin >> N >> D >> K >> C;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	visited[C] += 1;
	answer += 1;
	 
	for (int i = 0; i < K; i++) {
		visited[map[i]] += 1;
		if (visited[map[i]] == 1)
			answer += 1;
		map[i + N] = map[i];
	}

	int temp = answer;

	int tail = 0;
	int head = K-1;

	while (1) {
		if (tail == N)
			break;

		visited[map[tail]] -= 1;
		if (visited[map[tail]] == 0)
			temp -= 1;

		tail += 1;
		head += 1;

		visited[map[head]] += 1;
		if (visited[map[head]] == 1)
			temp += 1;

		if (temp > answer)
			answer = temp;

	}

	cout << answer;
	
	return 0;
}