# Write your MySQL query statement below

SELECT a.name AS Customers FROM Customers AS a WHERE a.id NOT IN 
(SELECT customerId FROM Orders)