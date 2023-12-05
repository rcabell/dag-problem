# dag-problem
An exercise in detecting cycles in digraphs

-----

Let $G = (V,E)$ be a directed graph (*digraph*) with vertex set $V$ and edge set $E$. Each
directed edge $e \in E$ is an ordered pair of vertices $(v_1,v_2)$, with $v_1, v_2 \in V$. Note that a
directed edge from a vertex $v$ to itself, i.e., an edge $(v,v)$, is permissible.

A directed path is a sequence of vertices $\langle v_0, \ldots, v_m \rangle$ such that
$(v_i, v_(i+1))$ in $E$ for $i = 0, \ldots, m-1$. A cycle in a digraph is a path with $v_0 \equiv v_m$.
A directed acyclic graph (*dag*) is a digraph that contains no cycles.

Recall that a digraph $G = (V,E)$ may be respresented as a set of adjacency
lists, one list for each vertex $v \in V$. The adjacency list for $v$ contains the vertices
$u_i \forall (v,u_i) \in E$, i.e, all vertices to which $v$ contains an outgoing edge.

If we assume that the vertices are numbered $0, \ldots, |V|-1$, then the adjacency list
for each vertex $v$ may be represented as a bit-array, where a bit value of 1 in
array position $i$ implies an edge $(v, v_i)$. When $|V| \le 32$, a 32-bit integer
is sufficient to represent the adjacency list for a vertex.

In this exercise, our objective is to write a function in C/C++ that will
determine whether a digraph is a dag. The main driver program, which is
provided, takes as a command-line argument the name of a file containing a
representation of a digraph and reads the graph into an array of uint32_t
values. The size of the array is equal to the number of vertices in the digraph,
and each element $i$ of the array stores the adjacency list for vertex $v_i$.

The function to determine whether a digraph is a dag has the following
prototype:
```c
int is_dag(uint32_t digraph[], int n_vertices);
```
This function takes as input an adjacency list representation of a digraph
and the number of vertices in the graph. The size of the `digraph` array is
`n_vertices`, with `n_vertices` at most 32. The function returns 1 if the given
graph is a dag, and 0 otherwise.

After implementing the `is_dag` function, the program should be run for each of
the digraphs in the `examples/` sub-directory of this repository.
