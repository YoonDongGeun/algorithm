#include <iostream>
using namespace std;

// �˰��� �з� : ����, DP
//
// ���� �ܰ�
// 1. DP ���� ���ϱ� (�Ǻ���ġ ����)
// 2. 1�� ������ �������� N * 4 + (N-1) * 2

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	long long dp[81] = { 0, };
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	if (N == 1) cout << 4;
	else cout << dp[N-1] * 4 + dp[N - 2] * 2;
}