-- Create Database
CREATE DATABASE OrganizationDB;
USE OrganizationDB;

-- Create Employee Table
CREATE TABLE Employee (
    EMP_ID INT PRIMARY KEY,
    FIRST_NAME VARCHAR(50),
    LAST_NAME VARCHAR(50),
    SALARY DECIMAL(10,2),
    JOINING_DATE DATE,
    DEPARTMENT VARCHAR(50)
);

-- Create Employee Backup Table
CREATE TABLE employee_backup (
    EMP_ID INT PRIMARY KEY,
    FIRST_NAME VARCHAR(50),
    LAST_NAME VARCHAR(50),
    SALARY DECIMAL(10,2),
    JOINING_DATE DATE,
    DEPARTMENT VARCHAR(50)
);

-- Create Employee Data Insert Table
CREATE TABLE insert_count (
    table_name VARCHAR(50),
    count INT
);
-- Create Bonus Table
CREATE TABLE Bonus (
    EMP_REF_ID INT,
    BONUS_AMOUNT DECIMAL(10,2),
    BONUS_DATE DATE,
    FOREIGN KEY (EMP_REF_ID) REFERENCES Employee(EMP_ID)
);

-- Create Title Table
CREATE TABLE Title (
    EMP_REF_ID INT,
    EMP_TITLE VARCHAR(50),
    AFFECTED_FROM DATE,
    FOREIGN KEY (EMP_REF_ID) REFERENCES Employee(EMP_ID)
);

-- Insert Sample Data
-- Note: You need to replace the sample data with actual values.
-- Insert at least 50 records in each table.

