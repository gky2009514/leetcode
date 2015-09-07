SELECT t.Request_at Day, 
round(sum(
	case when t.Status LIKE 'cancelled_%' then 1 else 0 end) / count(*), 2) CancellationRate
FROM Trips t INNER JOIN Users u ON t.Client_Id = u.Users_Id AND u.Banned = 'No'
WHERE t.Request_at between '2013-10-01' AND '2013-10-03'
GROUP BY t.Request_at