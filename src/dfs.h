#pragma once

#include "graph.h"

template <typename VertexElement, typename EdgeElement>
class DFS {
private:

    struct VertexData {
        bool visited;
        VertexElement element;
    };

    struct EdgeData {
        bool visited;
        EdgeElement element;
    };

    typedef Graph<VertexData,EdgeData> G;
    typedef typename G::VertexList VertexList;
    typedef typename G::VertexItor VertexItor;
    typedef typename G::EdgeList EdgeList;
    typedef typename G::EdgeItor EdgeItor;
    
    G graph;

public:

    typedef typename G::Vertex Vertex;
    typedef typename G::Edge Edge;

    Vertex& insertVertex(const VertexElement& element) {
        return graph.insertVertex({false, element});
    }

    Edge& insertEdge(const Vertex& v, const Vertex& u, const EdgeElement& element) {
        return graph.insertEdge(v, u, {false, element});
    }

protected:

    void initialize() {
        VertexList verts = graph.vertices();
        for (VertexItor pv = verts.begin(); pv != verts.end(); ++pv) {
            unvisit(*pv);
        }

        EdgeList edges = graph.edges();
        for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe) {
            unvisit(*pe);
        }
    }

    void traverse(Vertex& v) {
        startVisit(v);
        visit(v);
        EdgeList incident = v.incidentEdges();
        EdgeItor pe = incident.begin();
        while (!isDone() && pe != incident.end()) {
            Edge& e = *pe++;
            if (!isVisited(e)) {
                visit(e);
                Vertex& w = e.opposite(v);
                if (!isVisited(w))  {
                    traverseDiscovery(e, v);
                    if (!isDone()) {
                        traverse(w);
                    }
                } else {
                    traverseBack(e, v);
                }
            }
        }
        if (!isDone()) {
            finishVisit(v);
        }
    }

    virtual void startVisit(Vertex& v) {}
    virtual void traverseDiscovery(Edge& e, const Vertex& from) {}
    virtual void traverseBack(const Edge& e, const Vertex& from) {}
    virtual void finishVisit(const Vertex& v) {}

    virtual bool isDone() const {
        return false;
    }

    void visit(Vertex& v) {
        (*v).visited = true;
    }

    void visit(Edge& e) {
        (*e).visited = true;
    }

    void unvisit(Vertex& v) {
        (*v).visited = false;
    }

    void unvisit(Edge& e) {
        (*e).visited = false;
    }

    bool isVisited(Vertex& v) {
        return (*v).visited;
    }

    bool isVisited(Edge& e) {
        return (*e).visited;
    }
};
