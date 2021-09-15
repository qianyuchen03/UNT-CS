# UNT-CS
Final Project
MEAN GREEN EAGLELIFT SYSTEM
Using inheritance and polymorphism, create an object oriented program controlling a ride share system with passengers, drivers, and rides

Pseudo Code:

Add function for passengers-
Prompt user for ID, name, payment, handicapped, rating, pets
Create passenger object
Populate object
Add object to array list

Add function for drivers-
Prompt user for ID, name, capacity, handicapped, vehicle, rating, availability, pets, notes
Create driver object
Populate object
Add object to array list

Add function for rides-
Prompt user for ID, locations, times, size of party, status, rating
Create ride object
Populate object
Add object to array list

Check function for drivers in rides class-
Prompt for driver assigned to ride
Check if driver has same qualities as the ride is defined as
When passed, continue add function

Print details function for passengers-
Prompt for passenger name
Find passenger for name (return ID)
Search all orders (passenger ID)
If passenger ID matches order, print details

Print details function for drivers-
Prompt for driver name
Find driver for name (return ID)
Search all orders (driver ID)
If driver ID matches order, print details

Print details function for rides-
Prompt for ride ID
Find ride for ID (return ID)
Search all rides (ride ID)
If ride ID matches prompted ID, print details

Edit function for passengers-
Prompt for passenger name
Prompt for criteria user wants to change
Read in new information into the collection

Edit function for drivers-
Prompt for driver name
Prompt for criteria user wants to change
Read in new information into the collection

Edit function for rides-
Prompt for ride ID
Prompt for criteria user wants to change
Read in new information into the collection

Print all entries function for passengers/drivers/rides-
Prompt for all entries for the passengers/drivers/rides
Display the entries by outputting the array list of objects, identified by their name (passenger/driver) or ID (ride)

Print rides for passengers-
Prompt for passenger name
Find passenger for name (return ID)
Output all of the rides the passenger has using the the ride IDs

Print rides for drivers-
Prompt for driver name
Find driver for name (return ID)
Output all of the rides the driver is assigned to using the ride IDs

Delete function for passengers-
Prompt for passenger ID
Get index of the passenger in the array
Assign everything in the array index to nothing
For all the array indexes after the deleted index, decrement their indexes, replacing the deleted index/entry

Delete function for drivers-
Prompt for driver ID
Get index of the driver in the array
Assign everything in the array index to nothing
For all the array indexes after the deleted index, decrement their indexes, replacing the deleted index/entry

Delete function for rides-
Prompt for ride ID
Get index of the ride in the array
Assign everything in the array index to nothing
For all the array indexes after the deleted index, decrement their indexes, replacing the deleted index/entry

Update ride status function-
Set for every 5 minutes, loop through the ride object array
Check if the current time has exceeded any of the ride objects’ drop off times
If so, edit the ride from active to completed

Print driver’s schedule in rides class function-
Prompt for driver name
Find driver for name (return ID)
Output list of all the assigned rides with their pickup times and status

Print passenger’s schedule in rides class function-
Prompt for passenger name
Find passenger for name (return ID)
Output list of all the assigned rides with their pickup times and status

Print certain status rides in rides class-
Prompt for status (active, complete, cancelled)
Loop through the ride object array
Check for the prompted status
Output list of all the selected status rides
