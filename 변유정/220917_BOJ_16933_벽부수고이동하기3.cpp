#include <iostream>
#include <queue>
using namespace std;

/// BFS + a(����ȭ)
/// ���� ���μ��� �̵��ϱ� ���� (�ڵ忡�� �����ϴ� �ƴ�)
/// 
/// ���� �ܰ�
/// 1. ���� ������ 0(��)���� 1(��)����
/// 2. ���������� 0�̸� �̹� ��Ȱų� �ӹ��� ������ �ִ���
/// 3. ���������� 1�̸�
/// 3-1. ���� ������ ������
/// 3-2. ���̸� �̹� �ӹ��� ������ �ִ���
/// 3-3. ���̸� ���� �ִ� ��������
/// 
/// �׿��� ������ ���μ��� �̵��ϱ�� ����!
/// ����ȭ �Ϸ��� �ٸ� ǥ������ �ٲ�� �ҰŰ���

struct Node
{
	// day �� ���� ��(0)���� ��(1)����
	int cnt, wall, y, x, day;
};

int N, M, K;
int map[1000][1000];
int used[1000][1000][10];
int dy[5] = { 1,0,-1,0 };
int dx[5] = { 0,1,0,-1 };
queue <Node> q;

int bfs()
{
	if (N == 1 && M == 1) return 1;
	q.push({ 1,0,0,0,0 });
	used[0][0][0] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (ny == N - 1 && nx == M - 1) return now.cnt + 1;

			// 2�ܰ�
			if (map[ny][nx] == 0 && used[ny][nx][now.wall] < 2)
			{
				used[ny][nx][now.wall]++;
				if (now.day == 0) q.push({ now.cnt+1,now.wall,ny,nx,1 });
				else q.push({ now.cnt+1,now.wall,ny,nx,0 });
			}
			// 3�ܰ� (3-3)
			else if (map[ny][nx] == 1 && now.wall < K)
			{
				// 3-2 �ܰ�
				if (now.day == 1)
				{
					used[now.y][now.x][now.wall]++;
					q.push({ now.cnt + 1,now.wall,now.y,now.x,0 });
				}
				// 3-3�ܰ�
				else if (now.day == 0 && used[ny][nx][now.wall + 1] < 2)
				{
					used[ny][nx][now.wall + 1]++;
					q.push({ now.cnt + 1,now.wall + 1,ny,nx,1 });
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int y = 0; y < N; y++)
	{
		string temp;
		cin >> temp;
		for (int x = 0; x < M; x++)
			map[y][x] = temp[x] - '0';
	}
	cout << bfs();
	return 0;
}

//�ٸ� ����� ����ȭ �ڵ�
//#include <iostream>
//#include <queue>
//using namespace std;
//struct Info
//{
//    int y, x, break_wall, cnt, day;
//};
//queue<Info> q;
//Info start;
//char map[1001][1001];
//bool visited[1001][1001][11];
//int move_x[4] = { 1,0,-1,0 }, move_y[4] = { 0,1,0,-1 }, size_y = 0, size_x = 0, limit_break_wall = 0;
//int use_bfs()
//{
//    Info temp, next;
//    while (!q.empty())
//    {
//        temp = q.front(); q.pop();
//        if (temp.y == size_y && temp.x == size_x)
//            return temp.cnt;
//        bool block = false;
//        for (int d = 0; d < 4; d++)
//        {
//            next.y = temp.y + move_y[d];
//            next.x = temp.x + move_x[d];
//            next.break_wall = temp.break_wall;
//            if (next.y > 0 && next.y <= size_y && next.x > 0 && next.x <= size_x && next.break_wall <= limit_break_wall)
//            {
//                if (map[next.y][next.x] == '0' && !visited[next.y][next.x][temp.break_wall])
//                {
//                    next.cnt = temp.cnt + 1;
//                    next.day = 1 - temp.day;
//                    visited[next.y][next.x][next.break_wall] = true;
//                    q.push(next);
//                }
//                else if (map[next.y][next.x] == '1' && next.break_wall != limit_break_wall && !visited[next.y][next.x][temp.break_wall + 1])
//                {
//                    if (temp.day)
//                    {
//                        next.break_wall += 1;
//                        next.cnt = temp.cnt + 1;
//                        next.day = 1 - temp.day;
//                        visited[next.y][next.x][next.break_wall] = true;
//                        q.push(next);
//                    }
//                    else
//                        block = true;
//                }
//            }
//        }
//        if (block)
//        {
//            next.y = temp.y;
//            next.x = temp.x;
//            next.break_wall = temp.break_wall;
//            next.day = 1 - temp.day;
//            next.cnt = temp.cnt + 1;
//            q.push(next);
//        }
//    }
//    return -1;
//}
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    cin >> size_y >> size_x >> limit_break_wall;
//    for (int i = 1; i <= size_y; i++)
//    {
//        string tmp;
//        cin >> tmp;
//        for (int j = 1; j <= size_x; j++)
//        {
//            map[i][j] = tmp[j - 1];
//        }
//    }
//    start.y = 1; start.x = 1; start.break_wall = 0; start.cnt = 1; start.day = 1;
//    visited[1][1][0] = true;
//    q.push(start);
//    cout << use_bfs();
//}