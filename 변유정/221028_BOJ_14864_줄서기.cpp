#include <iostream>
#include <vector>
using namespace std;

// �˰��� �з� : ����, �ֵ� Ȥ
// �ֵ� Ȥ : ����ȭ�� �˰����� �����ϴ� ���� �ƴ϶� �ش� �������� ���� â������ ���̵� ã�Ƽ� ���� �ذ�

// ���� �ڵ� ��ó : https://justicehui.github.io/koi/2019/03/17/BOJ14864/
// ���ڵ� : 100��
// �Ʒ��ڵ� : 7��

// ���ڵ� ���� �ܰ� (���� ���ϰ� ����)
// 1. �켱 �迭�� ���� �ε�����ŭ ���� �ο� (�ε��� 1 - 1, 2 - 2 ...)
// 2. M ��ŭ�� �������� ������ ��, �� ���� �ε��� ++, �� ���� �ε��� --
// 3. �迭 Ȯ�� - 
// 3-1. ���� �迭 ���� �� N�� �Ѱų� 0�����̸� �߸��� ���� �迭
// 3-2. ���� �迭 �� �̹� ���� ī���� ���ڸ� ��������� �߸��� ���� �迭

// �Ʒ��ڵ� ���� �ܰ� (���� ��ȯ)
// 1. �켱 �迭�� ���� �ε�����ŭ ���� �ο�
// 2. M ��ŭ�� �������� ������ ��, ���� ���� �ٲٱ�
// 3. �迭 Ȯ��
// 3-1. ���� �ٲ� ���ڿ� ���� �ʴ� ���Ͱ� ������ �߸��� ���� �迭

vector <int> box;
int N, M;

void check()
{
	bool used[100001] = { 0, };
	for (int i = 1; i <= N; i++)
	{
		if (box[i] > N || box[i] <= 0)
		{
			cout << -1;
			exit(0);
		}
		if (used[box[i]])
		{
			cout << -1;
			exit(0);
		}
		used[box[i]] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	box.resize(N + 1);

	for (int i = 1; i <= N; i++)
		box[i] = i;

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		box[a]++;
		box[b]--;
	}
	check();
	for (int i = 1; i <= N; i++)
		cout << box[i] << ' ';
}

//int N, M, card[100001];
//vector <int> box[100001];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		box[a].push_back(b);
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		card[i] = i;
//		sort(box[i].rbegin(), box[i].rend());
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		int idx = 0;
//		for (int k = N; k>= i ; k--)
//		{
//			if (idx != box[i].size() && box[i][idx] == k)
//			{
//				idx++;
//				if (card[i] < card[k])
//				{
//					int temp = card[i];
//					card[i] = card[k];
//					card[k] = temp;
//				}
//			}
//			else
//			{
//				if (card[i] > card[k])
//				{
//					int temp = card[i];
//					card[i] = card[k];
//					card[k] = temp;
//				}
//			}
//		}
//	}
//	bool flag = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		int idx = 0;
//		for (int k = N; k > i; k--)
//		{
//			if (card[i] > card[k])
//			{
//				if (box[i][idx] == k)
//					idx++;
//				else
//				{
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if (flag == 1) break;
//	}
//
//	if (flag == 0)
//	{
//		for (int i = 1; i <= N; i++)
//			cout << card[i] << " ";
//	}
//	else cout << -1;
//}