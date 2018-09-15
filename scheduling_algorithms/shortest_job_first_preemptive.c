#include<stdio.h>

int wait[10];// stack of executed process

int array_sum(int a[], int n) {
    int s=0;
    n--;
    while(n>=0)
        s+= a[n],n--;
    return s;
}

void show_data(int process[], int arrival[], int burst[], int n) {
    int i, sum=0;
    printf("process arrival burst waiting \n");
    for(i=0; i<n; i++) {
        sum += wait[i];
        printf("%2d %8d %7d %6d\n", process[i], arrival[i], burst[i], wait[i]);

    }
    printf("Average waiting time: %.2f\n", sum/(n*1.0));
}
int main() {

    int process[10]={0, 1, 2, 3}, arrival[10]={0, 2, 4, 7}, burst[10] = {7, 10, 2, 6};
    int process2[10]={0, 1, 2, 3}, arrival2[10]={0, 2, 4, 7}, burst2[10] = {7, 10, 2, 6};
    int i, wait_t=0, n=4, j=0;

    //considering sorted arrival time
    int time=array_sum(burst, n);


    int k=0, select, t, smallest, mn=99999;
    i=0;
    smallest=i;
    int tt=0;

    printf("Preemptive - Shortest Job First\n\n");
    for(t=0; t<time; t++) {

        for(j=0; j<n; j++) {
            if(arrival[j]<=t && burst[j]<mn && burst[j]>0) {
                mn = burst[j];
                smallest = j;
            }
        }

        //printf("min: %d small:%d time:%d\n", mn, smallest, t+1);

        //decrement burst time
        //waiting = ending-arrival-burst
        burst[smallest]--;

        //printf("P%d  %d\n",smallest, t+1);
        mn = 99999;
        if (burst[smallest]==0) {
                //printf("\n-P%d T%d BT%d AT%d %d-\n",smallest, t+1, burst2[smallest], arrival2[smallest],(t+1)-arrival2[smallest]-burst2[smallest]);
                wait[smallest] = (t+1)-arrival2[smallest]-burst2[smallest];
        }

    }



    show_data(process, arrival, burst, n);
return 0;
}
