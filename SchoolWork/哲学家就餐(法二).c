#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<errno.h>

int philosophers[5] = {0,1,2,3,4}; //哲学家
pthread_mutex_t chopsticks[5]; //互斥量

void think(void);
void eat(void);
void *philosopher(void*);

int main(){
	srand(time(NULL));
	pthread_t philo[5]; //线程
				
	for(int i=0;i<5;i++){
		pthread_mutex_init(&chopsticks[i],NULL);
	} //初始化互斥量

	for(int i=0;i<5;i++){
		pthread_create(&philo[i],NULL,philosopher,(void *)&philosophers[i]);
	} //创建线程

	for(int i=0;i<5;i++){
		pthread_join(philo[i],NULL);
	} //汇合线程

	for(int i=0;i<5;i++){
		pthread_mutex_destroy(&chopsticks[i]);
	}

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

		loop: pthread_mutex_lock(&chopsticks[id]);
		if(pthread_mutex_trylock(&chopsticks[(id+1)%5]) == EBUSY){
			pthread_mutex_unlock(&chopsticks[id]);
			goto loop;
		}

		printf("philosopher %d is eating\n",id);
		eat();

		printf("philosopher %d finished eating\n",id);
		pthread_mutex_unlock(&chopsticks[id]);
		pthread_mutex_unlock(&chopsticks[(id+1)%5]);

	}
}
