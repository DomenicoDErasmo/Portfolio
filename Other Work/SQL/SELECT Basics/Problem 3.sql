/*
Select the names and areas of countries with an area between 200,000 and 250,000 square km
*/

SELECT name, area
FROM world
WHERE area BETWEEN 200000 AND 250000