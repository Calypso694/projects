-- Keep a log of any SQL queries you execute as you solve the mystery.

-- THEFT TOOK PLACE
 --July 28, 2023
 --took place on Humphrey Street.

--Start by looking for a crime scene report
--that matches the date and the location of the crime
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND year = 2023 AND street = 'Humphrey Street';

--no known witnesses for the CS Report.
--Duck was take at 10:15AM
--humphrey street bakery is mentioned
SELECT transcript, name
FROM interviews
WHERE day = 28 AND month = 7 AND transcript LIKE '%bakery%';
--3 witnesses
--littering took 16:36
--i should check the interviews
--looking for the interviewees whos name in PEOPLE match up might help.
--each person was interviewed on that day. possible 6 suspects.
SELECT interviews.name, people.name
FROM interviews
JOIN people ON interviews.name = people.name
WHERE month = 7 AND day = 28 AND year = 2023;

--Ruth saw someone she knew taking money out of ATM on LEGGETT STREET early in
--the morning. i can check ATM logs. maybe the bank account that withdrew money
--is the thief? car drove away check security logs? 10 minutes after theft?

--license plates of bakery security logs
SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND year = 2023 AND hour = 10 AND minute BETWEEN 15 AND 25;

--security log plates and names.
SELECT b.license_plate, p.name
FROM bakery_security_logs b
JOIN people p ON b.license_plate = p.license_plate
WHERE month = 7 AND day = 28 AND year = 2023 AND hour = 10 AND minute BETWEEN 15 AND 25;

--eugene mentioned phone call lasting about 60 seconds.
SELECT c.name AS caller_name, r.name AS receiver_name
FROM phone_calls
JOIN people AS c ON phone_calls.caller = c.phone_number
JOIN people AS r ON phone_calls.receiver = r.phone_number
WHERE month = 7 AND day = 28 AND year = 2023 AND duration <= 60;

--check ATM transactions to narrowdown payment info.
SELECT at.id AS transaction_id, at.year, at.month, at.day, at.atm_location, at.transaction_type, at.amount, p1.name AS sender_name, p2.name AS receiver_name
FROM atm_transactions at
JOIN bank_accounts ba ON at.account_number = ba.account_number
JOIN people p1 ON ba.person_id = p1.id
JOIN phone_calls pc ON p1.phone_number = pc.caller
JOIN people p2 ON pc.receiver = p2.phone_number
WHERE at.atm_location = 'Leggett Street' AND at.day = 28;

-- too many numbers to get down SO checking the flights and seeing which of the
--passengers is on the flight from this list will narrow down the thief and accomplice.
SELECT *
FROM airports
WHERE city = 'Fiftyville';

-- planning to take the earliest flight
--out of fiftyville tomorrow the 29th.
--theif asked accomplice to purchase the flight tickets.
--i should check the flight logs,where the flights were going and who booked the
--tickets.
SELECT flights.destination_airport_id, airports.full_name, airports.city
FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE flights.origin_airport_id = 8 AND flights.month = 7 AND flights.day = 29 AND flights.year = 2023 AND flights.hour = 8 AND flights.minute = 20;

-- id 8
-- abv CSF
--fiftyville regional airport - fiftyville
--earliest flight is 8:20. id is 36. destination is 4. look for destination of flight.
--getting the passport_number from passengers and people will narrow my search
--and check which one matches the flight
-- find passengers on the earliest flight
SELECT people.name
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.origin_airport_id = airports.id
WHERE airports.city = 'Fiftyville'
AND flights.month = 7 AND flights.day = 29 AND flights.year = 2023 AND flights.hour = 8 AND flights.minute = 20;

-- Final check to confirm the destination of the flight
--Bruce is the only consistent name in every check. 
SELECT people.name
FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.id = 36;
