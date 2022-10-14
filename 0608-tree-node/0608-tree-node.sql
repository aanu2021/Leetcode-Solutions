# Write your MySQL query statement below


# Union And Select

# SELECT id , 'Root' AS type

#        FROM Tree
       
#        WHERE p_id IS NULL
       
# UNION

# SELECT id , 'Leaf' AS type

#        FROM Tree
       
#        WHERE id NOT IN(SELECT p_id FROM Tree WHERE p_id IS NOT NULL) AND p_id IS NOT NULL
       
# UNION

# SELECT id , 'Inner' AS type

#        FROM Tree
       
#        WHERE id IN (SELECT p_id FROM Tree WHERE p_id is NOT NULL) AND p_id IS NOT NULL
       
#        ORDER BY id;



# Control Flow Statement - Case

SELECT id , 

        CASE
        
        WHEN p_id IS NULL THEN 'Root'
        
        WHEN id NOT IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL) AND p_id IS NOT NULL THEN 'Leaf'
        
        ELSE 'Inner'
        
        END
        
        AS type
        
        FROM Tree
        
        ORDER BY id;

