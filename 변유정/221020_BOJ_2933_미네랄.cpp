#include <iostream>
#include <queue>
using namespace std;

//���� �ܰ� (ť�θ� ����)
// 1. �̳׶� ����('x') ����
// 2. â��, ��� ������� ����� ������ ���� �Է� �ް� ���� (broken)
// 2-1. â�� ���� - 0���� ¦���϶�. 'x' ������ '.'���� �ٲٰ� ����
// 2-2. ��� ���� - Ȧ�� �϶�, 'x' ������ '.' ���� �ٲٰ� ����

// 3. �̳׶� �ٴڱ��� ������ (move)
// 3-1. �ٴں��� Ž�� - ������ ť q�� �ְ� '.'���� �ٲ��ְ� ������
// 3-2. ���� �̾��� �ִ� �̳׶� �� ã�� �ִ� ������ �� �ִ� ���� ã��
// 3-3. ���̸�ŭ ��ġ �ٲ��ְ� 'x'�� �� �ٲ��ֱ�
// 3-4. Ž���� �̳׶� ������ �� �̳׶� ������ ������ Ž�� ����

// 4. N�� ��ŭ �����ϰ� cave �迭 ���

// ���ͷθ� �����غ���

int R, C, N;
int mineral = 0;
char cave[102][102];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0, 0};

void broken(int h, int dir)
{
	if (dir == 0)
	{
		int st = 0;
		while (st < C)
		{
			if (cave[R - h][st] == 'x')
			{
				cave[R - h][st] = '.';
				mineral--;
				break;
			}
			st++;
		}
	}

	else
	{
		int st = C;
		while (st--)
		{
			if (cave[R - h][st] == 'x')
			{
				cave[R - h][st] = '.';
				mineral--;
				break;
			}
		}
	}
}

void move()
{
	int used[102][102] = { 0, };
	int temp = 0;
	queue <pair<int, int>> q;
	for (int y = R - 1; y >= 0; y--)
	{
		for (int x = 0; x < C; x++)
		{
			if (temp == mineral) break;
			if (used[y][x] == 1 || cave[y][x] == '.') continue;
			used[y][x] = 1;
			q.push({ y,x });
			temp++;
			queue <pair<int, int>> now;
			while (!q.empty())
			{
				int ny = q.front().first;
				int nx = q.front().second;
				q.pop();
				cave[ny][nx] = '.';
				now.push({ ny,nx });
				for (int i = 0; i < 4; i++)
				{
					int nny = ny + dy[i];
					int nnx = nx + dx[i];
					if (nny < 0 || nny >= R || nnx < 0 || nnx >= C) continue;
					if (used[nny][nnx] == 1 || cave[nny][nnx] == '.') continue;
					used[nny][nnx] = 1;
					q.push({ nny,nnx });
					temp++;
				}
			}
			int k = now.size();
			int mxx = 1e9;
			while (k--)
			{
				int ny = now.front().first;
				int nx = now.front().second;
				now.pop();
				int nny = ny;
				while (true)
				{
					if (cave[nny + 1][nx] == 'x' || nny + 1 >= R)
					{
						mxx = min(mxx, nny - ny);
						break;
					}
					nny++;
				}
				now.push({ ny,nx });
			}
			while (!now.empty())
			{
				int ny = now.front().first;
				int nx = now.front().second;
				now.pop();
				used[ny][nx] = 0;
				ny += mxx;
				used[ny][nx] = 1;
				cave[ny][nx] = 'x';
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> cave[i][j];
			if (cave[i][j] == 'x') mineral++;
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int height;
		cin >> height;
		broken(height, i % 2);
		move();
	}

	for (int y = 0; y < R; y++)
		cout << cave[y] << '\n';
}