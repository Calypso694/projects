UPDATE shows SET title = "How I Met Your Mother" WHERE title = "How i met your mother";

SELECT * FROM shows;

UPDATE shows SET title = "The Office" WHERE title = "Office";
UPDATE shows SET title = "The Office" WHERE title = "%office";
UPDATE shows SET title = "Adventure Time" WHERE title LIKE "adventure time";
UPDATE shows SET title = "Arrow" WHERE title LIKE "arrow";
UPDATE shows SET title = "Avatar: The Last Airbender" WHERE title LIKE "avatar the last airbender"
UPDATE shows SET title = "Avatar: The Last Airbender" WHERE title LIKE "%Airbender";
UPDATE shows SET title = "Brooklyn Nine-Nine" WHERE title LIKE "B99";
UPDATE shows SET title = "Brooklyn Nine-Nine" WHERE title LIKE "Brooklyn%";
UPDATE shows SET title = "Criminal Minds" WHERE title LIKE "criminal minds";
UPDATE shows SET title = "Community" WHERE title LIKE "community";
UPDATE shows SET title = "Family Guy" WHERE title LIKE "family guy";
UPDATE shows SET title = "Friends" WHERE title LIKE "friends";
UPDATE shows SET title = "Game of Thrones" WHERE title LIKE "GoT";
UPDATE shows SET title = "Game of Thrones" WHERE title LIKE "Game&";
UPDATE shows SET title = "Gilmore Girls" WHERE title LIKE "gilmore girls";
UPDATE shows SET title = "Grey’s Anatomy" WHERE title LIKE "grey's anatomy";
UPDATE shows SET title = "Grey's AAnatomy" WHERE title LIKE "%anatomy";
UPDATE shows SET title = "It’s Always Sunny in Philadelphia" WHERE title LIKE "%Philadelphia";
UPDATE shows SET title = "Parks and Recreation" WHERE title LIKE "parks and recreation";
UPDATE shows SET title = "Parks and Recreation" WHERE title LIKE "parks%";
UPDATE shows SET title = "Sherlock" WHERE title LIKE "sherlock";
UPDATE shows SET title = "Sherlock Holmes" WHERE title LIKE "153";
UPDATE shows SET title = "Squid Game" WHERE title LIKE "squid game";
UPDATE shows SET title = "The Bachelorette" WHERE title LIKE "the bachelorette";
UPDATE shows SET title = "The Crown" WHERE title LIKE "the crown";
UPDATE shows SET title = "The Queen's Gambit" WHERE title LIKE "the queen's gambit";
UPDATE shows SET title = "The Untamed" WHERE title LIKE "the untamed";
UPDATE shows SET title = "Billions" WHERE title LIKE "billions";

SELECT * FROM shows ORDER BY title;



