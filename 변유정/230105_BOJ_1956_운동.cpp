#include <iostream>
#include <queue>
using namespace std;

// �˰��� - �÷��̵� ����
// ȿ���� ���� �ڵ�

int V, E, a, b, c;
// V : ���� ����, E : ���� ���� , abc : a���������� b�������� ���� �Ÿ� c
int vill[402][402];
// ���� - ���� ���� �Ÿ� ����
int ans = 1e9;
// ���

int find_road(int start)
{
	// �ǵ��� ���� �� �����ϴ� �Լ�
	int ans1 = 1e9;
	queue <pair<int, int>> q;
	for (int i = 1; i <= V; i++)
	{
		if (vill[start][i] == 1e9) continue;
		q.push({ i, vill[start][i] });
	}
	while (!q.empty())
	{
		int tmp = q.front().first;
		int leng = q.front().second;
		q.pop();
		if (tmp == start)
		{
			if (ans1 > leng) ans1 = leng;
			continue;
		}
		for (int i = 1; i <= V; i++)
		{
			if (vill[tmp][i] + leng > ans1) continue;
			if (vill[start][i] <= vill[tmp][i] + leng) continue;
			vill[start][i] = vill[tmp][i] + leng;
			q.push({ i, vill[tmp][i] + leng });
		}
	}
	return ans1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	for (int y = 1; y <= V; y++)
		for (int x = 1; x <= V; x++)
			vill[y][x] = 1e9;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		vill[a][b] = c;
	}

	for (int i = 1; i <= V; i++)
	{
		// �����ϴ� ������ �ּҰŸ� ã��
		int temp = find_road(i);
		if (temp < ans) ans = temp;
	}

	if (ans == 1e9) cout << -1;
	else cout << ans;
	return 0;
}

// �÷��̵� ���� �ڵ�
// 3�� for�� ������ �������ִ°� �߿�!

//int main() {
//
//	int v, e, a, b, c, minimum = INF;
//	cin >> v >> e;
//	int dist[v + 1][v + 1];
//	for (int i = 0; i <= v; i++) {
//		fill(dist[i], dist[i] + v + 1, INF);
//	}
//	for (int i = 0; i < e; i++) {
//		cin >> a >> b >> c;
//		dist[a][b] = c;
//	}
//	for (int i = 1; i <= v; i++) {
//		for (int j = 1; j <= v; j++) {
//			for (int k = 1; k <= v; k++) {
//				if (dist[j][i] + dist[i][k] < dist[j][k]) {
//					dist[j][k] = dist[j][i] + dist[i][k];
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= v; i++) {
//		if (dist[i][i] < minimum) {
//			minimum = dist[i][i];
//		}
//	}
//	if (minimum == INF) {
//		cout << -1;
//		return 0;
//	}
//	cout << minimum;
//}