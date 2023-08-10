CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT(E1.salary) FROM EMPLOYEE E1 WHERE N-1 = (SELECT COUNT(DISTINCT E2.salary) FROM EMPLOYEE E2 WHERE E2.salary > E1.salary)
  );
END