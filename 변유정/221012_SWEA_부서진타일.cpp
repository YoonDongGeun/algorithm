#include <iostream>
using namespace std;

// �μ��� Ÿ��
// ** ������ �� : �߰��� �´� Ÿ���� ������ �ٷ� ������Ѵ�
// ** ���ڰ� �ƴ϶� ���ڿ��� �޾ƺ���

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T,N,M;
	int dy[4] = { 0,1,0,1 };
	int dx[4] = { 0,0,1,1 };
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M;
		char tile[56][56];
		for (int y = 0; y < N; y++)
				cin >> tile[y];

		bool flag = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (tile[y][x] == '#')
				{
					if (tile[y + 1][x] == '#' && tile[y][x + 1] == '#' && tile[y + 1][x + 1] == '#')
					{
						tile[y + 1][x] = '.';
						tile[y][x + 1] = '.';
						tile[y + 1][x + 1] = '.';
					}
					else
					{
						flag = 1;
						break;
					}
				}
			}
			if (flag) break;
		}
		if (flag == 1) cout << '#' << tc << " NO" << "\n";
		else cout << "#" << tc << " YES" << "\n";
	}
}