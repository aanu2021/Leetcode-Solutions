# Write your MySQL query statement below

# Union is used to join two set / column . If both the sets contain same entity , then it will be counted only once.


SELECT employee_id FROM Employees WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)

UNION

SELECT employee_id FROM Salaries WHERE employee_id NOT IN (SELECT employee_id FROM Employees)

ORDER BY employee_id;


