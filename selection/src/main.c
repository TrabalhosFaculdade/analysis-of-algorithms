#include <stdlib.h>
#include <stdio.h>
#include "selection.h"

#define TESTING_QNT 6

activity_t *test_6();
void print_activities(activity_t *activities, int n);

int main()
{
    activity_t *testing_group = test_6();
    selection_t result = select_activities(testing_group, TESTING_QNT);

    printf("List of activities to be selected\n");
    print_activities(testing_group, TESTING_QNT);

    printf("List of selected activities\n");
    print_activities(result.activities, result.n);

    free(testing_group);
    free(result.activities);

    exit(EXIT_SUCCESS);
}

/**
 starting times =  {1, 3, 0, 5, 8, 5}; 
 ending times   =  {2, 4, 6, 7, 9, 9}; 
*/
activity_t *test_6()
{
    activity_t a = {
        .start = 1,
        .end = 2};

    activity_t b = {
        .start = 3,
        .end = 4};

    activity_t c = {
        .start = 0,
        .end = 6};

    activity_t d = {
        .start = 5,
        .end = 7};

    activity_t e = {
        .start = 7,
        .end = 9};

    activity_t f = {
        .start = 5,
        .end = 9};

    activity_t *activities = malloc(sizeof(activity_t) * TESTING_QNT);
    if (activities == NULL)
    {
        fprintf(stderr, "Error while allocating memory for testing activities");
        exit(EXIT_FAILURE);
    }

    activities[0] = a;
    activities[1] = b;
    activities[2] = c;
    activities[3] = d;
    activities[4] = e;
    activities[5] = f;

    return activities;
}

void print_activities(activity_t *activities, int n)
{
    for (int i = 0; i < n; i++)
        printf("start - %d, end - %d\n", activities[i].start, activities[i].end);

    printf("\n");
}