-- Employee Table
INSERT INTO Employee VALUES (1, 'John', 'Doe', 60000.00, '2022-01-01', 'Admin');
INSERT INTO Employee VALUES (2, 'Jane', 'Smith', 55000.00, '2022-02-15', 'HR');
INSERT INTO Employee VALUES (3, 'Bob', 'Johnson', 70000.00, '2022-03-10', 'IT');
INSERT INTO Employee VALUES (4, 'Emily', 'Williams', 80000.00, '2022-04-20', 'Finance');
INSERT INTO Employee VALUES (5, 'David', 'Brown', 65000.00, '2022-05-05', 'Admin');
INSERT INTO Employee VALUES (6, 'Sophia', 'Jones', 72000.00, '2022-06-15', 'IT');
INSERT INTO Employee VALUES (7, 'Matthew', 'Wilson', 58000.00, '2022-07-02', 'HR');
INSERT INTO Employee VALUES (8, 'Ava', 'Davis', 75000.00, '2022-08-10', 'Finance');
INSERT INTO Employee VALUES (9, 'Michael', 'Miller', 67000.00, '2022-09-18', 'Admin');
INSERT INTO Employee VALUES (10, 'Olivia', 'Moore', 70000.00, '2022-10-01', 'IT');
INSERT INTO Employee VALUES (11, 'Ethan', 'Martin', 62000.00, '2022-11-15', 'Admin');
INSERT INTO Employee VALUES (12, 'Isabella', 'Harris', 78000.00, '2022-12-20', 'Finance');
INSERT INTO Employee VALUES (13, 'Daniel', 'Jackson', 59000.00, '2023-01-05', 'HR');
INSERT INTO Employee VALUES (14, 'Mia', 'Lee', 71000.00, '2023-02-12', 'IT');
INSERT INTO Employee VALUES (15, 'William', 'Taylor', 68000.00, '2023-03-01', 'Admin');
INSERT INTO Employee VALUES (16, 'Ava', 'Clark', 74000.00, '2023-04-15', 'Finance');
INSERT INTO Employee VALUES (17, 'Liam', 'Evans', 63000.00, '2023-05-10', 'HR');
INSERT INTO Employee VALUES (18, 'Emma', 'White', 79000.00, '2023-06-20', 'IT');
INSERT INTO Employee VALUES (19, 'Noah', 'Hall', 60000.00, '2023-07-05', 'Admin');
INSERT INTO Employee VALUES (20, 'Sophia', 'Ward', 72000.00, '2023-08-10', 'Finance');
INSERT INTO Employee VALUES (21, 'Logan', 'Turner', 56000.00, '2023-09-18', 'HR');
INSERT INTO Employee VALUES (22, 'Olivia', 'Carter', 77000.00, '2023-10-01', 'IT');
INSERT INTO Employee VALUES (23, 'Aiden', 'Baker', 64000.00, '2023-11-15', 'Admin');
INSERT INTO Employee VALUES (24, 'Amelia', 'Lopez', 83000.00, '2023-12-20', 'Finance');
INSERT INTO Employee VALUES (25, 'Lucas', 'Collins', 59000.00, '2024-01-05', 'HR');
INSERT INTO Employee VALUES (26, 'Ella', 'Cooper', 70000.00, '2024-02-12', 'IT');
INSERT INTO Employee VALUES (27, 'Jackson', 'Torres', 68000.00, '2024-03-01', 'Admin');
INSERT INTO Employee VALUES (28, 'Avery', 'Reed', 75000.00, '2024-04-15', 'Finance');
INSERT INTO Employee VALUES (29, 'Carter', 'Morgan', 61000.00, '2024-05-10', 'HR');
INSERT INTO Employee VALUES (30, 'Scarlett', 'Fisher', 72000.00, '2024-06-20', 'IT');
INSERT INTO Employee VALUES (31, 'Grayson', 'Porter', 54000.00, '2024-07-05', 'Admin');
INSERT INTO Employee VALUES (32, 'Lily', 'Ferguson', 76000.00, '2024-08-10', 'Finance');
INSERT INTO Employee VALUES (33, 'Christopher', 'Hill', 67000.00, '2024-09-18', 'HR');
INSERT INTO Employee VALUES (34, 'Zoey', 'Perry', 71000.00, '2024-10-01', 'IT');
INSERT INTO Employee VALUES (35, 'Nathan', 'Harrison', 59000.00, '2024-11-15', 'Admin');
INSERT INTO Employee VALUES (36, 'Addison', 'Graham', 78000.00, '2024-12-20', 'Finance');
INSERT INTO Employee VALUES (37, 'Mason', 'Sullivan', 63000.00, '2025-01-05', 'HR');
INSERT INTO Employee VALUES (38, 'Hannah', 'Woods', 71000.00, '2025-02-12', 'IT');
INSERT INTO Employee VALUES (39, 'Elijah', 'Kennedy', 66000.00, '2025-03-01', 'Admin');
INSERT INTO Employee VALUES (40, 'Leah', 'Barnes', 79000.00, '2025-04-15', 'Finance');
INSERT INTO Employee VALUES (41, 'Owen', 'Ross', 60000.00, '2025-05-10', 'HR');
INSERT INTO Employee VALUES (42, 'Natalie', 'Perez', 73000.00, '2025-06-20', 'IT');
INSERT INTO Employee VALUES (43, 'Caleb', 'Gomez', 57000.00, '2025-07-05', 'Admin');
INSERT INTO Employee VALUES (44, 'Brooklyn', 'Fletcher', 80000.00, '2025-08-10', 'Finance');
INSERT INTO Employee VALUES (45, 'Isaac', 'Jimenez', 69000.00, '2025-09-18', 'HR');
INSERT INTO Employee VALUES (46, 'Eva', 'Watkins', 72000.00, '2025-10-01', 'IT');
INSERT INTO Employee VALUES (47, 'Gabriel', 'Ortega', 62000.00, '2025-11-15', 'Admin');
INSERT INTO Employee VALUES (48, 'Aria', 'Rodriguez', 77000.00, '2025-12-20', 'Finance');
INSERT INTO Employee VALUES (49, 'Jack', 'Ruiz', 65000.00, '2026-01-05', 'HR');
INSERT INTO Employee VALUES (50, 'Aiden', 'Garcia', 70000.00, '2022-02-12', 'IT');


