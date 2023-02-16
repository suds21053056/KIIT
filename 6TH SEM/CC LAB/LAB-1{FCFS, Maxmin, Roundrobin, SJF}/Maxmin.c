// WAP in C to implement Maxmin scheduling algorithm //

#include <stdio.h>
#include <stdlib.h>

struct Process {
  int pid;
  int estimatedRunTime;
};

int compare(const void* a, const void* b) {
  return ((struct Process*)b)->estimatedRunTime - ((struct Process*)a)->estimatedRunTime;
}

int main() {
  struct Process processes[] = {{1, 8}, {2, 6}, {3, 7}, {4, 3}};
  int n = sizeof(processes) / sizeof(processes[0]);

  qsort(processes, n, sizeof(struct Process), compare);

  printf("Process_ID\tEstimated_RunTime\tPriority\n");

  for (int i = 0; i < n; i++) {
    printf("\t%d\t\t\t\t%d\t\t\t\t%d\n", processes[i].pid, processes[i].estimatedRunTime, n - i);
  }

  return 0;
}
