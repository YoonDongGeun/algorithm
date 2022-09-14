#include <iostream>
using namespace std;
// 'SWEA Ȱ�ַ� �Ǽ�'�� ���� ����

//  �ùķ��̼� + ����
//  �����Ҷ� ��ü������ �ܰ� �����ϰ� ¥���Ѵ�
//  A������ ���������� �ַ� ������ ������ �̷� ������ ���� Ǯ������Ѵ�

// ���� �ܰ�
// 1. ������ ���� �����Ҷ�
// 2. �������� ������ �����ʹ������� (�� > ��) �ݺ������� ���� Ȯ��
// 3. �����ʹ��� ���� ������ ���ʹ������� (�� > ��) �ݺ������� ���� Ȯ��
// 4. ���� ������ �信 1 �����ֱ�

// 2-1. �������� 1�� �����ؾ���. 1 �ʰ��� ���� flag Ȱ���ؼ� ���߰� ���� �ٷ� �Ѿ��

int N, L;
int road[101][101];
int used_y[101][101] = {0,};
int used_x[101][101] = {0,};
int ans = 0;

// 1. �������� ���� ��
int same_y(int y)
{
	for (int i = 0; i < N-1; i++)
		if (road[y][i] != road[y][i + 1]) return 0;
	return 1;
}

int same_x(int x)
{
	for (int i = 0; i < N - 1; i++)
		if (road[i][x] != road[i + 1][x]) return 0;
	return 1;
}

// 2. �������� ���� ��
int diff_y(int y, int x, int k)
{
	for (int i = 1; i <= L; i++)
	{
		int a = x + i * k;
		if (a < 0 || a >= N) return 0; // ��������ų�
		if ((road[y][x] - road[y][a]) != 1) return 0; // �������� 1 �ʰ��̰ų�
		if (used_y[y][a] == 1) return 0; // �̹� ���� ���θ� 0
		
		used_y[y][a] = 1; // ���� ���ǥ��
	}
	return 1;
}

int diff_x(int y, int x, int k)
{
	for (int i = 1; i <= L; i++)
	{
		int a = y + i * k;
		if (a < 0 || a >= N) return 0; 
		if ((road[y][x] - road[a][x]) != 1) return 0;
		if (used_x[a][x] == 1) return 0;
		used_x[a][x] = 1;
	}
	return 1;
}

void fly()
{
	for (int y = 0; y < N; y++)
	{
		int flag = 2;
		if (same_y(y) == 1) ans += 1; // 1. �������� ������ +
		else // 2. �������� ������
		{
			for (int i = 0; i < N-1; i++) // ������(������ ����)���� ���� Ž��
			{
				if (road[y][i] == road[y][i + 1] + 1)
				{
					flag = diff_y(y, i, 1); // ���������� L��ŭ ���̰� ��ӵ��� ������ flag = 0
					if (flag == 0) break; // flag���� �������� ���� �߻��ϸ� ����
				}
				else if (abs(road[y][i] - road[y][i + 1]) > 1)
				{
					flag = 0; break; // ������ �׳� 2 �̻� ���̳��� ����
				}
			}
			if (flag == 0) continue; // flag�� ���� �߻��� �����ϰ� ��� ����
			for (int i = N - 1; i >= 1; i--) // ���� ������ ������ (���� ����)���� ���� Ž��
			{
				if ((road[y][i] - road[y][i - 1]) == 1)
				{
					flag = diff_y(y, i, -1);
					if (flag == 0) break;
				}
				else if (abs(road[y][i] - road[y][i - 1]) > 1)
				{
					flag = 0; break;
				}
			}
		}
		if (flag == 1) ans++;
	}

	for (int x = 0; x < N; x++)
	{
		int flag = 2;
		if (same_x(x) == 1) ans += 1;
		else
		{
			for (int i = 0; i < N -1; i++)
			{
				if (road[i][x] - road[i + 1][x] == 1)
				{
					flag = diff_x(i, x, 1);
					if (flag == 0) break;
				}
				else if (abs(road[i][x] - road[i + 1][x]) > 1)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 0) continue;
			for (int i = N - 1; i >= 1; i--)
			{
				if ((road[i][x] - road[i - 1][x]) == 1)
				{
					flag = diff_x(i, x, -1);
					if (flag == 0) break;
				}
				else if (abs(road[i][x] - road[i - 1][x]) > 1)
				{
					flag = 0; break;
				}
			}
		}
		if (flag == 1) ans++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> road[y][x];
	fly();
	cout << ans;
	return 0;
}


//// ���ڵ� (���ǰ�)
// 
// ���� ������ �پ��� ������� ����
// ������ ���ʿ��� �ڵ�� ���̷��� ������ �ؾ���
// 
//#include <cstdio>
//int main() {
//	int n, l, ans = 0, i, j, c;
//	short a[200][100];
//	scanf("%d %d", &n, &l);
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			scanf("%hd", &a[i][j]);
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			a[i + n][j] = a[j][i];
//	for (i = 0; i < n * 2; i++) {
//		c = 1;
//		for (j = 0; j < n - 1; j++) {
//			if (a[i][j] == a[i][j + 1]) c++;
//			else if (a[i][j] + 1 == a[i][j + 1] && c >= l) c = 1;
//			else if (a[i][j] - 1 == a[i][j + 1] && c >= 0) c = -l + 1;
//			else break;
//		}
//		if (j == n - 1 && c >= 0) ans++;
//	}
//	printf("%d", ans);
//	return 0;
//}
