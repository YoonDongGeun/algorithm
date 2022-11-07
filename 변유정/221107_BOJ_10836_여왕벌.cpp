#include <iostream>
using namespace std;

// �˰��� : ����, �ùķ��̼�

// �ð� ���̴� ��� : �ݺ��ϴ� ������ ã�� �迭 ũ�⸦ �ٿ��� �Ѵ�
// �迭 0���� �����ϰ� �������� ù ���� �ݺ��ϰ� �ֱ� ������ ���� ��� �迭�� ���� ������ �ʿ䰡 ����.

// �� : 100�� / �Ʒ� : 83�� (��� �迭 �����ϰ� ���)
int M, N, larva[1401] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int k = 0;
		while (a--)
		{
			k++;
		}
		while (b--)
		{
			larva[k++]++;
		}
		while (c--)
		{
			larva[k++] += 2;
		}
	}
	for (int s = M - 1; s >= 0; s--)
	{
		cout << larva[s] + 1 << ' ';
		for (int p = M; p < 2 * M - 1; p++)
			cout << larva[p] + 1 << ' ';
		cout << '\n';
	}
}

//int M, N, larva[701][701] = { 0, };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> M >> N;
//	for (int y = 0; y < M; y++)
//		for (int x = 0; x < M; x++)
//			larva[y][x] = 1;
//	for (int i = 0; i < N; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		int y = M - 1;
//		int x = 0;
//		while (a--)
//		{
//			if (y == 0) x++;
//			else y--;
//		}
//		while (b--)
//		{
//			larva[y][x] += 1;
//			if (y == 0) x++;
//			else y--;
//		}
//		while (c--)
//		{
//			larva[y][x] += 2;
//			if (y == 0) x++;
//			else y--;
//		}
//	}
//	for (int p = 0; p < M; p++)
//	{
//		cout << larva[p][0] << ' ';
//		for (int t = 1; t < M; t++)
//			cout << larva[0][t] << ' ';
//		cout << '\n';
//	}
//}