#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

struct pt {
    int x, y;
    pt() {}
    pt(int _x, int _y) : x(_x), y(_y) {}
};

const int N = 10;
int maps[N][N] = {{0, 1, 1, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 0},
                  {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 1, 0},
                  {1, 1, 1, 0, 1, 0, 0}, {1, 1, 1, 1, 0, 0, 0}};
bool visited[N][N] = {false};

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int row = 6, col = 7;

bool judge(pt p) {
    if (p.x < row && p.y < col && p.x >= 0 && p.y >= 0) {
        if (visited[p.x][p.y] == false && maps[p.x][p.y] == 1) {
            return true;
        }
    }
    return false;
}

void dfs(pt p){
    if(judge(p) == false) return;
    visited[p.x][p.y] = true;
     for (int i = 0; i < 4; i++) {
            pt p_son = {p.x + dx[i], p.y + dy[i]};
            dfs(p_son);
        }
}



int main() {
    pt p;
    int cnt = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maps[i][j] != 0 && visited[i][j] == false) {
                p = {i, j};
                dfs(p);
                cnt++;
            }
        }
    }
    printf("cnt of blocks: %d\n", cnt);
}
