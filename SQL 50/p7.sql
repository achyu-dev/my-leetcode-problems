# Write your MySQL query statement below
select prod.product_name, sales.price, sales.year
from Sales sales
left join Product prod 
on s.product_id = p.product_id;