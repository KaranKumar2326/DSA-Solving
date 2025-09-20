# Write your MySQL query statement below
/*SELECT *
FROM Patients 
WHERE concat(substr(upper()));
ORDER BY patient_id ASC;

SELECT * FROM events WHERE EXTRACT(YEAR FROM start_time) = 2024;*/

SELECT *
FROM PATIENTS 
WHERE conditions like ('DIAB1%') OR conditions like ('% DIAB1%') ;