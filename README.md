# Municipal Financial Management System (MFMS)

## PAP521S – Programming in Practice

A C99-based Municipal Financial Management System developed as a group project for the PAP521S Programming in Practice course at the Namibia University of Science and Technology (NUST).

---

## Group Members

| Member | Student Number | Responsibility |
|---|---|---|
| Dalia Uusiki | 224020463 | Employee Management Lead |
| Ester Haradoes |225052318 | Budget Management Lead |
| Mekere Zaombo |224067184 | Supplier Management Lead + Partial Reports |
| Ngajozikue Kamarama | 225027518 | Asset Management Lead + Partial Reports |
| Sheen N Shipiki| 225043548 | Main Menu & Input Validation Lead |
| Matilde Samuel | 225029774 | String Utilities Lead + Technical Report |
| Vikapita Condoleeze Makari| 225055678 | Integration Lead + GitHub & README |

Submitted by: Vikapita Condoleeze Makari - 225055678

---

## Project Description

The Municipal Financial Management System (MFMS) is a foundation-level financial management system designed to demonstrate the use of fundamental C programming concepts in a municipal environment.

The system provides functionality for managing employees, departmental budgets, suppliers and municipal assets. It also provides reports that summarise the information stored in the system.

The project demonstrates:

- Input and output
- Variables and data types
- Structures
- Arrays
- Strings
- Functions
- Conditional statements
- Loops
- Searching
- Calculations
- Input validation
- Modular programming
- Git and GitHub collaboration

---

## System Features

### 1. Employee Management

The Employee Management module allows users to:

- Add employees
- Display registered employees
- Search for an employee by ID
- Calculate total employee salary

Employee information includes:

- Employee ID
- Employee name
- Department
- Basic salary
- Housing allowance
- Transport allowance

The total salary is calculated using:

**Total Salary = Basic Salary + Housing Allowance + Transport Allowance**

---

### 2. Budget Management

The Budget Management module allows users to:

- Enter departmental budgets
- Record departmental expenditure
- Calculate remaining budget
- Display budget information
- Identify departments that have exceeded their budgets

The remaining budget is calculated using:

**Remaining Budget = Allocated Budget − Expenditure**

---

### 3. Supplier Management

The Supplier Management module allows users to:

- Add suppliers
- Display suppliers
- Search for suppliers
- Compare suppliers according to their location

Supplier information includes:

- Supplier ID
- Supplier name
- Email address
- Telephone number
- Town/location

---

### 4. Asset Management

The Asset Management module provides a municipal asset register.

Users can:

- Add assets
- Display assets
- Search for assets
- Display assets according to department
- Calculate the total value of registered assets

Asset information includes:

- Asset ID
- Asset name
- Asset type
- Purchase value
- Department
- Condition

---

### 5. Reports Module

The Reports Module provides summaries of the information stored in the system.

Available reports include:

#### Employee Report
- Total number of employees
- Total salary
- Average salary
- Highest salary
- Lowest salary

#### Budget Report
- Total departments
- Total allocated budget
- Total expenditure
- Total remaining budget
- Departments exceeding their budgets

#### Supplier Report
- Supplier information and summary

#### Asset Report
- Total number of assets
- Total asset value
- Asset information

---

## Input Validation

The system includes input validation to improve reliability and prevent invalid data from being entered.

Examples include:

- Invalid menu choices are rejected
- Employee IDs must be positive
- Employee names cannot be empty
- Salaries cannot be negative
- Allowances cannot be negative
- Budgets cannot be negative
- Invalid numeric input is handled through validation functions

---

## Technologies and Tools

The project was developed using:

- **Programming Language:** C99
- **Compiler:** GCC
- **IDE/Editor:** Visual Studio Code
- **Version Control:** Git
- **Repository:** GitHub

---

## Project Structure

```text
PAP-project/
│
├── main.c
├── menu.c
├── menu.h
│
├── employees.c
├── employees.h
│
├── budget.c
├── budget.h
│
├── suppliers.c
├── suppliers.h
│
├── assets.c
├── assets.h
│
├── reports.c
├── reports.h
│
├── validation.c
├── validation.h
│
├── string_utils.c
├── string_utils.h
│
└── README.md
```

---

## Compilation

Open a terminal in the project directory and compile the system using:

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c menu.c employees.c budget.c suppliers.c assets.c reports.c validation.c string_utils.c -o mfms
```

The `test_strings.c` file is a separate string utility test file and is not included in the main system compilation because it contains its own `main()` function.

---

## Running the System

After successful compilation, run the program using:

### Windows PowerShell

```powershell
.\mfms.exe
```

The system will display the main menu:

```text
===================================================
       MUNICIPAL FINANCIAL MANAGEMENT SYSTEM
===================================================
  1. Employee Management
  2. Budget Management
  3. Supplier Management
  4. Asset Management
  5. Reports Module
  6. Exit System
===================================================
```

---

## Individual Responsibilities

### Dalia – Employee Management Lead
Responsible for the Employee Management module, including employee data structures, adding employees, displaying employees, searching employees and salary calculations.

### Ester – Budget Management Lead
Responsible for the Budget Management module, including departmental budgets, expenditure, remaining budgets and identifying departments that exceed their budgets.

### Mekere – Supplier Management Lead + Partial Reports
Responsible for Supplier Management functionality and contributing to the Reports Module.

### Ngajozikue – Asset Management Lead + Partial Reports
Responsible for Asset Management functionality and contributing to the Reports Module.

### Sheen – Main Menu & Input Validation Lead
Responsible for the main menu system, navigation and input validation functionality.

### Matilde – String Utilities Lead + Technical Report
Responsible for string utility functionality and contributing to the technical report.

### Vikapita – Integration Lead + GitHub & README
Responsible for integrating the individual modules, coordinating the GitHub repository and branches, resolving integration issues, testing the integrated system, maintaining the README and preparing the final integrated version.

---

## GitHub Collaboration

The project was developed collaboratively using Git and GitHub.

Each group member contributed to their assigned module through Git branches and commits. The individual branches were integrated into the main branch while preserving the contribution history.

The final integration included:

- Employee Management
- Budget Management
- Supplier Management
- Asset Management
- Reports
- Main Menu
- Input Validation
- String Utilities

---

## Testing

The integrated system was tested to verify the functionality of the main modules.

Testing included:

- Adding employees
- Displaying employees
- Searching for existing employees
- Searching for non-existing employees
- Employee salary calculations
- Employee reports
- Budget reports
- Supplier reports
- Asset reports
- Invalid menu choices
- Negative employee IDs
- Empty employee names
- Negative salaries

The system was compiled using GCC with:

```bash
gcc -std=c99 -Wall -Wextra -pedantic
```

and tested through the integrated executable.

---

## Project Status

The Municipal Financial Management System has been integrated into the `main` branch and pushed to the group's GitHub repository.

The project demonstrates modular C programming, structured data management, validation, calculations, reporting and collaborative Git/GitHub development.