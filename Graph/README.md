# Graph Algorithms Practice

This folder contains my solutions and notes for various Graph problems and algorithms. Below is a list of problems I solved and the key concepts learned from each.

## 📌 Problems & Learnings

1. **G-21. topoSort.cpp** - Learned how to perform Topological Sorting using DFS.
2. **G-22. Kahn's_algo.cpp** - Topological sorting using BFS (Kahn's Algorithm) with indegree array.
3. **G-23. Detect_a_Cycle_in_Directed_Graph.cpp** - Used Kahn's Algorithm / DFS to detect if a cycle exists in a directed graph.
4. **G-25. Find_Eventual_Safe_States_Kahn's.cpp** - Reversed the graph edges and used Kahn's algorithm to find safe nodes.
5. **G-26. Alien_Dictionary.cpp** - Modeled string ordering as a directed graph to find the alien alphabet order using Topological Sort.
6. **G-27. Shortest_Path_in_DAG.cpp** - Used Topological Sort to find the shortest path in a Directed Acyclic Graph efficiently `O(V+E)`.
7. **G-28. Shortest_Path_in_Undirected_Graph_with_Unit_Weights.cpp** - Used simple BFS queue to find the shortest distance since weights are uniform.
8. **G-29. Word_Ladder_I.cpp** - Solved using BFS to find the shortest transformation sequence from start word to end word.
9. **G-30. Word_Ladder_II.cpp** - Kept track of all shortest paths using BFS + backtracking (DFS).
10. **G-32. Dijkstra's_Algorithm_using_PQ.cpp** - Implemented Dijkstra using a Min-Heap (Priority Queue).
11. **G-33. Dijkstra's_Algorithm_using_set.cpp** - Implemented Dijkstra using `std::set` which helps in erasing existing larger distance nodes.
12. **G-35. Print_Shortest_Path_Dijkstra's_Algorithm.cpp** - Used a parent array to trace back the shortest path.
13. **G-36. Shortest_Distance_in_a_Binary_Maze.cpp** - Used BFS to find the shortest clear path in a 2D grid. (Dijkstra not needed as weight is uniform 1).
14. **G-37. Path_With_Minimum_Effort.cpp** - Used Dijkstra to minimize the maximum absolute difference in heights in a path.
15. **G-38. Cheapest_Flights_Within_K_Stops.cpp** - Used a Queue (BFS style) rather than PQ, because steps/stops constraint was more important than absolute distance.
16. **G-39. Minimum_Multiplications_to_Reach_End.cpp** - Dijkstra's concept applied on a modulo graph `(node * arr[i]) % 100000`.
17. **G-40. Number_of_Ways_to_Arrive_at_Destination.cpp** - Maintained an extra `ways[]` array in Dijkstra to count paths with the exact shortest distance.
18. **G-41. Bellman_Ford_Algorithm.cpp** - Learned how to compute shortest paths with negative weights and detect negative cycles.
19. **G-42. Floyd_Warshall_Algorithm.cpp** - Learned how to compute all-pairs shortest paths using the Dynamic Programming based Floyd-Warshall Algorithm.

---

## 🌎 Real-Life Applications of Core Graph Algorithms

### 1. Topological Sorting (DFS / Kahn's BFS)

**Real-Life Problem:** Course Prerequisites or Task Scheduling.
**Example:** You want to graduate, but you must take "Math 101" before "Physics 201", and "Physics 201" before "Quantum Mechanics".
**How it solves it:** Topological sort puts nodes (courses) in a straight line so that every prerequisite appears before its dependent course. If a cycle exists (e.g., A requires B, B requires A), topological sort will fail to process all nodes, which also helps detect impossible task loops!

### 2. Dijkstra's Algorithm

**Real-Life Problem:** Google Maps or GPS Navigation.
**Example:** You want the fastest route from your Home to the Airport. The roads are edges, and the travel time (or distance) is the weight.
**How it solves it:** Dijkstra's algorithm uses a priority queue to always explore the shortest known path first. It acts like water flowing through pipes; it reaches closest intersections first until it hits the destination. (Note: Dijkstra cannot handle negative weights, just like driving backward doesn't decrease the fuel you already used!)

