#include <iostream>
#include <vector>
using namespace std;

/// 
/// �ùķ��̼� + ���� (?)
/// 1. ������ K�� ���� ���ϱ� (K ���� - 1~2*N)
/// 2. ������ ���� ���ϱ� (���� ���) ���밪 y,x ������ �� ���� �Ѿ�� ������ �ֱ�
/// 3. ���� Ȩ cnt ���� ���ϱ� (�̶� cost�� 0 �̸��̸� 0���� �ǵ����ֱ�)
/// 4. cnt�� ans���� ũ�� �����ϱ�

int T, N, M, K;
int city[21][21];
int ans = 0;
vector <pair<int, int>> service;


/// 2�ܰ�
void diamond(int area)
{
    for (int y = -area + 1; y < area; y++)
        for (int x = -area + 1; x < area; x++)
            if (abs(y) + abs(x) < area) service.push_back({ y,x });
}

/// 3�ܰ�
int secu(int cost, int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < service.size(); i++)
    {
        int ny = y + service[i].first;
        int nx = x + service[i].second;
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (city[ny][nx] == 1)
        {
            cnt++;
            cost += M;
        }
    }
    if (cost < 0) return 0;
    else return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N >> M;
        int temp = 0;
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
            {
                cin >> city[y][x];
                if (city[y][x] == 1)
                    temp += M;
            }

        // 1�ܰ�
        for (K = N * 2; K >= 1; K--)
            if (K * K + (K - 1) * (K - 1) < temp) break;

        for (int i = 1; i <= K; i++)
        {
            // ���ο� ������ ���� ���ϱ�
            service.clear();
            diamond(i);
            int cost = i * i + (i - 1) * (i - 1);
            for (int y = 0; y < N; y++)
            {
                for (int x = 0; x < N; x++)
                {
                    // 4�ܰ�
                    int tmp = secu(-cost, y, x);
                    if (ans < tmp) ans = tmp;
                }
            }
        }
        cout << "#" << tc << " " << ans << "\n";
        ans = 0;
    }
}

// �ٸ���� �ڵ� ����ȭ
//#include <iostream>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false); cin.tie(0);
//    int t, hx[400], hy[400], idx, n, m, ans;
//    char a[20][20];
//    cin >> t;
//    for (int tc = 1; tc <= t; tc++) {
//        ans = idx = 0;
//        cin >> n >> m;
//        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//            cin >> a[i][j];
//            if (a[i][j] == '1') hx[idx] = i, hy[idx++] = j;
//        }
//        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//            int c[41] = { 0, };
//            for (int k = 0; k < idx; k++) c[abs(i - hx[k]) + abs(j - hy[k]) + 1]++;
//            for (int k = 1; k < 41; k++) {
//                c[k] += c[k - 1];
//                if (c[k] * m - ((k - 1) * (k - 1) + k * k) >= 0)
//                    ans = c[k] > ans ? c[k] : ans;
//            }
//        }
//        cout << "#" << tc << " " << ans << '\n';
//    }
//    return 0;
//}