#include <iostream>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
};

bool compare(Process a, Process b) {
    return a.arrival_time < b.arrival_time;
}

int main() {
    int n, time_quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> time_quantum;
    Process processes[n];
    cout << "Enter the arrival time and burst time for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        processes[i].id = i + 1;
        cin >> processes[i].arrival_time >> processes[i].burst_time;
    }
    sort(processes, processes + n, compare);
    int completion_time[n], turn_around_time[n], waiting_time[n], response_time[n];
    int current_time = 0, remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = false;
                if (remaining_time[i] > time_quantum) {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                } else {
                    current_time = current_time + remaining_time[i];
                    completion_time[i] = current_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == true) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = completion_time[i] - processes[i].arrival_time;
        waiting_time[i] = turn_around_time[i] - processes[i].burst_time;
        response_time[i] = waiting_time[i];
    }
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].arrival_time << "\t\t" << processes[i].burst_time << "\t\t" << completion_time[i] << "\t\t" << turn_around_time[i] << "\t\t\t" << waiting_time[i] << "\t\t\t" << response_time[i] << endl;
    }
    return 0;
}
