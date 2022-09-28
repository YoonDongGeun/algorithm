#include <iostream>
using namespace std;

// ��Ʈ������ ���� ����Ʈ
//https://sf2020.tistory.com/29

int N;
double work[16][16];
// ��Ʈ������ + dp
double dp[1 << 16];
double dp1[16];

double make_dp(int now, int used)
{
	// �� �̻� �Ѿ������ �ǵ��ƿ���
	if (now >= N) return 1;
	// -1 �� �ƴϰ� �Ǹ� �ִ� ã�� �Ǵ� ��
	if (dp[used] != -1) return dp[used];
	// ���� �ּڰ��� 0���� �ٲ��ֱ�
	dp[used] = 0;
	for (int i = 0; i < N; i++)
		// ���ǹ� : ���� i�� ������� �ʾҴٸ�(��ġ�°� ���ٸ�)    // | ���ļ� ��������
		if (!(used & 1 << i)) dp[used] = max(dp[used], make_dp(now + 1, used | 1 << i) * work[now][i]);
	return dp[used];
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
		cin >> N;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
			{
				cin >> work[y][x];
				work[y][x] /= 100;
			}

		// �ʱⰪ -1�� �ٲ��ֱ�
		for (int i = 0; i < (1 << N); i++)
			dp[i] = -1;
		cout << '#' << tc << " ";
		cout << fixed;
		cout.precision(6);
		cout << make_dp(0,0) * 100 << '\n';
	}
}