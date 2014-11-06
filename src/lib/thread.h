#ifndef __thread_h
#define __thread_h

#include <pthread.h>
#include <signal.h>
typedef struct argumentos{
    int id;
    Mat realMap;
    double corr;
    vector<String> letters;
} Arg;
class Thread
{
public:
    Thread(int ( * const entry)(void), Arg *arg) {
    if(pthread_create(&thread, 0, (void*(*)(void*))entry, (void *)arg))
        thread = 0;
    }
    Thread() {

    }
    ~Thread() { pthread_kill(thread, SIGKILL); }

    int join(int * status) { return pthread_join(thread, (void **)status); }
    friend void exit(int status = 0) { pthread_exit((void *) status); }

private:
    pthread_t thread;
};

#endif
