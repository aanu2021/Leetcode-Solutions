# Write your MySQL query statement below

SELECT name AS Customers FROM Customers  WHERE id NOT IN (Select customerId FROM Orders);