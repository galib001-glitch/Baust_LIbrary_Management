#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/// ---------- Structures ---------- ///
typedef struct {
    int id;
    char title[50];
    char author[50];
    char category[30];
    int quantity;
} Book;

typedef struct {
    int id;
    char name[50];
    char department[30];
} Student;

typedef struct {
    int id;
    char name[50];
    char department[30];
} Teacher;

typedef struct {
    int id;
    char brand[30];
    char status[10]; // Available / In Use
} Computer;

typedef struct {
    int bookID;
    int studentID;
    char issueDate[11];  // dd/mm/yyyy
    char returnDate[11]; // dd/mm/yyyy or "N/A"
} Transaction;

/// ---------- File Names ---------- ///
#define BOOK_FILE "books.dat"
#define STUDENT_FILE "students.dat"
#define TEACHER_FILE "teachers.dat"
#define COMPUTER_FILE "computers.dat"
#define TRANSACTION_FILE "transactions.dat"

/// ---------- Function Prototypes ---------- ///
void bookMenu();
void studentMenu();
void teacherMenu();
void computerMenu();
void issueMenu();
void reportMenu();

void addBook();
void viewBooks();
void searchBook();
void addStudent();
void viewStudents();
void addTeacher();
void viewTeachers();
void addComputer();
void viewComputers();
void issueBook();
void returnBook();
void viewIssuedBooks();
void reportAvailableBooks();
void reportIssuedBooks();

int authenticate();

/// ---------- Utility Functions ---------- ///
void clearScreen() {
    system("cls||clear");
}

char *currentDate() {
    static char dateStr[11];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateStr, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    return dateStr;
}

/// ---------- BOOK FUNCTIONS ---------- ///
void addBook() {
    FILE *fp = fopen(BOOK_FILE, "ab");
    Book b;

    printf("\nEnter Book ID: "); scanf("%d", &b.id); getchar();
    printf("Enter Title: "); fgets(b.title, sizeof(b.title), stdin); b.title[strcspn(b.title, "\n")] = 0;
    printf("Enter Author: "); fgets(b.author, sizeof(b.author), stdin); b.author[strcspn(b.author, "\n")] = 0;
    printf("Enter Category: "); fgets(b.category, sizeof(b.category), stdin); b.category[strcspn(b.category, "\n")] = 0;
    printf("Enter Quantity: "); scanf("%d", &b.quantity);

    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);
    printf("\n✅ Book Added Successfully!\n");
}

void viewBooks() {
    FILE *fp = fopen(BOOK_FILE, "rb");
    Book b;
    printf("\n📚 --- Book List ---\n");
    printf("%-5s %-20s %-15s %-15s %-5s\n", "ID", "Title", "Author", "Category", "Qty");
    printf("-------------------------------------------------------------\n");
    while (fread(&b, sizeof(Book), 1, fp)) {
        printf("%-5d %-20s %-15s %-15s %-5d\n", b.id, b.title, b.author, b.category, b.quantity);
    }
    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen(BOOK_FILE, "rb");
    Book b;
    int id, found = 0;
    printf("\nEnter Book ID to search: "); scanf("%d", &id);
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            printf("\n✅ Book Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nCategory: %s\nQuantity: %d\n",
                   b.id, b.title, b.author, b.category, b.quantity);
            found = 1; break;
        }
    }
    if (!found) printf("\n❌ Book not found!\n");
    fclose(fp);
}

/// ---------- STUDENT FUNCTIONS ---------- ///
void addStudent() {
    FILE *fp = fopen(STUDENT_FILE, "ab");
    Student s;
    printf("\nEnter Student ID: "); scanf("%d", &s.id); getchar();
    printf("Enter Name: "); fgets(s.name, sizeof(s.name), stdin); s.name[strcspn(s.name, "\n")] = 0;
    printf("Enter Department: "); fgets(s.department, sizeof(s.department), stdin); s.department[strcspn(s.department, "\n")] = 0;

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("\n✅ Student Added Successfully!\n");
}

void viewStudents() {
    FILE *fp = fopen(STUDENT_FILE, "rb");
    Student s;
    printf("\n🎓 --- Student List ---\n");
    printf("%-5s %-20s %-15s\n", "ID", "Name", "Department");
    printf("--------------------------------------\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("%-5d %-20s %-15s\n", s.id, s.name, s.department);
    }
    fclose(fp);
}

