# Write your MySQL query statement below

SELECT DISTINCT a.id

FROM Weather a,Weather b

WHERE a.temperature > b.temperature

AND DATEDIFF(a.recordDate,b.recordDate) = 1;