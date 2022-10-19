#include <iostream>
#include <algorithm>
using namespace std;

//DP ����
// ��Ʈ : ���Ժ��� ������
// �賶������ ��� �����鼭,
// 1. ���� ��ƿ���� ���Ը� ���� �賶���� ���ؼ� �ִ밪 �ø���
// 2. �Ѿ�� ���� �賶������ ���ֱ�

int N, K, bag[101][2];
int dp[101][100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> bag[i][0] >> bag[i][1];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= bag[i][0]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - bag[i][0]] + bag[i][1]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];
}