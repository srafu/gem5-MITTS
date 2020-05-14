#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]){

    omp_set_num_threads(2);
    #pragma omp parallel
    {
        if(omp_get_thread_num()){
            system("gcc testFile0.c -o test0");
        } else {
            system("gcc testFile1.c -o test1");
        }
    }

    return 0;
}