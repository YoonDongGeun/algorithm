#include <iostream>
using namespace std;

// ��ٹ��� ��� ���� �����ϱ�
// i, j, k ��° ������ arr[i] < arr[j] && arr[i] > arr[k] �� �Ǵ� ���̽� ã��
// �˰��� : ������

int N, arr[5001] = { 0, }, bus[5001][5001] = { 0, };
long long ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	// arr[i][j] : j��°���� �����ʿ� �ִ� ���ڵ� ��, i ���� ���� ���� �͵��� ����
	for (int i = 1; i <= N; i++)
	{
		bus[i][N] = 0;
		for (int j = N; j >= 1; j--)
		{
			if (arr[j] < i) bus[i][j - 1] = bus[i][j] + 1;
			else bus[i][j - 1] = bus[i][j];
		}
	}

	for (int i = 1; i < N; i++)
		for (int j = i + 1; j <= N; j++)
			// arr[i] < arr[j]
			if (arr[i] < arr[j])
				// j ���� �ڿ� �ִ� ���ڵ� ��, arr[i] > arr[k] �� ������ �����ֱ�
				ans += bus[arr[i]][j];
	cout << ans;
}