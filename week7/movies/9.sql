SELECT name
FROM people
JOIN directors ON people.id = directors.person_id
JOIN movies ON movies.id = directors.movie_id
WHERE year = 2004
ORDER BY birth;
