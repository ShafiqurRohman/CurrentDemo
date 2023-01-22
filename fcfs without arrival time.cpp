#include <iostream>
using namespace std;

// Structure to store information about a process
struct Process {
    int pid; // Process ID
    int burstTime; // CPU burst time of the process
    int completionTime; // Completion time of the process
    int waitingTime; // Waiting time of the process
    int tatTime;
};

// Function to calculate the waiting time and completion time of processes
void calculateWaitingTime(Process p[], int n) {
    // Calculate completion time for all processes
    p[0].completionTime = p[0].burstTime;
    for (int i = 1; i < n; i++) {
        p[i].completionTime = p[i-1].completionTime + p[i].burstTime;
    }
    for (int i = 0; i < n; i++) {
        p[i].tatTime = p[i].completionTime;
    }
    // Calculate waiting time for the rest of the processes
    p[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i-1].completionTime;
    }
}

// Function to sort the processes by arrival time
void sortByPidTime(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].pid > p[j].pid) {
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
        cout << "Enter burst time for process " << p[i].pid << ": ";
        cin >> p[i].burstTime;
    }
    // Sort the processes by arrival time
    sortByPidTime(p, n);
    // Calculate the waiting time and completion time of the processes
    calculateWaitingTime(p, n);
    // Output the results
    cout << "Process ID\tBurst Time\tCompletion Time\tTAT Time\tWaiting Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t\t" << p[i].burstTime << "\t\t" << p[i].completionTime << "\t\t" << p[i].tatTime<< "\t\t" << p[i].waitingTime<< endl;
    }
    return 0;
}
