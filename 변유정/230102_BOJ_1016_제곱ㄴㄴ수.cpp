#include <iostream>
using namespace std;

// �˰��� - ����, ������, �Ҽ�����, �����佺�׳׽��� ü
// ���� : 1 <= min <= 1,000,000,000,000
//		  min <= max <= min + 1,000,000

long long mn, mx;
bool checked[1100000];
// ���� : min - max 1,000,000 �̱� ������ üũ

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> mn >> mx;
	int ans = 0;

	for (long long i = 2; i * i <= mx; i++)
	{
		long long N = mn / (i * i);
		// ������ ��� �ּڰ� ���ϱ� (mn ���� �����ؾ���)
		if (mn % (i * i)) N++;

		while (N * i * i <= mx)
		{
			checked[N * i * i - mn] = 1;
			N++;
		}
	}
	for (int i = 0; i <= mx - mn; i++)
		if (!checked[i]) ans++;
	cout << ans;
}