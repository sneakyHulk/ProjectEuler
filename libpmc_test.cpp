#include <iostream>
#include <stdio.h>
#include <stdlib.h>

extern "C" {

// a list of edges, where index_offset is the starting index
int max_clique(long long nedges, int *ei, int *ej, int index_offset,
               int outsize, int *clique);
};

#include <pmc/pmc.h>

void test1() {
  // test a triangle
  int ei[] = {3,  3,  3,  3,  3,  3,  3,  3,  7,  7,  7,  11,
              13, 13, 17, 19, 19, 19, 23, 23, 29, 37, 37, 43};
  int ej[] = {
      7,  11, 17, 31, 37, 59, 67, 73, 19, 61, 97, 23,
      19, 61, 83, 31, 79, 97, 47, 89, 71, 67, 79, 97,
  };
  int output[] = {0, 0, 0, 0};

  int C = max_clique(24, ej, ei, 0, 4, output);
  if (C != 3) {
    fprintf(stderr, "Test failed");
    exit(-1);
  }
}

int main(int argc, char **argv) { test1(); };
