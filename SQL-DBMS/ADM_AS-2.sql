-- Create the database
CREATE DATABASE studentdata;

-- Use the studentdata database
USE studentdata;

-- Create the student table
CREATE TABLE student (
  serial_number INT PRIMARY KEY,
  student_name VARCHAR(50),
  subject1 INT,
  subject2 INT,
  subject3 INT,
  subject4 INT,
  subject5 INT,
  subject6 INT
);

-- Insert 10 sample student records
INSERT INTO student (serial_number, student_name, subject1, subject2, subject3, subject4, subject5, subject6)
VALUES
  (1, 'John Doe', 85, 92, 78, 88, 94, 90),
  (2, 'Jane Smith', 75, 80, 82, 88, 79, 85),
  (3, 'Bob Johnson', 92, 88, 90, 87, 95, 91),
  (4, 'Alice Brown', 78, 85, 76, 80, 82, 89),
  (5, 'Charlie Davis', 93, 91, 89, 96, 87, 84),
  (6, 'Eva White', 86, 92, 88, 75, 80, 92),
  (7, 'David Lee', 77, 83, 79, 81, 75, 88),
  (8, 'Grace Miller', 89, 90, 85, 92, 88, 91),
  (9, 'Samuel Wilson', 94, 88, 87, 90, 91, 95),
  (10, 'Olivia Turner', 82, 79, 80, 78, 84, 87);

-- Select all records from the student table
SELECT * FROM student;

-- Create a stored procedure to print "Hello World"
DELIMITER //
CREATE PROCEDURE temp()
BEGIN
  SELECT "Hello World";
END;
//
DELIMITER ;
-- Call the temp stored procedure
CALL temp();

-- Create a stored procedure to calculate factorial
DELIMITER //
CREATE PROCEDURE facto(IN n INT)
BEGIN
  DECLARE i INT DEFAULT 1;
  DECLARE fact INT DEFAULT 1;
  
  factorial: LOOP
    SET fact = fact * i;
    SET i = i + 1;
    IF i <= n THEN
      ITERATE factorial;
    END IF;
    LEAVE factorial;
  END LOOP;
  
  SELECT i, fact, n;
END;
//
DELIMITER ;
call studentdata.facto(5);

-- Create a stored function to calculate the average grade for 6 subjects
DELIMITER //
CREATE PROCEDURE calculate_average_grade(IN score1 INT, IN score2 INT, IN score3 INT, IN score4 INT, IN score5 INT, IN score6 INT)
BEGIN
  DECLARE average_score INT;
  DECLARE total_score INT;
  DECLARE avg_grade VARCHAR(10);

  -- Calculate total score
  SET total_score = score1 + score2 + score3 + score4 + score5 + score6;

  -- Calculate average score
  SET average_score = total_score / 6;

  -- Calculate the average grade based on the average score
  IF average_score >= 90 THEN
    SET avg_grade = 'A';
  ELSEIF average_score >= 70 THEN
    SET avg_grade = 'B';
  ELSEIF average_score >= 60 THEN
    SET avg_grade = 'C';
  ELSEIF average_score >= 50 THEN
    SET avg_grade = 'D';
  ELSE
    SET avg_grade = 'E';
  END IF;

  -- Return the average grade
  SELECT avg_grade, average_score;
END;
//
DELIMITER ;
call studentdata.calculate_average_grade(100, 59, 60, 78, 80, 99);

-- Create a stored procedure to calculate average grade from student table
DELIMITER //
CREATE PROCEDURE calculate_student_average_grade(IN student_id INT)
BEGIN
  DECLARE score1 INT;
  DECLARE score2 INT;
  DECLARE score3 INT;
  DECLARE score4 INT;
  DECLARE score5 INT;
  DECLARE score6 INT;
  DECLARE average_score INT;
  DECLARE avg_grade VARCHAR(10);

  -- Fetch scores for the specified student_id from the student table
  SELECT subject1, subject2, subject3, subject4, subject5, subject6
  INTO score1, score2, score3, score4, score5, score6
  FROM student
  WHERE serial_number = student_id;

  -- Calculate total score
  SET average_score = (score1 + score2 + score3 + score4 + score5 + score6) / 6;

  -- Calculate the average grade based on the average score
  IF average_score >= 90 THEN
    SET avg_grade = 'A';
  ELSEIF average_score >= 70 THEN
    SET avg_grade = 'B';
  ELSEIF average_score >= 60 THEN
    SET avg_grade = 'C';
  ELSEIF average_score >= 50 THEN
    SET avg_grade = 'D';
  ELSE
    SET avg_grade = 'E';
  END IF;

  -- Return the average grade and average score
  SELECT avg_grade AS grade, average_score AS avg_score;
END;
//
DELIMITER ;
call studentdata.calculate_student_average_grade(2);