-- Bonus Table
INSERT INTO Bonus VALUES (1, 5000, '2022-02-01');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (2, 1200, '2023-08-09');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (3, 4300, '2023-06-25');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (4, 1000, '2022-08-20');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (5, 3000, '2023-09-14');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (6, 4300, '2023-06-20');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (7, 4300, '2022-10-02');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (8, 1200, '2023-03-26');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (9, 1200, '2023-05-27');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (10, 5000, '2022-03-02');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (11, 2600, '2023-02-19');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (12, 2500, '2024-02-21');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (13, 2500, '2024-01-05');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (14, 1000, '2022-02-06');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (15, 4300, '2023-04-07');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (16, 4300, '2021-11-24');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (17, 2000, '2021-11-22');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (18, 4300, '2023-10-09');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (19, 2500, '2023-06-14');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (20, 4000, '2022-07-08');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (21, 4300, '2021-11-29');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (22, 1200, '2022-03-25');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (23, 3000, '2022-02-07');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (24, 1000, '2023-10-15');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (25, 3000, '2021-11-01');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (26, 4000, '2022-10-22');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (27, 4000, '2022-08-20');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (28, 2600, '2024-01-21');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (29, 1000, '2022-11-25');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (30, 2600, '2022-06-08');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (31, 1000, '2022-04-06');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (32, 4300, '2024-02-12');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (33, 2000, '2022-04-07');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (34, 1200, '2022-05-13');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (35, 4000, '2022-01-31');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (36, 1200, '2022-12-07');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (37, 4300, '2022-05-11');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (38, 5000, '2023-12-04');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (39, 2500, '2023-04-06');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (40, 2600, '2023-03-04');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (41, 2000, '2023-11-02');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (42, 3000, '2023-07-30');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (43, 2600, '2022-03-25');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (44, 1200, '2021-12-20');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (45, 4000, '2021-11-14');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (46, 4000, '2023-01-17');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (47, 5000, '2022-04-06');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (48, 1000, '2022-05-01');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (49, 4300, '2022-03-27');
insert into Bonus (EMP_REF_ID, BONUS_AMOUNT, BONUS_DATE) values (50, 2600, '2022-10-31');

-- Title Table
INSERT INTO Title VALUES (1, 'Manager', '2022-01-01');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (2, 'Assistant', '2022-02-03');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (3, 'Manager', '2023-10-30');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (4, 'Assistant', '2022-07-19');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (5, 'Peoun', '2023-08-03');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (6, 'Manager', '2023-12-21');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (7, 'Manager', '2024-01-06');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (8, 'Peoun', '2023-09-25');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (9, 'Manager', '2022-04-30');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (10, 'Peoun', '2022-09-25');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (11, 'Manager', '2023-07-29');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (12, 'Manager', '2022-09-03');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (13, 'Employee', '2022-08-27');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (14, 'Peoun', '2023-02-21');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (15, 'Manager', '2022-06-02');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (16, 'Peoun', '2023-07-28');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (17, 'Assistant', '2023-06-23');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (18, 'Peoun', '2023-06-24');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (19, 'Manager', '2022-07-09');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (20, 'Employee', '2023-05-04');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (21, 'Peoun', '2023-12-11');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (22, 'Assistant', '2022-11-02');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (23, 'Peoun', '2022-08-17');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (24, 'Peoun', '2023-08-20');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (25, 'Assistant', '2023-08-03');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (26, 'Employee', '2023-04-20');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (27, 'Assistant', '2021-11-16');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (28, 'Assistant', '2023-08-28');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (29, 'Manager', '2024-02-03');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (30, 'Manager', '2022-03-27');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (31, 'Assistant', '2022-10-19');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (32, 'Employee', '2022-02-07');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (33, 'Manager', '2022-02-28');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (34, 'Employee', '2022-01-18');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (35, 'Assistant', '2022-10-24');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (36, 'Manager', '2022-04-18');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (37, 'Peoun', '2022-03-20');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (38, 'Manager', '2023-12-25');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (39, 'Manager', '2023-08-30');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (40, 'Peoun', '2023-05-18');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (41, 'Manager', '2023-09-10');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (42, 'Peoun', '2021-11-06');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (43, 'Manager', '2023-11-22');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (44, 'Assistant', '2024-01-20');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (45, 'Manager', '2022-10-14');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (46, 'Employee', '2021-11-19');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (47, 'Employee', '2023-02-08');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (48, 'Assistant', '2023-05-21');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (49, 'Peoun', '2022-01-07');
insert into Title (EMP_REF_ID, EMP_TITLE, AFFECTED_FROM) values (50, 'Employee', '2023-11-21');

