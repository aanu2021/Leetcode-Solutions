# Write your MySQL query statement below

# If - Else  /  Case  Statement

# Syntax --> IF (Condition , if yes , if no)

# Syntax -->  Case

#             WHEN Condition THEN if yes
             
#             ELSE if no
             
#             END



# SELECT 

#        employee_id,
       
#        If(employee_id%2 AND name NOT LIKE 'M%' , salary , 0) 
       
#        AS bonus
       
#        FROM Employees 
       
#        ORDER BY employee_id
       

# SELECT employee_id,

#        CASE
       
#        WHEN employee_id%2=1 AND name NOT LIKE 'M%' THEN salary
       
#        ELSE 0
       
#        END 
       
#        AS bonus
       
#        FROM Employees
       
#        ORDER BY employee_id;

SELECT employee_id , IF(employee_id%2=1 AND name NOT LIKE 'M%',salary,0) AS bonus FROM Employees ORDER BY employee_id;
