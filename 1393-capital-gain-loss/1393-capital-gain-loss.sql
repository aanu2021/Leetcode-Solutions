# Write your MySQL query statement below

SELECT stock_name , 

SUM(

 CASE 
    
 WHEN operation='Buy' THEN -price
    
 ELSE price
    
 END   

) AS capital_gain_loss

FROM Stocks   

# WHERE CASE price

#       WHEN operation='Buy' THEN -price
      
#       ELSE price
      
#       END   

GROUP BY stock_name

ORDER BY stock_name;
