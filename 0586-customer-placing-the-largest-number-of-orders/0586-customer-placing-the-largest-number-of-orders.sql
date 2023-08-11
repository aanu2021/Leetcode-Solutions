# Write your MySQL query statement below

SELECT customer_number FROM orders 
GROUP BY customer_number 
HAVING COUNT(*) = (SELECT MAX(counts) 
                   FROM (SELECT COUNT(*) as counts FROM orders
                         GROUP BY customer_number) as sub)

