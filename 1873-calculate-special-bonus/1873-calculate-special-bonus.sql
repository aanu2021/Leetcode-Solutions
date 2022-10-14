# Write your MySQL query statement below

# If - Else  /  Case  Statement

SELECT employee_id , IF(employee_id%2 AND name NOT LIKE 'M%' , salary,0) AS bonus FROM Employees ORDER BY employee_id;
