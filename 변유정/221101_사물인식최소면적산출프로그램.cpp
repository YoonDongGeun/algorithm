#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �˰��� ���� : dfs / ���Ʈ����
// �� : dfs(O) , �Ʒ� : ����Ž�� (X)
// �� ���� ����
// - ���� �� ������� �ִ� �ּڰ� ��ǥ�� �����ϱ�
// - �� ������ �� �������� ���� �� �� �ּڰ� ����

// �Ʒ� ���� ����
// - ��ǥ ��ü ���鼭 �ΰ��� ¦��� �ݺ��� ����
// - �� �迭 ��ǥ ���鼭 ���ϸ� Ȯ��
// - ��� �� ��������� ���� �ּڰ� ����

int N, K, area = 1e9;
vector <pair<int, int>> color[21];

void point(int cnt, int miny, int minx, int maxy, int maxx)
{
	if (cnt == K + 1)
	{
		int temp = (maxy - miny) * (maxx - minx);
		area = min(temp, area);
		return;
	}

	for (int i = 0; i < color[cnt].size(); i++)
	{
		int ny = color[cnt][i].first;
		int nx = color[cnt][i].second;
		int minyy, minxx, maxyy, maxxx;
		minyy = min(miny, ny);
		minxx = min(minx, nx);
		maxyy = max(maxy, ny);
		maxxx = max(maxx, nx);
		int temp = (maxyy - minyy) * (maxxx - minxx);
		if (area <= temp) continue;
		point(cnt + 1, minyy, minxx, maxyy, maxxx);
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
		int y, x, c;
		cin >> y >> x >> c;
		color[c].push_back({ y,x });
	}
	point(1, 1001, 1001, -1001, -1001);
	cout << area;
}


//vector <pair<int, int>> color[21];
//vector <pair<int, int>> point;
//int N, K, sy, sx, ey, ex, area;
//
//void find_area()
//{
//	for (int i = 0; i < point.size() - 1; i++)
//	{
//		for (int j = i + 1; j < point.size(); j++)
//		{
//			int sy = min(point[i].first, point[j].first);
//			int sx = min(point[i].second, point[j].second);
//			int ey = max(point[i].first, point[j].first);
//			int ex = max(point[i].second, point[j].second);
//
//			int cnt = 0;
//			for (int k = 1; k <= K; k++)
//			{
//				for (int x = 0; x < color[k].size(); x++)
//				{
//					int ny = color[k][x].first;
//					int nx = color[k][x].second;
//					if (ny >= sy && ny <= ey && nx >= sx && nx <= ex)
//					{
//						cnt++;
//						break;
//					}
//				}
//			}
//
//			if (cnt == K)
//				if ((ex - sx) * (ey - sy) < area)
//					area = (ex - sx) * (ey - sy);
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	sy = 1001;
//	sx = 1001;
//	ey = -1001;
//	ex = -1001;
//	cin >> N >> K;
//	for (int i = 0; i < N; i++)
//	{
//		int y, x, c;
//		cin >> y >> x >> c;
//		color[c].push_back({ y,x });
//		point.push_back({ y,x });
//		if (ey < y) ey = y;
//		if (ex < x) ex = x;
//		if (sy > y) sy = y;
//		if (sx > x) sx = x;
//	}
//	area = (ey - sy) * (ex - sx);
//	find_area();
//	cout << area;
//}