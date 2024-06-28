#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "payment.h"
#include "common.h"



void addPaymentRecord(LinkedList *list, const char *fullName, const char *payDate, float payAmount, const char *idnumber) {
    PaymentRecord *newRecord = createPaymentRecord(list, fullName, payDate, payAmount, idnumber);
    if (list->start == NULL) {
        list->start = newRecord;
        list->end = newRecord;
    } else {
        list->end->next = newRecord;
        newRecord->prev = list->end;
        list->end = newRecord;
    }
}
