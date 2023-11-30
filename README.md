# Lab 45: Graph Depth First Search

In this lab, we will use DFS to solve a maze. The maze is a simple grid of squares represented by row and column indices:

        0   1   2   3   4
      +---------------+---+
    0 | S             |   |
      +---+   +   +---+   |
    1 |   |   |           |
      |   +   +-------+   |
    2 |               |   |
      |   +   +---+   +---+
    3 |   |       |     E |
      +---+-------+-------+

We can represent a maze as a graph such that each vertex is a square in the grid. For example, the start of this maze is at vertex (0,0) and the end of the maze is at vertex (3,4). Edges of the graph represent a viable path through the maze. For example, there is an edge from (0,0) to (0,1) but not from (0,0) to (1,0) due to the wall.

## C++ Implementation

The graph ADT and DFS algorithm are already provided in `graph.h` and `dfs.h`. They are almost identical to the code examples in Chapter 13 of the textbook. 

A framework for the path finding algorithm to solve the maze is provided in the `PathFinder` class of `path.h`, but it is incomplete. Your task is to complete the implementation. If you need a hint, refer to the `FindPath` example in section 13.3 of the textbook. They are very similar except that `PathFinder` keeps track of the target vertex as a `GridLocation` object (instead of a `Vertex`) and the path as a `std:vector<GridLocation>` (instead of a `VertexList`).

There are no unit tests for `PathFinder` in this project. Instead, a graph representing the above maze is already provided in `main`. Simply run the `main` target and check the output. If your code is working properly, you should see a path to the exit:

    (0,0)
    (0,1)
    (1,1)
    (2,1)
    (2,2)
    (2,3)
    (3,3)
    (3,4)

## Next Steps

Once you have `PathFinder` working with the above maze, try adding or removing some walls, such as:

        0   1   2   3   4
      +---------------+---+
    0 | S             |   |
      +---+   +   +---+   |
    1 |   |   |           |
      |   +---+-------+   |
    2 |                   |
      |   +   +-----------+
    3 |   |             E |
      +---+---------------+

Does your `PathFinder` still find a path?

What happens if you remove an edge such that there is _no_ viable path through the maze?
