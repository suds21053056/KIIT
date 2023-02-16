// WAP in C to implement FCFS scheduling algorithm //

#include <stdio.h>

struct Process {
  int pid;
  int arrivalTime;
  int burstTime;
};

int main() {
  struct Process processes[] = {{1, 0, 6}, {2, 2, 8}, {3, 4, 7}, {4, 6, 3}};
  int n = sizeof(processes) / sizeof(processes[0]);

  int totalWaitingTime = 0;
  int totalTurnaroundTime = 0;

  printf("Process_ID\tArrival_Time\tBurst_Time\tWaiting_Time\tTurnaround_Time\n");

  for (int i = 0; i < n; i++) {
    int waitingTime;
    if (i == 0) {
      waitingTime = 0;
    } else {
      waitingTime = totalTurnaroundTime - processes[i].arrivalTime;
    }

    int turnaroundTime = waitingTime + processes[i].burstTime;
    totalWaitingTime += waitingTime;
    totalTurnaroundTime += turnaroundTime;

    printf("\t%d\t\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\t\t%d\n", processes[i].pid, processes[i].arrivalTime, processes[i].burstTime, waitingTime, turnaroundTime);
  }

  float avgWaitingTime = (float)totalWaitingTime / (float)n;
  float avgTurnaroundTime = (float)totalTurnaroundTime / (float)n;

  printf("Average waiting time: %.2f\n", avgWaitingTime);
  printf("Average turnaround time: %.2f\n", avgTurnaroundTime);

  return 0;
}
