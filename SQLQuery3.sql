--Bai 1
USE Northwind
GO

CREATE FUNCTION ChaoBan
(
	@ten nvarchar (100)
)
RETURNS nvarchar(100)
AS
Begin
	RETURN N'Xin Chao Ban ' + @ten
END
GO
Print dbo.ChaoBan(N'Dinh Nhu Hai')
Go

--Bai 2
CREATE FUNCTION TenNhanVienDayDu
(
	@MaNhanVien int
)
RETURNS nvarchar(100)
AS
Begin
	Declare @KQ nvarchar(100)
	Select
		@KQ = LastName + ' '+FirstName
	From Employees
	Where EmployeeID = @MaNhanVien
	Return @KQ
END
GO
Print dbo.TenNhanVienDayDu(7)
GO
--Bai 3
CREATE FUNCTION SLKhachHangCuaQuocGia
(
	@TenQuocGia nvarchar(15)
)
RETURNS int
AS
Begin
	DECLARE @SL int
	SELECT @SL = Count(*) 
	FROM Customers
	Where Country = @TenQuocGia

	RETURN @SL
END
GO
Print dbo.SLKhachHangCuaQuocGia(N'UK')
GO

--Bai6
CREATE FUNCTION SLDonHangCuaKhachHang3
(
	@TenQuocGia nvarchar(15)
)
RETURNS int
AS
Begin
	DECLARE @SL int
	if @TenQuocGia is null
		Select @SL = Count(*)
		From Customers c , Orders o
		Where c.CustomerID = o.CustomerID
	else 
		Select @SL = Count(*)
		From Customers c , Orders o
		Where c.CustomerID = o.CustomerID and c.Country = @TenQuocGia
	RETURN @SL
END
GO
Print dbo.SLDonHangCuaKhachHang3(null)
GO

--Bai 8
CREATE FUNCTION DSDonHangCuaKhachHang
(
	@MaKhacHang nchar(5)
)
RETURNS table
AS RETURN(
	SELECT * FROM Orders
	WHERE CustomerID = @MaKhacHang
)		
GO
SELECT * FROM dbo.DSDonHangCuaKhachHang(N'HANAR')
GO
--Bai 9
CREATE FUNCTION DSDonHangCuaKhachHang1
(
    @TenQuocGia NVARCHAR(15)
)
RETURNS TABLE
AS
RETURN(
	SELECT o.*
	FROM Customers AS c
    INNER JOIN Orders AS o ON c.CustomerID = o.CustomerID
    WHERE c.Country = @TenQuocGia
);
GO
SELECT * FROM dbo.DSDonHangCuaKhachHang1(N'UK')
GO

-- bai 11
CREATE FUNCTION DSHangHoaCuaKhachHang1
(
    @MaKhachHang nchar(20)
)
RETURNS TABLE
AS RETURN
(
    SELECT p.ProductID, ProductName, SUM(od.Quantity) as TongSoLuong
	FROM Orders o, Customers c, Products p, [Order Details] od
	WHERE  c.CustomerID = o.CustomerID and o.OrderID = od.OrderID 
	and od.ProductID = p.ProductID and c.CustomerID = @MaKhachHang
	GROUP BY p.ProductID,p.ProductName
)
GO
SELECT * 
FROM dbo.DSHangHoaCuaKhachHang1(N'ALFKI');
GO