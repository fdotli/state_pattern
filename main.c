#include <stdio.h>
#include <stdlib.h>

#include "digital_watch.h"

int main(void)
{
    digital_watch_t *dw = NULL;

    printf("Start your stop watch, extended version\n");

    dw = digital_watch_new();

    digital_watch_stop(dw);
    digital_watch_stop(dw);
    digital_watch_split(dw);

    digital_watch_start(dw);
    digital_watch_start(dw);

    digital_watch_split(dw);
    digital_watch_split(dw);

    digital_watch_stop(dw);

    digital_watch_split(dw);
    digital_watch_start(dw);
    digital_watch_stop(dw);

    digital_watch_del(dw);

    printf("Terminate your stop watch\n");

    return 0;
}


