#include <iostream>
#include <cstring>
using namespace std;

int T, N, K;
int diamond[10001] = { 0, };
// ������ ũ�⿡ ���� �迭�� ����

// ������ ���� ������������, �ѹ��� �޾Ƽ� �����Ŀ� �ص� ������ ����
// (vector �ƴϸ� �׳� �迭��)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> K;
		memset(diamond, 0, sizeof(diamond));
		int maxx = -1;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			diamond[a]++;
			if (maxx < a) maxx = a;
		}
		int ans = 0;
		if (maxx <= K)
		{
			for (int i = 1; i <= maxx; i++)
				ans += diamond[i];
		}
		else 
		{
			for (int i = 1; i <= maxx - K; i++)
			{
				int temp = 0;
				for (int k = 0; k <= K; k++)
				{
					temp += diamond[i + k];
				}
				if (ans < temp) ans = temp;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}

/// ũ�⿡ ���� ���غ���
/// �ݺ��� (tc) �ȿ� �� �ڵ�
/// vector <int> v;
/// for (int i = 0;i<N;i++)
///	{
///		int a;
///		cin >> a;
///		v.push_back(a);
/// }
/// sort(v.begin(),v.end());
/// 
/// int cnt = 0;
/// int ans = 0;
/// for (int i = 0;i<N;i++)
/// {
///		for (int j = i+1;j<N;j++)
///		{
///			if (v[j] - v[i] <= K) cnt++;
///			else break;
///		}
///		if (cnt > ans) ans = cnt;
///		cnt = 0;
/// }
/// v.clear();