### 3. Bellman-Ford Algorithm

**Real-Life Problem:** Financial Arbitrage or Network Routing Protocols.
**Example:** Suppose you convert USD $\to$ EUR $\to$ GBP $\to$ USD. Because of mismatched currency exchange rates, you might end up with MORE money than you started with. This is a "negative weight cycle" in graph terms!
**How it solves it:** By intentionally trying to update distances "One More Time" after $V-1$ iterations. If the cost (or currency exchange penalty) drops further, the algorithm flags a negative loop, instantly alerting traders to an arbitrage opportunity.

### 4. Floyd-Warshall Algorithm

**Real-Life Problem:** Telecommunication Networks or Multi-city Logistics.
**Example:** An internet service provider wants to know the fastest latency between _every_ possible pair of servers (routers) simultaneously to quickly reroute traffic if a connection drops. Or, an airline wants a lookup table of the absolute cheapest connecting flights between _all_ 100 cities they operate in.
**How it solves it:** Instead of calculating from one starting city, it tests every single city as a "layover" (the intermediate node _k_). It computes an "All-Pairs Shortest Path" matrix that can be referenced `O(1)` time later.

---

## ⚖️ Shortest Path Algorithms Comparison: When to use what?

| Algorithm | Graph Constraints | When to use? | Why? | Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| **Dijkstra** | Single-Source, Non-negative weights | When you need the shortest path from *one* source to all nodes, and the graph has **no negative edges**. | It uses a greedy approach (Priority Queue) making it practically the fastest for large graphs. Fails on negative weights. | $O(E \log V)$ |
| **Bellman-Ford** | Single-Source, Handles negative weights | When the graph has **negative weights** or you explicitly need to **detect negative weight cycles**. | Relaxes all edges $V-1$ times. Guaranteed to find shortest paths even with negative weights. Slower than Dijkstra. | $O(V \times E)$ |
| **Floyd-Warshall** | All-Pairs, Handles negative weights | When you need shortest paths between **every possible pair** of nodes, or graph is small ($V \le 400$). | Computes "all-pairs" simultaneously. Excellent for answering multiple $O(1)$ queries after preprocessing. | $O(V^3)$ |

---

## 🚀 Dijkstra's Algorithm

### How it works

Dijkstra's Algorithm finds the shortest path from a source node to all other nodes in a graph with non-negative edge weights.
It uses a **Min-Heap (Priority Queue)** to always process the node with the current shortest known distance.

**Edge Relaxation:**
If the distance to reach a node `u` plus the weight of the edge `u -> v` is less than the current known distance to `v`, we update the distance to `v`.

```cpp
if (dist[u] + weight < dist[v]) {
    dist[v] = dist[u] + weight;
    pq.push({dist[v], v});
}
```

### Step-by-Step Example

Assume Source Node is **0**.

```mermaid
graph LR
    0 -- 2 --> 1
    0 -- 6 --> 2
    1 -- 3 --> 2
```

1. Start at `0` (dist = 0).
2. Relax edges from `0`: `0->1` makes dist to `1` = 2. `0->2` makes dist to `2` = 6.
3. Pick smallest unused node: `1`.
4. Relax edges from `1`: `1->2` (weight 3). New dist to `2` is `dist[1] + 3 = 2 + 3 = 5`. Since 5 < 6, update `dist[2]=5`.
5. Shortest path to `2` is now 5.

---

## 🛠 Bellman-Ford Algorithm

### How it works

Unlike Dijkstra, Bellman-Ford can handle **negative edge weights**. It works by "relaxing" all edges exactly `V - 1` times (where V is the number of vertices). If we relax the edges one more time (the N-th iteration) and any distance still decreases, it means the graph has a **Negative Weight Cycle**.

### Where is Bellman-Ford needed?

- When the graph has **negative weights**. Dijkstra fails with negative weights because it assumes once a node is processed, its shortest distance is final.
- When we have to **detect negative cycles** (e.g., arbitrage opportunities in financial markets).

### Question 1: Why exactly N - 1 iterations are needed?

