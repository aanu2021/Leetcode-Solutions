CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      
      SELECT DISTINCT salary FROM Employee AS E1 WHERE N-1 = (SELECT COUNT(DISTINCT salary) FROM EMPLOYEE AS E2 WHERE E1.salary < E2.salary) 
      
  );
END