#include <iostream>
#include <cstring>
using namespace std;

/// ���� �����ϱ�
/// �ʿ��� ���� : DP(�޸������̼�), ������
/// 
/// �߿��� ���� 2���� �迭�̱� ������ �� ���⿡�� �ּҰ����� ������� �Ѵ�
/// - ���� �߿�!
/// - DP topdown bottom-up �ٽ� �����ϱ� (�̰Ŵ� �ִ밪���� ���ϱ� ������ topdown)

int T, N, M;
int arr[51][51]; // ���ݸ� ��ġ�� ������
int summ[51][51]; // ������ ��ġ������ ������
int dp[51][51][51][51];///[a][b][c][d] : a,b ���� c,d ���� �ڸ��µ� �ʿ��� ������ ��

void prefix_sum() ///��ġ�� ������ �̸� ���ϱ�
{
	for (int y = 1;y<=N;y++)
		for (int x = 1; x <= M; x++)
			summ[y][x] = summ[y][x - 1] + summ[y - 1][x] - summ[y-1][x - 1] + arr[y][x];
}

int div_choco(int s_y,int s_x,int e_y,int e_x)
{
	if (s_y == e_y && s_x == e_x) return 0;
	if (dp[s_y][s_x][e_y][e_x] != -1) return dp[s_y][s_x][e_y][e_x];

	dp[s_y][s_x][e_y][e_x] = 1e9;
	// �̸� ū������ �����α�
	int temp = summ[e_y][e_x] - summ[s_y - 1][e_x] - summ[e_y][s_x - 1] + summ[s_y-1][s_x-1];
	// {s_y,s_x} ~ {e_y,e_x} ���� arr ������ ���ϱ�
	for (int i = s_y; i < e_y; i++)
		dp[s_y][s_x][e_y][e_x] = min(dp[s_y][s_x][e_y][e_x], div_choco(s_y, s_x, i, e_x) + div_choco(i + 1, s_x, e_y, e_x) + temp);
	//���� �ڸ��� (y)
	// ���� �߶󺸰� ���� �� ������ �װɷ� �ٲٱ�

	for (int i = s_x; i < e_x; i++)
		dp[s_y][s_x][e_y][e_x] = min(dp[s_y][s_x][e_y][e_x], div_choco(s_y, s_x, e_y, i) + div_choco(s_y, i+1, e_y, e_x) + temp);
	// ���� �ڸ��� (x)
	// ���η� �߶󺸰� ���� �� ������ �װɷ� �ٲٱ�


	return dp[s_y][s_x][e_y][e_x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M;
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= M; x++)
				cin >> arr[y][x];

		memset(summ, 0, sizeof(summ));
		memset(dp, -1, sizeof(dp));

		prefix_sum();
		int ans = div_choco(1, 1, N, M);
		cout << "#" << tc << " " << ans << "\n";
	}
}