/// ---------- TEACHER FUNCTIONS ---------- ///
void addTeacher() {
    FILE *fp = fopen(TEACHER_FILE, "ab");
    Teacher t;
    printf("\nEnter Teacher ID: "); scanf("%d", &t.id); getchar();
    printf("Enter Name: "); fgets(t.name, sizeof(t.name), stdin); t.name[strcspn(t.name, "\n")] = 0;
    printf("Enter Department: "); fgets(t.department, sizeof(t.department), stdin); t.department[strcspn(t.department, "\n")] = 0;

    fwrite(&t, sizeof(Teacher), 1, fp);
    fclose(fp);
    printf("\n✅ Teacher Added Successfully!\n");
}

void viewTeachers() {
    FILE *fp = fopen(TEACHER_FILE, "rb");
    Teacher t;
    printf("\n👨‍🏫 --- Teacher List ---\n");
    printf("%-5s %-20s %-15s\n", "ID", "Name", "Department");
    printf("--------------------------------------\n");
    while (fread(&t, sizeof(Teacher), 1, fp)) {
        printf("%-5d %-20s %-15s\n", t.id, t.name, t.department);
    }
    fclose(fp);
}

/// ---------- COMPUTER FUNCTIONS ---------- ///
void addComputer() {
    FILE *fp = fopen(COMPUTER_FILE, "ab");
    Computer c;
    printf("\nEnter Computer ID: "); scanf("%d", &c.id); getchar();
    printf("Enter Brand: "); fgets(c.brand, sizeof(c.brand), stdin); c.brand[strcspn(c.brand, "\n")] = 0;
    strcpy(c.status, "Available");

    fwrite(&c, sizeof(Computer), 1, fp);
    fclose(fp);
    printf("\n✅ Computer Added Successfully!\n");
}

void viewComputers() {
    FILE *fp = fopen(COMPUTER_FILE, "rb");
    Computer c;
    printf("\n💻 --- Computer List ---\n");
    printf("%-5s %-15s %-10s\n", "ID", "Brand", "Status");
    printf("--------------------------------\n");
    while (fread(&c, sizeof(Computer), 1, fp)) {
        printf("%-5d %-15s %-10s\n", c.id, c.brand, c.status);
    }
    fclose(fp);
}

/// ---------- ISSUE/RETURN SYSTEM ---------- ///
void issueBook() {
    FILE *fpBook = fopen(BOOK_FILE, "rb+");
    FILE *fpTran = fopen(TRANSACTION_FILE, "ab");

    Transaction tr;
    int id, found = 0;
    Book b;

    printf("\nEnter Book ID to issue: "); scanf("%d", &id);
    printf("Enter Student ID: "); scanf("%d", &tr.studentID);

    while (fread(&b, sizeof(Book), 1, fpBook)) {
        if (b.id == id) {
            found = 1;
            if (b.quantity > 0) {
                b.quantity--;
                fseek(fpBook, -(long)sizeof(Book), SEEK_CUR);  // ✅ FIXED CAST
                fwrite(&b, sizeof(Book), 1, fpBook);

                tr.bookID = id;
                strcpy(tr.issueDate, currentDate());
                strcpy(tr.returnDate, "N/A");
                fwrite(&tr, sizeof(Transaction), 1, fpTran);

                printf("\n✅ Book Issued Successfully on %s\n", tr.issueDate);
            } else {
                printf("\n❌ No copies left!\n");
            }
            break;
        }
    }

    if (!found) printf("\n❌ Book not found!\n");

    fclose(fpBook);
    fclose(fpTran);
}

void returnBook() {
    FILE *fpBook = fopen(BOOK_FILE, "rb+");
    FILE *fpTran = fopen(TRANSACTION_FILE, "rb+");

    int studentID, bookID, found = 0;
    Book b;
    Transaction tr;

    printf("\nEnter Student ID: "); scanf("%d", &studentID);
    printf("Enter Book ID to return: "); scanf("%d", &bookID);

    while (fread(&tr, sizeof(Transaction), 1, fpTran)) {
        if (tr.studentID == studentID && tr.bookID == bookID && strcmp(tr.returnDate, "N/A") == 0) {
            found = 1;
            strcpy(tr.returnDate, currentDate());
            fseek(fpTran, -(long)sizeof(Transaction), SEEK_CUR);  // ✅ FIXED CAST
            fwrite(&tr, sizeof(Transaction), 1, fpTran);

            rewind(fpBook);
            while (fread(&b, sizeof(Book), 1, fpBook)) {
                if (b.id == bookID) {
                    b.quantity++;
                    fseek(fpBook, -(long)sizeof(Book), SEEK_CUR);  // ✅ FIXED CAST
                    fwrite(&b, sizeof(Book), 1, fpBook);
                    break;
                }
            }

            printf("\n✅ Book Returned on %s\n", tr.returnDate);
            printf("⚠ Fine calculation: (for demo) 5 Taka/day late if overdue.\n");
            break;
        }
    }

    if (!found) printf("\n❌ Transaction not found or book already returned!\n");

    fclose(fpBook);
    fclose(fpTran);
}

