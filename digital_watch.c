#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "digital_watch.h"

struct watch_state;

typedef void (* event_func)(struct watch_state *);

struct watch_state
{
    event_func start;
    event_func stop;
    event_func split;
};

typedef struct watch_state watch_state_t;

static void start(watch_state_t * state);
static void stop(watch_state_t * state);
static void split(watch_state_t * state);

typedef struct concrete_watch_state
{
    watch_state_t state;
    char * name;
} concrete_watch_state_t;

/*
                +---------+
                |         |
     +-stop-----> stopped |
     |          |         |
+----+-----+    +-+----^--+
|          |      |    |   
| splitted |    start stop 
|          |      +    +   
+----^-----+    +-v----+--+
     |          |         |
     +-split+---+ started |
                |         |
                +---------+
*/
                
concrete_watch_state_t stopped_state = {{start, NULL, NULL}, "stopped"};

concrete_watch_state_t started_state = {{NULL, stop, split}, "started"};

concrete_watch_state_t splited_state = {{NULL, stop, NULL}, "splited"}; 

static void start(watch_state_t * state)
{
    unsigned int secs = 5;
    unsigned int i = 0;

    /* Do some work here to stop*/
    for(i = 0; i < secs; i++) {    
        sleep(1);
        printf("Startting the stopwatch ...%u\n", i);
    }
}

static void stop(watch_state_t * state)
{
    unsigned int secs = 5;
    unsigned int i = 0;

    /* Do some work here to stop*/
    for(i = 0; i < secs; i++) {    
        sleep(1);
        printf("Stopping the stopwatch ...%u\n", i);
    }
}

static void split(watch_state_t * state)
{
    unsigned int secs = 5;
    unsigned int i = 0;

    /* Do some work here to stop*/
    for(i = 0; i < secs; i++) {    
        sleep(1);
        printf("Splitting the stopwatch ...%u\n", i);
    }
}

struct digital_watch
{
    concrete_watch_state_t * state;
    int           time;
};

digital_watch_t * digital_watch_new(void)
{
    digital_watch_t * watch;

    watch = malloc(sizeof(*watch));

    watch->state = &stopped_state;
    watch->time  = 0;

    return watch;
}

void digital_watch_del(digital_watch_t * watch)
{
    watch->state = NULL;
    watch->time  = 0;
}

void digital_watch_start(digital_watch_t * watch)
{
    if (watch->state->state.start)
    {
        watch->state->state.start(&watch->state->state);
        watch->state = &started_state;
    }

    printf("[ %s ] state [ %s ] time [ %d ]\n", __func__, watch->state->name, watch->time);
}

void digital_watch_stop(digital_watch_t * watch)
{
    if (watch->state->state.stop)
    {
        watch->state->state.stop(&watch->state->state);
        watch->state = &stopped_state;
    }

    printf("[ %s ] state [ %s ] time [ %d ]\n", __func__, watch->state->name, watch->time);
}

void digital_watch_split(digital_watch_t * watch)
{
    if (watch->state->state.split)
    {
        watch->state->state.split(&watch->state->state);
        watch->state = &splited_state;
    }

    printf("[ %s ] state [ %s ] time [ %d ]\n", __func__, watch->state->name, watch->time);
}

