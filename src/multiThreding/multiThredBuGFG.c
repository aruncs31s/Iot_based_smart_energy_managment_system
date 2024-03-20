/* Source : https://www.geeksforgeeks.org/multithreading-in-c/ */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *energy_mangement();
void *solar_tracking();
void *energy_monitoring();

void *myThreadFun(void *vargp) {
  sleep(2);
  printf("Printing GeeksQuiz from Thread \n");
  return NULL;
}

void *energy_mangement(void *thread_id_energy_management) {

  printf("\n Energy Management id : %d,"((int *)thread_id_energy_management));
  return NULL;
}

void *solar_tracking(void *thread_id_solar_tracking) {
  long *thread_id_solar_tracking = (long *)(thread_id_solar_tracking);
  printf("\nSolar Tracking id %d ", *thread_id_solar_tracking);
  return NULL;
}
void *energy_monitoring() { return NULL; }

int main() {

  pthread_t thread_id_energy_management;
  pthread_t thread_id_solar_tracking;
  pthread_t thread_id_energy_monitoring;

  printf("Before Thread\n");

  pthread_create(&thread_id_energy_management, NULL, energy_mangement,
                 (void *)&thread_id_energy_management);
  pthread_create(&thread_id_solar_tracking, NULL, solar_tracking,
                 (void *)thread_id_energy_management);

  pthread_join(thread_id_energy_management, NULL);
  pthread_join(thread_id_solar_tracking, NULL);
  printf("After Thread\n");
  exit(0);
}
