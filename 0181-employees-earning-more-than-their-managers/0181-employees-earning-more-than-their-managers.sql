# Write your MySQL query statement below

select e1.name as Employee from Employee e1 where e1.managerId is not null and e1.salary > (select e2.salary from Employee e2 where e2.id = e1.managerId);