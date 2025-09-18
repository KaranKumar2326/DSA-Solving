# Write your MySQL query statement below
SELECT product_name , year, price FROM Sales as s INNER JOIN Product as p on s.product_id = p.product_id;