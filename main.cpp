#include "path.h"

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	const int ROWS = 4;
	const int COLUMNS = 5;
	GridLocation startLoc = {0, 0};
	GridLocation endLoc = {3, 4};
	vector<vector<PathFinder::Vertex>> v;
	PathFinder pathFinder;

	auto& startVertex = pathFinder.insertVertex(startLoc);

	for (int row = 0; row < ROWS; row++) {
		v.push_back(vector<PathFinder::Vertex>());
		for (int col = 0; col < COLUMNS; col++) {
			GridLocation loc = {row, col};
			if (loc == startLoc) {
				v[row].push_back(startVertex);
			} else {
				v[row].push_back(pathFinder.insertVertex(loc));
			}
		}
	}

    //       0   1   2   3   4
    //     +---------------+---+
    //   0 | S             |   |
    //     +---+   +   +---+   |
    //   1 |   |   |           |
    //     |   +   +-------+   |
    //   2 |               |   |
    //     |   +   +---+   +---+
    //   3 |   |       |     E |
    //     +---+-------+-------+

	// Horizontal edges
	// pathFinder.insertEdge(v[0][0], v[0][1], 0);
	// pathFinder.insertEdge(v[0][1], v[0][2], 0);
	// pathFinder.insertEdge(v[0][2], v[0][3], 0);
	// pathFinder.insertEdge(v[1][2], v[1][3], 0);
	// pathFinder.insertEdge(v[1][3], v[1][4], 0);
	// pathFinder.insertEdge(v[2][0], v[2][1], 0);
	// pathFinder.insertEdge(v[2][1], v[2][2], 0);
	// pathFinder.insertEdge(v[2][2], v[2][3], 0);
	// pathFinder.insertEdge(v[3][1], v[3][2], 0);
	// pathFinder.insertEdge(v[3][3], v[3][4], 0);

	// Vertical edges
	// pathFinder.insertEdge(v[1][0], v[2][0], 0);
	// pathFinder.insertEdge(v[2][0], v[3][0], 0);
	// pathFinder.insertEdge(v[0][1], v[1][1], 0);
	// pathFinder.insertEdge(v[1][1], v[2][1], 0);
	// pathFinder.insertEdge(v[2][1], v[3][1], 0);
	// pathFinder.insertEdge(v[0][2], v[1][2], 0);
	// pathFinder.insertEdge(v[2][3], v[3][3], 0);
	// pathFinder.insertEdge(v[0][4], v[1][4], 0);
	// pathFinder.insertEdge(v[1][4], v[2][4], 0);

	//       0   1   2   3   4
	//     +---------------+---+
	//   0 | S             |   |
	//     +---+   +   +---+   |
	//   1 |   |   |           |
	//     |   +---+-------+   |
	//   2 |                   |
	//     |   +   +-----------+
	//   3 |   |             E |
	//     +---+---------------+

	// Horizontal edges
	pathFinder.insertEdge(v[0][0], v[0][1], 0);
	pathFinder.insertEdge(v[0][1], v[0][2], 0);
	pathFinder.insertEdge(v[0][2], v[0][3], 0);
	pathFinder.insertEdge(v[1][2], v[1][3], 0);
	pathFinder.insertEdge(v[1][3], v[1][4], 0);
	pathFinder.insertEdge(v[2][0], v[2][1], 0);
	pathFinder.insertEdge(v[2][1], v[2][2], 0);
	pathFinder.insertEdge(v[2][2], v[2][3], 0);
	pathFinder.insertEdge(v[2][3], v[2][4], 0);
	pathFinder.insertEdge(v[3][1], v[3][2], 0);
	pathFinder.insertEdge(v[3][2], v[3][3], 0);
	pathFinder.insertEdge(v[3][3], v[3][4], 0);

	// Vertical edges
	pathFinder.insertEdge(v[1][0], v[2][0], 0);
	pathFinder.insertEdge(v[2][0], v[3][0], 0);
	pathFinder.insertEdge(v[0][1], v[1][1], 0);
	pathFinder.insertEdge(v[2][1], v[3][1], 0);
	pathFinder.insertEdge(v[0][2], v[1][2], 0);
	pathFinder.insertEdge(v[0][4], v[1][4], 0);
	pathFinder.insertEdge(v[1][4], v[2][4], 0);

	cout << "Path to the exit:" << endl;
	auto path = pathFinder.findPath(startVertex, endLoc);
	for (auto& loc : path) {
		cout << loc << endl;
	}

	return EXIT_SUCCESS;
}
