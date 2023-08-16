# Write your MySQL query statement below

# Insurance
# pid
# tiv_2015
# tiv_2016
# lat
# lon

# Output : Sum of all total investment values in 2016

# Conditions : 

# 1. Have the same tiv_2015 value as one or more other policyholders.

# 2. Not located in the same city.


# Task : 

# 1. First select those pid s, who are having atleast one pid (different) in the Insurance table, and both of them have the same tiv_2015 and atleast one of their lat and lon are different.


# 2. Calculate the sum of tiv_2016 values of that table.

# with Tablet as
# (select pid,tiv_2015,tiv_2016 
# from Insurance 
# group by concat(lat," ",lon)
# having count(*) = 1),
# Tablet2 as
# (select ROUND(SUM(tiv_2016),2) as tiv_2016
# from Tablet
# group by tiv_2015
# having count(*) > 1)
# select ROUND(SUM(tiv_2016),2) as tiv_2016
# from Tablet2;


select ROUND(SUM(tiv_2016),2) as tiv_2016
from Insurance
where tiv_2015 in
(
    select tiv_2015 from Insurance
    group by tiv_2015
    having count(*) > 1
)
and (lat,lon) in 
(
    select lat,lon from Insurance
    group by lat,lon
    having count(*) = 1
);


 
 