# Write your MySQL query statement below

# INITCAP is the utility that is used in SQL(Oracle) to do these , but there is no such in-built utility over MySQL

# Instead of these we can use combination of CONCAT , SUBSTR , LOWER , UPPER . 


# SELECT user_id,CONCAT(UPPER(SUBSTR(name,1,1)),LOWER(SUBSTR(name,2,LENGTH(name)-1))) AS name FROM Users ORDER BY user_id;


SELECT 

user_id,

CONCAT(UPPER(LEFT(name,1)),LOWER(RIGHT(name,LENGTH(name)-1))) 

AS name

FROM Users

ORDER BY user_id;