In the worst-case scenario, the shortest path between any two nodes can have at most `V - 1` edges.

Imagine a graph with edges processed in the reversed order of the path:

```mermaid
graph LR
    0 -- 1 --> 1
    1 -- 1 --> 2
    2 -- 1 --> 3
    3 -- 1 --> 4
```

If our source is `0` and edges are given as: `3->4`, `2->3`, `1->2`, `0->1`

- **Iteration 1**: Only `0 -> 1` can be relaxed. `dist[1]` becomes 1. Other edges are skipped because source node distances are still infinity.
- **Iteration 2**: Now `dist[1]` is known, so `1 -> 2` can be relaxed. `dist[2]` becomes 2.
- **Iteration 3**: Now `dist[2]` is known, so `2 -> 3` can be relaxed. `dist[3]` becomes 3.
- **Iteration 4**: `3 -> 4` is relaxed. `dist[4]` becomes 4.

So for a graph of 5 nodes, it took exactly `V - 1 = 4` iterations for the distance to propagate from the source to the farthest node. This guarantees that `V - 1` iterations are sufficient for ANY graph!

### Question 2: How does it detect a negative cycle in the N-th iteration?

A negative cycle is a cycle where the total sum of edge weights is less than zero. Every time you go around the cycle, your distance decreases.

Let's look at this example negative cycle graph:

```mermaid
graph LR
    1 -- -1 --> 2
    2 -- -1 --> 3
    3 -- -1 --> 1
```

If there is a negative cycle, you can keep spinning in that cycle to get a path with `-∞` cost.
Since the maximum valid shortest path length is `V - 1`, if we relax all edges one more time (the V-th or N-th time) and the distance to ANY node drops again, it mathematically proves that an infinite negative loop (negative cycle) exists.

### Flowchart of Bellman-Ford

```mermaid
graph TD
    A[Initialize dist array to Infinity] --> B[Set dist of Source = 0]
    B --> C[Loop i from 1 to V-1]
    C --> D[For every edge u -> v with weight W]
    D --> E{"dist[u] + W < dist[v]?"}
    E -- Yes --> F["dist[v] = dist[u] + W"]
    E -- No --> G[Next Edge]
    F --> G
    G --> H{"More Edges?"}
    H -- Yes --> D
    H -- No --> I{"i < V-1?"}
    I -- Yes --> C
    I -- No --> J[Iteration V: For every edge]
    J --> K{"dist[u] + W < dist[v]?"}
    K -- Yes --> L[Negative Cycle Detected!]
    K -- No --> M[Shortest Paths Found]
```

---

## 🌐 Floyd-Warshall Algorithm

### What is Multi-Source Shortest Path?

Instead of finding the shortest path from _one single starting node_ to all other nodes (like Dijkstra or Bellman-Ford), a **Multi-Source Shortest Path** algorithm finds the shortest path between **every possible pair** of nodes in the graph at once.

### Why is it needed?

- Sometimes we need to know the shortest distance from _Node A to B_, _Node C to D_, _Node E to B_, all at the same time.
- Running Dijkstra $V$ times (for each vertex as a source) takes $O(V \times E \log V)$. If the graph is dense (lots of edges) or has negative edges, it becomes very slow or incorrect.
- Floyd-Warshall solves this elegantly in $O(V^3)$ using Dynamic Programming and handles negative edge weights perfectly.

### Beginner Friendly Analogy: The "Shortcut" Approach

Imagine you are trying to travel from **City A** to **City B**. The direct flight costs ₹6000.
But what if you take a flight from **City A to City K (via)**, and then another flight from **City K to City B**?
If City A $\to$ City K costs ₹2000 and City K $\to$ City B costs ₹3000, then the total via City K is ₹5000.
Since ₹5000 < ₹6000, you have found a **shorter path**!

Floyd-Warshall does exactly this. It checks every single node as a possible "City K" (middleman) to see if routing the path through it makes the journey cheaper.

### How it works (The "Via Node" Concept)

The core idea is simple: **Can I find a shorter path from node $i$ to node $j$ by going through an intermediate node $k$?**

