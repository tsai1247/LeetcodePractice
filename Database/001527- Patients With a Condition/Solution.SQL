# Write your MySQL query statement below

SELECT * FROM Patients
WHERE conditions LIKE "DIAB1%" or conditions LIKE "% DIAB1%";

# the condition below can also be 「conditions REGEXP '\\bDIAB1'」，the '\b' means the boundary of words
# That is, `SELECT * FROM Patients WHERE conditions REGEXP '\\bDIAB1';`
