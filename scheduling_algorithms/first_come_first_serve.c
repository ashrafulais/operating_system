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

int main() {
    int burst[10] = {8, 5, 7, 8}, arrival[10] = {0, 2, 1, 3}, copyArrival[10];
    int n=4, i, wait_t=0, turnaround_t=0, sum=0;

    copyArray(arrival, copyArrival, n);
    sortByArrival(burst, arrival, n);

    printf("Process  Burst_Time  Arrival_Time  Waiting_Time  Turnaround_Time\n");
    for(i=0; i<n; i++) {
        turnaround_t += burst[i];
        printf("\nP%d %11d %12d %13d %11d\n", copyArrival[i]+1 , burst[i], arrival[i], wait_t, turnaround_t);

        wait_t += burst[i];
        sum += i<=2 ? wait_t : 0;
    }
    printf("\nAverage waiting time: %.2f\n", sum/4.0);

return 0;
}
