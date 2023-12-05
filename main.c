#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int is_dag(uint32_t digraph[], int n_vertices);
int read_graph(const char *filename, uint32_t *graph[], int *n_vertices);

int main(int argc, const char **argv)
{
	int i;

	if (argc <= 1) {
		fprintf(stderr, "\nUsage: is_dag <digraph file>\n\n");
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


int is_dag(uint32_t digraph[], int n_vertices)
{
	return 0;
}


int read_graph(const char *filename, uint32_t *graph[], int *n_vertices)
{
	FILE *f;
	int i, j;

	if ((f = fopen(filename, "r")) == NULL) {
		return 1;
	}

	fscanf(f, "%d", n_vertices);
	*graph = malloc(sizeof(uint32_t) * (size_t)(*n_vertices));
	for (i = 0; i < *n_vertices; i++) {
		for (j = 0; j < 4; j++) {
			int b;
			fscanf(f, "%2x", &b);
			(*graph)[i] <<= 8;
			(*graph)[i] |= (uint32_t)b;
		}
	}

	fclose(f);

	return 0;
}
