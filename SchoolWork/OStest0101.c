#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

sem_t chopsticks[5]; //信号量
int philosophers[5] = {0,1,2,3,4}; //哲学家
pthread_mutex_t mutex; //互斥量

void think(void);
void eat(void);
void *philosopher(void*);

int main(){
	srand(time(NULL));
	pthread_t philo[5]; //线程
	
	for(int i=0;i<5;i++){
		sem_init(&chopsticks[i],0,1);
	} //初始化信号量

	pthread_mutex_init(&mutex,NULL); //初始化互斥量

	for(int i=0;i<5;i++){
		pthread_create(&philo[i],NULL,philosopher,(void *)&philosophers[i]);
	} //创建线程

	for(int i=0;i<5;i++){
		pthread_join(philo[i],NULL);
	} //汇合线程

	for(int i=0;i<5;i++){
		sem_destroy(&chopsticks[i]);
	}

	pthread_mutex_destroy(&mutex);

	return 0;
}

void think(void){
	int i = rand()%3;
	sleep(i);
}

void eat(void){
	int i = rand()%2;
	sleep(i);
}

void *philosopher(void* threadid){
	int id = *((int *)threadid);
	for(int i=0;i<3;i++){
		printf("philosopher %d is thinking\n",id);
		think();

		printf("philosopher %d is hungry\n",id);

		pthread_mutex_lock(&mutex);
		sem_wait(&chopsticks[id]);
		sem_wait(&chopsticks[(id+1)%5]);
		pthread_mutex_unlock(&mutex);

		printf("philosopher %d is eating\n",id);
		eat();

		printf("philosopher %d finished eating\n",id);

		sem_post(&chopsticks[id]);
		sem_post(&chopsticks[(id+1)%5]);
	}
}
