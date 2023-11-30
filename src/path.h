#pragma once

#include "dfs.h"

#include <sstream>

struct GridLocation {
    int row;
    int column;
};

bool operator==(const GridLocation& lhs, const GridLocation& rhs)
{
    return lhs.row == rhs.row && lhs.column == rhs.column;
}

std::ostream& operator<<(std::ostream& os, const GridLocation& loc)
{
    std::ostringstream ss;
    ss << "(" << loc.row << "," << loc.column << ")";
    os << ss.str();
    return os;
}

class PathFinder : public DFS<GridLocation,int> {

private:

    std::vector<GridLocation> path;
    GridLocation target;
    bool done;

protected:

    void startVisit(Vertex& v) {
        GridLocation vertexLocation = (*v).element;
        path.push_back(vertexLocation);
        if (vertexLocation == target) {
            done = true;
        }
    }

    void finishVisit(const Vertex& v) {
        if (!done) {
            path.pop_back();
        }
    }

    bool isDone() const {
        return done;
    }

public:

    const std::vector<GridLocation>& findPath(Vertex& s, const GridLocation& t) {
        initialize();
        path.clear();
        target = t;
        done = false;
        traverse(s);
        return path; 
    }
};
