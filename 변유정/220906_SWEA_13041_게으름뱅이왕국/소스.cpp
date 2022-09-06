#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// �߿��� �� : ������ �°� ���Ǿ����� �ƴ��� �����ؼ� ���ؾ��Ѵ�
/// ���������� �ſ� �߿��ϴ�

int T,N,K;
vector <pair<int, int>> v;
int arr[10001];
int used[10001][2] = {0,}; // 1. �����ߴ��� ���ߴ��� , 2.�ϰ��� �������� �ƴ���
long long ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> K;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		ans = 0;
		v.clear();
		for (int y = 0; y <= N; y++)
			for (int x = 0; x < 2; x++)
				used[y][x] = 0;

		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			v.push_back({ a,arr[i] });
		}
		sort(v.begin(), v.end());
		
		for (int i = N-1; i >= 0 && K>0; i--)
		{
			if (used[v[i].second][1] == 1) continue;
			used[v[i].second][1] = 1;
			used[i][0] = 1;
			K--;
		}
		
		for (int i = 0; i < N && K>0; i++)
		{
			if (used[i][0] == 1) continue;
			ans += v[i].first;
			K--;
		}
		cout << "#" << tc << " " << ans << endl;
	}
}