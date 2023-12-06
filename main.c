#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "digraph_utils.h"

/*
 * Forward declarations of is_dag
 * See function definition further down for documentation
 */
int is_dag(uint32_t digraph[], int n_vertices);


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

		printf("%s is a dag? %i\n", argv[i], is_dag(digraph, n_vertices));

		free(digraph);
	}

	return 0;
}


/*
 *
 */
int is_dag(uint32_t digraph[], int n_vertices)
{
	return 0;
}
