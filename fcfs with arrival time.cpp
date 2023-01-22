#include <iostream>
using namespace std;

// Structure to store information about a process
struct Process {
    int pid; // Process ID
    int arrivalTime; // Arrival time of the process
    int burstTime; // CPU burst time of the process
    int completionTime; // Completion time of the process
    int waitingTime; // Waiting time of the process
    int tatTime;
};

// Function to calculate the waiting time and completion time of processes
void calculateWaitingTime(Process p[], int n) {
    // Waiting time for the first process is 0
    p[0].waitingTime = 0;
    // Calculate waiting time for the rest of the processes
    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i - 1].burstTime + p[i - 1].waitingTime;
    }
    // Calculate completion time for all processes
    for (int i = 0; i < n; i++) {
        p[i].completionTime = p[i].burstTime + p[i].waitingTime;
    }
    for (int i = 0; i < n; i++) {
        p[i].tatTime = p[i].completionTime + p[i].arrivalTime;
    }
}

// Function to sort the processes by arrival time
void sortByArrivalTime(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrivalTime > p[j].arrivalTime) {
                swap(p[i], p[j]);
            }
        }
    }
}

int main() {
    // Number of processes
    int n;
    cout << "Enter the number of process : ";
    cin >> n;
    Process p[n];
    // Input the arrival time and burst time of each process
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter arrival time for process " << p[i].pid << ": ";
        cin >> p[i].arrivalTime;
        cout << "Enter burst time for process " << p[i].pid << ": ";
        cin >> p[i].burstTime;
    }
    // Sort the processes by arrival time
    sortByArrivalTime(p, n);
    // Calculate the waiting time and completion time of the processes
    calculateWaitingTime(p, n);
    // Output the results
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTAT Time\tWaiting Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].burstTime << "\t\t" << p[i].completionTime << "\t\t" << p[i].tatTime<< "\t\t" << p[i].waitingTime<< endl;
    }
    return 0;
}
