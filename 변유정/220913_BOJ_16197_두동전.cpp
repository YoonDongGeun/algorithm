#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

//BFS + ��Ʈ��ŷ
//�ʹݿ� ������ Ʋ�ȴµ�, ���� ���� ��ġ�� �� ����� �Ѵ�.
// ó�� used_coin�� 1�� ������� ������, ���� ������ �� �����ϰ� Ǯ����Ѵ٤�

struct Coin {    ///���� �ΰ� ��ġ �ѹ��� ť�� �����ϱ�
	int y1, x1, y2, x2;
};

int N, M;
char arr[21][21];
queue <Coin> q;
int used[21][21][21][21] = {0,};
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ans = 1e9;
int yy1 = 0, xx1 = 0, yy2 = 0, xx2 = 0; //���� ��ġ ����

void bfs()
{
	while (!q.empty())
	{
		int y1 = q.front().y1;
		int x1 = q.front().x1;
		int y2 = q.front().y2;
		int x2 = q.front().x2;
		q.pop();
		if (used[y1][x1][y2][x2] > 10) continue; //10���� �Ѿ�� ���ѵǱ� ������ �ǵ��ư���
		for (int i = 0; i < 4; i++)
		{
			int ny1 = y1 + dy[i];
			int nx1 = x1 + dx[i];
			int ny2 = y2 + dy[i];
			int nx2 = x2 + dx[i];
			// ���� 2�� ��� ���� ������ �������� �ǵ�������
			if ((ny1<0 || ny1>=N || nx1 < 0 || nx1 >= M) && (ny2 < 0 || ny2 >= N || nx2 < 0 || nx2 >= M)) continue;
			// �Ѵ� ���� �ȿ� ���� ���
			else if (ny1 >= 0 && ny1 < N && nx1 >=0 && nx1 < M && ny2 >= 0 && ny2 < N && nx2 >= 0 && nx2 < M)
			{
				// 1. ���� �ΰ� ��� ���� ������ �� �������� �ʰ� �ǵ��ư���
				if (arr[ny1][nx1] == '#' && arr[ny2][nx2] == '#') continue;
				// 2. ���� �Ѱ����� ������ ��
				if (arr[ny1][nx1] == '#')
				{
					ny1 = y1;
					nx1 = x1;
				}
				if (arr[ny2][nx2] == '#')
				{
					ny2 = y2;
					nx2 = x2;
				}
				// ���� ����ߴ� �ڸ��� �ǵ��ư���
				if (used[ny1][nx1][ny2][nx2] != 0) continue;
				used[ny1][nx1][ny2][nx2] = used[y1][x1][y2][x2] + 1;
				q.push({ ny1,nx1,ny2,nx2 });
			}
			// ���� 1���� ���� ������ �������� �� ans�� �����صα�
			else ans = min(ans,used[y1][x1][y2][x2]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < M; x++)
		{
			arr[y][x] = str[x];
			if (arr[y][x] == 'o')
			{
				if (yy1 == 0)
				{
					yy1 = y;
					xx1 = x;
				}
				else
				{
					yy2 = y;
					xx2 = x;
				}
			}
		}
	}
	// �ΰ� ���� ó�� ��ġ ť�� �ֱ�
	q.push({ yy1,xx1,yy2,xx2 });
	used[yy1][xx1][yy2][xx2] = 1;
	bfs();
	//ans���� �״�ΰų� Ȥ�� 10�� �Ѿ������ -1 ���
	if (ans > 10) cout << -1;
	else cout << ans;
	return 0;
}

//DFS�� ������ �ڵ�

//#define pii pair<int, int>
//int N, M, result = 1e9 + 7;
//int Map[21][21];    // 2 : ���� ��ġ   0 : �� ��ġ   1 : ��ĭ
//vector< pii > startP;
//int dr[4] = { 0, 0, 1, -1 }, dc[4] = { 1, -1, 0, 0 };
//
//void input() {
//	// Map���� ����� ���� -1�� ����
//	memset(Map, -1, sizeof(Map));
//
//	cin >> N >> M;
//	string str;
//	for (int i = 1; i <= N; i++) {
//		cin >> str;
//		for (int j = 0; j < M; j++) {
//			if (str[j] == 'o') {
//				Map[i][j + 1] = 2;
//				startP.push_back({ i, j + 1 });
//			}
//			else if (str[j] == '#') Map[i][j + 1] = 0;
//			else Map[i][j + 1] = 1;
//		}
//	}
//}
//
//bool isOut(const pii& A) {
//	if (A.first < 1 || A.first > N || A.second < 1 || A.second > M) return true;
//	return false;
//}
//
//void dfs(pii A, pii B, int cnt) {
//	// ���� result���� cnt�� ũ�ٸ� ���̻��� Ž���� ���ʿ�
//	if (result < cnt) return;
//
//	// cnt �� 10���� Ŀ���� result�� ����
//	if (cnt > 10) {
//		result = min(result, cnt);
//		return;
//	}
//
//	// �� �� ���������� �ǵ��ư�
//	if (isOut(A) && isOut(B)) return;
//	// �ϳ��� ���������� result�� �ּ� cnt������ ��ü
//	else if ((isOut(A) && !isOut(B)) || (!isOut(A) && isOut(B))) {
//		result = min(result, cnt);
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		pii An = { A.first + dr[i], A.second + dc[i] };
//		pii Bn = { B.first + dr[i], B.second + dc[i] };
//		if (!Map[An.first][An.second]) An = A;
//		if (!Map[Bn.first][Bn.second]) Bn = B;
//
//		dfs(An, Bn, cnt + 1);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	input();
//	dfs(startP[0], startP[1], 0);
//
//	if (result > 10) cout << -1;
//	else cout << result;
//
//	return 0;
//}

// ��ó : https://hyeo-noo.tistory.com/126