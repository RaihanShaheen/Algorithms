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
int const N = 500;
int const INF = 3e8+10;
int cost[N][N];
int n, m, s;

struct node{
	int u, cost;

	node(int u, int cost){
		this->u = u;
		this->cost = cost;
	}
};

void floyed(){
	
	

	for (int k = 0; k <= n; ++k){
		for (int i = 0; i <= n; ++i){
			for (int j = 0; j <= n; ++j){
				if (cost[i][j] > cost[i][k] + cost[k][j]){
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}


}


int main(){

	
	int t;

	scanf("%d%d", &n,&m);
	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= n; ++j){
			if (i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = INF;
		}
	}

	for (int i = 0, x,y, r; i < m; ++i){
		scanf("%d%d%d", &x,&y,&r);
		cost[x][y] = r;
	}

	

	floyed();

	int q;

	scanf("%d", &q);

	for (int i = 0,x,y; i < q; ++i){
		scanf("%d%d", &x,&y);
		if (cost[x][y] == INF)
			printf("-1\n");
		else
		printf("%d\n", cost[x][y]);
	}

	return 0;
}