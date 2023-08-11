# Write your MySQL query statement below

select customer_number from Orders
group by customer_number
having count(*) = 
(select MAX(counts) from (select count(*) as counts from Orders group by customer_number) as sub)