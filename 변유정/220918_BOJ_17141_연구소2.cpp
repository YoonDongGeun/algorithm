#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// BFS + DFS
// �����ܰ�
// 1. ���̷��� ���� ĭ 2(virus)�� ���Ϳ� �����ϱ�
// 2. �� ĭ �� M�� ��ŭ �����ϱ�
// 3. M������ BFS �� �ɸ��� �ð� �ǵ����ֱ�
// 3-1. 0,2�� ��� ���̷����� ������ ������ �ɸ��ð� �ǵ����ְ�
// 3-2. �׷��� �ʴٸ� 1e9 �ǵ����ֱ�
// 
// 4. �� �� ���� ���� �� ���
// 4-1. ���� ���� ���� ���� 1e9�� -1 ��� (��� ����� ���� 0,2�� ���̷�����
// �������� �������)


int N, M, lab[50][50];
// virus - ���̷��� ���� �� �ִ� ĭ �����
vector <pair<int, int>> virus;
// used_v - �� ĭ�� ����ߴ���
bool used_v[10];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int ans = 1e9;
// v - ����Ǽ� M�� ���̷��� �����
vector <pair<int, int>> v;

int bfs()
{
	// used_b - �� ĭ�� ����ߴ��� ���ߴ��� Ȯ��
	int used_b[50][50] = { 0, };
	// temp - ���̷����� ������ �� ť
	queue<pair<int, int>> temp;
	for (int i = 0; i < M; i++)
	{
		int ty = v[i].first;
		int tx = v[i].second;
		temp.push({ ty,tx });
		used_b[ty][tx] = 1;
	}
	int result = 0;
	while (!temp.empty())
	{
		int y = temp.front().first;
		int x = temp.front().second;
		temp.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (lab[ny][nx] == 1 || used_b[ny][nx] != 0) continue;
			used_b[ny][nx] = used_b[y][x] + 1;
			// ������ ����ġ��
			if (used_b[ny][nx] > ans) return 1e9;
			temp.push({ ny, nx });
		}
	}
	// 0�Ǵ� 2�� ��� ���̷��� ������ ��������� Ȯ��
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (lab[y][x] != 1 && used_b[y][x] == 0) return 1e9;
			else if (used_b[y][x] > result) result = used_b[y][x];
		}
	}
	return result - 1;
}

// ����Ǽ� �����
void dfs(int now, int cnt)
{
	if (cnt == M)
	{
		int k = bfs();
		if (k < ans) ans = k;
		return;
	}

	for (int i = now; i < virus.size(); i++)
	{
		if (used_v[i] == 1) continue;
		int y = virus[i].first;
		int x = virus[i].second;
		used_v[i] = 1;
		v.push_back({ y,x });
		dfs(i, cnt + 1);

		v.pop_back();
		used_v[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> lab[y][x];
			if (lab[y][x] == 2)
				virus.push_back({ y,x });
		}
	}
	dfs(0, 0);
	if (ans == 1e9) cout << -1;
	else cout << ans;
}