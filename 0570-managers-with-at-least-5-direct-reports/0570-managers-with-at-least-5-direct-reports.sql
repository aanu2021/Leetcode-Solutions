# Write your MySQL query statement below
select name
from Employee
where id in (select managerId from Employee where managerId is not null group by managerId having count(*) >= 5);


# {"headers": {"Employee": ["id", "name", "department", "managerId"]}, "rows": {"Employee": [[101, "John", "A", null],[102, "Dan", "A", 101], [103, "James", "A", 101], [104, "Amy", "A", 101], [105, "Anne", "A", 101], [106, "Ron", "B", 101],[111, "John", "A", null],[112, "Dan", "A", 111], [113, "James", "A", 111], [114, "Amy", "A", 111], [115, "Anne", "A", 111], [116, "Ron", "B", 111]]}}


# 101 John A null
# 102 Dan  A 101
# 103 James A 101
# 104 Amy A 101
# 105 Anne 