create DATABASE Teachers;
use Teachers;

-- Creating Teacher table
CREATE TABLE Teacher (
    t_no INT PRIMARY KEY,
    f_name VARCHAR(255),
    l_name VARCHAR(255),
    salary DECIMAL(10, 2),
    supervisor INT,
    joining_date DATE,
    birth_date DATE,
    title VARCHAR(50)
);

-- Creating Class table
CREATE TABLE Class (
    class_no INT PRIMARY KEY,
    t_no INT,
    room_no INT,
    FOREIGN KEY (t_no) REFERENCES Teacher(t_no)
);

-- Creating Pay_scale table
CREATE TABLE Pay_scale (
    Min_limit DECIMAL(10, 2),
    Max_limit DECIMAL(10, 2),
    grade VARCHAR(10),
    PRIMARY KEY (Min_limit, Max_limit)
);

-- Inserting data into Teacher table
INSERT INTO Teacher (t_no, f_name, l_name, salary, supervisor, joining_date, birth_date, title)
VALUES
    (1, 'John', 'Doe', 50000.00, NULL, '2020-01-15', '1980-05-20', 'Professor'),
    (2, 'Jane', 'Smith', 60000.00, 1, '2018-03-10', '1985-09-12', 'Associate Professor'),
    (3, 'Mark', 'Johnson', 45000.00, 1, '2019-07-22', '1990-11-30', 'Assistant Professor'),
    (4, 'Alice', 'Williams', 55000.00, NULL, '2021-02-05', '1982-08-18', 'Professor'),
    (5, 'Bob', 'Jones', 70000.00, 2, '2017-06-08', '1975-04-25', 'Professor'),
    (6, 'Emily', 'Davis', 48000.00, 3, '2022-09-14', '1988-12-07', 'Assistant Professor'),
    (7, 'Michael', 'Brown', 62000.00, 1, '2016-04-30', '1972-03-15', 'Professor'),
    (8, 'Samantha', 'Miller', 58000.00, NULL, '2023-11-02', '1983-07-10', 'Associate Professor'),
    (9, 'David', 'Anderson', 52000.00, 5, '2020-08-18', '1978-09-28', 'Assistant Professor'),
    (10, 'Sophia', 'Garcia', 53000.00, 2, '2019-01-07', '1987-06-03', 'Associate Professor'),
    (11, 'Laura', 'Martinez', 8000.00, 1, '2020-04-12', '1982-09-22', 'Assistant Professor'),
    (12, 'Daniel', 'Wilson', 15000.00, 3, '2019-08-25', '1975-11-10', 'Associate Professor'),
    (13, 'Ella', 'Taylor', 12000.00, 1, '2022-02-18', '1988-05-05', 'Assistant Professor'),
    (14, 'Christopher', 'Moore', 25000.00, 2, '2018-06-30', '1980-12-15', 'Professor'),
    (15, 'Sophie', 'Lee', 18000.00, NULL, '2021-11-08', '1990-03-28', 'Associate Professor'),
    (16, 'Connor', 'Hill', 10000.00, 5, '2017-03-02', '1985-07-18', 'Assistant Professor'),
    (17, 'Olivia', 'Allen', 30000.00, 7, '2016-09-14', '1972-10-30', 'Professor'),
    (18, 'Jackson', 'Ward', 7000.00, 8, '2023-04-30', '1983-03-25', 'Assistant Professor'),
    (19, 'Aria', 'Clark', 11000.00, NULL, '2020-08-18', '1978-05-20', 'Associate Professor'),
    (20, 'Logan', 'Evans', 6000.00, 5, '2019-01-07', '1987-11-03', 'Assistant Professor');

-- Inserting data into Class table with different room numbers
INSERT INTO Class (class_no, t_no, room_no)
VALUES
    (101, 1, 201),
    (102, 2, 202),
    (103, 3, 203),
    (104, 4, 204),
    (105, 5, 205),
    (106, 6, 206),
    (107, 7, 207),
    (108, 8, 208),
    (109, 9, 209),
    (110, 10, 210),
    (111, 11, 211),
    (112, 12, 212),
    (113, 13, 213),
    (114, 14, 214),
    (115, 15, 215),
    (116, 16, 216),
    (117, 17, 217),
    (118, 18, 218),
    (119, 19, 219),
    (120, 20, 220);
-- Inserting data into Pay_scale table
INSERT INTO Pay_scale (Min_limit, Max_limit, grade)
VALUES
    (0.00, 9999.99, 'Grade A'),
    (10000.00, 19999.99, 'Grade B'),
    (20000.00, 39999.99, 'Grade C'),
    (40000.00, 49999.99, 'Grade D'),
    (50000.00, 69999.99, 'Grade E'),
    (70000.00, 99999.99, 'Grade F');


-- Task 1: Accept a range of salary and print details of teachers from the teacher table.
DELIMITER //
CREATE PROCEDURE TEACHER_RANGE(IN min_sal INT, IN max_sal INT)
BEGIN
    IF min_sal <= max_sal THEN
		SELECT * FROM Teacher WHERE salary BETWEEN min_sal AND max_sal;
	ELSE 
		SELECT "PLZ ENTER IN PROPER MANNER MIN_SAL < MAX_SAL";
	END IF;
