# Write your MySQL query statement below

# UPDATE Salary 

#        SET sex = CASE sex
       
#                  WHEN 'm' THEN 'f'
                 
#                  ELSE 'm'
                 
#                  END


update Salary
set sex = case
          when sex='m' then 'f'
          else 'm'
          end