#include<stdio.h>

void sort_data(int process[], int burst[], int n) {
    int i, j, temp1, temp2;

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j && burst[i]<burst[j]) {
                temp1 = burst[i];
                burst[i] = burst[j];
                burst[j] = temp1;

                temp2 = process[i];
                process[i] = process[j];
                process[j] = temp2;
            }
        }
    }
}

int main() {

    int burst[10] = {10, 12, 3, 11}, process[10]={0, 1, 2, 3};
    int i, wait_t=0, turn_t=0, n=4;
    float avg_wait=0;

    sort_data(process, burst, n);

    printf("process burst waiting turnaround\n");
    for(i=0; i<n; i++) {
        if(i>0) wait_t += burst[i-1];
        turn_t = wait_t + burst[i];
        printf("%2d %8d %6d %7d\n", process[i], burst[i], wait_t, turn_t);

        avg_wait += wait_t;
    }
    printf("Average waiting time: %.2f\n", avg_wait/n*1.0);

return 0;
}
