#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

// BFS + ť 2�� ���ִ� ����

int N;

// ���ϻ����� ���, �ƴ� ������� ������ �����ϱ�
char grid_c[101][101];
char grid_nc[101][101];
// pop�ؼ� ������ ��ϱ� �ٽ� ���
queue <pair<int,int>> color;
int C = 0, NC = 0;
int used[101][101] = { 0, };
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void bfs()
{
	// ���ϻ����� �ƴ� ����� ���� �׸�
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (used[y][x] == 1) continue;
			else
			{
				color.push({ y,x });
				used[y][x] = 1;
				while (!color.empty())
				{
					int y = color.front().first;
					int x = color.front().second;
					color.pop();
					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
						if (grid_c[y][x] != grid_c[ny][nx]) continue;
						if (used[ny][nx] != 0) continue;
						used[ny][nx] = 1;
						color.push({ ny,nx });
					}
				}
				// �����ϳ� ���������� �����ֱ�
				C++;
			}
	 	}
	}
	// used �������� �ʱ�ȭ
	memset(used, 0, sizeof(used));
	// ���ϻ����� ����� ���� �׸�
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (used[y][x] == 1) continue;
			else
			{
				color.push({ y,x });
				used[y][x] = 1;
				while (!color.empty())
				{
					int y = color.front().first;
					int x = color.front().second;
					color.pop();
					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
						if (grid_nc[y][x] != grid_nc[ny][nx]) continue;
						if (used[ny][nx] != 0) continue;
						used[ny][nx] = 1;
						color.push({ ny,nx });
					}
				}
				NC++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int y = 0; y < N; y++)
	{
		string temp;
		cin >> temp;
		for (int x = 0; x < N; x++)
		{
			// ���ϻ��� X ����
			grid_c[y][x] = temp[x];
			// ���ϻ��� O �׳� ����
			if (temp[x] == 'R' || temp[x] == 'G') grid_nc[y][x] = 'R';
			else grid_nc[y][x] = 'B';
		}
	}
	bfs();
	cout << C << " " << NC;
}

// DFS�ε� Ǯ�� �ִ�
//#include <iostream>
//#include<cstring>
//using namespace std;
//
//char a[101][101];
//
//int ch[101][101];
//
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { -1,1,0,0 };
//
//int n;
//
//void DFS(int x, int y)
//{
//	ch[x][y] = true;
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//		if (ch[nx][ny] == 0 && a[x][y] == a[nx][ny])
//		{
//			DFS(nx, ny);
//		}
//	}
//}
//
//int main()
//{
//	int cnt = 0;
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ch[i][j] == 0)
//			{
//				DFS(i, j);
//				cnt++;
//			}
//		}
//	}
//
//	cout << cnt << " ";
//	memset(ch, 0, sizeof(ch));
//	cnt = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] == 'G')
//				a[i][j] = 'R';
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ch[i][j] == 0)
//			{
//				DFS(i, j);
//				cnt++;
//			}
//		}
//	}
//	cout << cnt << endl;
//}