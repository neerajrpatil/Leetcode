-- # Write your MySQL query statement below
-- SELECT name FROM Customer
-- WHERE referee_id IS NULL or referee_id!=2;
select name from customer
where referee_id is  null or referee_id!=2

-- to handle null values i can use = operator
-- i must use is null, is not null