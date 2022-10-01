#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// �迭 ����
// land - ���� �α� ��
// combine - ���� ���漱�� ���� ����
// change - ���漱 ���� ������� �α� ���

// ���� ����
// 1. ť�� ����ؼ� ���� ���漱�� ���� ������ ������� ã��
// 2. ���� �ݺ����ָ鼭 �� ������ �α��� ���� 
// 3. ���� �����ص� ���� ����  ���� ������ ������� �����Ƿ� time(�ݺ��� �ϼ�) ��ȯ
//

int N, L, R, land[51][51];
int combine[51][51], change[2502];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int comb(int y, int x, int num)
{
	queue <pair<int, int>> q;
	q.push({ y,x });
	combine[y][x] = num;
	int cnt = 1;
	int smm = land[y][x];
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (combine[ny][nx]) continue;
			if (abs(land[ny][nx] - land[yy][xx]) < L || abs(land[ny][nx] - land[yy][xx]) > R) continue;
			smm += land[ny][nx];
			cnt++;
			combine[ny][nx] = num;
			q.push({ ny,nx });
		}
	}
	return smm / cnt;
}

int open()
{
	int time = 0;
	while (time <= 2000)
	{
		int cnt = 1;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (combine[y][x])
					land[y][x] = change[combine[y][x]];
				else
				{
					change[cnt] = comb(y, x, cnt);
					land[y][x] = change[combine[y][x]];
					cnt++;
				}
			}
		}
		if (cnt > N * N) break;
		time++;
		memset(combine, 0, sizeof(combine));
		memset(change, 0, sizeof(change));
	}
	return time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R;
	for (int y = 0 ;y<N;y++)
		for (int x = 0; x < N; x++)
			cin >> land[y][x];
	cout << open();
}