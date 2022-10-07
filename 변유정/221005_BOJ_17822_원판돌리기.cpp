#include <iostream>
using namespace std;

// ���� + �ùķ��̼�
//
// ���� �ܰ�
// 1. main() �Է� �ޱ�
// 2. �迭 ȸ���ϱ� (maketurn)
// 3. ȸ�� �� ����� ���� �ִ��� Ȯ�� (linked)
// 3-1. ������ ��޵� ���ǵ� (���� ����)�� �������� ���� Ȯ��
// 3-2. ����� ���� ������ ����� ���� ��� 0���� �ٲ��ֱ�
// 3-3. ����� ���� ������ ��հ��� circle �� �� �� +1, -1 ���ֱ�
//
// *** 3-3 �߿����� : ��հ��� ������ ������ �������� �ʴ´�. (double ���� ������ ��)
// �׷��ϱ� �̸� ���ص� �� ������ �� ���� ���� ���ϴ� ���� �� ����!
//

int N, M, T, circle[51][51];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void linked()
{
	bool flag = 0;
	bool xx[51][51] = { 0, };
	int temp = 0, cnt = 0;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			if (circle[y][x] == 0) continue;
			temp += circle[y][x];
			cnt++;
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny == 0 || ny == N + 1) continue;
				if (nx == 0) nx = M;
				if (nx == M + 1) nx = 1;
				if (circle[y][x] == circle[ny][nx])
				{
					xx[y][x] = 1;
					xx[ny][nx] = 1;
					flag = 1;
				}
			}
		}
	}
	if (flag == 1)
	{
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= M; x++)
				if (xx[y][x] == 1)
					circle[y][x] = 0;
	}
	else
	{
		for (int y = 1;y<=N;y++)
			for (int x = 1; x <= M; x++)
			{
				if (circle[y][x] == 0) continue;
				if (temp < circle[y][x] * cnt) circle[y][x]--;
				else if (temp > circle[y][x] * cnt) circle[y][x]++;
			}
	}
}

void maketurn(int x, int d, int k)
{
	for (int i = 1; i <= N; i++)
	{
		if (i % x == 0)
		{
			int cnt = k;
			if (d == 1)
			{
				while (cnt--)
				{
					int temp = circle[i][1];
					for (int j = 1; j < M; j++)
						circle[i][j] = circle[i][j + 1];
					circle[i][M] = temp;
				}
			}
			else
			{
				while (cnt--)
				{
					int temp = circle[i][M];
					for (int j = M; j > 1; j--)
						circle[i][j] = circle[i][j - 1];
					circle[i][1] = temp;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= M; x++)
			cin >> circle[y][x];

	for (int i = 0; i < T; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		maketurn(x, d, k);
		linked();
	}
	int ans = 0;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= M; x++)
			ans += circle[y][x];
	cout << ans;
}