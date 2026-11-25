# Write your MySQL query statement below
select distinct author_id as id
from Views
where viewer_id = author_id
order by author_id asc

-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna