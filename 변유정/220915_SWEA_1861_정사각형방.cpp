#include <iostream>
using namespace std;

// dfs�� Ǯ����
// �� �渶�� ���ƴٴϸ鼭 ���� �ִ� �氳�� �ִ� ����� ���鼭
// temp�� �Ͻ������� ���� �ְ� ans�� ans_idx ���ϸ鼭 �� �ٲٱ�

// ���� ���ǿ��� 1�̻� N^2 ���� ���� �̿��ص� �ɵ� �ʹ�

int T, N;
// �� ����
int room[1001][1001];

// �� �濡�� �� �� �ִ� ����
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int temp;
int ans, ans_idx;

void dfs(int y,int x, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (temp < cnt) temp = cnt;
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (room[ny][nx] != room[y][x] + 1) continue;
		dfs(ny, nx, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> room[y][x];
		ans = -1;
		temp = 0;
		ans_idx = 1000001;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				dfs(y, x, 1);
				// �ִ� �� �� �ִ� ���� ������ �������� ���� ��
				if (temp > ans)
				{
					ans = temp;
					ans_idx = room[y][x];
				}
				// ������ ������ ���۹��� ���ڰ� �� ���� ��
				else if (temp == ans && room[y][x] < ans_idx)
					ans_idx = room[y][x];

				temp = 0;
			}
		}
		cout << "#" << tc << " " << ans_idx << " " << ans << "\n";
	}
}

// BFS�� Ǫ�� ���
//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//const int MAX_N = 1010;
//int T, N;
//int Arr[MAX_N][MAX_N];
//bool visit[MAX_N][MAX_N];
//int dc[4] = { 1, 0, -1, 0 };
//int dr[4] = { 0, 1, 0, -1 };
//int answer;
//int max_cnt = 0;
//typedef struct {
//    int r, c;
//}point;
//queue<point> Q;
//
//void init() {
//    answer = 100000;
//    max_cnt = 0;
//    memset(visit, false, sizeof(visit));
//}
//
//bool checkRange(point p) {
//    if (p.r >= 0 && p.r < N && p.c >= 0 && p.c < N) return true;
//    return false;
//}
//
//void BFS(point p) {
//    int temp_cnt = 0, temp_answer = Arr[p.r][p.c];
//    point curr, next;
//
//    curr = p;
//    Q.push(curr);
//    visit[curr.r][curr.c] = true;
//
//    while (!Q.empty()) {
//        curr = Q.front(); Q.pop();
//        temp_cnt++;
//        temp_answer = min(temp_answer, Arr[curr.r][curr.c]);
//
//        for (int d = 0; d < 4; d++) {
//            next.r = curr.r + dr[d], next.c = curr.c + dc[d];
//            if (checkRange(next) && !visit[next.r][next.c]) {
//                if (Arr[curr.r][curr.c] + 1 == Arr[next.r][next.c] || Arr[curr.r][curr.c] - 1 == Arr[next.r][next.c]) {
//                    Q.push(next);
//                    visit[next.r][next.c] = true;
//                }
//            }
//        }
//    }
//
//    if (max_cnt == temp_cnt) {
//        //printf("�ִ�ġ�� ���� %d vs %d => %d\n", answer, Arr[p.r][p.c], min(answer, Arr[p.r][p.c]));
//        answer = min(answer, temp_answer);
//
//    }
//    else if (max_cnt < temp_cnt) {
//        //printf("�ִ�ġ ���� %d vs %d => %d\n", answer, Arr[p.r][p.c], min(answer, Arr[p.r][p.c]));
//        max_cnt = temp_cnt;
//        answer = temp_answer;
//    }
//}
//
//int main() {
//    scanf("%d", &T);
//    for (int t = 1; t <= T; t++) {
//        init();
//
//        scanf("%d", &N);
//        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &Arr[i][j]);
//
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                if (!visit[i][j]) BFS({ i, j });
//            }
//        }
//
//        printf("#%d %d %d\n", t, answer, max_cnt);
//    }
//}