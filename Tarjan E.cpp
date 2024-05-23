Tarjan
SCC
vector<vector<int>> adj, scc;
vector<set<int>> dag;
vector<int> dfs_num, dfs_low, compId;
vector<bool> inStack;
stack<int> stk;
int timer;
void dfs(int node) {
	dfs_num[node] = dfs_low[node] = ++timer;
	stk.push(node);
	inStack[node] = 1;
	for (int child : adj[node])
		if (!dfs_num[child]) {
			dfs(child);
			dfs_low[node] = min(dfs_low[node], dfs_low[child]);
		}
		else if (inStack[child])
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);
	//can be dfs_low[node] = min(dfs_low[node], dfs_low[child]);
	if (dfs_low[node] == dfs_num[node]) {
		scc.push_back(vector<int>());
		int v = -1;
		while (v != node) {
			v = stk.top();
			stk.pop();
			inStack[v] = 0;
			scc.back().push_back(v);
			compId[v] = scc.size() - 1;
		}
	}
}
void SCC() {
	timer = 0;
	dfs_num = dfs_low = compId = vector<int>(adj.size());
	inStack = vector<bool>(adj.size());
	scc = vector<vector<int>>();
	for (int i = 1; i < adj.size(); i++)
		if (!dfs_num[i]) dfs(i);
}
void DAG() {
	dag = vector<set<int>>(scc.size());
	for (int i = 1; i < adj.size(); i++)
		for (int j : adj[i])
			if (compId[i] != compId[j])
				dag[compId[i]].insert(compId[j]);
}

Articulation points and bridges
vector<vector<int>> adj;
vector<int> dfs_num, dfs_low;
vector<bool> articulation_point;
vector<pair<int, int>> bridge;
stack<pair<int, int>> edges;
vector<vector<pair<int, int>>> BCC; //biconnected components
int timer, cntChild;

void dfs(int node, int par) {
	dfs_num[node] = dfs_low[node] = ++timer;
	for (int child : adj[node]) {
		if (par != child && dfs_num[child] < dfs_num[node])
			edges.push({ node, child });


		if (!dfs_num[child]) {
			if (par == -1)
				cntChild++;
			dfs(child, node);
			if (dfs_low[child] >= dfs_num[node]) {
				articulation_point[node] = 1;
				//get biconnected component
				BCC.push_back(vector<pair<int, int>>());
				pair<int, int> edge;
				do {
					edge = edges.top();
					BCC.back().push_back(edge);
					edges.pop();
				} while (edge.first != node || edge.second != child);
			}
                  //can be (dfs_low[child] == dfs_num[child])
			if (dfs_low[child] > dfs_num[node]) 
				bridge.push_back({ node, child });
			dfs_low[node] = min(dfs_low[node], dfs_low[child]);
		}
		else if (child != par)
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);
	}
}

void articulation_points_and_bridges() {
	timer = 0;
	dfs_num = dfs_low = vector<int>(adj.size());
	articulation_point = vector<bool>(adj.size());
	bridge = vector<pair<int, int>>();
	for (int i = 1; i < adj.size(); i++)
		if (!dfs_num[i]) {
			cntChild = 0;
			dfs(i, -1);
			articulation_point[i] = cntChild > 1;
		}
}
Edge classification
vector<vector<int>> adj;
vector<int> start, finish;
int timer;
void dfsEdgeClassification(int node) {
	start[node] = timer++;
	for (int child : adj[node]) {
		if (start[child] == -1)
			dfsEdgeClassification(child);
		else {
			if (finish[child] == -1)
				; // Back Edge
			else if (start[node] < start[child])
				; // Forward Edge
			else; // Cross Edge
		}
	}
	finish[node] = timer++;
}
