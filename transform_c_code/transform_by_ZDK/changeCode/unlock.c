#include <stdlib.h>
#include <string.h>
struct pthread_t{};
struct pthread_mutex{};
struct list{};
struct pthread_mutex_t{ int i; };
struct pthread_cond_t{ int i; };
int pthread_mutex_lock(struct pthread_mutex_t* mutex_t){ return 0; }
int pthread_mutex_unlock(struct pthread_mutex_t* mutex_t){ return 0; }
void pthread_cond_wait(struct pthread_cond_t* cond_t, struct pthread_mutex_t* mutex_t);
void pthread_cond_signal(struct pthread_cond_t* cond_t);
void bioCreateBackgroundJob(int type, void *arg1, void *arg2, void *arg3) {
    const int BIO_NUM_OPS=100;
    static struct pthread_t bio_threads[BIO_NUM_OPS];
    static struct pthread_mutex_t bio_mutex[BIO_NUM_OPS];
    static struct pthread_cond_t bio_newjob_cond[BIO_NUM_OPS];
    static struct pthread_cond_t bio_step_cond[BIO_NUM_OPS];
    static struct list *bio_jobs[BIO_NUM_OPS];
    static unsigned long long bio_pending[BIO_NUM_OPS];
    pthread_mutex_lock(&bio_mutex[type]);
    bio_pending[type]++;
    pthread_cond_signal(&bio_newjob_cond[type]);
    pthread_mutex_unlock(&bio_mutex[type]);
}
