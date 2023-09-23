# Write your MySQL query statement below
SELECT p1.email as Email
FROM Person p1
JOIN Person p2 ON p1.email = p2.email
WHERE p1.id <> p2.id
GROUP BY p1.email
HAVING COUNT(*) > 1;