/* Write your T-SQL query statement below */
WITH CTE as(
SELECT 
delivery_id, 
customer_id,
order_date,
customer_pref_delivery_date,
ROW_NUMBER() OVER(PARTITION BY customer_id ORDER BY order_date) AS row_number
from Delivery ) 

SELECT round(
(100*cast(count(delivery_id) as decimal)) / (select count(*) from cte where row_number=1),2) as immediate_percentage
from cte
WHERE ROW_NUMBER=1 AND
ORDER_DATE=customer_pref_delivery_date