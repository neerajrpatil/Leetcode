# Write your MySQL query statement below


-- select count(*)/(select count(*)from activity group by player_id)*100.00
-- from activity
-- where player_id,date_sub(event_date,interval 1 day)
-- in (
--     select player_id,min(event_date) as min
--     from activity
--     group by player_id;
-- )

-- ;
SELECT 
    round(COUNT(*)/(SELECT count(distinct player_id) from activity),2) AS fraction
FROM activity
WHERE (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) IN (
    SELECT player_id, MIN(event_date)
    FROM activity
    GROUP BY player_id
);

