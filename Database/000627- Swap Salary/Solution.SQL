# Write your MySQL query statement below
UPDATE Salary SET sex = IF(sex = 'f', 'm', 'f');

# Another solution is use "CASE":
# UPDATE Salary SET sex = CASE WHEN sex='f' THEN 'm' WHEN sex='m' THEN 'f' END;