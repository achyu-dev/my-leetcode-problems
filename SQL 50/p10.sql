with cte as (
select machine_id , sum(
case when activity_type='start' then -timestamp
else timestamp end ) as summer , count(*)/2 as process
from activity
group by machine_id
)

select machine_id , round ((summer/process)::NUMERIC,3) as processing_time from cte;