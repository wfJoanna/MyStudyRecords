#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

FILE *fp;
char buffer[10];
int in = 0,out = 0;
sem_t empty,full;
pthread_mutex_t mutex;

void *producer(void*);
void *consumer(void*);

int main(){
	pthread_t p[3];
	pthread_t c[2];

	sem_init(&empty,0,10);
	sem_init(&full,0,0);
	pthread_mutex_init(&mutex,NULL);

	fp = fopen("./source.txt","r");
	for(int i=0;i<3;i++){
		pthread_create(&p[i],NULL,producer,(void *)&i);
	}
	for(int i=0;i<2;i++){
		pthread_create(&c[i],NULL,consumer,(void *)&i);
	}
	
	for(int i=0;i<3;i++){
		pthread_join(p[i],NULL);
	}
	for(int i=0;i<2;i++){
	        pthread_join(c[i],NULL);
	}

	fclose(fp);
	sem_destroy(&empty);
	sem_destroy(&full);
	pthread_mutex_destroy(&mutex);
	return 0;
}

void *producer(void *threadid){
	int id = *((int *)threadid);
	for(int i=0;i<6;i++){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		fscanf(fp,"%c",&buffer[in]);
		printf("producer%d生产\'%c\',缓冲区位置%d\n",id,buffer[in],in);
		in = (in+1)%10;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);	
	}
}

void *consumer(void* threadid){
	int id = *((int *)threadid);
	for(int i=0;i<6;i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		printf("consumer%d消费\'%c\',缓冲区位置%d\n",id,buffer[out],out);
		buffer[out] = 0;
		out = (out+1)%10;
		pthread_mutex_unlock(&mutex);	
		sem_post(&empty);
	}
}
