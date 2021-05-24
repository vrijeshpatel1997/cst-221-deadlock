// Vrijesh patel
// CST 221
// 5/23/21
// This is my own work


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <pthread.h>


#define THREADNUM 8

pthread_mutex_t fuelmutex;


int fuel = 50;

pthread_mutex_t watermutex;
 int water = 10;

void* fillgas(void* args){

  if(rand() % 2 == 0){
    pthread_mutex_lock(&fuelmutex);
        sleep(1);
      pthread_mutex_lock(&watermutex);



  }else{

    pthread_mutex_lock(&watermutex);
        sleep(1);
      pthread_mutex_lock(&fuelmutex);
  }

fuel+= 50; // add gas
water = fuel;
printf("Increased fuel to %d and set water to %d\n", fuel, water );

pthread_mutex_unlock(&fuelmutex);
  pthread_mutex_unlock(&watermutex);



}

int main(int argc, char *argv[]){

  pthread_t th[THREADNUM];
  pthread_mutex_init(&fuelmutex, NULL);
  pthread_mutex_init(&watermutex, NULL);
  int i;

  for(i = 0; i < THREADNUM; i++){

    if(pthread_create(&th[i], NULL, &fillgas, NULL) != 0){

      perror("failed  to create thread");
    }
  }

  for(i = 0; i < THREADNUM; i++){

    if(pthread_join(th[i], NULL) != 0){

      perror("failed  to joun thread");
    }
  }

  printf("fuel %d\n", fuel );

    printf("water %d\n", water );
  pthread_mutex_destroy(&fuelmutex);
    pthread_mutex_destroy(&watermutex);
  return 0;
}
