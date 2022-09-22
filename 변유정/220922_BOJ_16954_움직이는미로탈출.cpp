#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// BFS (�迭�θ� Ǯ���!!)
// ���� : ���� > ��
// ���� �Ʒ��θ� ������
// ������ ���� ��ġ ����, �� 9���� �������� �� �� ����

char board[8][8];
int flag = 0;
int dy[9] = { 1, 0,-1, 0, 1, 1,-1,-1,0 };
int dx[9] = { 0, 1, 0,-1, 1,-1, 1,-1,0 };
vector <pair<int, int>> wall;
queue <pair<int, int>> wookjae;
bool used[8][8];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			cin >> board[y][x];
			if (board[y][x] == '#')
				wall.push_back({ y,x });
		}
	}
	wookjae.push({ 7,0 });

	while (!wookjae.empty()) // ������ ��� ���� �л������ ���� �� �� ����
	{
		int cnt = wookjae.size(); // ������ �ִ� �ڸ� ����
		memset(used, 0, sizeof(used));
		while (cnt--)
		{
			int y = wookjae.front().first;
			int x = wookjae.front().second;
			wookjae.pop();

			if (y == 0 && x == 7)
			{
				flag = 1;
				break;
			}

			if (board[y][x] == '#') continue; // ������ �л� ���� ������ ť�� �������� �� ����

			for (int i = 0; i < 9; i++) // ������ ���� �ִ� ������ Ž��
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) continue;
				if (used[ny][nx] || board[ny][nx] == '#') continue;
				used[ny][nx] = 1;
				wookjae.push({ ny,nx });
			}
		}

		for (int y = 0; y < 8; y++) // �� �̵��ϱ� ���� �ʱ�ȭ
			for (int x = 0; x < 8; x++)
				board[y][x] = '.';

		for (int i = 0; i < wall.size(); i++)
		{
			int y = wall[i].first;
			int x = wall[i].second;


			if (y == 7) // ���� ���� �ǾƷ��� �������� ��
			{
				wall.erase(wall.begin() + i); // �� ����ҿ��� ���ܽ�Ű��
				i--;
				continue;
			}
			board[y + 1][x] = '#'; // �� �̵�
			wall[i].first++;
		}
		if (flag == 1) break; // ���� �������� (0,7) �����ߴٸ� �׸� ���� ���߱�
	}
	cout << flag;
}