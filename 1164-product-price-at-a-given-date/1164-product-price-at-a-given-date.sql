# Write your MySQL query statement below

# on  2019-08-16
# valid dates are -> datediff(change_date,'2019-08-16') >= 0

select * from 
(
    (select product_id,new_price as price 
    from Products
    where (product_id,change_date) in 
    (select product_id,MAX(change_date)
    from Products
    where datediff(change_date,'2019-08-16') <= 0
    group by product_id))
    Union
    (select product_id,10 as price
    from Products
    group by product_id
    having datediff(MIN(change_date),'2019-08-16') > 0)
) as Tablet order by price desc;    

