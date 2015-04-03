typedef struct digital_watch digital_watch_t;

digital_watch_t * digital_watch_new(void);

void              digital_watch_del(digital_watch_t * watch);

void              digital_watch_start(digital_watch_t * watch);

void              digital_watch_stop(digital_watch_t * watch);

void              digital_watch_split(digital_watch_t * watch);

