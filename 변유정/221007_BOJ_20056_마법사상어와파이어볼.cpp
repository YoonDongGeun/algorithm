#include <iostream>
#include <vector>
using namespace std;

// ���� - ���� �ùķ��̼�
// ���� ���� �ܰ�
// - move_fireball()
// 1. ���� ������� �켱 ���̾ �������ֱ�
// 2. �̵� ���� ��, 2�� �̻� ���̾�� ������ ���!
// 3. ��� ���� �� ���� == 0 �̸� �ٽ� �־����� �ʱ�
// 4. ���� 0�� �ƴϸ� ���⿡ ���� �ٽ� �־��ֱ�
// 5. K��ŭ �ݺ�!

// �� �ȿ��� �ݺ��Ѵٰ� s(�ӷ�) �ٲ����� ����.....(s = s%N)

struct Data
{
	int m, s, d;
};

int N, M, K;
vector <Data> Fireball[52][52];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

void move_fireball()
{
	// 1�ܰ�
	vector <Data> tmp[52][52];
	for (int y = 0;y<N;y++)
		for (int x = 0; x < N; x++)
		{
			if (Fireball[y][x].size() >= 1)
			{
				int k = Fireball[y][x].size();
				while (k--)
				{
					Data temp = Fireball[y][x].back();
					Fireball[y][x].pop_back();
					int ny = y + dy[temp.d] * temp.s;
					int nx = x + dx[temp.d] * temp.s;
					// 1-1. ���� ����� �׸�ŭ ������ֱ�
					while (ny >= N) ny -= N;
					while (ny < 0) ny += N;
					while (nx >= N) nx -= N;
					while (nx < 0) nx += N;
					tmp[ny][nx].push_back(temp);
				}
			}
		}
	// 2�ܰ�
	for (int y = 0;y<N;y++)
		for (int x = 0; x < N; x++)
		{
			if (tmp[y][x].size() > 1)
			{
				int k = tmp[y][x].size();
				int weight = 0;
				int speed = 0;
				int flag = 0;
				int now = k;
				while(now--)
				{
					Data temp = tmp[y][x].back();
					tmp[y][x].pop_back();
					weight += temp.m;
					speed += temp.s;
					flag += temp.d % 2;
				}
				int p_weight = weight / 5;
				int p_speed = speed / k;
				// 3�ܰ�
				if (p_weight == 0) continue;
				// 4�ܰ�
				for (int i = 0; i < 4; i++)
				{
					// ��� ¦��,Ȧ�� or �ƴԿ� ���� ������
					if (flag == 0 || flag == k) tmp[y][x].push_back({ p_weight,p_speed,i * 2 });
					else tmp[y][x].push_back({ p_weight,p_speed,i * 2 + 1 });
				}
			}
		}
	// 5. �ٽ� �������ֱ�
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			for (int i = 0; i < tmp[y][x].size(); i++)
				Fireball[y][x].push_back(tmp[y][x][i]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		Fireball[r-1][c-1].push_back({ m,s,d });
	}
	while (K--)
		move_fireball();
	
	int ans = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			for (int i = 0; i < Fireball[y][x].size(); i++)
				ans += Fireball[y][x][i].m;
	cout << ans;
}