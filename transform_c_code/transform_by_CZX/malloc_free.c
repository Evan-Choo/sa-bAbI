#include <stdlib.h>
#include <string.h>
struct pthread_mutex_t{ int i; };
struct pthread_cond_t{ int i; };
int pthread_mutex_lock(struct pthread_mutex_t* mutex_t){ return 0; }
int pthread_mutex_unlock(struct pthread_mutex_t* mutex_t){ return 0; }
void pthread_cond_wait(struct pthread_cond_t* cond_t, struct pthread_mutex_t* mutex_t);
void pthread_cond_signal(struct pthread_cond_t* cond_t);
struct aeApiState {int epfd;char *events;} aeApiState;
int main() {
    const int _MAX_PATH = 10;

    char *string;
 
   /* Allocate space for a path name */
   string = malloc( _MAX_PATH );
 
   // In a C++ file, explicitly cast malloc's return.  For example, 
   // string = (char *)malloc( _MAX_PATH );
 
      string = "0";
      free( string );
    return 0;
}
