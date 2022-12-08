#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// �˰��� : ����, �׸��� �˰���, �켱���� ť
// �ּ� ���ǽ� ����ϱ� ����
// 1. room (���ǽ�) �����صα� (���۽ð� ������)
// 2. master �켱����ť�� ��¥ ���ǽ� ���ǥ �����ϱ�

int N,a,b; 
vector <pair<int, int>> room; // ���ǽ� �̿� �ð�ǥ
priority_queue<int, vector<int>, greater<int>> master; // �̿� ���ǽ� �����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		room.push_back({ a,b });
	}
	sort(room.begin(), room.end());
	master.push(room[0].second); // ù���� ���ǽ��� �켱 �־�α�
	for (int i = 1; i < N; i++)
	{
		if (master.top() <= room[i].first) master.pop();
		// master �켱���� ť�� ���缭 ���� ��,
		// ���� �ð�ǥ �ð��� ���ؼ� pop ���� ����
		// ��ó�� �ð�ǥ �������� ���ǽ� ��� �����ϸ� pop�ϰ� ���� �ֱ�
		// �ƴϸ� �� ���ǽ��� ����ϴϱ�, �׳� ���� master�� �ֱ�
		master.push(room[i].second);
	}
	cout << master.size();
}

// �ؿ��� vector�θ� ���� (�ð��ʰ���)

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int N, a, b;
//vector <pair<int, int>> room;
//vector <int> master;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a >> b;
//		room.push_back({ a,b });
//	}
//	sort(room.begin(), room.end());
//	master.push_back(room[0].second);
//	for (int i = 1; i < N; i++)
//	{
//		sort(master.begin(), master.end());
//		if (master[0] <= room[i].first) master[0] = room[i].second;
//		else master.push_back(room[i].second);
//	}
//	cout << master.size();
//}