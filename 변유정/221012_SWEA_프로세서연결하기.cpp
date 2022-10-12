#include <iostream>
#include <vector>
using namespace std;

// ���μ��� �����ϱ�
// ����Ž��

// 1. ������� vector (core) �� ����ֱ� (�����ڸ��� �ִ°� ����)
// 2. ������� ���� �ٸ��� ���ָ鼭 Ž��
// 2-1. ���⿡ �°� ���� ���� �� ������ ������ �߰� �� ���� �ھ�� �Ѿ��
// 2-2. ��� ���⿡ ���� ������ �׳� ���� �ھ�� �Ѿ��
//
// 3. ������ �ھ���� Ȯ��������
// 3-1. ���� �ھ�� �ִ�� ���� �� ���� ����
// 3-2. �ھ���� ��������� �ھ���� ���ٸ� ���� �ѱ��� �� �� ����
//

int N, processor[13][13];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector <pair<int, int>> core;
int ans, result;

int wire(int dir, int a, int b)
{
	int y = a;
	int x = b;
	int cnt = 0;
	bool flag = 0;
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) break;
		if (processor[ny][nx] == 1)
		{
			flag = 1;
			break;
		}
		y = ny;
		x = nx;
		cnt++;
	}
	if (!flag) return cnt;
	else return -1;
}

void make_wire(int dir, int y, int x,int num)
{
	while (true)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) break;
		processor[ny][nx] = num;
		y = ny;
		x = nx;
	}
}

void order(int can_, int length, int now)
{
	if (now == core.size())
	{
		if (ans < can_)
		{
			ans = can_;
			result = length;
		}
		else if (ans == can_)
			result = min(result, length);
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		int temp = wire(k, core[now].first, core[now].second);
		if (temp != -1)
		{
			make_wire(k, core[now].first, core[now].second, 1);
			order(can_ + 1, length + temp, now + 1);
			make_wire(k, core[now].first, core[now].second, 0);
		}
	}
	order(can_, length, now + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		ans = 0;
		result = 1e9;
		cin >> N;
		for (int y = 0;y<N;y++)
			for (int x = 0; x < N; x++)
			{
				cin >> processor[y][x];
				if (processor[y][x] == 1)
				{
					if (y == 0 || x == 0 || y == N - 1 || x == N - 1) continue;
					else core.push_back({ y,x });
				}
			}
		order(0, 0, 0);
		cout << "#" << tc << " " << result << '\n';
		core.clear();
	}
}