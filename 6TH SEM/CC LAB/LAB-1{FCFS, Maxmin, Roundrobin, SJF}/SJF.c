// WAP in C to implement SJF scheduling algorithm //

#include <stdio.h>
#include <stdlib.h>

struct Process {
  int pid;
  int burstTime;
};

int compare(const void* a, const void* b) {
  return ((struct Process*)a)->burstTime - ((struct Process*)b)->burstTime;
}

int main() {
  struct Process processes[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};
  int n = sizeof(processes) / sizeof(processes[0]);

  qsort(processes, n, sizeof(struct Process), compare);

  int totalTime = 0;
  int waitingTime = 0;

  printf("Process ID\tBurst Time\tWaiting Time\n");

  for (int i = 0; i < n; i++) {
    totalTime += processes[i].burstTime;
    waitingTime = totalTime - processes[i].burstTime;

    printf("\t%d\t\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].burstTime, waitingTime);
  }

  return 0;
}
