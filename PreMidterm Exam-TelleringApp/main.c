#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "payment.h"
#include "common.h"

int main() {
    LinkedList *paymentList = createLinkedList();
    char choice;
    char again = ' ';
    char deletor = ' ';
    do {
        printf("\n=== PAYMENT RECORD MAIN MENU ===\n");
        printf("[+] Add new payment record\n");
        printf("[-] Delete payment record\n");
        printf("[X] Exit program\n");
        printf("Choice? ");
        scanf(" %c", &choice);
        switch(choice) {
            case '+': {
                do{
                char fullName[100];
                char payDate[11];
                char idnumber[11];
                float payAmount;

                printf("\n=== ADD PAYMENT RECORD ===\n");
                printf("Input ID #: ");
                scanf("%s", idnumber);
                printf("Input payee's full name: ");
                scanf("%s", fullName);
                printf("Input pay date (mm/dd/yyyy): ");
                scanf("%s", payDate);
                printf("Input pay amount: ");
                scanf("%f", &payAmount);
                addPaymentRecord(paymentList, fullName, payDate, payAmount, idnumber);
                printf("\nAgain [Y/N]? ");
                fflush(stdin);
                scanf("%c", &again);
                }while(again != 'N' && again != 'n');
                displayPaymentRecords(paymentList);
                break;
            }
            case '-': {
                printf("\n=== DELETE PAYMENT RECORD ===\n");
                printf("Record #\tPay Date\tPay Amt\t\tPay ID\t\tPayee\n");
                printf("=============================================================================\n");

                PaymentRecord *current = paymentList->start;

                printf("%d\t\t%s\t\t%.2f\t\t%s\t\t%s\n", current->id, current->payDate, current->payAmount, current->idnumber, current->fullName);
                current = current->next;
                printf("\nWARNING - the record above will be deleted!");
                printf("\nProceed [y/n]? ");
                fflush(stdin);
                scanf("%c", &deletor);
                if(deletor != 'N' && deletor != 'n'){
                    if (paymentList->counter > 0) {
                        deleteFirstPaymentRecord(paymentList);
                        printf("Payment record deleted successfully.\n");
                    if (paymentList->counter > 0)
                        displayPaymentRecords(paymentList);
                    } else {
                        printf("No payment records to delete.\n");
                        }
                    }
                break;
            }
            case 'X':
            case 'x':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'X' && choice != 'x');

    // Free allocated memory
    while (paymentList->counter > 0) {
        deleteFirstPaymentRecord(paymentList);
    }
    free(paymentList);

    return 0;
}

PaymentRecord* createPaymentRecord(LinkedList *list, const char *fullName, const char *payDate, float payAmount, const char *idnumber) {
    PaymentRecord *newRecord = (PaymentRecord *)malloc(sizeof(PaymentRecord));
    if (newRecord == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newRecord->fullName, fullName);
    strcpy(newRecord->payDate, payDate);
    strcpy(newRecord->idnumber, idnumber);
    newRecord->payAmount = payAmount;
    newRecord->id = ++list->counter;
    newRecord->prev = NULL;
    newRecord->next = NULL;

    return newRecord;
}

LinkedList* createLinkedList() {
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    if (l == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    l->counter = 0;
    l->start = NULL;
    l->end = NULL;
    return l;
}

