# Write your MySQL query statement below

select ROUND(100*(COUNT(*)/(select COUNT(*) from Delivery)),2) as immediate_percentage from Delivery
where order_date = customer_pref_delivery_date;