-- 1. SQL query to print all Employee details from the Employee table order by FIRST_NAME Ascending and DEPARTMENT Descending.
SELECT * FROM Employee ORDER BY FIRST_NAME ASC, DEPARTMENT DESC;

-- 2 SQL query to fetch the count of employees working in the department ‘Admin’.
SELECT COUNT(*) FROM Employee WHERE DEPARTMENT = 'Admin';

-- 3. SQL query to fetch Employee names with salaries >= 50000 and <= 100000.
SELECT FIRST_NAME, LAST_NAME FROM Employee WHERE SALARY BETWEEN 50000 AND 100000;

-- 4. SQL query to print details of the Workers who are also Managers.
SELECT E.* FROM Employee E
JOIN Title T ON E.EMP_ID = T.EMP_REF_ID AND T.EMP_TITLE = 'Manager';

-- 5. SQL query to fetch duplicate records having matching data in some fields of a table.
SELECT EMP_ID, COUNT(*) FROM Employee GROUP BY EMP_ID HAVING COUNT(*) > 1;

-- 6. SQL query to show only even rows from a table.
SELECT * FROM Employee WHERE MOD(EMP_ID, 2) = 0;

-- 7. SQL query to show records from one table that another table does not have. Find employees in employee table that do not exist in bonus table.
DELETE FROM Bonus WHERE EMP_REF_ID = 50;
SELECT * FROM Employee WHERE EMP_ID NOT IN (SELECT EMP_REF_ID FROM Bonus);

-- 8. SQL query to show the top n (say 10) records of a table.
SELECT * FROM Employee LIMIT 10;

-- 9. Find people who have the same salary.
SELECT SALARY, COUNT(*) FROM Employee GROUP BY SALARY HAVING COUNT(*) > 1;

-- 10. SQL query to fetch the first 50% records from a table. 
SELECT * FROM (
    SELECT *,
           ROW_NUMBER() OVER (ORDER BY EMP_ID) AS rn
    FROM Employee
) AS subquery
WHERE rn <= (SELECT COUNT(*)/2 FROM Employee);

-- 11. Find the highest 2 salaries without LIMIT or TOP.
SELECT DISTINCT SALARY FROM Employee ORDER BY SALARY DESC LIMIT 2;

-- 12. Create a trigger to ensure that no employee joining date less than current date can be inserted in the database.
DELIMITER //
CREATE TRIGGER before_insert_employee
BEFORE INSERT ON Employee
FOR EACH ROW
BEGIN
    IF NEW.JOINING_DATE >= CURDATE() THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Joining date must be less than the current date.';
    END IF;
END;
//
DELIMITER ;
-- TSETING 12
INSERT INTO Employee VALUES (51, 'PATEL', 'Fletcher', 80000.00, '2025-08-10', 'Finance');

-- 13. Create a trigger which will work before deletion in employee table and create a duplicate copy of the record in another table employee_backup.
DELIMITER //
CREATE TRIGGER before_delete_employee
BEFORE DELETE ON Employee
FOR EACH ROW
BEGIN
    INSERT INTO employee_backup (EMP_ID, FIRST_NAME, LAST_NAME, SALARY, JOINING_DATE, DEPARTMENT)
    VALUES (OLD.EMP_ID, OLD.FIRST_NAME, OLD.LAST_NAME, OLD.SALARY, OLD.JOINING_DATE, OLD.DEPARTMENT);
END;
//
DELIMITER ;
-- TESING 13
DELETE FROM Title WHERE EMP_REF_ID = 50;
DELETE FROM Bonus WHERE EMP_REF_ID = 50;
DELETE FROM Employee WHERE EMP_ID = 50;
select * FROM employee_backup;

-- 14. Create a trigger to count the number of new tuples inserted using each insert statement.
DELIMITER //
CREATE TRIGGER after_insert_employee
AFTER INSERT ON Employee
FOR EACH ROW
BEGIN
    INSERT INTO insert_count (table_name, count)
    VALUES ('Employee', 1)
    ON DUPLICATE KEY UPDATE count = count + 1;
END;
//
DELIMITER ;
-- TESTING 14 
INSERT INTO Employee VALUES (52, 'PATELboss', 'Fletcher', 80000.00, '2021-08-10', 'Finance');
select * from insert_count;


