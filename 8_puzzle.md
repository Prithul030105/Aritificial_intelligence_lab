mplemented Algorithms
1. Depth First Search (DFS)

Explores nodes by going as deep as possible in one direction before backtracking.

May go into deep/irrelevant branches, not always optimal.

Works using a stack for exploration.

2. Breadth First Search (BFS)

Explores level by level, ensuring the shallowest solution is found.

Guarantees optimal solution if all moves have equal cost.

Works using a queue for exploration.

3. Best-First Search (Heuristic Search)

Uses a heuristic function to choose the most promising state.

Implemented with Manhattan Distance heuristic.

Works with a priority queue (states with lower heuristic are explored first).

More efficient than BFS/DFS in large state spaces.
