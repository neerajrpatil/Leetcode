# Write your MySQL query statement below
with cte as (
    select min(id)
    from person
    group by email
)
delete
from person
where id not in (
    select *
    from cte
)