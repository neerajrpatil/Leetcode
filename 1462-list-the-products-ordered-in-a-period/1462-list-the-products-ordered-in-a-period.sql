# Write your MySQL query statement below
select temp1.product_name,temp2.x as unit
from products temp1
join (
select p.product_id,sum(unit) as x
from products p
join orders o
on p.product_id=o.product_id and o.order_date like "2020-02%"
group by p.product_id
having x>=100
) temp2
where temp1.product_id=temp2.product_id
