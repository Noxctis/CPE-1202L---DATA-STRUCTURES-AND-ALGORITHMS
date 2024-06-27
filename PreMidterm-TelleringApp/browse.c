#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "payment.h"
#include "common.h"

void displayPaymentRecords(LinkedList *list) {
    printf("Record #\tPay Date\tPay Amt\t\tPay ID\t\tPayee\n");
    printf("=============================================================================\n");
    PaymentRecord *current = list->start;
    while (current != NULL) {
        printf("%d\t\t%s\t\t%.2f\t\t%s\t\t%s\n", current->id, current->payDate, current->payAmount, current->idnumber, current->fullName);
        current = current->next;
    }
    printf("\nGrand Total: %.2f\n", calculateTotalAmount(list));
}
