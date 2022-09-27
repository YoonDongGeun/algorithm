#include <iostream>
#include <vector>
using namespace std;

// �ùķ��̼� + ����
// (�� + ����) + (���� + �ܿ�) - ����
// ������ ��
// 1. �� ó�� �޴� ���� ���� ���Ǵ� ����� �ƴϴ� (��� 5)
// 2. �ڵ� ��ġ�� �� �������ָ� '���̰� � �������� ��� �Դ´�' �� '�Է����� �־����� ������ ��ġ�� ��� ���� �ٸ�'
// ���� �������� ���� �������� �ʿ� ����
// 3. �ݺ����� ���� ������ �ڵ� �迭 �� ����

int N, M, K;
int A[11][11];
int yangboon[11][11];
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
// ���� ��ġ�� ���� �������ֱ�
vector <int> S2D2[11][11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> A[y][x];
			yangboon[y][x] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		S2D2[x][y].push_back(z);
	}

	while (K--)
	{
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (!S2D2[y][x].empty())
				{
					int temp = 0;
					for (int idx = S2D2[y][x].size()-1; idx >=0; idx--)
					{
						if (S2D2[y][x][idx] <= yangboon[y][x]) // ��
						{
							yangboon[y][x] -= S2D2[y][x][idx];
							S2D2[y][x][idx] += 1;
						}
						else
						{
							// ����
							temp += S2D2[y][x][idx]/2;
							S2D2[y][x].erase(S2D2[y][x].begin() + idx);
						}
					}
					yangboon[y][x] += temp;
				}
			}
		}

		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (!S2D2[y][x].empty())
				{
					for (int idx = 0; idx < S2D2[y][x].size(); idx++)
					{
						// ����
						if (S2D2[y][x][idx] % 5 == 0)
						{
							for (int k = 0; k < 8; k++)
							{
								int ny = y + dy[k];
								int nx = x + dx[k];
								if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
								S2D2[ny][nx].push_back(1);
							}
						}
					}
				}
				// �ܿ�
				yangboon[y][x] += A[y][x];
			}
		}
	}

	int ans = 0;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			if (!S2D2[y][x].empty())
				ans += S2D2[y][x].size();

	cout << ans;
}