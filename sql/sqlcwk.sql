/*
@Chenyu Wang

This is an sql file to put your queries for SQL coursework. 
You can write your comment in sqlite with -- or /* * /

To read the sql and execute it in the sqlite, simply
type .read sqlcwk.sql on the terminal after sqlite3 musicstore.db.
*/

/* =====================================================
   WARNNIG: DO NOT REMOVE THE DROP VIEW
   Dropping existing views if exists
   =====================================================
*/
DROP VIEW IF EXISTS vNoCustomerEmployee; 
DROP VIEW IF EXISTS v10MostSoldMusicGenres; 
DROP VIEW IF EXISTS vTopAlbumEachGenre; 
DROP VIEW IF EXISTS v20TopSellingArtists; 
DROP VIEW IF EXISTS vTopCustomerEachGenre; 

/*
============================================================================
Task 1: Complete the query for vNoCustomerEmployee.
DO NOT REMOVE THE STATEMENT "CREATE VIEW vNoCustomerEmployee AS"
============================================================================
*/
CREATE VIEW vNoCustomerEmployee AS
SELECT e.EmployeeId, e.FirstName, e.LastName, e.Title FROM employees e
WHERE e.EmployeeId NOT IN (
    SELECT DISTINCT c.SupportRepId
    FROM customers c
    WHERE c.SupportRepId IS NOT NULL
);

/*
============================================================================
Task 2: Complete the query for v10MostSoldMusicGenres
DO NOT REMOVE THE STATEMENT "CREATE VIEW v10MostSoldMusicGenres AS"
============================================================================
*/
CREATE VIEW v10MostSoldMusicGenres AS
SELECT g.Name as Genre, SUM(ii.Quantity) as Sales
FROM 
    genres g
JOIN 
    tracks t ON g.GenreId = t.GenreId
JOIN 
    invoice_items ii ON t.TrackId = ii.TrackId
GROUP BY 
    g.Name
ORDER BY 
    Sales DESC
LIMIT 10;


/*
============================================================================
Task 3: Complete the query for vTopAlbumEachGenre
DO NOT REMOVE THE STATEMENT "CREATE VIEW vTopAlbumEachGenre AS"
============================================================================
*/
CREATE VIEW vTopAlbumEachGenre AS
SELECT Genre, Album, Artist, Sales
FROM (
    SELECT 
        g.Name as Genre,
        a.Title as Album,
        ar.Name as Artist,
        SUM(ii.Quantity) as Sales,
        RANK() OVER (PARTITION BY g.Name ORDER BY SUM(ii.Quantity) DESC) as Rank
    FROM 
        genres g
    JOIN 
        tracks t ON g.GenreId = t.GenreId
    JOIN 
        albums a ON t.AlbumId = a.AlbumId
    JOIN 
        artists ar ON a.ArtistId = ar.ArtistId
    JOIN 
        invoice_items ii ON t.TrackId = ii.TrackId
    GROUP BY 
        g.Name, a.AlbumId
) as SubQuery
WHERE 
    Rank = 1;


/*
============================================================================
Task 4: Complete the query for v20TopSellingArtists
DO NOT REMOVE THE STATEMENT "CREATE VIEW v20TopSellingArtists AS"
============================================================================
*/

CREATE VIEW v20TopSellingArtists AS
SELECT ar.Name AS Artist, COUNT(DISTINCT a.AlbumId) AS TotalAlbum, SUM(ii.Quantity) AS TrackSold
FROM 
    artists ar
JOIN 
    albums a ON ar.ArtistId = a.ArtistId
JOIN 
    tracks t ON a.AlbumId = t.AlbumId
JOIN 
    invoice_items ii ON t.TrackId = ii.TrackId
GROUP BY 
    ar.ArtistId
ORDER BY 
    TrackSold DESC
LIMIT 20;

/*
============================================================================
Task 5: Complete the query for vTopCustomerEachGenre
DO NOT REMOVE THE STATEMENT "CREATE VIEW vTopCustomerEachGenre AS" 
============================================================================
*/
CREATE VIEW vTopCustomerEachGenre AS
SELECT 
    Genre,
    TopSpender,
    TotalSpending
FROM (
    SELECT 
        g.Name as Genre,
        c.FirstName || ' ' || c.LastName as TopSpender,
        ROUND(SUM(ii.UnitPrice * ii.Quantity), 2) as TotalSpending,
        ROW_NUMBER() OVER (PARTITION BY g.GenreId ORDER BY SUM(ii.UnitPrice * ii.Quantity) DESC) as rn
    FROM 
        genres g
    JOIN 
        tracks t ON g.GenreId = t.GenreId
    JOIN 
        invoice_items ii ON t.TrackId = ii.TrackId
    JOIN 
        invoices i ON ii.InvoiceId = i.InvoiceId
    JOIN 
        customers c ON i.CustomerId = c.CustomerId
    GROUP BY 
        g.GenreId, c.CustomerId
    ORDER BY 
        g.Name
) sub
WHERE 
    sub.rn = 1;
