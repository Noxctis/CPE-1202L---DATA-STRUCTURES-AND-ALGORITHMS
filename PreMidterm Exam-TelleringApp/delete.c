#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "payment.h"
#include "common.h"

void deleteFirstPaymentRecord(LinkedList *list) {
    if (list->start == NULL)
        return;

    PaymentRecord *temp = list->start;
    list->start = list->start->next;
    if (list->start != NULL)
        list->start->prev = NULL;
    free(temp);
    list->counter--;
}
