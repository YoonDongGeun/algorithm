#include <iostream>
#include <algorithm>
using namespace std;

// ȭ��ǥ �׸���
// 1. ��ġ�� ���� �迭�� Ǯ�� - �ð� ���� �ɸ�
// 2. �Է¼����� ���� �迭�� Ǯ�� - N^2

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, point[5001][2] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> point[i][0] >> point[i][1];

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int mnn = 1e9;
		for (int j = 0; j < N; j++)
		{
			if (i != j && point[i][1] == point[j][1])
				mnn = min(mnn, abs(point[i][0] - point[j][0]));
		}
		ans += mnn;
	}
	cout << ans;
}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, point[100001] = { 0, };
//	cin >> N;
//	int m_idx = 0;
//	for (int i = 0; i < N; i++)
//	{
//		int t;
//		cin >> t;
//		cin >> point[t];
//		if (t > m_idx) m_idx = t;
//	}
//	int ans = 0;
//	for (int i = 0; i <= m_idx; i++)
//	{
//		if (point[i] == 0) continue;
//		int temp1 = 0;
//		int temp2 = 0;
//		int idx1 = i;
//		int idx2 = i;
//		while (true)
//		{
//			idx1--;
//			temp1++;
//			if (idx1 < 0)
//			{
//				temp1 = 1e9;
//				break;
//			}
//			if (point[idx1] == point[i]) break;
//		}
//		while (true)
//		{
//			idx2++;
//			temp2++;
//			if (idx2 > m_idx)
//			{
//				temp2 = 1e9;
//				break;
//			}
//			if (point[idx2] == point[i]) break;
//		}
//		ans += min(temp1, temp2);
//	}
//	cout << ans;
//}