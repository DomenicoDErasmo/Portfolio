/*
Show the name and population for Sweden, Norway, and Denmark
*/
SELECT name, population
FROM world
WHERE name IN ('Sweden', 'Norway', 'Denmark');