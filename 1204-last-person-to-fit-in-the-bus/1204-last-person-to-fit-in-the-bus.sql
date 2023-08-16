# Write your MySQL query statement below

# Queue

# person_id
# person_name
# weight
# turn

with Q as 
(select * from Queue order by turn asc)

select Q1.person_name from Q Q1
where (select SUM(Q2.weight) from Q Q2 where Q1.turn >= Q2.turn) <= 1000 order by Q1.turn desc limit 1;
