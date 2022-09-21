# Write your MySQL query statement below

SELECT name AS Employee FROM Employee AS E1 WHERE E1.salary > (SELECT salary FROM Employee E2 WHERE E2.id = E1.managerId);