# Write your MySQL query statement below

select 
Prices.product_id,
ROUND(SUM(price*units)/SUM(units),2) as average_price
from Prices join UnitsSold
on Prices.product_id = UnitsSold.product_id and
datediff(purchase_date,start_date) >= 0 and
datediff(purchase_date,end_date) <= 0
group by Prices.product_id;