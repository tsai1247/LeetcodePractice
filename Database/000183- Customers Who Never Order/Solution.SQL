# The "LEFT JOIN" means the result contains all data in Customers and the data from Orders if it matches "ON" condition, else "NULL".
# Therefore, the "Orders.customerId IS NULL" will filter the Customers not in Orders.
SELECT Customers.name AS Customers
FROM Customers LEFT JOIN Orders 
ON Customers.id = Orders.customerId 
WHERE Orders.customerId IS NULL;