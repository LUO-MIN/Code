--批量插入数据
insert into actor values
(1,'PENELOPE','GUINESS','2006-02-15 12:34:33'),
(2,'NICK','WAHLBERG','2006-02-15 12:34:33')

-- 找出所有员工当前(to_date='9999-01-01')具体的薪水salary情况，
-- 对于相同的薪水只显示一次,并按照逆序显示(依赖order by)
select distinct salary from salaries
where to_date='9999-01-01' 
order by salary DESC


--查找最晚入职员工的所有信息
select * from employees where hire_date in (select max(hire_date) from employees);
-- 或者
 select * from employees where hire_date = (select max(hire_date) from employees);
 
 --查找入职员工时间排名倒数第三的员工所有信息
 select * from employees
order by hire_date DESC limit 1 offset 2

select * from employees
order by hire_date DESC limit 1,2

-- 查找薪水涨幅超过15次的员工号emp_no以及其对应的涨幅次数t
select emp_no,count(emp_no) as t 
from salaries
group by emp_no
having count(emp_no)>15
