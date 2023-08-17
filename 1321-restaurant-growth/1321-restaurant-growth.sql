# Write your MySQL query statement below

with C as
(
    select visited_on,SUM(amount) as amount
    from Customer
    group by visited_on
)

select 
C1.visited_on, 
SUM(C2.amount) as amount,
ROUND(SUM(C2.amount)/7,2) as average_amount
from C C1,C C2
where datediff(C1.visited_on,C2.visited_on) between 0 and 6
and datediff(C1.visited_on,(select MIN(visited_on) from C)) >= 6
group by C1.visited_on
order by C1.visited_on;

