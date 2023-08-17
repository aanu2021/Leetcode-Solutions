# Write your MySQL query statement below

select 
ROUND(100*AVG(order_date=customer_pref_delivery_date),2) as immediate_percentage 
from Delivery;