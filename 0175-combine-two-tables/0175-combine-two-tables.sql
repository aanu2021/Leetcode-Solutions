# Write your MySQL query statement below

# SELECT p.firstName AS firstName, p.lastName AS lastName , a.city AS city , a.state AS state 

#       FROM Person p , Address a
      
#       WHERE p.personId = a.personId;


# Here these piece of code is not working as it will be showing only
# those tuples , where p.personId matches exactly with a.personId.


SELECT p.firstName AS firstName , p.lastName AS lastName , a.city AS city , a.state AS state

     FROM Person p 
     
     LEFT JOIN Address a
     
     ON p.personId = a.personId;
