# Write your MySQL query statement below
# New keywords: COUNT, GROUP_CONCAT, DISTINCT
SELECT sell_date, 
        COUNT(DISTINCT product) AS num_sold,
        GROUP_CONCAT(DISTINCT product SEPARATOR ',') AS products
FROM Activities
GROUP BY sell_date

