#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
using namespace std;
void _move(int);
void search(int);
void _get(int, int);
void _merge(int, int, int, int);

int n, temp;
int answer = 0;
vector<vector<int>> map;
queue<int> q;
void search(int count) {
	if (count == 5) {
		for (int i = 0; i < n; i++) {
			answer = max(answer, *max_element(map[i].begin(), map[i].end()));
		}
		return;
	}

	vector<vector<int>> oldMap;
	oldMap.resize(n, vector<int>(n, 0));
	copy(map.begin(), map.end(), oldMap.begin());
	for (int i = 0; i < 4; i++) {
		_move(i);
		search(count + 1);
		copy(oldMap.begin(), oldMap.end(), map.begin());
	}
}

void _get(int y, int x) {
    // map을 비우고 queue에 넣는 과정
	if (map[y][x]) {
		q.push(map[y][x]);
		map[y][x] = 0;
	}
}

void _merge(int y, int x, int dy, int dx) {
    // queue와 map을 비교하면서 map에 값을 채우는 과정
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (map[y][x] == 0) {
			map[y][x] = temp;
		}
		else if (map[y][x] == temp) {
			map[y][x] *= 2;
			x += dx;
			y += dy;
		}
		else {
			x += dx;
			y += dy;
			map[y][x] = temp;
		}
	}
}
void _move(int option) {
	if (option == 0) {
		// up
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				_get(j, i);
			}
			_merge(0, i, 1, 0);
		}
	}
	else if (option == 1) {
		// down
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >=0; j--) {
				_get(j, i);
			}
			_merge(n-1, i, -1, 0);
		}
	}
	else if (option == 2) {
		// left
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				_get(i, j);
			}
			_merge(i, 0, 0, 1);
		}
	}
	else {
		// right
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >=0; j--) {
				_get(i, j);
			}
			_merge(i, n-1, 0, -1);
		}
	}
}


int main() {
	int index = 0;
	cin >> n;
	cin.ignore();
	
	map.resize(n, vector<int>(n, 0));
	string a;
	string token;

	for (int i = 0; i < n; i++) {
		index = 0;
		getline(cin, a);
		istringstream iss(a);
		while (getline(iss, token, ' ')) {
			map[i][index++] = stoi(token);
		}
	}
	search(0);
	cout << answer;

}
