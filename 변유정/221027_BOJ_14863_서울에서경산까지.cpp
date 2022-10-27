#include <iostream>
#include <algorithm>
using namespace std;

// �˰��� �з� : DP
// �迭 DP[N ���� ����][K �ð�]

// Bool operator �����ϸ� �� ���� Ǯ�� ����

int N, K;
int time[101][2];
int money[101][2];
// 0 - ����, 1 - ������
int DP[101][100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++)
			cin >> time[i][j] >> money[i][j];
	// ���� 0 �϶����� �ִ� �ð��� ������ �ֱ� ������ �̸� �����ֱ�
	DP[0][time[0][0]] = max(DP[0][time[0][0]], money[0][0]);
	DP[0][time[0][1]] = max(DP[0][time[0][1]], money[0][1]);

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			// DP �迭 �ȿ� ���ڰ� ���� ���� �������ֱ�
			if (DP[i - 1][j] > 0)
			{
				// �ð��� ���ص� �ʰ��� ���� ������ �� �� �� DP �迭�� ����ֱ� (���� , ������ ���� �� ��)
				if (j + time[i][0] <= K) DP[i][j + time[i][0]] = max(DP[i][j + time[i][0]], DP[i - 1][j] + money[i][0]);
				if (j + time[i][1] <= K) DP[i][j + time[i][1]] = max(DP[i][j + time[i][1]], DP[i - 1][j] + money[i][1]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= K; i++)
		ans = max(ans, DP[N-1][i]);
	cout << ans;
}

// �ؿ��� ����Ž������ ������ �ڵ� (�����½�ũ 1�� ���� ������)

//void trip(int now, int left, long long don)
//{
//	if (now == N)
//	{
//		if (ans < don) ans = don;
//		return;
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		if (left - time[now][i] < 0) continue;
//		trip(now + 1, left - time[now][i], don + money[now][i]);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < 2; j++)
//			cin >> time[i][j] >> money[i][j];
//	ans = 0;
//	trip(0, K, 0);
//	cout << ans;
//	return 0;
//}