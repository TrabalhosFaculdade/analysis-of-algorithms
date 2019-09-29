#ifndef SELECTION
#define SELECTION

typedef struct
{
    int start;
    int end;
} activity_t;

typedef struct
{
    activity_t *activities;
    int n;
} selection_t;

selection_t select_activities(activity_t *activities, int n);

#endif