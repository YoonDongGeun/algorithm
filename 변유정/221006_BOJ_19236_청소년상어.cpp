#include <iostream>
using namespace std;

// ���� + �ùķ��̼�
// ���� �ܰ�
// 1. (0,0) ��� �α�
// 2. ����� �̵� (��ȣ ������� �ϴ� ���� �ſ� �߿�!)
// 2-1. ���� �ش� ��ȣ�� ����Ⱑ �̵��� �ѹ� �ߴٸ� ǥ�����ֱ� (�ߺ� ������ ��������)
// 2-2. �ش� ��ȣ�� ����Ⱑ �� �� �ִ� ���� ����
// * �� �� ���� �� : ���� ��� ��, ��� �ִ� ��

// 3. �״��� ��� �̵�
// 3-1. �� ���� �� �ִ� ����� �ִ밪 ã�ƾ� �ϱ� ������, �迭 �ǵ������ ��
//  ** temp �迭�� �� ����
// 3-2. �� �� �� ���� �� : ���� ��� ��, ���� ���� ���� ���� ��
// 3-3. ��� �� �� �ִ� �� ���� ans ��� �������ֱ�

int fish[4][4][2]; // fish[][][0] - ����� ��ȣ, fish[][][1] - ����� ����
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int s_dir,ans = 0;

// 2�ܰ�
void moving(int sy,int sx)
{
	for (int i = 1; i <= 16; i++)
	{ 
		int flag = 0;
		for (int y = 0; y < 4; y++)
		{
			if (flag == 1) continue;
			for (int x = 0; x < 4; x++)
			{
				if (flag == 1) continue;
				if (fish[y][x][0] == i)
				{
					int dirr = fish[y][x][1];
					while (true)
					{
						if (dirr == 9) dirr = 1;
						int ny = y + dy[dirr];
						int nx = x + dx[dirr];
						if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)
						{
							dirr++;
							continue;
						}
						if (ny == sy && nx == sx)
						{
							dirr++;
							continue;
						}
						int temp1 = fish[y][x][0];
						int temp2 = dirr;
						fish[y][x][0] = fish[ny][nx][0];
						fish[y][x][1] = fish[ny][nx][1];
						fish[ny][nx][0] = temp1;
						fish[ny][nx][1] = temp2;
						flag = 1;
						break;
					}
				}
			}
		}
	}
}

// 3�ܰ�
void shark(int sy,int sx,int sdir,int result)
{
	if (ans < result) ans = result;
	moving(sy, sx);
	int temp[4][4][2];
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			for (int i = 0; i < 2; i++)
				temp[y][x][i] = fish[y][x][i];

	for (int i = 1; i <= 3; i++)
	{
		int ny = sy + i * dy[sdir];
		int nx = sx + i * dx[sdir];
		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
		if (fish[ny][nx][0] == 0) continue;
		int ndir = fish[ny][nx][1];
		int plus = fish[ny][nx][0];
		fish[ny][nx][1] = 0;
		fish[ny][nx][0] = 0;
		shark(ny, nx, ndir, result + plus);

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				for (int i = 0; i < 2; i++)
					fish[y][x][i] = temp[y][x][i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			cin >> fish[y][x][0] >> fish[y][x][1];

	int k = fish[0][0][0];
	ans += k;
	fish[0][0][0] = 0;
	s_dir = fish[0][0][1];
	fish[0][0][1] = 0;
	shark(0, 0, s_dir, k);
	cout << ans;
}