Let's assume our path goes from Node $i$ to Node $j$. We try to inject a middleman node $k$.
If we can reach $k$ from $i$ (meaning `dist[i][k]` is valid), and $j$ from $k$ (meaning `dist[k][j]` is valid), we check:
Is `Distance(i to j)` > `Distance(i to k) + Distance(k to j)`?
If yes, we update our distance to the newly found shorter path:

```cpp
// Check if paths via k exist
if (dist[i][k] != infinity && dist[k][j] != infinity) {
    // Take the minimum of direct path vs path going via node 'k'
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
```

We do this checking by making every vertex (from $0$ to $N-1$) the intermediate node $k$ one by one, step-by-step.

> **💡 Important Detail for Beginners:**
> Why check `!= infinity`? Because if node `k` is unreachable from `i`, then `dist[i][k]` is infinity. Adding any number to infinity might cause an integer overflow in C++ (e.g., $10^8 + 1$). Also, logically, if you can't reach the middleman, you can't use him for a shortcut!

### Beginner Friendly Example

Consider the following graph:

- $0 \to 2$ (weight 2)
- $0 \to 1$ (weight 6)
- $0 \to 3$ (weight 4)
- $2 \to 4$ (weight 1)
- $2 \to 1$ (weight 3)
- $3 \to 1$ (weight 1)
- $4 \to 1$ (weight 1)

**Visual Representation of the Directed Graph:**

```mermaid
graph TD
    0 -->|6| 1
    0 -->|2| 2
    0 -->|4| 3
    2 -->|3| 1
    2 -->|1| 4
    3 -->|1| 1
    4 -->|1| 1
```

Let's analyze calculating the shortest path from **Node 0 to Node 1**.
Initially, using only direct edges, the distance is **6**. (So, `dist[0][1] = 6`)

Then we gradually introduce middleman nodes ($k$), keeping track of paths found so far:

- **Via Node 2 ($k=2$):** Path $0 \to 2 \to 1$. Distance = $dist[0][2] + dist[2][1] = 2 + 3 = 5$. Since 5 < 6, we update the matrix: `dist[0][1] = 5`. (We also discover path to $4$: $dist[0][4] = dist[0][2] + dist[2][4] = 2 + 1 = 3$).
- **Via Node 3 ($k=3$):** Path $0 \to 3 \to 1$. Distance = $dist[0][3] + dist[3][1] = 4 + 1 = 5$. It's not strictly smaller than our current 5, no change.
- **Via Node 4 ($k=4$):** Can we reach 4 from 0? Yes! Our previous steps stored `dist[0][4] = 3`. So, Path $0 \to \dots \to 4 \to 1$. Distance = $dist[0][4] + dist[4][1] = 3 + 1 = 4$. Since 4 < 5, update `dist[0][1] = 4`.

Ultimately, the shortest path from $0$ to $1$ becomes **4**!

### Matrix Calculation Step-by-Step

Let's see how the Adjacency Matrix updates at each iteration when we set $k = 0, 1, 2, 3, 4$.

**1. Initial Matrix ($\text{when } k = -1$, direct edges only):**
| From/To | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| **0** | 0 | 6 | 2 | 4 | $\infty$ |
| **1** | $\infty$ | 0 | $\infty$ | $\infty$ | $\infty$ |
| **2** | $\infty$ | 3 | 0 | $\infty$ | 1 |
| **3** | $\infty$ | 1 | $\infty$ | 0 | $\infty$ |
| **4** | $\infty$ | 1 | $\infty$ | $\infty$ | 0 |

**2. Matrix via $k = 0$ (Considering Node 0 as middleman):**

- Remains unchanged because nobody can reach node 0 anyway.

**3. Matrix via $k = 1$ (Considering Node 1 as middleman):**

- Remains unchanged because from node 1 we cannot go anywhere.

**4. Matrix via $k = 2$ (Considering Node 2 as middleman):**

- $0 \to 1$ via 2: $dist[0][2] + dist[2][1] = 2 + 3 = 5$. Update `dist[0][1] = 5`.
- $0 \to 4$ via 2: $dist[0][2] + dist[2][4] = 2 + 1 = 3$. Update `dist[0][4] = 3`.
  | From/To | 0 | 1 | 2 | 3 | 4 |
  |---|---|---|---|---|---|
  | **0** | 0 | **5** | 2 | 4 | **3** |
  _(Rest remains same)_

