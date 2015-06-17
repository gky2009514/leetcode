SELECT c.Name AS Employee FROM 
	(SELECT a.Name, a.Salary AS es, b.Salary AS ms FROM 
		Employee a INNER JOIN Employee b ON a.ManagerId = b.Id
	) c 
WHERE es > ms