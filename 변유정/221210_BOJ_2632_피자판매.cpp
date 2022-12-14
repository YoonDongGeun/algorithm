#include <iostream>
using namespace std;

// �˰��� : ������, �̺�Ž��
// ���� ��� : ������ ����� ���� �̸� �� ���ϰ� Ǯ����
// �Ʒ� ��� : A�� �켱 ���س���, B�� ������ ���ϸ鼭 ������ (�� �������)

int custom, A, B,pizzaA[1001], pizzaB[1001];
// custom : �� ���ϴ� ���� ������
// A : A���� ���� ����, B: B���� ���� ����
// pizzaA : A���� ���� �� ũ�� , pizzaB : B���� ���� �� ũ��
int pieceA[2000001] = { 0, }; // ���� ���� ���� ũ�� �� ����
int pieceB[2000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> custom;
	cin >> A >> B;
	for (int i = 0; i < A; i++)
		cin >> pizzaA[i];
	for (int i = 0; i < B; i++)
		cin >> pizzaB[i];
	
	// A���� ���� ���� : ���� ���� ��� ������ �ٸ��� ���ֱ�
	// �̾��� �־�� �ϱ� ������ ������� �ϳ��� �����ֱ�
	for (int i = 0; i < A; i++)
	{
		int temp = pizzaA[i];
		pieceA[temp]++;
		for (int j = 1; j < A-1; j++)
		{
			temp += pizzaA[(i + j) % A];
			pieceA[temp]++;
		}
		if (i == 0) // ��ü A���� ���� ũ�� ��
		{
			temp += pizzaA[A - 1];
			pieceA[temp]++;
		}
	}
	// B���� ���� ����
	for (int i = 0; i < B; i++)
	{
		int temp = pizzaB[i];
		pieceB[temp]++;
		for (int j = 1; j < B-1; j++)
		{
			temp += pizzaB[(i + j) % B];
			pieceB[temp]++;
		}
		if (i == 0)
		{
			temp += pizzaB[B-1];
			pieceB[temp]++;
		}
	}
	int cnt = 0;
	cnt += pieceA[custom] + pieceB[custom]; 
	// A���� , B���� ���տ��� custom ũ�Ⱑ �ִ� �� ���� �����ֱ�
	for (int i = 1; i < custom; i++)
		cnt += (pieceA[i] * pieceB[custom - i]);
		// ���ճ��� ���� �� �ִ� ����� �� �����ֱ�
	cout << cnt;
}

//int x[2001], y[2001];
//int s[2000001];
//int main()
//{
//	int n, a, b, i, j, cnt = 0, sum;
//	scanf("%d%d%d", &n, &a, &b);
//	for (i = 0; i < a; i++)
//		scanf("%d", &x[i]);
//	for (i = a; i < a * 2; i++)
//		x[i] = x[i - a];
//	for (i = 0; i < b; i++)
//		scanf("%d", &y[i]);
//	for (i = b; i < b * 2; i++)
//		y[i] = y[i - b];
//
//	for (i = 0; i < a; i++)
//	{
//		sum = 0;
//		for (j = i; j < i + a - 1; j++)
//		{
//			sum += x[j];
//			s[sum]++;
//		}
//	}
//	sum = 0;
//	for (i = 0; i < a; i++)
//		sum += x[i];
//	s[sum]++;
//	for (i = 0; i < b; i++)
//	{
//		sum = 0;
//		for (j = i; j < i + b - 1; j++)
//		{
//			sum += y[j];
//			if (sum <= n)
//				cnt += s[n - sum];
//			if (sum == n)
//				cnt++;
//		}
//	}
//	sum = 0;
//	for (i = 0; i < b; i++)
//		sum += y[i];
//	if (sum <= n)
//		cnt += s[n - sum];
//	if (sum == n)
//		cnt++;
//	printf("%d", cnt + s[n]);
//}