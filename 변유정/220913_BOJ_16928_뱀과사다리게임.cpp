#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/// ���� : bfs�� ���, �ݺ��� �ȿ��� �����ִ� ��찡 ������
/// ���� ������ �ȹٷ� ������� (�ȱ׷� out of bounds)
/// �׸��� ������ �ٸ��� ����� (next �κ�)

int N, M;
int used[101] = { 0, };
vector <pair<int, int>> ladder;
vector <pair<int, int>> snake;
queue <int> now;

void bfs()
{
	while (!now.empty())
	{
		int n = now.front();
		now.pop();
		if (n == 100) break;
		for (int i = 1; i <= 6; i++)
		{
			int next = n + i;
			// 100�� �Ѿ�� �ʰ� next ���� ���� ���ֱ�
			if (next > 100) continue;
			// ���� ������ �ʰ� �׳� ���� ���� : 
			// ���� ����ؼ� �ܰŸ� ���� �� �ִٰ� �Ǵ�
			for (int k = 0; k < M; k++)
				if (snake[k].first == next) next = snake[k].second;
			for (int k = 0; k < N; k++)
				if (ladder[k].first == next) next = ladder[k].second;
			
			// ��ٸ�, �쿡�� next �ٲ�� ������ �̶� next Ȯ���������
			if (used[next] != 0) continue;
			used[next] = used[n] + 1;
			now.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder.push_back({ a,b });
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		snake.push_back({ a,b });
	}
	used[1] = 1;
	now.push(1);
	bfs();
	// 1�� ���� ���¿��� �����߱� ������ 1 �ٽ� ���ֱ�
	cout << used[100]-1;
	return 0;
}

/// �׳� ��ٸ��� ���� ��ġ�� ������ ª�� �ڵ� �ɵ�
// ��ģ �ڵ�

//int los[101];
//int d[101];
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; ++i)
//	{
//		int n1, n2;
//		cin >> n1 >> n2;
//		los[n1] = n2;
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		int n1, n2;
//		cin >> n1 >> n2;
//		los[n1] = n2;
//	}
//
//	queue<int> q;
//	memset(d, -1, sizeof(d));
//	q.push(1);
//	d[1] = 0;
//	while (!q.empty())
//	{
//		int x = q.front();
//		q.pop();
//		for (int i = 1; i <= 6; ++i)
//		{
//			int nx = x + i;
//			if (nx > 100) continue;
//
//			// ladder or snake��� �̵��ؾ� �Ѵ�.
//			if (los[nx] != 0) {
//				nx = los[nx];
//			}
//			if (d[nx] == -1) {
//				d[nx] = d[x] + 1;
//				q.push(nx);
//			}
//		}
//	}
//	cout << d[100] << "\n";
//	return 0;
//}
// ��ó : https://100100e.tistory.com/194