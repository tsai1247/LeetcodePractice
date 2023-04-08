# key of the problem: 
#       * IF(condition, value, else_value)
#       * LIKE 'some_pattern' will get true or false.
#       * 「name LIKE 'M%'」 also known as 「SUBSTRING (name, 1, 1) != 'M'」 or 「SUBSTRING (name FROM 1 FOR 1) != 'M'」
SELECT  employee_id, 
        IF(employee_id%2 = 1 AND name NOT LIKE 'M%', salary, 0) AS bonus 
FROM Employees
ORDER BY employee_id;