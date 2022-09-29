#include <iostream>
#include <queue>
using namespace std;

// �ݷ� ������
// https://www.acmicpc.net/board/view/56469

// ť Ȱ�� ���ϱ� + ��ġ �� �����ϱ�
// ������ �ٲٴ� ���� - ���ø��� ���� ���� ��ȭ�ϱ�
// �׷��� ���� ���� ���� ��������Ѵ�

int N, K, L;
int board[101][101]; // ��, ��� ���� �����ϱ�
int direct[10001]; // �ð��뿡 ���� ���� ��ȭ �迭 �����ϱ�
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
queue <pair<int, int>> Snake;

int snake()
{
	board[1][1] = 1;
	int dir = 0,cnt = 1;
	Snake.push({ 1,1 });
	while (true)
	{
		int y = Snake.back().first;
		int x = Snake.back().second;
		int ny = y + dy[dir%4];
		int nx = x + dx[dir% 4];
		if (ny <= 0 || nx <= 0 || ny > N || nx > N) break; // ���� �΋H���� ��
		if (board[ny][nx] == 1) break; // �ڱ� ���� �΋H���� ��
		else if (board[ny][nx] == -1) // ����� ������ ��
		{
			board[ny][nx] = 1; // ��� �԰� �ڱ� �� �ø���
			Snake.push({ ny,nx });
		}
		else // �׿� ��ĭ
		{
			board[ny][nx] = 1;
			// ���� ���� + ���� ���̱�
			int ey = Snake.front().first;
			int ex = Snake.front().second;
			Snake.pop();
			board[ey][ex] = 0;
			Snake.push({ ny,nx });
		}
		dir += direct[cnt];
		cnt += 1;
	}
	return cnt;
}

int main()
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = -1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		if (b == 'D') direct[a] = 1; // ������ ����
		else direct[a] = 3; // ���� ����
	}
	cout << snake();
}