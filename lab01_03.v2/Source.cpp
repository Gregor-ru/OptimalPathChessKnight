#include "my_list.h"
#include "my_set.h"
#include "my_queue.h"


const int moves[][2] = { {2, -1}, {2, 1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };

bool is_valid(int x, int y, int N) {
    return (x >= 0 && x < N) && (y >= 0 && y < N);
}

int find_shortest_distance(int N, ChessNode src, ChessNode dest) {

    MySet<ChessNode> visited;
    MyQueue<ChessNode> q;
    q.enqueue(src);

    while (!q.empty()) {
        ChessNode node = q.peek();
        q.dequeue();

        int x = node.x;
        int y = node.y;
        int dist = node.dist;

        if (x == dest.x && y == dest.y) {
            return dist;
        }

        if (!visited.contains(node)) {
            visited.insert(node);

            for (const auto& move : moves) {
                int x1 = x + move[0];
                int y1 = y + move[1];

                if (is_valid(x1, y1, N)) {
                    q.enqueue({ x1, y1, dist + 1 });
                }
            }
        }
    }

    return -1;
}

int main() {
    int N = 8;
    ChessNode src = { 1, 5 };
    ChessNode dest = { 6, 2 };

    cout << "The minimum number of steps required is " <<
        find_shortest_distance(N, src, dest);

    return 0;
}
