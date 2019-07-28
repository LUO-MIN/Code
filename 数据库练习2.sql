-- 获取所有部门当前manager的当前薪水情况，给出dept_no, emp_no以及salary，
--当前表示to_date='9999-01-01'
select d.dept_no,d.emp_no,s.salary
from dept_manager as d,salaries as s
where s.emp_no=d.emp_no and d.to_date='9999-01-01' and s.to_date='9999-01-01'  

--从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。
select title,count(title)as t
from titles
group by title 
having count(title)>=2

--编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。
select Email
from Person
group by Email
having count(Email)>1

--如果一个国家的面积超过300万平方公里，或者人口超过2500万，那么这个国家就是大国家。
--编写一个SQL查询，输出表中所有大国家的名称、人口和面积。
select name,population,area
from World
where area>3000000  or population>25000000

--编写一个 SQL 查询，获取 Employee 表中第 n 高的薪水（Salary）。
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N=N-1;
  RETURN (
      select distinct Salary
      from Employee
      order by salary DESC
      limit N,1
      
  );
END