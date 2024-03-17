USE product;
create table pro (
p_id int not null primary key,
company varchar(50),
qty int,
cost int

);

INSERT INTO Pro (p_id,company,qty,cost)
value (1,'l&t',2,20);
INSERT INTO Pro (p_id,company,qty,cost)
value (2,'Oracle',3,35),
(3,'Oracle',2,40),
(4,'l&t',4,30),
(5,'IBM',2,25),
(6,'IBM',2,20),
(7,'l&t',3,50),
(8,'Oracle',4,30),
(9,'IBM',4,40),
(10,'IBM',5,20)
;
SELECT * FROM PRO;

SELECT COUNT(*) FROM PRO;
SELECT COUNT(*) FROM PRO WHERE cost>=25;
select count(distinct company) from pro;
SELECT COUNT(*) FROM PRO group by company;
SELECT company, COUNT(*) FROM PRO group by company having count(*)>2;
select sum(cost) from pro;
select sum(cost) from pro where qty>3;
select sum(cost) from pro where qty>3 group by company;
select sum(cost) from pro where qty>3 group by company having sum(cost)>=100;
select min(cost) from pro;