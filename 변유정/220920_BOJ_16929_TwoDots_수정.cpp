#include <iostream>
using namespace std;

// ���� �ڵ�� �ٸ���
// 1. ���� ���� ������ ������ Ȯ���ϴ� ���� ����
// 2. ��� ������ ���°� �ƴ϶� ����� ������ �ݴ� ������ ������� �ʵ��� ��
// 3. ���� ����� ������ �ٽ� ���ƿԴٸ�, �ѹ��� �����̹Ƿ� �ű⼭ ���߱�

// �ڵ尡 �� ���������� ���ʿ��� ���� �����ؼ� �ð��� �� ��������

int N, M;
char board[50][50];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool used[50][50];
char check;
bool ans;

void dfs(int y, int x, int dir)
{
	used[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		if ((i + 2) % 4 == dir) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (board[ny][nx] != check) continue;
		if (used[ny][nx] == 1) ans = 1;
		used[ny][nx] = 1;
		if (ans == 1) return;
		dfs(ny, nx, i);
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
			if (used[y][x]) continue;
			check = board[y][x];
			dfs(y, x, 0);
			if (ans) break;
		}
		if (ans) break;
	}
	if (ans) cout << "Yes";
	else cout << "No";
	return 0;
}