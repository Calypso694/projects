--In 13.sql, write a SQL query to list
--the names of all people who starred in
--a movie in which Kevin Bacon also starred.
--Your query should output a table with a
--single column for the name of each person.
--There may be multiple people named
--Kevin Bacon in the database.
--Be sure to only select the Kevin Bacon born in 1958.
--Kevin Bacon himself should not be included in the resulting list.

SELECT DISTINCT p.name
FROM stars s
JOIN people p ON s.person_id = p.id
WHERE s.movie_id IN (
    SELECT s2.movie_id
    FROM stars s2
    JOIN people p2 ON s2.person_id = p2.id
    WHERE p2.name = 'Kevin Bacon' AND p2.birth = 1958
) AND p.name != 'Kevin Bacon';


