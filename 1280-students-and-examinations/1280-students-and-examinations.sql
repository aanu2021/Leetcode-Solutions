# Write your MySQL query statement below

with Tablet as 
(select 
Students.student_id,
Students.student_name,
Subjects.subject_name
from Students cross join Subjects)

select 
Tablet.student_id,
Tablet.student_name,
Tablet.subject_name,
case
when (Tablet.student_id,Tablet.subject_name) not in (select student_id,subject_name from Examinations) then 0 
else COUNT(*)
end as attended_exams
from 
Tablet left join Examinations on Tablet.student_id=Examinations.student_id and Tablet.subject_name=Examinations.subject_name
group by Tablet.student_id,Tablet.subject_name
order by Tablet.student_id,Tablet.subject_name;


# {"headers": ["student_id", "student_name", "subject_name", "attended_exams"], "values": [[1, "Alice", "Math", 3], [1, "Alice", "Physics", 2], [1, "Alice", "Programming", 1], [2, "Bob", "Math", 1], [2, "Bob", "Programming", 1], [13, "John", "Math", 1], [13, "John", "Physics", 1], [13, "John", "Programming", 1]]}
 
 