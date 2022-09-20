#include <iostream>
using namespace std;

// �ð� �����ɸ� �ڵ� (DFS)
// 
// ���� ���
// 1. �Է¹��� �迭 �ϳ��� ���鼭 �� ���� ������(������)�� ������ Ȯ��
// 2. ���ٸ�, �ѹ��� ���� �� ���� �� ���� �Ʒ��� (������)
// 3. dfs���� ���鼭 �������� ���İ� �� �ִ��� Ȯ��
// 
// 3-1. �������� �ٸ� ���� ������ ����, �̹� ����ߴ� ���̸� ����
// 
// �� ���� ����� ���Ŀ� ������ �����ϸ� �ƾ��٤�

int N, M;
char board[50][50];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ey, ex;
bool used[50][50];
char check;
bool ans;

void dfs(int y, int x,int dir)
{
	if (y == ey && x == ex)
	{
		ans = 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int k = (dir + i) % 4;
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (board[ny][nx] != check || used[ny][nx] == 1) continue;
		used[ny][nx] = 1;
		dfs(ny, nx, dir + i);
		used[ny][nx] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> board[y][x];

	for (int y = 0; y < N - 1; y++)
	{
		for (int x = 0; x < M - 1; x++)
		{
			if (board[y][x] == board[y][x + 1])
			{
				ey = y+1;
				ex = x;
				used[y][x] = 1;
				used[y][x + 1] = 1;
				check = board[y][x];
				dfs(y, x+1, 0);
				if (ans == 1) break;
			}
		}
		if (ans == 1) break;
	}
	if (ans == 1) cout << "Yes";
	else cout << "No";
	return 0;
}

// �� ���� ���
//#include <cstdio>
//
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,-1,0,1 };
//
//int n, m, ans = 1;
//char map[50][51];
//bool visit[50][50] = { false };
//
//bool dfs(int x, int y, int d) {
//	visit[x][y] = true;
//	for (int i = 0; i < 4; i++) {
//		if ((i + 2) % 4 == d) continue; // ������ ����ģ ���� ����
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[x][y] != map[nx][ny]) continue;
//		if (visit[nx][ny]) return false;
//		if (!dfs(nx, ny, i)) return false;
//	}
//	return true;
//}
//
//int main() {
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) scanf("%s", map[i]);
//	for (int i = 0; i < n && ans; i++) {
//		for (int j = 0; j < m && ans; j++) {
//			if (visit[i][j]) continue;
//			if (!dfs(i, j, -1)) ans = 0;
//		}
//	}
//	printf("%s", ans ? "No" : "Yes");
//}