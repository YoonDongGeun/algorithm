#include <iostream>
using namespace std;

// ��Ʈ����ŷ
// ����
// 1. K(���Ǵ� ���ĺ�) ������ ������
// 1-1. K �� 5���� ������ ���� ������ �ܾ� ����
// 1-2. K�� 26�̸� ��� ���ĺ� ��� ���� (����� �ܾ� ��� ��������)

// 2. ���ĺ� ��� �迭 �����
// 2-1. antic �� �⺻ ����̹Ƿ� �̸� ǥ��
// 2-2. ������ ���ĺ��� ������ ���缭 �����ϱ�

// 3. ������ ���缭 ������ ���ĺ� �迭�� ������ �� �ִ� �ܾ� �ִ� ���� ã��
// 3-1. ���� �ܾ� �� ���ĺ��� ���õ��� �ʾҴٸ� �� �ܾ�� ���� �Ұ���

// 4. �ܾ� ���� �������� �ǵ����� 2���� �ݺ�

int N, K;
string words[51];
bool used[26];
int ans = -1;

void dfs(int now, int cnt)
{
	if (cnt + 5 == K)
	{
		int teaching = 0;
		for (int idx = 0; idx < N; idx++)
		{
			bool flag = 0;
			// ���� �����ֱ� (�ܾ� ��,�� 4���ڴ� ������ �����ϴ�)
			for (int k = 4; k < words[idx].size()-4; k++)
			{
				char tt = words[idx][k];
				if (!used[tt - 'a'])
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
				teaching++;
		}
		if (ans < teaching)
			ans = teaching;
		return;
	}

	for (int i = now; i < 26; i++)
	{
		if (used[i])
			continue;
		used[i] = 1;
		dfs(i + 1, cnt + 1);
		used[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		words[i] = temp;
	}

	if (K < 5)
		cout << 0;
	else if (K == 26)
		cout << N;
	else
	{
		string ess = "antic";
		for (int i = 0; i < 5; i++)
			used[ess[i] - 'a'] = 1;
		dfs(0, 0);
		cout << ans;
	}
}