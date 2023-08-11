# Write your MySQL query statement below

select
Department.name as Department,
e1.name as Employee,
e1.salary as Salary
from
Employee e1 join Department
on 
e1.departmentId = Department.id
where
3 > 
(
select count(distinct(salary))
from Employee e2
where e2.salary > e1.salary
and
      e2.departmentId = e1.departmentId
)

