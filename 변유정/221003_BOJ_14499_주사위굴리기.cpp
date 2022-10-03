#include <iostream>
using namespace std;

// �ùķ��̼� + ����
// ����� ���� : ��Ϲ���

// ������ �� �ֻ��� �迭 ��ġ�� ��� ���ϴ��� �� �����غ����ϴ� ����
// ����
// 1. �迭 ũ��(map)�� ���� �ֻ��� ������ ��ġ(cx,cy) �Է¹ޱ�
// 2. K�� ��ŭ �ֻ��� �����ֱ� (���⿡ ���� �ֻ��� ������)
// 3. �迭�� ����� ������ ���� �׳� �Ѿ��

int N, M, cx, cy, K, map[21][21];
int dice[7] = { 0, };

void moving(int num)
{
	if (num == 1)
	{
		cx++;
		int temp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = temp;
	}
	
	else if (num == 2)
	{
		cx--;
		int temp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = temp;
	}

	else if (num == 3)
	{
		cy--;
		int temp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = temp;
	}

	else if (num == 4)
	{
		cy++;
		int temp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> cy >> cx >> K;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	int now = 1;
	while (K--)
	{
		int dir;
		cin >> dir;
		if (dir == 1 && cx >= M - 1) continue;
		else if (dir == 2 && cx <= 0) continue;
		else if (dir == 3 && cy <= 0) continue;
		else if (dir == 4 && cy >= N - 1) continue;
		moving(dir);
		if (map[cy][cx] == 0)
			map[cy][cx] = dice[6];
		else
		{
			dice[6] = map[cy][cx];
			map[cy][cx] = 0;
		}
		cout << dice[1] << '\n';
	}
}