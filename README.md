"# Baust_Library_Management" 
****BAUST Library Management System*******
A complete library management program written in C for BAUST University Library.

*****Overview
The BAUST Library Management System is a console-based program written in pure C language that manages:

**Books

**Students

**Teachers

**Computers

**Book Issue/Return Transactions

This project was created as a real-world university project to demonstrate file handling, structures, and modular programming in C.

********Features*********
✔ Admin Login System (Username: admin, Password: 1234)
✔ Book Management – Add, View, Search books
✔ Student & Teacher Management – Register & list members
✔ Computer Management – Track computers in the library
✔ Book Issue/Return System – Borrow and return books
✔ Fine Calculation Placeholder – Shows how overdue fines can be calculated
✔ Reports – View available books & issued books

*******File Structure*********
bash
Copy
Edit
├── baust_library.c        # Main program file
├── books.dat              # Binary file storing book records
├── students.dat           # Binary file storing student records
├── teachers.dat           # Binary file storing teacher records
├── computers.dat          # Binary file storing computer records
├── transactions.dat       # Binary file storing issue/return records
└── README.md              # Project documentation
********How to Compile & Run*******
***** On Windows (using GCC / MinGW)
bash
Copy
Edit
gcc baust_library.c -o baust_library
baust_library.exe
***** On Linux / Mac
bash
Copy
Edit
gcc baust_library.c -o baust_library
./baust_library
Login Information
Username: admin

Password: 1234

Menu System
markdown
Copy
Edit
====== BAUST LIBRARY MANAGEMENT ======
1. Book Management
2. Student Management
3. Teacher Management
4. Computer Management
5. Issue/Return System
6. Reports
0. Exit
&&&&& Each module has its own sub-menu for easy navigation.&&&&&

*****Future Improvements****
** Fine Calculation (auto-calculation based on due date)
** Export Reports to Text/PDF
** GUI Version (using GTK or web-based frontend)
** Database Integration (SQLite/MySQL) 

**********Tech Used*********
Language: C

Storage: File handling with .dat binary files

Platform: Console (cross-platform)

****Why This Project?********

** Practical use of C programming

** Handling real-world data management

** File I/O for persistent storage


