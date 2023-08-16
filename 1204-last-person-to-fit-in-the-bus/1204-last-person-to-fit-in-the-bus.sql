# Write your MySQL query statement below

# Queue

# person_id
# person_name
# weight
# turn


select Q1.person_name from Queue Q1
where (select SUM(Q2.weight) from Queue Q2 where Q1.turn >= Q2.turn) <= 1000 order by Q1.turn desc limit 1;
