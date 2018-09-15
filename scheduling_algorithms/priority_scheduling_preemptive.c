#include<stdio.h>

int wait[10];

int array_sum(int a[], int n) {
    int s=0;
    n--;
    while(n>=0)
        s+= a[n],n--;
    return s;
}

void show_data(int p[], int bt[], int at[], int pr[], int n) {
    int i, sum=0;
    printf("process burst arrival priority waiting \n");
    for(i=0; i<n; i++) {
        sum += wait[i];
        printf("%2d %8d %6d %7d %8d\n", p[i], bt[i], at[i], pr[i], wait[i]);
    }
    printf("Average waiting time: %.2f\n", sum/(n*1.0));
}
int main() {

    int process[10]={0, 1, 2, 3} , burst[10]={7, 10, 2, 6}, arrival[10]={0, 2, 4, 7}, priority[10]={2, 3, 1, 4};
    int process2[10]={0, 1, 2, 3} , burst2[10]={7, 10, 2, 6}, arrival2[10]={0, 2, 4, 7}, priority2[10]={2, 3, 1, 4};
    int i, j, n=4;
    int time=array_sum(burst, n);


    int t, smallest, mn=99999;
    smallest=0;

    printf("Preemptive - Priority scheduling\n\n");
    for(t=0; t<time; t++) {

        for(j=0; j<n; j++) {
            if(arrival[j]<=t && priority[j]<mn && burst[j]>0) {
                mn = priority[j];
                smallest = j;
            }
        }
        //waiting = ending-arrival-burst
        burst[smallest]--;

        //printf("P%d  %d\n",smallest, t+1);
        mn = 99999;
        if (burst[smallest]==0) {
                wait[smallest] = (t+1)-arrival2[smallest]-burst2[smallest];
        }

    }



    show_data(process, burst, arrival, priority, n);


return 0;
}
