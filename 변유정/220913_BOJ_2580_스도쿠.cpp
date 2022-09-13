#include <iostream>
#include <vector>
using namespace std;

/// �ð��ʰ� ���� : ������ ���� ���� Ǯ�� ����!!
/// ��ü ����� �� �־�鼭 ���, ��Ʈ��ŷ


int sudoku[10][10];
bool flag = 0;
vector <pair<int, int>> zero;

// ���� ���� �� �ִ��� �ľ��ϱ�
int row(int y, int x, int k)
{
	for (int i = 0; i < 9; i++)
		if (sudoku[i][x] == k) return 1;
	return 0;
}

// ���� ���� �� �ִ��� �ľ��ϱ�
int col(int y, int x, int k)
{
	for (int i = 0; i < 9; i++)
		if (sudoku[y][i] == k) return 1;
	return 0;
}

// ���簢�� ���� �� �ִ��� �ľ��ϱ�
int square(int y, int x, int k)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (sudoku[(y / 3) * 3 + i][(x / 3) * 3 + j] == k) return 1;
	return 0;
}

// ���� �־��
void board(int cnt)
{
	if (cnt == zero.size())
	{
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
				cout << sudoku[y][x] << " ";
			cout << "\n";
		}
		flag = 1;
		return;
	}
	int y = zero[cnt].first;
	int x = zero[cnt].second;
	for (int j = 1; j <= 9; j++)
	{
		if (row(y, x, j) == 1 || col(y, x, j) == 1 || square(y, x, j) == 1) continue;
		sudoku[y][x] = j;
		board(cnt + 1);
		if (flag == 1) return;
		sudoku[y][x] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
		{
			cin >> sudoku[y][x];
			if (sudoku[y][x] == 0)
				zero.push_back({ y,x });
		}
	board(0);
}