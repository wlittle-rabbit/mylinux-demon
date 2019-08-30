/*互斥锁是唯一的，只能被一个线程锁定。第二个线程只能等待第一个线程解锁后，再获取互斥锁，等待期间第二个线程被挂起。*/
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
struct source{
	char name[20];
	int len;
}sou;
pthread_mutex_t lock;
sem_t sem;
void pthread0();
void pthread1(int a);
void pthread0()
{
	int count=3;
	while(count>0){
		printf("pthread0\n");
		sem_post(&sem);
		sleep(2);
		count--;
	}
}
void pthread1(int a)
{	
	int b;
	b=a;
	while(b>0){
		sem_wait(&sem);
		printf("pthread1,time left=%d\n",b);
		sleep(2);
		b--;
	}
}
void pthread2()
{
	while(1){
	printf("thread2\n");	
	pthread_mutex_lock(&lock);
	sleep(2);
	printf("thread2-1\n");
	sleep(2);
	printf("thread2-2\n");
	sleep(2);
	printf("thread2-3\n");
	pthread_mutex_unlock(&lock);
	sleep(2);
	}
}
void pthread3()
{
	while(1){
	pthread_mutex_lock(&lock);
	printf("thread3\n");
	sleep(1);
	pthread_mutex_unlock(&lock);
	sleep(2);
	}
}
int main()
{
	pthread_t id0;
	pthread_t id1;
	int i=2;
	pthread_mutex_init(&lock,NULL);	
//	sem_init(&sem,0,0);
//	pthread_create(&id0,NULL,(void *)pthread0,NULL);
//	pthread_create(&id1,NULL,(void *)pthread1,i);
	pthread_create(&id0,NULL,(void *)pthread2,NULL);
	pthread_create(&id1,NULL,(void *)pthread3,i);

	pthread_join(id0,NULL);
	pthread_mutex_destroy(&lock);
	pthread_join(id1,NULL);
//	sem_destroy(&sem);
	return 0;
}
