# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

# Note that the common statement "DELETE FROM Person" is a abbreviation of "DELETE tmp FROM Person tmp"
DELETE a FROM Person a, Person b WHERE a.email = b.email AND a.id > b.id;