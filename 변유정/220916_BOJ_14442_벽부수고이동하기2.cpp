#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/// 
/// ���μ��� �̵��ϱ� ���빮��
/// �����ϴ� ���� �������� �ð��ʰ����� �߻�
/// 0. �迭������ ���°�����
/// 1. ���μ��� �̵��ϱ�� �ܰ� ����
/// 2. �ð��ʰ� ���̱� ���� �����
/// (1) string���� �޾Ƽ� �����ߴٰ� ���ڷ� �ٲ� (string �迭 Ž��)
/// (2) used bool ���� + cnt ����
/// (3) �迭 ���� ���� (�̰� ���� �߿�)
/// 

struct broke
{
	int y, x;
	int wall;
	int cnt;
};

int N, M, K;

// 0�ܰ�
int map[1000][1000];
bool used[1000][1000][10] = { 0, };
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
queue <broke> now;

void bfs()
{
	while (!now.empty())
	{
		int y = now.front().y;
		int x = now.front().x;
		int wall_ = now.front().wall;
		int cnt = now.front().cnt;
		now.pop();
		if (y == N - 1 && x == M - 1)
		{
			cout << cnt;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (used[ny][nx][wall_] == 0)
			{
				if (map[ny][nx] == 1)
				{
					if (wall_ < K)
					{
						now.push({ ny,nx,wall_ + 1, cnt + 1 });
						used[ny][nx][wall_ + 1] = 1;
					}
				}

				else if (map[ny][nx] == 0)
				{
						now.push({ ny,nx,wall_, cnt + 1 });
						used[ny][nx][wall_] = 1;
				}
			}
		}
	}
	cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	string temp;
	for (int y = 0; y < N; y++)
	{
		cin >> temp;
		for (int x = 0; x < M; x++)
			map[y][x] = temp[x] - '0';
	}
	now.push({ 0,0,0,1 });
	used[0][0][0] = 1;
	bfs() ;
	return 0;
}

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int R, C;
//int K;
//char map[1001][1002];
//int solve;
//bool chk[1001][1001][11];
//
//struct STATUS {
//	int r, c;
//	int k;
//	int cnt;
//};
//
//queue<STATUS>q;
//
//void Input_Data() {
//	//�ʱ�ȭ
//	solve = 0x7fffffff;
//
//	cin >> R >> C >> K;
//	for (int r = 1; r <= R; r++) {
//		cin >> &map[r][1];
//	}
//}
//
//void BFS() {
//	int dr[] = { 0,0,0,1,-1 };
//	int dc[] = { 0,1,-1,0,0 };
//	//�ʱ� ���� ����
//	q.push({ 1,1,K,1 });
//	chk[1][1][K] = 1;
//
//	if (R == 1 && C == 1) {
//		solve = 1;
//		return;
//	}
//
//	// ���� ���� queue;
//	while (!q.empty()) {
//		STATUS data = q.front(); q.pop();
//
//		//���� ���� ����
//		for (int dir = 1; dir <= 4; dir++) {
//			STATUS ndata;
//			ndata.r = data.r + dr[dir];
//			ndata.c = data.c + dc[dir];
//			ndata.k = data.k;
//			ndata.cnt = data.cnt + 1;
//
//			//��ǥ ��ȿ�� Ȯ��
//			if (1 > ndata.r || ndata.r > R || 1 > ndata.c || ndata.c > C) continue;
//			if (map[ndata.r][ndata.c] == '1') {
//				if (ndata.k == 0) continue;
//				ndata.k--;
//			}
//			if (chk[ndata.r][ndata.c][ndata.k] == 1) continue;
//			if (ndata.r == R && ndata.c == C) {
//				solve = ndata.cnt;
//				return;
//			}
//
//			q.push(ndata);
//			chk[ndata.r][ndata.c][ndata.k] = 1;
//		}
//	}
//	solve = -1;
//	return;
//}
//
//int main(void)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	Input_Data();
//	BFS();
//	cout << solve << '\n';
//
//	return 0;
//}