**5. Matrix via $k = 3$ (Considering Node 3 as middleman):**

- Matrix remains same. $0 \to 1$ via 3 gives $4 + 1 = 5$, but we already found a path of length 5 earlier. (Nothing strictly smaller).

**6. Matrix via $k = 4$ (Considering Node 4 as middleman):**

- $0 \to 1$ via 4: Uses `dist[0][4]` which was calculated in $k=2$ step as 3. So, $dist[0][4] + dist[4][1] = 3 + 1 = 4$. Update `dist[0][1] = 4`.
- $2 \to 1$ via 4: $dist[2][4] + dist[4][1] = 1 + 1 = 2$. Update `dist[2][1] = 2`.

**Final Output Matrix:**
| From/To | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| **0** | 0 | **4** | 2 | 4 | 3 |
| **1** | $\infty$ | 0 | $\infty$ | $\infty$ | $\infty$ |
| **2** | $\infty$ | **2** | 0 | $\infty$ | 1 |
| **3** | $\infty$ | 1 | $\infty$ | 0 | $\infty$ |
| **4** | $\infty$ | 1 | $\infty$ | $\infty$ | 0 |

By the end of iterating $k$ sequentially, we evaluated every possible nested combination of paths dynamically, confirming the core algorithm principle!

---

## 🏙️ Problem Deep-Dive: Find the City With the Smallest Number of Neighbors at a Threshold Distance (G-43)

### Why use Floyd-Warshall here instead of Dijkstra?

In this problem, we are asked to evaluate every single city to find out which one can reach the fewest number of other cities within a `distanceThreshold`. 
To do this, we must know the shortest path from **EVERY city to EVERY OTHER city**. 

Since we need **All-Pairs Shortest Paths**, **Floyd-Warshall** is the most intuitive and direct fit! 
The problem constraints usually have a very small number of cities ($N \le 100$). For such small constraints, the $O(V^3)$ time complexity of Floyd-Warshall is perfectly acceptable. More importantly, it is **super easy to code** (just 3 simple nested loops) compared to setting up adjacency lists and priority queues.

### Can we use Dijkstra instead?

**Yes, absolutely!** 
Because all edge distances are positive in this problem (no negative weights), Dijkstra is a perfectly valid and excellent approach.

**How?**
Dijkstra finds the shortest path from *one* source to all other nodes. Since we need the shortest paths for *every* city, we simply **run Dijkstra $V$ times** (treating each city as a starting node inside a loop).

**Time Complexity using Dijkstra:**
- One run of Dijkstra takes: $O(E \log V)$
- Running it $V$ times takes: $O(V \times E \log V)$

### Comparison: Which is better?

| Algorithm | Complexity | When to use for this specific problem? |
| :--- | :--- | :--- |
| **Floyd-Warshall** | $O(V^3)$ | Graph is dense, or $V$ is small ($\le 100$). It gives you a clean DP matrix approach without complex data structures. |
| **Dijkstra ($V$ times)** | $O(V \times E \log V)$ | Graph is sparse (few edges), or $V$ is large (e.g., $10^4$). This will run significantly faster than $O(V^3)$. |

---

## 🌲 Spanning Tree & Minimum Spanning Tree (MST)

### What is a Spanning Tree?
A **Spanning Tree** of a connected, undirected graph is a subgraph that is a tree and includes **all the vertices** of the original graph.
Basically, it "spans" across all nodes without forming any cycles.

