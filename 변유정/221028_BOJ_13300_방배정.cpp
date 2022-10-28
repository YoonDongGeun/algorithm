#include <iostream>
using namespace std;

// �˰��� �з� : ����, ����
// 
// ���� �ܰ�
// 1. �л� 6�г� ���� �迭 �����
// 2. �迭 �л����� 0�̸� pass
// 3. 0�� �ƴϸ� �ѹ��� �ִ� �ο��� K �� ���� �� �����ֱ�
// 4. ������ �������� ������ +1 ���ֱ�

int N, K;
int student[7][2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		student[b][a]++;
	}
	int ans = 0;
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (student[i][j] == 0) continue;
			ans += student[i][j] / K;
			if (student[i][j] % K != 0) ans += 1;
		}
	}
	cout << ans;
}