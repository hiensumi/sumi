#include <bits/stdc++.h>

const int N = 7;
const int M = 3;
const int SIZE = 10000;
const long long INFLL = std::numeric_limits<long long>::max();

std::vector<std::pair<int, int>> adj[SIZE];
long long dis_1[SIZE], dis_2[SIZE];
std::queue<int> queue;
int in_queue[SIZE];
int ind, cnt, num[SIZE], low[SIZE], scc[SIZE];
std::stack<int> stack;
int on_stack[SIZE];
std::vector<int> order;
void tarjan(int u){
	num[u] = low[u] = ++ind;
	stack.push(u);
	on_stack[u] = 1;
	for (auto [v, w] : adj[u])
		if (num[v] == 0)
		{
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		}
		else if(on_stack[v])
			low[u] = std::min(low[u], num[v]);
	if (num[u] == low[u])
	{
		++cnt;
		int v;
		do
		{
			v = stack.top();
			stack.pop();
			on_stack[v] = 0;
			order.push_back(v);
			scc[v] = u;	
		} while (v != u);
	}
}

void segmented_spfa()
{
	tarjan(0);
	std::cerr << "Number of SCCs: " << cnt << std::endl;
	dis_2[0] = 0;
	for(int i = std::min(N-1, (int)order.size() - 1); i >= 0;){
		int root = scc[order[i]];
//		std::cout << -1;
		for (; i >= 0 && scc[order[i]] == root; --i){
//			std::cout << -1 << " ";
			if (dis_2[order[i]] != INFLL)
			{
				queue.push(order[i]);
				in_queue[order[i]] = 1;
			}
		}
		while (!queue.empty())
		{
			int u = queue.front();
			std::cout << u << " ";
			queue.pop();
			in_queue[u] = 0;
			for (auto [v, w] : adj[u])
				if (dis_2[u] + w < dis_2[v])
				{
					dis_2[v] = dis_2[u] + w;
					if (scc[v] == root && in_queue[v] == 0)
					{
						queue.push(v);
						in_queue[v] = 1;
					}
				}
		}
	}
}

int main(){
	for (int i = 0; i < M; ++i){
		int u, v, w;
		std::cin >> u >> v >> w;
		u--;
		v--;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i = 0; i < 4; ++i){
		int u, v, w;
		std::cin >> u >> v >> w;
		u--;
		v--;
		adj[u].emplace_back(v, w);
	}
	std::fill(dis_2, dis_2 + N, INFLL);
	//spfa();
	
	segmented_spfa();
	std::cout << std::endl;
	for (int i = 0; i < N; ++i){
		std::cout << dis_2[i] << " ";
	}
//		assert(dis_1[i] == dis_2[i]);	
	
	return 0;
}