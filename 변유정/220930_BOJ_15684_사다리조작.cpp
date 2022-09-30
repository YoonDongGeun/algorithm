#include <iostream>
using namespace std;

// ���Ʈ����, ��Ʈ��ŷ, ����
// ���� �ܰ�
// 1. ��ٸ� ���μ� - ����(1), ������(2)
// 2. �ּ� 0�� - �ִ� 3���� �ٸ� ���μ� ���� (bridge)
// 3. ���� 0 - 1 - 2 - 3 �÷����鼭 ans�� �ٲ�� �װ� �ּڰ�
// 4. ���� �������ٰ� ó�� �������� ������ ������ ��� (line)
// 5. ���μ� ��� �����ϸ� ��

// ladder ����, ���������� ������ 1,2�� �����ߴµ�
// bool �������� �ϰų� if �� ���̸� �ð��� �� ���� �� ����

int N, M, H, ladder[32][12];
int ans = 4;

int line()
{
	int flag = 0;
	for (int i = 1; i <= N; i++)
	{
		int sy = 1;
		int sx = i;
		while (true)
		{
			if (sy > H) break;
			if (ladder[sy][sx] == 1) // �������̸� ���������� �̵�
				sx++;
			else if (ladder[sy][sx] == 2) // �������̸� �������� �̵�
				sx--;
			sy++;
		}
		if (sx != i) flag = 1;
		if (flag == 1) break;
	}
	return flag;
}

void bridge(int cnt, int sy, int goal)
{
	if (cnt == goal)
	{
		if (line() == 0) ans = cnt;
		return;
	}

	for (int y = sy; y <= H; y++)
		for (int x = 1; x < N; x++)
		{
			if (ladder[y][x] != 0 || ladder[y][x + 1] != 0) continue;
			ladder[y][x] = 1;
			ladder[y][x + 1] = 2;
			bridge(cnt + 1, y, goal);
			ladder[y][x] = 0;
			ladder[y][x + 1] = 0;
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
		ladder[a][b + 1] = 2;
	}
	for (int i = 0; i < 4; i++)
	{
		bridge(0,1,i);
		if (ans != 4) break;
	}
	if (ans == 4) cout << -1;
	else cout << ans;
}