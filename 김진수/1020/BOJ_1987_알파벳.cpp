#include <iostream>
#include <string>
#include <vector>
using namespace std;
// getline �־ȴ�� ���پ�
// [A] ���� ���� ����
int R, C;
vector<vector<string>>arr;
vector<vector<string>>visited;
int result = 0;

// [B] delta ���� ����
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

// [D] DFS �Լ� ����
void dfs(int i, int j, string alphabet)
{
	for (int dr = 0; dr < 4; dr++)
	{
		int ni = i + di[dr];
		int nj = j + dj[dr];

		if (0 <= ni < R and 0 <= nj < C and (alphabet.find(arr[ni][nj]) != string::npos))
		{
			if (visited[ni][nj] != alphabet + arr[ni][nj])
			{
				visited[ni][nj] = alphabet + arr[ni][nj];
				dfs(ni, nj, alphabet + arr[ni][nj]);
			}
		}
	}

	if (result < alphabet.length())
	{
		result = alphabet.length();
	}
	return;
}


// [1] �Է°� ����
int main()
{
	cin >> R >> C;
	cin.ignore();
	for (int i = 0; i < R; i++)
	{
		getline(cin, arr[i]);
	}

	visited[0][0] = arr[0][0];
	dfs(0, 0, arr[0][0]);
	cout << result << '\n';
	return 0;
}