# Write your MySQL query statement below

SELECT MAX(salary) AS secondHighestSalary FROM EMPLOYEE WHERE salary <> (SELECT MAX(salary) FROM EMPLOYEE)
