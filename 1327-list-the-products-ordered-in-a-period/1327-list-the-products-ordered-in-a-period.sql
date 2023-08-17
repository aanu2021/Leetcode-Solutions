# Write your MySQL query statement below

select 
Products.product_name,
SUM(Orders.unit) as unit
from Products join Orders
on Products.product_id = Orders.product_id
where LEFT(Orders.order_date,7) = '2020-02'
group by Products.product_id
having SUM(Orders.unit) >= 100;