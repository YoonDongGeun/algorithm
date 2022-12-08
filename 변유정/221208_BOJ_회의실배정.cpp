#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �˰��� : ����, �׸��� �˰���
// ��� : ȸ�ǰ� ���� ���� ������ ������ ���***
// ���� ȸ�� �ð��� ��ġ�� �׳� �Ѿ��

int N,a,b; // N - ȸ�� ����, a - ȸ�� ���۽ð�, b - ȸ�� ������ �ð�
vector <pair<int, int>> room; // ȸ�� ���ǥ �����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		room.push_back({ b,a }); // ������ �ð� �߽��̱� ������, �Ųٷ� �����ϱ�
	}
	sort(room.begin(), room.end());
	int cnt = 0, now = 0;
	for (int i = 0; i < N; i++)
	{
		if (now <= room[i].second) // ���� ���� �ð��� ���� ȸ�ǽ� ����ں��� �۴�
		{
			cnt++; // �̿� ����
			now = room[i].first; // �ٽ� ����
		}
	}
	cout << cnt;
}