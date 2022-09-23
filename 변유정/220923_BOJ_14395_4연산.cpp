#include <iostream>
#include <queue>
#include <string>
using namespace std;

// ������ >>> BFS
// �ڷ��� �ſ� �߿�! ������ Ŀ�� �� ������ long long���� �ٲٱ�
// ������ : *, +, -, /
// ���������� �迭 ����ֱ�
// 0, 1�� �ݺ����� ���ǰ� �Ǹ� ���ѷ����� ���� �� �ִ�
// �׷��� 0, 1 ��������� �� ������� �ʰ� üũ�ϱ�

struct play {
	long long num;
	string str;
};
queue <play> pp;
string ans = "-1";
bool used[2];

void program(int goal)
{
	while (!pp.empty())
	{
		play now = pp.front();
		pp.pop();
		if (now.num == goal)
		{
			ans = now.str;
			break;
		}

		long long k = now.num;
		string temp = now.str;
		if (k * k <= goal && k * k != k) pp.push({ k * k, temp + '*' });
		if (2 * k <= goal && 2 * k != k) pp.push({ 2 * k, temp + '+' });

		if (k != 0 && !used[0])
		{
			used[0] = 1;
			pp.push({ 0,temp + '-' });
		}
		if (k != 0 && k != 1 && !used[1])
		{
			used[1] = 1;
			pp.push({ 1, temp + '/' });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long a, b;
	cin >> a >> b;
	
	if (a == b) cout << 0;
	else
	{
		pp.push({ a,"" });
		program(b);
		cout << ans;
	}
}