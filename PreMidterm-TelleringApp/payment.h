#ifndef PAYMENT_H_INCLUDED
#define PAYMENT_H_INCLUDED

typedef struct PaymentRecord {
    struct PaymentRecord *prev;
    char fullName[100];
    char payDate[11];
    char idnumber[11];
    float payAmount;
    int id;
    struct PaymentRecord *next;
} PaymentRecord;

// Structure to represent a linked list of payment records
typedef struct {
    int counter;
    PaymentRecord *start;
    PaymentRecord *end;
} LinkedList;

// Function prototypes
PaymentRecord* createPaymentRecord(LinkedList *list, const char *fullName, const char *payDate, float payAmount, const  char *idnumber);
void deletePaymentRecord(LinkedList *list);
void addPaymentRecord(LinkedList *list, const char *fullName, const char *payDate, float payAmount, const char *idnumber);
void deleteFirstPaymentRecord(LinkedList *list);
void displayPaymentRecords(LinkedList *list);
float calculateTotalAmount(LinkedList *list);
LinkedList* createLinkedList();


#endif // PAYMENT_H_INCLUDED
