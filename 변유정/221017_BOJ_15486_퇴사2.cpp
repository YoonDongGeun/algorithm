#include <iostream>
using namespace std;

//dp�� Ǯ��
// �Ųٷ� ���鼭 ��� ����
// ��¥ �Ϸ簡 �ش�Ǳ� ������ ������ٶ� +1 �������

int N;
int consult[1500001][2] = { 0, };
int find_mxx[1500002] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> consult[i][0] >> consult[i][1];

	for (int i = N; i >= 1; i--)
	{
		if (i + consult[i][0] > N+1) find_mxx[i] = find_mxx[i + 1];
		else find_mxx[i] = max(find_mxx[i + 1], consult[i][1] + find_mxx[i + consult[i][0]]);
	}
	
	cout << find_mxx[1];
}

// �ݴ�� �غ���
//int now_mxx = 0;
//for (int i = 1; i <= N + 1; i++)
//{
//	now_mxx = max(find_mxx[i], now_mxx);
//	if (i + consult[i][0] > N + 1) continue;
//	find_mxx[i + consult[i][0]] = max(now_mxx + consult[i][1], find_mxx[i + consult[i][0]]);
//}