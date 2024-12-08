#include <stdio.h>
#include <string.h>

// Дати
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Інформація про книгу
typedef struct {
    char code[20];
    char author[50];
    char title[100];
} Book;

// Інформація про читача
typedef struct {
    int ticketNumber;
    char lastName[50];
} Reader;

// Бланк вимоги
typedef struct {
    Book book;
    Reader reader;
    Date orderDate;
} Request;

void inputRequest(Request *request) {
    printf("Введіть шифр книги: ");
    scanf("%s", request->book.code);
    printf("Введіть автора книги: ");
    scanf(" %[^\n]", request->book.author);
    printf("Введіть назву книги: ");
    scanf(" %[^\n]", request->book.title);

    printf("Введіть номер читацького квитка: ");
    scanf("%d", &request->reader.ticketNumber);
    printf("Введіть прізвище читача: ");
    scanf(" %[^\n]", request->reader.lastName);

    printf("Введіть дату замовлення (день місяць рік): ");
    scanf("%d %d %d", &request->orderDate.day, &request->orderDate.month, &request->orderDate.year);
}

void printRequest(const Request *request) {
    printf("\nБланк вимоги на книгу:\n");
    printf("Інформація про книгу:\n");
    printf("  Шифр: %s\n", request->book.code);
    printf("  Автор: %s\n", request->book.author);
    printf("  Назва: %s\n", request->book.title);

    printf("Інформація про читача:\n");
    printf("  Номер читацького квитка: %d\n", request->reader.ticketNumber);
    printf("  Прізвище: %s\n", request->reader.lastName);

    printf("Дата замовлення: %02d.%02d.%d\n",
           request->orderDate.day,
           request->orderDate.month,
           request->orderDate.year);
}

int main() {
    Request request;

    inputRequest(&request);

    printRequest(&request);

    return 0;
}
