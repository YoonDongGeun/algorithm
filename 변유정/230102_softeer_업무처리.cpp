#include<iostream>
#include <queue>
using namespace std;

int H, K, R, S = 1; // H: ������ Ʈ���� ����, K: ���� ����, R: ��¥;
queue <int> q[2048]; // ť Ʈ�� (���� ���� - �μ����� ���� Ʈ��)
int tt = 1; // tt : ���� �ð�, ans: ��(���� ��ȣ�� ��)
long long ans = 0;

void work()
{
	while (tt < R)
	{

		for (int i = 1; i < S; i++)
		{
			if (q[i * 2 + tt % 2].empty()) continue;
			// �߰��� �ذ� : tt%2
			q[i].push(q[i * 2 + tt % 2].front());
			q[i * 2 + tt % 2].pop();
		}
		tt++;
	}
	while (!q[1].empty()) // �μ��� R�� ���� ����� ����
	{
		ans += q[1].front();
		q[1].pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> H >> K >> R;
	for (int i = 0; i < H; i++) // ���̿� ���� ���� ���� �� (S)
		S *= 2;
	int a;
	for (int i = S; i < 2 * S; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> a; // ���� ���� i �� ����j�� ��ȣ
			q[i].push(a);
		}
	}
	work();
	cout << ans;
}

// ���� �ڵ�
//
//#include<iostream>
//#include <queue>
//using namespace std;
//
//int H, K, R, S = 1; // H: ������ Ʈ���� ����, K: ���� ����, R: ��¥;
//queue <int> q[2048]; // ť Ʈ�� (���� ���� - �μ����� ���� Ʈ��)
//int tt = 1, ans = 0; // tt : ���� �ð�, ans: ��(���� ��ȣ�� ��)
//
//void work()
//{
//	while (tt < R)
//	{
//		for (int i = 1; i < S; i++)
//		{
//			if (q[i * 2].empty()) continue;
//			if (tt % 2)
//			{
//				q[i].push(q[i * 2 + 1].front());
//				q[i * 2 + 1].pop();
//			}
//			else
//			{
//				q[i].push(q[i * 2].front());
//				q[i * 2].pop();
//			}
//		}
//		tt++;
//	}
//	while (!q[1].empty()) // �μ��� R�� ���� ����� ����
//	{
//		ans += q[1].front();
//		q[1].pop();
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> H >> K >> R;
//	for (int i = 0; i < H; i++) // ���̿� ���� ���� ���� �� (S)
//		S *= 2;
//	int a;
//	for (int i = S; i < 2 * S; i++)
//	{
//		for (int j = 0; j < K; j++)
//		{
//			cin >> a; // ���� ���� i �� ����j�� ��ȣ
//			q[i].push(a);
//		}
//	}
//	work();
//	cout << ans;
//}