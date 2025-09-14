--In 1.sql, write a SQL query to list the titles
--of all movies released in 2008.
--Your query should output a table with
--a single column for the title of each movie.

-- TO TEST: cat filename.sql | sqlite3 movies.db
-- CAN ALSO RUN: cat filename.sql | sqlite3 movies.db > output.txt

-- to redirect the output of the query to a text file called output.txt.
-- (This can be useful for checking how many rows are returned by your query!)
SELECT title
FROM movies
WHERE year = 2008;

