# Write your MySQL query statement below

# Count(Distinct) Group By

# GROUP_CONCAT is used to concatenate all the group of elements 

SELECT sell_date,

       COUNT(DISTINCT product) AS num_sold,
       
       GROUP_CONCAT(DISTINCT product ORDER BY product separator ',') As products
       
       FROM Activities
       
       GROUP BY sell_date
       
       ORDER BY sell_date;