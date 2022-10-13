#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//N : ���� ũ��, M:���� ���� ����, C : �� ä���� �� �ִ� �ִ� ��
// ���� ���� (�ι� ���)
// 1��° ��� : �� �ϲ� ���� ����
// 2��° ��� : ���� ���ܵ��� C�� �Ѿ�� �Ǿ��� ��, �����ϴ� ���� ����


int N, honey[11][11],M,C;
bool used[11][11];
int ans;
int back;
bool visited[11];

// ���� ä���ߴٴ� ���� �����
void make_used(int y, int x,int num)
{
	int cnt = M;
	while (cnt--)
	{
		used[y][x] = num;
		x++;
	}
}

// �� �հ� ����
void sum_honey(int y, int x, int idx,int summ, int kkk)
{
	back = max(back, summ);
	for (int i = idx; i < M; i++)
	{
		if (visited[i]) continue;
		if (kkk < honey[y][x + i]) continue;
		visited[i] = 1;
		sum_honey(y, x, i, summ + honey[y][x + i] * honey[y][x + i], kkk - honey[y][x + i]);
		visited[i] = 0;
	}
}

// �ϲ� ���� ä��
void bee(int cnt, int profit, int ny)
{
	if (cnt == 2)
	{
		if (ans < profit) ans = profit;
		return;
	}

	for (int y = ny; y < N; y++)
	{
		for (int x = 0; x <= N-M; x++)
		{
			if (!used[y][x])
			{
				int k = x;
				bool flag = 0;
				while (k < x+ M)
				{
					if (used[y][k])
					{
						flag = 1;
						break;
					}
					k++;
				}
				if (flag) continue;
				make_used(y,x,1);
				back = 0;
				sum_honey(y, x, 0, 0, C);
				bee(cnt + 1, profit + back, y);
				make_used(y, x, 0);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M >> C;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> honey[y][x];
		ans = 0;
		bee(0, 0, 0);
		cout << "#" << tc << " " << ans << "\n";
		memset(used, 0, sizeof(used));
	}
}