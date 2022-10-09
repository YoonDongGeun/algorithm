#include <iostream>
#include <vector>
using namespace std;

// ���� ���� �� ������
// 1. 3�ƿ� ������ ��, ���̽��� �ִ� Ÿ�ڵ� ���ֱ�
// 2. �̴� ���� ��, Ÿ�� ���� ��Ű��
// 3. 1�� ���� - 4�� Ÿ�� ����

int N, inning[50][9];
// 0 - Ȩ(���̽�), 1 - 1��, 2 - 2��, 3 - 3��
bool base[4] = { 0, };
// Ÿ�� ����
vector <int> hitter;
bool used[9] = { 0, };
int result = -1;

void hit()
{
	int out = 0;
	int now = 0;
	int inn = 0;
	int temp = 0;
	// �̴� ä�ﶧ���� ��� ġ��
	while (inn != N)
	{
		if (now == 9) now = 0;
		if (inning[inn][hitter[now]] == 0)
		{
			out += 1;
			now += 1;
			if (out == 3)
			{
				for (int i = 0; i < 4; i++)
					base[i] = 0;
				out = 0;
				inn += 1;
			}
		}
		else
		{
			int k = inning[inn][hitter[now]];
			base[0] = 1;
			for (int i = 3; i >= 0; i--)
			{
				if (base[i] == 0) continue;
				base[i] = 0;
				if (i + k >= 4) temp++;
				else base[i + k] = 1;
			}
			now += 1;
		}
	}
	result = max(result, temp);
}

void order(int cnt)
{
	// 4�� Ÿ��  - 1������ ���س���
	if (cnt == 3)
	{
		hitter.push_back(0);
		order(cnt + 1);
		hitter.pop_back();
	}
	if (cnt == 9)
	{
		hit();
		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (used[i]) continue;
		used[i] = 1;
		hitter.push_back(i);
		order(cnt + 1);
		used[i] = 0;
		hitter.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int k = 0; k < 9; k++)
			cin >> inning[i][k];
	used[0] = 1;
	order(0);
	cout << result;
}