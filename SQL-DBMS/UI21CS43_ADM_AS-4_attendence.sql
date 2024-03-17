CREATE DATABASE students;
USE students;

CREATE TABLE Student (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    adm43_marks INT CHECK (adm43_marks >= 0 AND adm43_marks <= 100),
    adm43_attendance INT CHECK (adm43_attendance >= 0 AND adm43_attendance <= 100)
);

CREATE TABLE chagnes_table (
    notification_id INT AUTO_INCREMENT PRIMARY KEY,
    stud_id INT,
    message VARCHAR(255),
    stud_name VARCHAR(50)
);

DELIMITER //
CREATE TRIGGER attend_mark_check
AFTER UPDATE ON Student
FOR EACH ROW
BEGIN
    IF NEW.adm43_attendance < 85 THEN
        INSERT INTO chagnes_table (stud_id, message, stud_name)
        VALUES (NEW.student_id , 'Low attendance for student ' , NEW.student_name);
    END IF;
	IF NEW.adm43_marks < 40 THEN
        INSERT INTO chagnes_table (stud_id, message, stud_name)
        VALUES (NEW.student_id ,'Low marks for student ' , NEW.student_name );
    END IF;
END;
//
DELIMITER ;

DELIMITER //
CREATE TRIGGER attend_mark_check_inst
AFTER INSERT ON Student
FOR EACH ROW
BEGIN
    IF NEW.adm43_attendance < 85 THEN
        INSERT INTO chagnes_table (stud_id, message, stud_name)
        VALUES (NEW.student_id, 'Low attendance for student ' , NEW.student_name);
    END IF;
	IF NEW.adm43_marks < 40 THEN
        INSERT INTO chagnes_table (stud_id, message, stud_name)
        VALUES (NEW.student_id, 'Low marks for student ' , NEW.student_name );
    END IF;
END;
//
DELIMITER ;

select * from chagnes_table;

INSERT INTO Student (student_id, student_name, adm43_marks, adm43_attendance) 
VALUES 
(1, 'John Doe', 85, 76),
(2, 'Jane Smith', 78, 82),
(3, 'Alice Johnson', 90, 85),
(4, 'Bob Williams', 82, 79),
(5, 'Emily Brown', 88, 92),
(6, 'Michael Davis', 76, 84),
(7, 'Sophia Wilson', 85, 91),
(8, 'William Martinez', 92, 88),
(9, 'Olivia Anderson', 79, 91),
(10, 'Daniel Taylor', 91, 88);

select * from chagnes_table;

select * from student;
UPDATE students.Student
SET adm43_attendance = 75
WHERE student_id = 1;

UPDATE students.Student
SET adm43_marks = 25
WHERE student_id = 1;

select * from chagnes_table;
select * from student;
