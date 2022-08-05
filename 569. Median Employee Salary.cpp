/*569. Median Employee Salary
Table: Employee
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| company      | varchar |
| salary       | int     |
+--------------+---------+
id is the primary key column for this table.
Each row of this table indicates the company and the salary of one employee.
Write an SQL query to find the median salary of each company.
Return the result table in any order.
Employee table:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 1  | A       | 2341   |
| 2  | A       | 341    |
| 3  | A       | 15     |
| 4  | A       | 15314  |
| 5  | A       | 451    |
| 6  | A       | 513    |
| 7  | B       | 15     |
| 8  | B       | 13     |
| 9  | B       | 1154   |
| 10 | B       | 1345   |
| 11 | B       | 1221   |
| 12 | B       | 234    |
| 13 | C       | 2345   |
| 14 | C       | 2645   |
| 15 | C       | 2645   |
| 16 | C       | 2652   |
| 17 | C       | 65     |
+----+---------+--------+
Output: 
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 5  | A       | 451    |
| 6  | A       | 513    |
| 12 | B       | 234    |
| 9  | B       | 1154   |
| 14 | C       | 2645   |
+----+---------+--------+
Follow up: Could you solve it without using any built-in or window functions?    */
SELECT MIN(A.Id) AS Id, A.Company, A.Salary
FROM Employee A, Employee B
WHERE A.Company = B.Company
GROUP BY A.Company, A.Salary
HAVING SUM(CASE WHEN B.Salary >= A.Salary then 1 ELSE 0 END) >= COUNT(*)/2
AND SUM(CASE WHEN B.Salary <= A.Salary then 1 ELSE 0 END) >= COUNT(*)/2


