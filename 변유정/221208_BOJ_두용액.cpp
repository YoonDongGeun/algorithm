#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �˰��� : ����, �� ������
// 1. ��׵��� ũ�� ������ �������ֱ�
// 2. ��� ó��, ������ �����͸� �����ְ� ��� ���� �����ָ鼭 �������ֱ�

int N; // �־����� ����(���) ����
vector <int> liquid; // ��� Ư���� �����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		liquid.push_back(a);
	}
	sort(liquid.begin(), liquid.end()); // 1�������� �������ֱ�
	int s = 0, e = N - 1; // �� ������ ��ġ
	int ans = 2000000000; // �� ��� ȥ�� �ִ밪 -> �ּҰ� ã���ֱ�
	int ans1 =0, ans2=0; // �� ��� �� �����ϱ�
	while (s < e)
	{
		int temp = liquid[e] + liquid[s];

		if (abs(temp) < ans) // �� ��� ���� ���� �� �۴ٸ�
		{
			ans = abs(temp); // ans ����
			ans1 = liquid[s]; // �� �������ֱ�
			ans2 = liquid[e];
			if (ans == 0) break; // ���ü� �ִ� ���� ���� ���� 0�̹Ƿ� 0�̸� ���߱�
		}
		if (temp < 0) s++; // ���� temp ���� ������ �� �����͸� �����̱�
		else e--; // ���� temp���� ����� �� �����͸� �����̱�
		// �����͸� �������� �� ��� ���� ���̱�
	}
	cout << ans1 << ' ' << ans2;
}