**Key rules of a Spanning Tree:**
1. It must contain **all the vertices** (nodes) of the graph.
2. It must have exactly **$V - 1$ edges** (where $V$ is the number of vertices).
3. It must have **no cycles** (it's a tree, so no loops allowed).
4. A single graph can have *many* different spanning trees.

### What is a Minimum Spanning Tree (MST)?
A **Minimum Spanning Tree (MST)** is a spanning tree where the **sum of the edge weights is as small as possible** (the absolute minimum). 

If a graph has edges with different weights (like costs, distances, or lengths), the MST is the specific spanning tree that connects all the nodes with the lowest total cost.

### 🌎 Real-Life Applications: Why and Where is it Used?
The main goal of an MST is to connect everything together using the **least amount of resources** (wire, road, cost, etc.).

**1. Network Design (The Classic Example):**
Imagine you need to lay down fiber-optic internet cables to connect 5 different cities. Laying down cable is extremely expensive per kilometer. You don't need a direct cable between *every single* city, you just need them all to be connected to the same overall network. Using an MST algorithm (like Prim's or Kruskal's) tells you the exact roads to lay cables on to minimize the total kilometers of wire used while ensuring no city is left offline.

**2. Electrical Wiring in Houses:**
If an electrician is wiring the electrical outlets in a new house, they want to connect all outlets to the main circuit breaker using the minimum length of copper wire to save money.

**3. Water Supply Networks / Pipelines:**
Connecting water pipes to multiple houses in a neighborhood so that everyone gets water without creating useless, expensive loops in the pipeline.

### Beginner Friendly Example (Mermaid Diagram)

Imagine 4 cities (`A`, `B`, `C`, `D`) and the cost to build roads between them.

**1. The Original Graph (All possible roads & their costs):**
```mermaid
graph TD
    A((A)) -- 1 --- B((B))
    A -- 4 --- C((C))
    A -- 3 --- D((D))
    B -- 2 --- C((C))
    C -- 5 --- D((D))
```

To connect all 4 cities, we only need exactly $4 - 1 = 3$ edges. 

**2. The Minimum Spanning Tree (The cheapest way to connect all):**
If we select the edges `A-B` (cost 1), `B-C` (cost 2), and `A-D` (cost 3), we connect all cities.
Total Cost = $1 + 2 + 3 = 6$.
(Any other combination connecting all 4 cities will cost more than 6!)

```mermaid
graph TD
    A((A)) -- 1 --- B((B))
    A -- 3 --- D((D))
    B -- 2 --- C((C))
    
    style A fill:#f9f,stroke:#333,stroke-width:2px
    style B fill:#f9f,stroke:#333,stroke-width:2px
    style C fill:#f9f,stroke:#333,stroke-width:2px
    style D fill:#f9f,stroke:#333,stroke-width:2px
```
*Notice how there are no cycles, all 4 cities are connected, and the total cost is minimized.*

---

## 🛠️ Prim's Algorithm

### How Prim's Algorithm Works
Prim's Algorithm builds the Minimum Spanning Tree one node at a time. It uses a **Priority Queue (Min-Heap)** to always pick the smallest available edge that connects a node we have *already visited* to a node we *haven't visited yet*.

**The core logic is simple:**
1. Start from any node (usually node `0`). Mark it as visited.
2. Put all its connected edges into a priority queue.
3. Pick the smallest edge from the queue. 
4. **Crucial Check:** If the node this edge goes to is *already visited*, we **skip it (continue)**! Why? Because connecting two already-visited nodes forms a **cycle**, which is forbidden in a tree.
5. If the node is *not* visited, mark it as visited, add the edge's weight to our total MST sum, and push all its new edges into the queue.
6. Repeat until all nodes are visited.

### The "Tempting but Cycle-Forming Edge" Scenario

What happens when Prim's encounters an edge that has a very small weight, but picking it would create a loop? Let's look at an intentional trap in a graph!

**The Graph Example:**
Consider 5 nodes (`0` to `4`). We have a very small, tempting edge between `0` and `2` with a weight of only `2`.

```mermaid
graph TD
    0((0)) -- 1 --- 1((1))
    1 -- 1 --- 2((2))
    0 -. "2 (Tempting Trap!)" .- 2
    2 -- 5 --- 3((3))
    3 -- 4 --- 4((4))
```

To human eyes, weight `2` looks like a great deal compared to the weights `4` or `5` later in the graph. Should we take it?

**Let's Trace Prim's Steps:**
1. Start at `0`. Pick edge `0-1` (weight 1). Nodes visited: `0, 1`.
2. From `1`, pick edge `1-2` (weight 1). Nodes visited: `0, 1, 2`.
3. Now, the priority queue pops the tempting edge `0-2` (weight 2).
4. **Wait!** Both `0` and `2` are already visited. If we connect them, we form the cycle `0-1-2-0`. 
5. Prim's Algorithm says: `"⚠️ Tempting but rejected (Cycle Formed!)"` and safely skips this edge.
6. Next, it picks `2-3` (weight 5) and `3-4` (weight 4) to finish connecting everyone.

### Final Minimum Spanning Tree
Here is the final MST. Notice how the tempting `0-2` edge was ignored to prevent the cycle, saving the tree structure!

```mermaid
graph TD
    0((0)) -- 1 --- 1((1))
    1 -- 1 --- 2((2))
    2 -- 5 --- 3((3))
    3 -- 4 --- 4((4))
    
    style 0 fill:#9f9,stroke:#333,stroke-width:2px
    style 1 fill:#9f9,stroke:#333,stroke-width:2px
    style 2 fill:#9f9,stroke:#333,stroke-width:2px
    style 3 fill:#9f9,stroke:#333,stroke-width:2px
    style 4 fill:#9f9,stroke:#333,stroke-width:2px
```
*Total MST Weight = 1 + 1 + 5 + 4 = 11*
*The $O(E \log V)$ efficiency of Prim's comes heavily from quickly ignoring these cycle-forming edges (`if(vis[node]) continue;`)!*

---

## 🛠️ Kruskal's Algorithm

### How Kruskal's Algorithm Works (The "Greedy Edge Picker")
While Prim's Algorithm grows the tree like a spreading spider web from one single starting point, **Kruskal's Algorithm** doesn't care about starting points! It just looks at the entire map, finds the absolute cheapest roads anywhere, and buys them one by one.

**The core logic is incredibly easy:**
1. **List them:** Put every single edge in a big list.
2. **Sort them:** Sort the list strictly from lowest weight to highest weight (cheapest first).
3. **Pick & Check:** Go down the list, picking the cheapest edge.
   - If connecting this edge forms a **loop (cycle)**, throw it in the trash! 🗑️
   - If it doesn't form a loop, keep it. You just bought a piece of the Minimum Spanning Tree! 🎉
4. Keep going until you have successfully connected all the nodes.

### But wait... How do we easily check for cycles?
This is exactly where the **Disjoint Set Union (DSU)** data structure comes to the rescue as a superhero! 🦸‍♂️

Whenever we consider picking an edge between Node `u` and Node `v`:
- We ask DSU: *"Hey, are `u` and `v` already connected to the same Ultimate Boss?"*  
  Code syntax: `if (ds.findUParent(u) == ds.findUParent(v))`
- If **Yes**: It means they are already secretly connected through some other path. Adding this new edge will definitely create a cycle. So, we immediately **reject** it.
- If **No**: Safe! We add the edge weight to our MST total, and tell the DSU to merge their teams (`ds.unionSize(u, v)`).

### Beginner Friendly Visual Example
Imagine we have a sorted edge list:
1. `Weight 1 (Node 1 - Node 4)`: DSU says different bosses. **Pick it!** Connect 1 and 4.
2. `Weight 2 (Node 1 - Node 2)`: DSU says different bosses. **Pick it!** Connect 1 and 2.
3. `Weight 3 (Node 2 - Node 4)`: DSU says: **Wait!** `Node 2` and `Node 4` both point to `Node 1` as their ultimate boss. They are already in the same team! If you connect 2 and 4, you form a cycle! **Reject it.** 🚫

### Prim's vs Kruskal's: Which one to use?
- Both algorithms generally run in roughly $O(E \log E)$ or $O(E \log V)$ time.
- **Kruskal's** is heavily preferred by competitive programmers because if you already have a pre-written DSU template, Kruskal's takes almost zero brainpower to write. Just `sort()` the edges, loop through them, and use DSU!
- **Prim's** is sometimes slightly better if you have an extremely **dense graph** (a graph where almost every node is connected to every other node), but generally, it comes down to your personal coding style preference!