END;
//
DELIMITER ;

-- Task 2: Calculate the bonus amount using a cursor
DELIMITER //
CREATE PROCEDURE TEACHER_BONUS()
BEGIN
    -- Declare variables to store fetched data
    DECLARE v_teacher_id INT;
    DECLARE v_f_name VARCHAR(250);
    DECLARE v_l_name VARCHAR(250);
    DECLARE v_salary DECIMAL(10, 2);
    DECLARE v_bonus DECIMAL(10, 2);

    -- Declare cursor
    DECLARE Teach_Bonus CURSOR FOR
        SELECT t_no, f_name, l_name, salary 
        FROM teacher;

    -- Declare handler for NOT FOUND condition
    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET v_teacher_id = NULL;

    -- Create a new table to store bonus values
    CREATE TABLE IF NOT EXISTS teacher_bonus (
        teacher_id INT PRIMARY KEY,
        f_name VARCHAR(250),
        l_name VARCHAR(250),
        bonus DECIMAL(10, 2)
    );

    -- Open the cursor
    OPEN Teach_Bonus;

    -- Fetch and process data from the cursor
    FETCH Teach_Bonus INTO v_teacher_id, v_f_name, v_l_name, v_salary;

    -- Loop through the cursor results
    WHILE v_teacher_id IS NOT NULL 
    DO
        -- Calculate bonus based on salary conditions
        IF v_salary < 10000 THEN
            SET v_bonus = 0.10 * v_salary;
        ELSEIF v_salary BETWEEN 10000 AND 20000 THEN
            SET v_bonus = 0.20 * v_salary;
        ELSEIF v_salary BETWEEN 20000 AND 25000 THEN
            SET v_bonus = 0.25 * v_salary;
        ELSE
            SET v_bonus = 0.30 * v_salary;
        END IF;

        -- Insert the calculated bonus into the new table
        INSERT INTO teacher_bonus (teacher_id, f_name, l_name, bonus) 
        VALUES (v_teacher_id, v_f_name, v_l_name, v_bonus);

        -- Fetch the next row
        FETCH Teach_Bonus INTO v_teacher_id, v_f_name, v_l_name, v_salary;
    END WHILE;

    -- Close the cursor
    CLOSE Teach_Bonus;
END //
DELIMITER ;
CALL TEACHER_BONUS();
SELECT * FROM teacher_bonus;


-- Task 3: Using a simple LOOP structure, list the first 10 records of the ‘teachers’ table.
DELIMITER //

CREATE PROCEDURE TEACHER_RECORD(IN n INT)
BEGIN 
    DECLARE v_t_no INT;
    DECLARE v_f_name VARCHAR(250);
    DECLARE v_l_name VARCHAR(250);
    DECLARE v_salary DECIMAL(10, 2);
    DECLARE v_supervisor BOOL;
    DECLARE v_joining_date DATE;
    DECLARE v_birth_date DATE;
    DECLARE v_title VARCHAR(50);
    DECLARE c INTEGER;
	
    DECLARE Teach_REC CURSOR FOR
		SELECT t_no, f_name, l_name, salary, supervisor, joining_date, birth_date, title
        FROM teacher;
	
    DECLARE CONTINUE HANDLER FOR NOT FOUND
		SET v_t_no = NULL;
	SET c = 1;
 
    CREATE TABLE IF NOT EXISTS TRECORDS (
        t_no int primary key, 
		f_name varchar(255), 
		l_name varchar(255), 
		salary DECIMAL(10,2), 
		supervisor INT, 
		joining_date date, 
		birth_date date, 
		title varchar(50)
    );
	
    OPEN Teach_REC;
		FETCH Teach_REC INTO v_t_no,v_f_name,v_l_name,v_salary,v_supervisor,v_joining_date,v_birth_date,v_title;

		WHILE c <= n  
		DO
			INSERT TRECORDS (t_no, f_name, l_name, salary, supervisor, joining_date, birth_date, title) 
			VALUES (v_t_no,v_f_name,v_l_name,v_salary,v_supervisor,v_joining_date,v_birth_date,v_title);
			FETCH Teach_REC INTO v_t_no,v_f_name,v_l_name,v_salary,v_supervisor,v_joining_date,v_birth_date,v_title;
			SET c = c + 1; 	
        END WHILE;   
    CLOSE Teach_REC;
END //

DELIMITER ;

SELECT * FROM TRECORDS;

-- Task 4: Accept the room number and display teacher details.
DELIMITER //
CREATE PROCEDURE TEACHER_ROOMNO(IN room_number INT )
BEGIN
	IF room_number >= 201 AND room_number <= 220 then
		select  Teacher.t_no, Teacher.f_name, Teacher.l_name, Teacher.birth_date, Teacher.title from Teacher join Class on Teacher.t_no = Class.t_no where room_number = Class.room_no  ;
	ELSE
		select "Enter room number between 201 and 220";
	END IF;
END;
//
DELIMITER ;

