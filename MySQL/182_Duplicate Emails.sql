SELECT a.Email FROM 
	(SELECT Email, COUNT(Email) AS cnt FROM 
		Person GROUP BY Email HAVING cnt > 1
	) a