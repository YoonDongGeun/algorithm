#include <iostream>
#include <vector>
using namespace std;

// ���ͷ� ����...�ߴµ� ��ť�� �ص� �ƾ��� ��
// �����̾Ʈ�� �κ� ��ġ�� ���� ����
// 1. �ö󰡴� ��ġ�� �������� ��ġ �ľ�
// 2. �������� ��ġ�� �׻� ����α�
// 3. ��������� ���� �����ϱ� (�̸� ������ġ�� �÷����� �������� ����!)

int N, K;
vector <int> belt;
vector <bool> robot;
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++)
	{
		int a;
		cin >> a;
		belt.push_back(a);
		robot.push_back(0);
	}

	while (true)
	{
		// 1. ��Ʈ �� ĭ���� �ִ� �κ��� �Բ� ��ĭ ȸ��
		int temp = belt[2*N-1];
		belt.pop_back();
		belt.insert(belt.begin(), temp);

		bool temp1 = robot[2 * N - 1];
		robot.pop_back();
		robot.insert(robot.begin(), temp1);
		robot[N - 1] = 0;

		// 2. �κ� �̵��ϱ� (�̵��� ĭ�� �κ��� ����, �������� 0���� ũ��)
		for (int i = N - 2; i >= 0; i--)
		{
			if (robot[i] == 1 && belt[i + 1] > 0 && robot[i + 1] == 0)
			{
				robot[i] = 0;
				robot[i + 1] = 1;
				belt[i + 1]--;
			}
		}
		if (robot[N - 1] == 1) robot[N - 1] = 0;

		// 3. �ø� ��ġ(0)�� ������ 0���� ũ�� �κ��� ������ �ø���
		if (belt[0] > 0 && robot[0] == 0)
		{
			belt[0]--;
			robot[0] = 1;
		}

		// 4. ������ 0��ĭ ���� K �̻��̸� ����
		int zero = 0;
		for (int i = 0; i < 2 * N; i++)
			if (belt[i] == 0) zero++;
		if (zero >= K) break;
		// �ƴϸ� ��� �����ϱ�
		cnt++;
	}
	cout << cnt + 1;
	return 0;
}

// deque�� �����ϱ� 
//#include <iostream>
//#include <deque>
//using namespace std;
//
//int n, k, zeroPower;
//struct Info {
//	bool isRobot;
//	int power;
//};
//deque<Info> belt;
//
//void input()
//{
//	int power;
//	cin >> n >> k;
//	for (int i = 0; i < 2 * n; i++) {
//		cin >> power;
//		belt.push_back({ false, power });
//	}
//}
//
//void rotate()
//{
//	Info info = belt.back();
//	belt.pop_back();
//	belt.push_front(info);
//	if (belt[n - 1].isRobot) belt[n - 1].isRobot = false;
//}
//
//void moveRobot()
//{
//	for (int i = n - 2; i >= 0; i--) {
//		if (belt[i].isRobot == true && belt[i + 1].isRobot == false && belt[i + 1].power >= 1) {
//			belt[i + 1].isRobot = true;
//			belt[i + 1].power--;
//			if (belt[i + 1].power == 0) zeroPower++;
//			if (i + 1 == n - 1) belt[i + 1].isRobot = false;
//			belt[i].isRobot = false;
//		}
//	}
//}
//
//void addRobot()
//{
//	if (belt[0].power > 0) {
//		belt[0].isRobot = true;
//		belt[0].power--;
//		if (belt[0].power == 0) zeroPower++;
//	}
//}
//
//int solve()
//{
//	int level = 0;
//	while (true) {
//		level++;
//		rotate();
//		moveRobot();
//		addRobot();
//		if (zeroPower >= k) break;
//	}
//	return level;
//}
//
//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	input();
//	cout << solve() << '\n';
//
//	return 0;
//}