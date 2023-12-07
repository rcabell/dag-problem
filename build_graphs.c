#include "graph_utils.h"

int main(void)
{
	uint32_t digraph[32];
	int n_vertices;
	int i;

	/*
	 * Graph with no edges
	 */
	init_graph(digraph, 32);
	write_graph("no_edges.grf", digraph, 6);

	/*
	 * Graph with one vertex and self-loop edge
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 1, 0, 0);
	write_graph("self_loop.grf", digraph, 1);

	/*
	 * Graph with two vertices and single loop
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 2, 0, 1);
	add_edge(digraph, 2, 1, 0);
	write_graph("two_loop.grf", digraph, 2);

	/*
	 * Graph with four vertices connected in a simple path
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 4, 0, 1);
	add_edge(digraph, 4, 1, 2);
	add_edge(digraph, 4, 2, 3);
	write_graph("simple_path.grf", digraph, 4);

	/*
	 * Full binary tree with four leaves
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 7, 0, 1);
	add_edge(digraph, 7, 0, 2);
	add_edge(digraph, 7, 1, 3);
	add_edge(digraph, 7, 1, 4);
	add_edge(digraph, 7, 2, 5);
	add_edge(digraph, 7, 2, 6);
	write_graph("binary_tree.grf", digraph, 7);

	/*
	 * K4, no cycles
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 4, 0, 1);
	add_edge(digraph, 4, 0, 2);
	add_edge(digraph, 4, 0, 3);
	add_edge(digraph, 4, 1, 2);
	add_edge(digraph, 4, 1, 3);
	add_edge(digraph, 4, 3, 2);
	write_graph("K4_nocycles.grf", digraph, 4);

	/*
	 * K4, with cycles
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 4, 0, 1);
	add_edge(digraph, 4, 0, 3);
	add_edge(digraph, 4, 1, 3);
	add_edge(digraph, 4, 2, 0);
	add_edge(digraph, 4, 2, 1);
	add_edge(digraph, 4, 3, 2);
	write_graph("K4_cycles.grf", digraph, 4);

	/*
	 * Simple cycle with 32 edges
	 */
	init_graph(digraph, 32);
	for (i = 0; i < 31; i++) {
		add_edge(digraph, 32, i, i+1);
	}
	add_edge(digraph, 32, 31, 0);
	write_graph("big_cycle.grf", digraph, 32);

	/*
	 * Full binary tree with four leaves, but swapping vertices 0 and 5
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 7, 5, 1);
	add_edge(digraph, 7, 5, 2);
	add_edge(digraph, 7, 1, 3);
	add_edge(digraph, 7, 1, 4);
	add_edge(digraph, 7, 2, 0);
	add_edge(digraph, 7, 2, 6);
	write_graph("binary_tree2.grf", digraph, 7);

	/*
	 * Tree-like but with loop
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 7, 5, 1);
	add_edge(digraph, 7, 5, 2);
	add_edge(digraph, 7, 1, 3);
	add_edge(digraph, 7, 1, 4);
	add_edge(digraph, 7, 2, 0);
	add_edge(digraph, 7, 2, 6);
	add_edge(digraph, 7, 6, 2);
	write_graph("not_a_tree.grf", digraph, 7);

	/*
	 * Three vertices, three edges with a cycle and vertex 0 a sink
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 3, 1, 0);
	add_edge(digraph, 3, 1, 2);
	add_edge(digraph, 3, 2, 1);
	write_graph("tricycle.grf", digraph, 3);

	/*
	 * Disconnected graph with cycle in second connected component
	 */
	init_graph(digraph, 32);
	add_edge(digraph, 6, 1, 0);
	add_edge(digraph, 6, 1, 2);
	add_edge(digraph, 6, 2, 0);
	add_edge(digraph, 6, 5, 4);
	add_edge(digraph, 6, 4, 3);
	add_edge(digraph, 6, 3, 5);
	write_graph("disconnected_cycle.grf", digraph, 6);

	return 0;
}
