#include <iostream>
#include <cstdlib>
using namespace std;
int cnt = 0;
int N, S;
int *n = new int[15]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int *STACK = new int[15]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
/*int n[arraymax] = { 0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 };
int STACK[arraymax] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};*/
int* k = STACK;
int* t = n;

void search()
{
	k++;
	S = 1;
	int W = k - STACK;

	if (W == N)
	{
		cnt++;
		k--;
		return;
	}
	else
	{
		for (int nx = 0; nx < N; nx++)
		{
			t = n + nx; /*�˻��� x�� 0~ nx*/
			S = 1;
			if (*t == 1)	/*���� �̹� x���� ��������� �Ѿ��*/
			{
				continue;
			}

			for (int j = 0; j < W; j++) /*���ÿ� ��� x���� �˻�*/
			{
				if (abs(nx - STACK[j]) == abs(W - j)) /* (���ȵ� �˻��� x�� - ���ÿ� ���[j�ε���] x��) == (y��ǥ - ������ ����� y��ǥ) */
				{
					S = 0;
					break;
				}
			}

			if (S == 1)
			{
				*t = 1;
				*k = nx;
				search();
				t = n + nx;
				*t = 0;
			}
		}
	}
	k--;
	return;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		*STACK = i;
		*(n + i) = 1;
		search();
		*(n + i) = 0;
	}

	cout << cnt << "\n";
	
	delete[] n;
	delete[] STACK;
	return 0;
}