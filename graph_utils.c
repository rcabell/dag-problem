#include <stdio.h>
#include <stdlib.h>
#include "graph_utils.h"

void init_graph(uint32_t graph[], int n_vertices)
{
	int i;

	for (i = 0; i < n_vertices; i++) {
		graph[i] = 0;
	}
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

int write_graph(const char *filename, uint32_t graph[], int n_vertices)
{
	FILE *f;
	int i, j;

	if ((f = fopen(filename, "w")) == NULL) {
		return 1;
	}

	fprintf(f, "%d\n", n_vertices);
	for (i = 0; i < n_vertices; i++) {
		if (i > 0) fprintf(f, " ");
		for (j = 24; j >= 0; j -= 8) {
			fprintf(f, "%02x", (graph[i] >> j) & 0xff);
		}
	}
	fprintf(f, "\n");

	fclose(f);

	return 0;
}

int add_edge(uint32_t graph[], int n_vertices, int a, int b)
{
	if (a < 0 || a >= n_vertices ||
	    b < 0 || b >= n_vertices) {
		return 1;	
	}

	graph[a] |= (1 << b);

	return 0;
}

int remove_edge(uint32_t graph[], int n_vertices, int a, int b)
{
	if (a < 0 || a >= n_vertices ||
	    b < 0 || b >= n_vertices) {
		return 1;	
	}

	graph[a] &= ~(1 << b);

	return 0;
}

void print_graph(uint32_t graph[], int n_vertices)
{
	int i, j;

	printf("digraph {\n");
	for (i = 0; i < n_vertices; i++) {
		if (graph[i]) {
			int need_space = 0;
			printf("%d -> {", i);
			for (j = 0; j < n_vertices; j++) {
				if (graph[i] & (1 << j)) {
					if (need_space) printf(" ");
					printf("%d", j);
					need_space = 1;
				}
			}
			printf("}\n");
		}
	}
	printf("}\n");
}
