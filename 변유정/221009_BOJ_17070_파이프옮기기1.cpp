#include <iostream>
using namespace std;

// ���� + �ùķ��̼�
// ���� ����
// 1. ������ ���� ��, ���� �������� �����ϱ�
// 2. ������ �ʱ� ���Ƶ� ���� - ���� (���ε��� ���� �̸� �����صα�)
// 3. �迭 3������ ������ ������ (����, ����, �밢�� ��)
// 4. ������ �̵��� ��, ���� �ִ��� ������ ������ �ű��

int N, home[17][17];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> home[y][x];
	int dp[17][17][3] = {0,};
	dp[1][2][0] = 1;
	for (int x = 3; x <= N; x++)
		if (!home[1][x]) dp[1][x][0] = dp[1][x - 1][0];

	for (int y = 2;y<=N;y++)
		for (int x = 2; x <= N; x++)
		{
			if (!home[y][x])
			{
				dp[y][x][0] = dp[y][x - 1][0] + dp[y][x - 1][2];
				dp[y][x][1] = dp[y - 1][x][1] + dp[y - 1][x][2];
			}
			if (!home[y][x] && !home[y - 1][x] && !home[y][x - 1])
				dp[y][x][2] = dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2];
		}
	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
}