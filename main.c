#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "graph_utils.h"

/*
 * Forward declarations of is_dag
 * The actual implementation of this function is in the is_dag.F90 file
 */
int is_dag(int n_vertices, int32_t digraph[]);


int main(int argc, const char **argv)
{
	int i;

	if (argc <= 1) {
		fprintf(stderr, "\nUsage: is_dag <digraph file>+\n\n");
		return 1;
	}

	for (i = 1; i < argc; i++) {
		uint32_t *digraph;
		int n_vertices;

		if (read_graph(argv[i], &digraph, &n_vertices)) {
			fprintf(stderr, "Error reading digraph from file %s\n", argv[i]);
			return 1;
		}

		printf("%s is a dag? %i\n", argv[i], is_dag(n_vertices, (int32_t *)digraph));

		free(digraph);
	}

	return 0;
}
