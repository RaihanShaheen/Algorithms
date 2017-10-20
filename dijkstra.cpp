#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <set>
#include <memory.h>
#include <map>
#include<algorithm>
#include<queue>
#include <math.h>
#include <stack>
using namespace std;
int const N = 1e4;
int const INF = 1e7;
int cost[N];
int n, m, s;

struct st{
	int u, cost;

	st(int u, int cost){
		this->u = u;
		this->cost = cost;
	}

	bool operator<(st const &other) const{
		return cost > other.cost;
	}

};

vector<vector<st> >g;

void dijkstra(){

	priority_queue<st>pq;
	for (int i = 0; i < n; ++i){
		if (i != s)
			cost[i] = INF;
		else
			cost[i] = 0;

		pq.push(st(i, cost[i]));
	}

	while (!pq.empty()){
		st top = pq.top();
		pq.pop();

		int from = top.u;
		for (int i = 0; i < g[from].size(); ++i){
			st to = g[top.u][i];

			if (cost[to.u] > to.cost + cost[from]){
				cost[to.u] = to.cost + cost[from];
			}


		}

	}


}



int main(){

	scanf("%d%d", &n, &m);

	g.resize(n);

	for (int i = 0, x, y, d; i < m; ++i){
		scanf("%d%d%d", &x, &y, &d);
		--x; --y;
		g[x].push_back(st(y, d));
		g[y].push_back(st(x, d));
	}

	scanf("%d", &s);
	--s;

	dijkstra();

	for (int i = 0; i < n; ++i){
		if (i == s)
			continue;
		if (cost[i] == INF)
			printf("%d ", -1);
		else
			printf("%d ", cost[i]);

	}

	return 0;
}