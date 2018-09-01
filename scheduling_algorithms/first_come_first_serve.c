#include<stdio.h>

void copyArray(int a[], int b[], int n) {
    int i;
    for(i=0; i<n; i++) {
        b[i] = a[i];
    }
}
void sortByArrival(int burst[], int arrival[], int n) {
    int i, j, temp1, temp2, val;

    //linear sorting :P lol
    for(i=0; i<n; i++) {
        for(j=i; j<n; j++) {
            if(arrival[i]>arrival[j] && i!=j) {
                //Writing bad code now coz
                //got an issue with swap function

                //swap(arrival[i], arrival[j]);
                temp1 = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp1;

                //swap(burst[i], burst[j]);
                temp2 = burst[i];
                burst[i] = burst[j];
                burst[j] = temp2;
            }
        }
    }

}

int wt[10];
int main() {
    int burst[10] = {8, 5, 7, 4}, arrival[10] = {0, 2, 1, 3}, copyArrival[10];
    int n=4, i, turnaround_t=0, sum=0, ws=0;

    //copy array for keeping track of processes
    copyArray(arrival, copyArrival, n);

    sortByArrival(burst, arrival, n);

    for(i=0; i<n; i++) {
        wt[i] = ws;
        ws += burst[i];
        if(i>0) wt[i] -= arrival[i];
    }

    printf("Process  Burst_Time  Arrival_Time  Waiting_Time  Turnaround_Time\n");
    for(i=0; i<n; i++) {
        turnaround_t = burst[i] + wt[i];
        printf("\nP%d %11d %12d %13d %11d\n", copyArrival[i]+1 , burst[i], arrival[i], wt[i], turnaround_t);

        sum += wt[i];
    }
    printf("\nAverage waiting time: %.2f\n", sum/(n*1.0));

return 0;
}
