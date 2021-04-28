#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 1024 // A double is 8 Bytes so each matrix is 8MB 

volatile double A[N][N];
volatile double B[N][N];
volatile double C[N][N];

void randomise_mats(){
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                        A[i][j] = (double) rand() / (double) RAND_MAX;
                        B[i][j] = (double) rand() / (double) RAND_MAX;
                        C[i][j] = 0.0;
                }
        }

}

void MMM() {
        
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                        for(int k=0; k<N; k++) {
                                C[i][j] += A[i][k] * B[k][j];
                        }
                }
        }

    return;
}


int main() {
        struct timespec t_start, t_end;

        clock_gettime(CLOCK_REALTIME, &t_start); // get the time at the start
        
        MMM();

        clock_gettime(CLOCK_REALTIME, &t_end);

        double expr_time = (t_end.tv_sec - t_start.tv_sec) + (t_end.tv_nsec - t_start.tv_nsec)/1000000000.0;  

        fprintf(stderr, "Experiment time = %f (seconds) \n", expr_time);
}




