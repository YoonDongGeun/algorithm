#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// A (���� â��) , B (���� â��) ������� �����������
//jungjunb ���� �ܰ�
// 1. �ð��� ��ġ�ϴ� �������� wait_a�� �ֱ�
// 2. �� ���� â���� ������ �� ä���ֱ�
// 3. �ð��� �ٵ� ���� ������ ����â������ ������ (+ wait_b �� �ֱ�)
// 4. �� ���� â���� ������ �� ä���ֱ� (wait_b�� ������)
// 5. �ð� �ٵ� ���� ������ ���� â������ ������ + �� ����
// 6. ���� + ���� �� ���� ���� �� �� �� (K)�� ������ ������)

int N, M, K, A, B;

int info[1002][3];
int a_data[11][3];
int b_data[11][3];

queue <int> wait_a;
queue <int> wait_b;

void jungjub()
{
	int customers = 0;
	int now = 0;
	for (int i = 0; i <= 11; i++)
		a_data[i][1] = -1;
	for (int i = 0; i <= 11; i++)
		b_data[i][1] = -1;
	while (true)
	{
		for (int i = 1; i <= K; i++)
			if (info[i][0] == now)
				wait_a.push(i);

		for (int i = 1; i <= N; i++)
		{
			if (a_data[i][1] == now)
			{
				a_data[i][1] = -1;
				wait_b.push(a_data[i][2]);
			}
		}

		for (int i = 1; i <= N; i++)
		{
			if (wait_a.empty())
				break;
			if (a_data[i][1] == -1)
			{
				a_data[i][1] = a_data[i][0] + now;
				a_data[i][2] = wait_a.front();
				info[a_data[i][2]][1] = i;
				wait_a.pop();
			}
		}

		for (int i = 1;i<=M;i++)
			if (b_data[i][1] == now)
			{
				b_data[i][1] = -1;
				customers++;
			}
		for (int i = 1; i <= M; i++)
		{
			if (wait_b.empty())
				break;
			if (b_data[i][1] == -1)
			{
				b_data[i][1] = b_data[i][0] + now;
				b_data[i][2] = wait_b.front();
				info[b_data[i][2]][2] = i;
				wait_b.pop();
			}
		}
		if (customers == K)
			break;
		now++;
	}
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
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++)
			cin >> a_data[i][0];
		for (int i = 1; i <= M; i++)
			cin >> b_data[i][0];
		for (int i = 1; i <= K; i++)
			cin >> info[i][0];
		jungjub();
		int ans = 0;
		for (int i = 1; i <= K; i++)
			if (info[i][1] == A && info[i][2] == B) ans += i;
		if (ans == 0) cout << '#' << tc << " " << -1 << '\n';
		else cout << '#' << tc << ' ' << ans << '\n';
	}
}

//������ �ڵ�

//#include <iostream>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//// ���� â�� ���� N, ���� â�� ���� M, ���� ����� �湮 ���� K
//// N���� ai : i��° ���� â������ ���� ���� ó���ϴ� �ð�
//// M���� bi : i��° ���� â������ ���� ���� ó���ϴ� �ð�
//// K���� tk : ���� �湮�ϴ� �ð�
//
//// ���� �ΰ� �� �̿� ���� â����ȣ  A, ���� â����ȣ B
//int N, M, K, A, B;
//int jub[11], jung[11], gogek[1001]; // N , M , K
//int ans;
//int used[11][2];
//int Data[1001][2];
//int who[11];
//queue <int> wait_jub;
//queue <int> wait_jung;
//
//void chuli()
//{
//	int time = 0;
//	int idx = 1;
//	while (time < K + 40)
//	{
//		if (!wait_jub.empty() && wait_jub.front() <= time)
//		{
//			for (int i = 1; i <= N; i++)
//			{
//				if (used[i][0] == 0 && wait_jub.front() <= time)
//				{
//					wait_jub.pop();
//					if (who[i] > 0)wait_jung.push(who[i]);
//					who[i] = idx;
//					Data[idx][0] = i;
//					used[i][0] = jub[i];
//					idx++;
//				}
//				else if (used[i][0] > 0) used[i][0]--;
//			}
//		}
//		for (int i = 1; i <= M; i++)
//		{
//			if (used[i][1] == 0 && !wait_jung.empty())
//			{
//				int temp = wait_jung.front();
//				wait_jung.pop();
//				Data[temp][1] = i;
//				used[i][1] = jung[i];
//			}
//			else if (used[i][1] > 0) used[i][1]--;
//		}
//		time++;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int T;
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++)
//	{
//		cin >> N >> M >> K >> A >> B;
//		for (int i = 1; i <= N; i++)
//			cin >> jub[i];
//		for (int i = 1; i <= M; i++)
//			cin >> jung[i];
//		for (int i = 1; i <= K; i++)
//		{
//			cin >> gogek[i];
//			wait_jub.push(gogek[i]);
//		}
//		ans = 0;
//		memset(Data, 0, sizeof(Data));
//		memset(used, 0, sizeof(used));
//		memset(who, 0, sizeof(who));
//		chuli();
//		for (int i = 1; i <= K; i++)
//			if (Data[i][0] == A && Data[i][1] == B) ans += i;
//
//		if (ans == 0) cout << "#" << tc << " " << -1 << '\n';
//		else cout << "#" << tc << " " << ans << '\n';
//	}
//}