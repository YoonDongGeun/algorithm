#include <iostream>
#include <queue>
using namespace std;

// ���� + �ùķ��̼�
// ������ ���� ���� �״�� ����
// ���� ����
// 1. dust ť�� ���� ���� �ֱ�
// 2. �� ������ ���� Ȯ�� ��Ű�� (ť�� ���߿� �ݿ� ����)
// 3. ���� û���� �۵� (����, �Ʒ��� �ٸ��� ������ �Լ� ���� ����)
// 4. �ٽ� ť�� ���� ���� �־��ֱ� (1,2,3 �ݺ�)
//
// ���� �� ����ؼ� ��,�Ʒ� ����û���� �۵��ϴ� �Լ� ���ĺ���
// ť ��� �迭 ����ؼ� �����غ���

struct dd
{
	int y, x, size;
};

int R, C, T;
int room[51][51];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
queue <dd> dust;
int clean[2];

void spread()
{
	while (!dust.empty())
	{
		dd temp = dust.front();
		dust.pop();
		int minus = temp.size / 5;
		for (int i = 0; i < 4; i++)
		{
			int ny = temp.y + dy[i];
			int nx = temp.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C || room[ny][nx] == -1) continue;
			room[temp.y][temp.x] -= minus;
			room[ny][nx] += minus;
		}
	}
}

void get_dust()
{
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			if (room[y][x] != -1 && room[y][x] != 0)
				dust.push({ y,x,room[y][x] });
}

void upclean()
{
	int up_y = clean[0];
	room[up_y - 1][0] = 0;
	for (int i = up_y - 2; i >= 0; i--)
		room[i + 1][0] = room[i][0];
	for (int i = 1; i < C; i++)
		room[0][i - 1] = room[0][i];
	for (int i = 1; i <= up_y; i++)
		room[i - 1][C - 1] = room[i][C - 1];
	for (int i = C - 2; i > 0; i--)
		room[up_y][i + 1] = room[up_y][i];
	room[up_y][1] = 0;
}

void downclean()
{
	int down_y = clean[1];
	room[down_y + 1][0] = 0;
	for (int i = down_y + 2; i < R; i++)
		room[i - 1][0] = room[i][0];
	for (int i = 1; i < C; i++)
		room[R - 1][i - 1] = room[R - 1][i];
	for (int i = R - 2; i >= down_y; i--)
		room[i + 1][C - 1] = room[i][C - 1];
	for (int i = C - 2; i > 0; i--)
		room[down_y][i + 1] = room[down_y][i];
	room[down_y][1] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> T;
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
		{
			cin >> room[y][x];
			if (room[y][x] == -1)
			{
				if (clean[0] == 0) clean[0] = y;
				else clean[1] = y;
			}
			else if (room[y][x] != 0)
				dust.push({ y,x,room[y][x] });
		}
	while (T--)
	{
		spread();
		upclean();
		downclean();
		get_dust();
		if (dust.empty())
			break;
	}
	int ans = 0;
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			if (room[y][x] != -1 && room[y][x] != 0)
				ans += room[y][x];
	cout << ans;
}

// �� ���� �ڵ�
// 
// �迭 ��ģ �ڵ�!!! t,p �ε��� �����ư��鼭 �迭 ������ ����
// 
//#include<stdio.h>
//int main() {
//	int R, C, T, A[2][50][50], idx = 0;
//	int air[2];
//	scanf("%d %d %d", &R, &C, &T);
//	for (int i = 0; i < R; ++i)for (int j = 0; j < C; ++j) {
//		scanf("%d", &A[0][i][j]);
//		if (A[0][i][j] < 0)	air[idx++] = i;
//	}
//	int t = 0, p = 1;
//	while (T--) {
//		for (int i = 0; i < R; ++i)for (int j = 0; j < C; ++j)	A[p][i][j] = 0;
//		A[p][air[0]][0] = A[p][air[1]][0] = -1;
//		for (int i = 0; i < R; ++i)for (int j = 0; j < C; ++j) {
//			if (A[t][i][j] > 0) {
//				int k = A[t][i][j], m = k / 5;
//				if (i > 0 && A[t][i - 1][j] >= 0)	A[p][i - 1][j] += m, k -= m;
//				if (j > 0 && A[t][i][j - 1] >= 0)	A[p][i][j - 1] += m, k -= m;
//				if (i < R - 1 && A[t][i + 1][j] >= 0) A[p][i + 1][j] += m, k -= m;
//				if (j < C - 1 && A[t][i][j + 1] >= 0) A[p][i][j + 1] += m, k -= m;
//				A[p][i][j] += k;
//			}
//		}
//		t = p, p ^= 1;
//		for (int i = air[0] - 1; i; --i)	A[t][i][0] = A[t][i - 1][0];
//		for (int i = 1; i < C; ++i)	A[t][0][i - 1] = A[t][0][i];
//		for (int i = 0; i < air[0]; ++i)	A[t][i][C - 1] = A[t][i + 1][C - 1];
//		for (int i = C - 2; i; --i)	A[t][air[0]][i + 1] = A[t][air[0]][i];
//		A[t][air[0]][1] = 0;
//		for (int i = air[1] + 2; i < R; ++i)	A[t][i - 1][0] = A[t][i][0];
//		for (int i = 1; i < C; ++i)	A[t][R - 1][i - 1] = A[t][R - 1][i];
//		for (int i = R - 1; i > air[1]; --i)	A[t][i][C - 1] = A[t][i - 1][C - 1];
//		for (int i = C - 2; i; --i)	A[t][air[1]][i + 1] = A[t][air[1]][i];
//		A[t][air[1]][1] = 0;
//	}
//	int ans = 0;
//	for (int i = 0; i < R; ++i)for (int j = 0; j < C; ++j)	ans += A[t][i][j];
//	printf("%d\n", ans + 2);
//	return 0;
//}