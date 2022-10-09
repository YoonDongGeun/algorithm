#include <iostream>
using namespace std;

// �ùķ��̼� + ����
// ���ǵ��� �� �����غ����ϴ� ����

// ����
// 1�� : ������ ��� �����ؼ� ���� - ������ : �ߺ��Ǵ� ������ ����
// 2�� : �ߺ� ���� ����ؼ� ���ܽ�Ŵ - ������ : ������ ���ϴٰ� �ߺ� ������ �ƴ� ���� �� ���� ���ѹ��� (ex: 30)
// 3�� : ���� ��� �������� ���� �׳� ���� ��θ� ���� (���� ��� X)

// ���� ����
// 1-1. �� 4���� ���ÿ� �ű� (a,b,c,d)
// 1-2. ���� �Ű����� ��, �̹� ������ �ִ� ���̸� �̵� X (������ ����)
// 1-3. 10�� ��� ���� �Ű��� ���� ���� ans ���� ũ�� ans ����

// 2. �� �ű� �� �Ķ��� ���� ���� / ���� �� ���� ���


int dice[10];
int board[33] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,13,16,19,22,24,28,27,26,25,30,35,40,0 };
int ans = 0;

// 2�ܰ�
int move_h(int now, int num)
{
	// 2-1. �Ķ��� ����
	if (now == 5)
	{
		if (num <= 3) now = num + 19;
		else now = num + 24;
	}
	else if (now == 10)
	{
		if (num <= 2) now = num + 22;
		else now = num + 25;
	}
	else if (now == 15)
		now = num + 24;
	// 2-2. ������ ���� (���� ���� ��ȣ�� �̾����� �ʱ� ������ ���� ���)
	else if (now >= 20 && now <= 22 && now + num > 22)
		now += num + 5;
	else if (now >= 23 && now <= 24 && now + num > 24)
		now += num + 3;
	else if (now <= 19 && now + num > 19)
		now += num + 11;
	else now += num;
	// 2-3. ���� ������������ �� ���ٸ� �׳� ������������ ���س���
	if (now > 31) now = 32;
	return now;
}

// 1�ܰ�
void roll(int cnt,int a,int b,int c,int d, int temp)
{
	if (cnt == 10)
	{
		ans = max(ans, temp);
		return;
	}

	if (a != 32)
	{
		int na = move_h(a, dice[cnt]);
		// 1-1 & 1-2 �ܰ�
		if (na != b && na != c && na != d || na == 32)
			roll(cnt + 1, na, b, c, d, temp + board[na]);
	}
	if (b != 32)
	{
		int nb = move_h(b, dice[cnt]);
		if (nb != a && nb != c && nb != d  || nb == 32)
			roll(cnt + 1, a, nb, c, d, temp + board[nb]);
	}

	if (c != 32)
	{
		int nc = move_h(c, dice[cnt]);
		if (nc != a && nc != b && nc != d || nc == 32)
			roll(cnt + 1, a, b, nc, d, temp + board[nc]);
	}

	if (d != 32)
	{
		int nd = move_h(d, dice[cnt]);
		if (nd != a && nd != b && nd != c || nd == 32)
			roll(cnt + 1, a, b, c, nd, temp + board[nd]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++)
		cin >> dice[i];
	roll(0, 0, 0, 0, 0,0);
	cout << ans;
}