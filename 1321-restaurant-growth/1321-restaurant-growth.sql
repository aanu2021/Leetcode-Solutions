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
where datediff(C1.visited_on,C2.visited_on) <= 6 and datediff(C1.visited_on,C2.visited_on) >= 0 and
datediff(C1.visited_on,(select MIN(visited_on) from C)) >= 6
group by C1.visited_on
order by C1.visited_on;



# SELECT a.visited_on AS visited_on, SUM(b.day_sum) AS amount,
#        ROUND(AVG(b.day_sum), 2) AS average_amount
# FROM
#   (SELECT visited_on, SUM(amount) AS day_sum FROM Customer GROUP BY visited_on ) a,
#   (SELECT visited_on, SUM(amount) AS day_sum FROM Customer GROUP BY visited_on ) b
# WHERE DATEDIFF(a.visited_on, b.visited_on) BETWEEN 0 AND 6
# GROUP BY a.visited_on
# having datediff(a.visited_on,MIN(b.visited_on)) >= 6;



# {"headers":{"Customer":["customer_id","name","visited_on","amount"]},"rows":{"Customer":
# [[1,"Jhon","2019-01-01",100],
#  [4,"Khaled","2019-01-04",130],
#  [5,"Winston","2019-01-05",110],
#  [6,"Elvis","2019-01-06",140],
#  [7,"Anna","2019-01-07",150],
#  [8,"Maria","2019-01-08",80],
#  [9,"Jaze","2019-01-09",110],
#  [1,"Jhon","2019-01-10",130],
#  [3,"Jade","2019-01-10",150]]}}


# {"headers": ["visited_on", "amount", "average_amount"], "values":
# [["2019-01-10", 1000, 142.86]]}


# {"headers":["visited_on","amount","average_amount"],"values":[["2019-01-07",630,90.00000],
# ["2019-01-08",610,87.14000],                     ["2019-01-09",720,102.86000],                         ["2019-01-10",1000,142.86000]]}
