# Write your MySQL query statement below

select * from Cinema 
where id%2 <> 0 and description <> "boring" 
order by rating desc;

# {"headers":{"cinema":["id", "movie", "description", "rating"]},"rows":{"cinema":[[1, "C", "good", 6.2], [2, "A", "fiction", 8.0], [3, "B", "great", 9.0], [4, "D", "fantastic", 4.0], [5, "E", "skytop", 9.9], [6, "F", "topest", 7.0], [7, "G", "finest", 9.5], [8, "H", "highest", 9.0], [9, "I", "3D", 9.8]]}}