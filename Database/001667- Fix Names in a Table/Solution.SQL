# Write your MySQL query statement below

# The new SQL keywords: CONCAT, UPPER, LOWER
SELECT 
    user_id, 
    CONCAT(
        UPPER(SUBSTRING(name FROM 1 FOR 1)), 
        LOWER(SUBSTRING(name FROM 2))
    ) AS name
FROM Users ORDER BY user_id;