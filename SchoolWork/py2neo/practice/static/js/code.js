$(function(){ //不用事件触发，就直接运行函数
  $.get('/graph', function(result) { //get()方法通过远程 HTTP GET 请求载入信息，请求成功时可调用回调函数。相当于用户还没访问/graph，前端就自动帮我们访问了
    var style = [
            {
              selector: 'node:selected',
              css: {
                "border-width": "6px",
                "border-color": "#AAD8FF",
                "border-opacity": "0.5",
                "background-color": "#77828C",
                "text-outline-color": "#77828C"
              }
            },

            { selector: 'node',
              css: {
                "width": "mapData(score, 0, 0.006769776522008331, 20, 60)",
                "height": "mapData(score, 0, 0.006769776522008331, 20, 60)",
                "font-size": "12px",
                "text-valign": "center",
                "text-halign": "center",
                "text-outline-color": "#555",
                "text-outline-width": "2px",
                "color": "#fff",
                "overlay-padding": "6px",
                "z-index": "10"
              }
            },

            { selector: 'node[label=":Person"]', //千万注意这儿label是:Person，不是Person！！！下面同理
              css: {
                'background-color': '#00cc99',
                'content': 'data(name)'
              }
            },

            { selector: 'node[label=":Movie"]',
              css: {
                'background-color': '#6666ff',
                'content': 'data(title)'
              }
            },

            { selector: 'edge',
              css: {
                'content': 'data(relationship)',
                'curve-style': 'bezier',
                'target-arrow-shape': 'triangle'
              }
            }
    ];

    var cy = cytoscape({
      container: document.getElementById('cy'),
      style: style,
      layout: {
        name: 'cose',
        idealEdgeLength: 100,
        nodeOverlap: 20,
        refresh: 20,
        fit: true,
        padding: 30,
        randomize: false,
        componentSpacing: 100,
        nodeRepulsion: 400000,
        edgeElasticity: 100,
        nestingFactor: 5,
        gravity: 80,
        numIter: 1000,
        initialTemp: 200,
        coolingFactor: 0.95,
        minTemp: 1.0
      },
      elements: result.elements
    });
  }, 'json');
});