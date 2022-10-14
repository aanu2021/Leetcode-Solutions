# Write your MySQL query statement below

SELECT id , 'Root' AS type 

       FROM Tree
       
       WHERE p_id IS NULL
       
UNION ALL

SELECT id , 'Leaf' AS type

        FROM Tree
        
        WHERE id NOT IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL) AND p_id IS NOT NULL
        
UNION ALL

SELECT id , 'Inner' AS type

         FROM Tree
         
          WHERE id IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL) AND p_id IS NOT NULL
          
          ORDER BY id;

