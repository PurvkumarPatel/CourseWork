
create database employee;

USE employee;
CREATE TABLE e_table (
  e_ID int NOT NULL,
  e_NAME varchar(255) DEFAULT NULL,
  e_AGE int ,
  e_ADDRESS varchar(255) DEFAULT NULL,
  e_salary int DEFAULT NULL,
  PRIMARY KEY (e_ID)
  
);
CREATE TABLE d_table (
  d_ID int NOT NULL,
  d_NAME varchar(255) DEFAULT NULL,
  PRIMARY KEY (d_ID)
);
insert into d_table
values (1,'CSE'),
(2,'EC'),
(3,'Civil'),
(4,'Mechanical');

insert into employee.e_table
values (1,'SITA',22,'Surat',1000),
       (2,'rohan',25,'ahemdabad',2500), 
       (3,'pankaj',21,'gandhinagar',1500),
       (4,'kishor',26,'vadodhra',2000),
      (5,'geet',23,'RAJKOT',1000), 
      (6,'rohan',24,'patan',2300),
      (7,'sheetal',25,'sihor',2400);
select * from e_table;
use employee;       
select e_NAME , e_AGE from e_table where e_AGE =  (select min(e_AGE) from e_table);
SET SQL_SAFE_UPDATES=0; 
update employee.e_table set e_salary = '500' where e_NAME = (select e_NAME where e_ADDRESS='ahemdabad' );
SET SQL_SAFE_UPDATES=1;

select e_NAME ,e_salary from e_table where e_salary >= (select e_salary from e_table where e_ID = 4);
select e_NAME,e_AGE,e_ADDRESS from e_table where e_salary = (select min(e_salary) from e_table);

