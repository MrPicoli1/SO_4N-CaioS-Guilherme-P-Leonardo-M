#include <iostream.h>;
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

int thread_count;

void *Pth_mat_vect(void* rank);

int main(int argc, char* argv[]){
	long thread = 0;
        pthread_t* thread_handles;

        thread_count = strtol(argv[1], NULL, 10);

        thread_handles = malloc(thread_count * sizeof(pthread_t));

        for (thread = 0; thread < thread_count; thread++){
                pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
        }

        printf("Matriz Y:\n");

        for (thread = 0; thread < thread_count; thread++){
                pthread_join(thread_handles[thread], NULL);
        }

        free(thread_handles);

        return 0;
}

void *Pth_mat_vect(void* rank){
        long my_rank = (long) rank;
        int i, j;
        int local_m = m / thread_count;
        int my_first_row = my_rank * local_m;
        int my_last_row = (my_rank + 1) * local_m - 1;
        
        for (i = my_first_row; i <= my_last_row; i++){
                y[i] = 0.0;
                
                for (j = 0; j < n; j++){
                        y[i] += A[i][j] * x[j];
                }       
        }       
        
        return NULL;
}
