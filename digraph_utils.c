#include <stdio.h>
#include <stdlib.h>
#include "digraph_utils.h"

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
