#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Number of vertices in the adjMatrix
#define N 4

// define infinity as maximum value of the integer
#define INF INT_MAX

// Function to run Floyd-Warshell algorithm
void FloydWarshell(int adjMatrix[][N])
{
	// cost[] stores shortest-path information
	int cost[N][N];

	// initialize cost[] matrix
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			// Initially cost would be same as weight of the edge
			cost[v][u] = adjMatrix[v][u];
		}
	}

	// Run Floyd-Warshell
	for (int k = 0; k < N; k++)
	{
		for (int v = 0; v < N; v++)
		{
			for (int u = 0; u < N; u++)
			{
				// If vertex k is on the shortest path from v to u,
				// then update the value of cost[v][u]

				if (cost[v][k] != INF && cost[k][u] != INF
					&& cost[v][k] + cost[k][u] < cost[v][u])
				{
					cost[v][u] = cost[v][k] + cost[k][u];
				}
			}

			// If diagonal elements become negative, the
			// graph contains a negative weight cycle
			if (cost[v][v] < 0)
			{
				cout << "Negative Weight Cycle Found!!";
				return;
			}
		}
	}

	cout << "No Negative Weight Cycle Found";
}

// main function
int main()
{
	// given adjacency representation of matrix
	int adjMatrix[N][N] =
	{
		{ 0,   INF, -2,  INF },
		{ 4,   0,   -3,  INF },
		{ INF, INF, 0,   2 },
		{ INF, -1,  INF, 0 }
	};

	// Run Floyd Warshell algorithm
	FloydWarshell(adjMatrix);

	return 0;
}