#include <iostream>
#include <algorithm>
using namespace std;

int N, bridge[3001], rock[3001];
// N : ¡�˴ٸ� ���� ����
// bridge : ���� ����
// rock : �������� ������ ���� ����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> bridge[i];

	rock[1] = 1;
	int ans = 1; // �ִ� �������� ������ ����
	for (int i = 2; i <= N; i++)
	{
		int temp = 1;
		for (int j = 1; j < i; j++)
			if (bridge[i] > bridge[j])
				temp = max(temp, rock[j] + 1);
		// i��° ������ �� �� �ִ�� ������ �� �ִ� ���� ����
		rock[i] = temp;
		// i��° ���� �������ֱ�
		ans = max(ans, rock[i]);
		// ans�� ���� max�� ����
	}
	cout << ans;
}