# coding=utf-8
from flask import Flask, jsonify, render_template
from py2neo import Graph

app = Flask(__name__)
graph = Graph("http://localhost:7474", username="neo4j", password='123456')


def buildNodes(nodeRecord):
    data = {"id": str(nodeRecord['n'].identity), "label": str(nodeRecord['n'].labels)}
    data.update(nodeRecord['n'])

    return {"data": data}


def buildEdges(relationRecord):
    data = {"source": str(relationRecord['r'].start_node.identity),
            "target": str(relationRecord['r'].end_node.identity),
            "relationship": str(relationRecord['r']).split('[')[1].split()[0]} # 因为关系的type不好获取，所以只能这样截取

    return {"data": data}


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/graph')
def get_graph():
    nodes = list(map(buildNodes, graph.run('MATCH (n) RETURN n').data()))
    edges = list(map(buildEdges, graph.run('MATCH ()-[r]->() RETURN r').data()))

    return jsonify(elements={"nodes": nodes, "edges": edges})


if __name__ == '__main__':
    app.run()
