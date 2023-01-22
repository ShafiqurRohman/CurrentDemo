#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int processNo;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
};

bool compareByArrivalTime(Process a, Process b) {
    if(a.arrivalTime == b.arrivalTime){
        return a.burstTime <= b.burstTime;
    }
    return a.arrivalTime <= b.arrivalTime;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process processes[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].processNo = i+1;
    }

    sort(processes, processes + n, compareByArrivalTime);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
        processes[i].responseTime = currentTime - processes[i].arrivalTime;
        currentTime = processes[i].completionTime;
    }

    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].processNo << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].completionTime << "\t\t" << processes[i].turnAroundTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].responseTime << endl;
    }

return 0;
}
