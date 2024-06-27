#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "payment.h"
#include "common.h"

float calculateTotalAmount(LinkedList *list) {
    float total = 0;
    PaymentRecord *current = list->start;
    while (current != NULL) {
        total += current->payAmount;
        current = current->next;
    }
    return total;
}
