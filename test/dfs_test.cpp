#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "dfs.h"

#include <vector>

using namespace std;

class DFSTest : public DFS<char,int> {

    virtual void startVisit(Vertex& v) {
        vertexVisits.push_back((*v).element);
    }

    virtual void traverseDiscovery(Edge& e, const Vertex& from) {
        discoveredEdges.push_back((*e).element);
    }

public:

    vector<char> vertexVisits;
    vector<int> discoveredEdges;

    void search(Vertex& v) {
        vertexVisits.clear();
        discoveredEdges.clear();
		initialize();
        traverse(v);
    }
};

TEST_CASE("DFS traversal")
{
	DFSTest dfs;
	auto& a = dfs.insertVertex('a');
	auto b = dfs.insertVertex('b');
	auto c = dfs.insertVertex('c');
	auto d = dfs.insertVertex('d');
	auto e = dfs.insertVertex('e');
	auto e1 = dfs.insertEdge(a, b, 1);
	auto e2 = dfs.insertEdge(a, c, 2);
	auto e3 = dfs.insertEdge(b, c, 3);
	auto e4 = dfs.insertEdge(b, d, 4);
	auto e5 = dfs.insertEdge(c, d, 5);
	auto e6 = dfs.insertEdge(c, e, 6);
	auto e7 = dfs.insertEdge(d, e, 7);

    dfs.search(a);
    REQUIRE(dfs.vertexVisits == vector<char> {'a', 'b', 'c', 'd', 'e'});
    REQUIRE(dfs.discoveredEdges == vector<int> {1, 3, 5, 7});
}