void viewIssuedBooks() {
    FILE *fpTran = fopen(TRANSACTION_FILE, "rb");
    Transaction tr;
    printf("\n📦 --- Issued Books ---\n");
    printf("%-10s %-10s %-12s %-12s\n", "BookID", "StudentID", "IssueDate", "ReturnDate");
    printf("------------------------------------------------\n");
    while (fread(&tr, sizeof(Transaction), 1, fpTran)) {
        printf("%-10d %-10d %-12s %-12s\n", tr.bookID, tr.studentID, tr.issueDate, tr.returnDate);
    }
    fclose(fpTran);
}

/// ---------- REPORTS ---------- ///
void reportAvailableBooks() {
    FILE *fp = fopen(BOOK_FILE, "rb");
    Book b;
    printf("\n📊 --- Available Books ---\n");
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.quantity > 0)
            printf("%d - %s (Qty: %d)\n", b.id, b.title, b.quantity);
    }
    fclose(fp);
}

void reportIssuedBooks() {
    FILE *fpTran = fopen(TRANSACTION_FILE, "rb");
    Transaction tr;
    printf("\n📊 --- Books Currently Issued ---\n");
    while (fread(&tr, sizeof(Transaction), 1, fpTran)) {
        if (strcmp(tr.returnDate, "N/A") == 0)
            printf("Book ID: %d → Student ID: %d (Issued: %s)\n", tr.bookID, tr.studentID, tr.issueDate);
    }
    fclose(fpTran);
}

/// ---------- MENUS ---------- ///
void bookMenu() {
    int choice;
    do {
        printf("\n📚 --- Book Menu ---\n");
        printf("1. Add Book\n2. View Books\n3. Search Book\n0. Back\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
        }
    } while (choice != 0);
}

void studentMenu() {
    int choice;
    do {
        printf("\n🎓 --- Student Menu ---\n");
        printf("1. Add Student\n2. View Students\n0. Back\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
        }
    } while (choice != 0);
}

void teacherMenu() {
    int choice;
    do {
        printf("\n👨‍🏫 --- Teacher Menu ---\n");
        printf("1. Add Teacher\n2. View Teachers\n0. Back\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addTeacher(); break;
            case 2: viewTeachers(); break;
        }
    } while (choice != 0);
}

void computerMenu() {
    int choice;
    do {
        printf("\n💻 --- Computer Menu ---\n");
        printf("1. Add Computer\n2. View Computers\n0. Back\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addComputer(); break;
            case 2: viewComputers(); break;
        }
    } while (choice != 0);
}

void issueMenu() {
    int choice;
    do {
        printf("\n📦 --- Issue/Return Menu ---\n");
        printf("1. Issue Book\n2. Return Book\n3. View All Issued Books\n0. Back\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: issueBook(); break;
            case 2: returnBook(); break;
            case 3: viewIssuedBooks(); break;
        }
    } while (choice != 0);
}

void reportMenu() {
    int choice;
    do {
        printf("\n📊 --- Reports Menu ---\n");
        printf("1. Available Books\n2. Currently Issued Books\n0. Back\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: reportAvailableBooks(); break;
            case 2: reportIssuedBooks(); break;
        }
    } while (choice != 0);
}

/// ---------- LOGIN ---------- ///
int authenticate() {
    char user[20], pass[20];
    printf("\nLogin Required\n");
    printf("Username: "); scanf("%s", user);
    printf("Password: "); scanf("%s", pass);
    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        printf("\n✅ Login Successful!\n");
        return 1;
    }
    printf("\n❌ Invalid credentials!\n");
    return 0;
}

/// ---------- MAIN ---------- ///
int main() {
    if (!authenticate()) return 0;

    int choice;
    do {
        printf("\n====== BAUST LIBRARY MANAGEMENT ======\n");
        printf("1. Book Management\n");
        printf("2. Student Management\n");
        printf("3. Teacher Management\n");
        printf("4. Computer Management\n");
        printf("5. Issue/Return System\n");
        printf("6. Reports\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: bookMenu(); break;
            case 2: studentMenu(); break;
            case 3: teacherMenu(); break;
            case 4: computerMenu(); break;
            case 5: issueMenu(); break;
            case 6: reportMenu(); break;
            case 0: printf("\nExiting...\n"); break;
            default: printf("\n❌ Invalid choice! Try again.\n");
        }
    } while (choice != 0);
    return 0;
}
