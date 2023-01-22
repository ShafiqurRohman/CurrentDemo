#include <iostream>
#include <algorithm>

using namespace std;

struct Process {
    int processNo;
    int arrivalTime;
    int priority;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
};

bool compare(Process a, Process b) {
    return a.priority < b.priority;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[n];

    cout << "Enter the details of the processes" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << endl;
        p[i].processNo = i+1;
        cout << "Arrival time: ";
        cin >> p[i].arrivalTime;
        cout << "Priority: ";
        cin >> p[i].priority;
        cout << "Burst time: ";
        cin >> p[i].burstTime;
    }

    sort(p, p + n, compare);

    int completionTime = p[0].arrivalTime + p[0].burstTime;
    p[0].completionTime = completionTime;
    p[0].turnAroundTime = completionTime - p[0].arrivalTime;
    p[0].waitingTime = p[0].turnAroundTime - p[0].burstTime;
    p[0].responseTime = p[0].waitingTime;

    for (int i = 1; i < n; i++) {
        completionTime += p[i].burstTime;
        p[i].completionTime = completionTime;
        p[i].turnAroundTime = completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
        p[i].responseTime = p[i-1].completionTime - p[i].arrivalTime;
    }

    cout << "Process No\tArrival Time\tPriority\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].processNo << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].priority << "\t\t" << p[i].burstTime << "\t\t" << p[i].completionTime << "\t\t" << p[i].turnAroundTime << "\t\t" << p[i].waitingTime << "\t\t" << p[i].responseTime << endl;
    }

    return 0;
}
