#include <iostream>
#include <vector>
using namespace std;

// �칰 �� ������
// �˰��� : ����

int N, M, A, B, gym[100001] = {0,};
vector <int> ff[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> gym[i];

	// ���ͷ� �������ֱ�
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		ff[A].push_back(B);
		ff[B].push_back(A);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		ans++;
		for (int j = 0; j < ff[i].size(); j++)
		{
			// ���� �ڱ�� ģ�� ��� �� ���԰� ���ų� ũ�� �칰�� �������� �ƴϴ�!
			if (gym[ff[i][j]] >= gym[i])
			{
				ans--; break;
			}
		}
	}
	cout << ans;
}