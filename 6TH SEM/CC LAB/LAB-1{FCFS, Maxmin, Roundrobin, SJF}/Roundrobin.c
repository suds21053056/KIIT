// WAP in C to implement Round Robin scheduling algorithm //

#include <stdio.h>

struct Process {
  int pid;
  int burstTime;
  int remainingTime;
};

int main() {
  struct Process processes[] = {{1, 6, 6}, {2, 8, 8}, {3, 7, 7}, {4, 3, 3}};
  int n = sizeof(processes) / sizeof(processes[0]);

  int quantum = 2;
  int time = 0;
  int done = 0;

  while (done < n) {
    for (int i = 0; i < n; i++) {
      if (processes[i].remainingTime > 0) {
        if (processes[i].remainingTime > quantum) {
          time += quantum;
          processes[i].remainingTime -= quantum;
        } else {
          time += processes[i].remainingTime;
          processes[i].remainingTime = 0;
          done++;

          printf("Process %d finished at time %d\n", processes[i].pid, time);
        }
      }
    }
  }
  return 0;
}
