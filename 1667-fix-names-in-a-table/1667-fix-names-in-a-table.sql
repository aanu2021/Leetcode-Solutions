# Write your MySQL query statement below

# INITCAP is the utility that is used in SQL(Oracle) to do these , but there is no such in-built utility over MySQL

Select user_id, CONCAT(UPPER(SUBSTR(name,1,1)),LOWER(SUBSTR(name,2,LENGTH(name)))) AS name FROM Users ORDER BY user_id;
