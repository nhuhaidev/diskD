USE Northwind
GO

CREATE PROC DSKhachHang
		@TenQuoGia nvarchar(15)
AS
Begin
	Select * From Customers
	Where Country = @TenQuoGia
End
GO

EXEC DSKhachHang N'UK'
GO
-- Bai 7
CREATE PROC DSDonHangTungQuocGia
		@TenQuocGia nvarchar(15)

AS
Begin
	Select c.Country , o.*
	From Customers c , Orders o
	Where
		c.CustomerID = o.CustomerID and c.Country = @TenQuocGia
END
GO
EXEC DSDonHangTungQuocGia N'UK'
GO

-- Bai 8
CREATE PROC SLKhachHangTungQuocGia
		@TenQuocGia nvarchar(15)
AS
Begin
	Select Count(*) as SLKhachHang
	From Customers
	Where Country = @TenQuocGia
END
GO
EXEC SLKhachHangTungQuocGia N'UK'
GO

--Bai9
CREATE PROC SLKhachHangTungQuocGia2(
		@TenQuocGia nvarchar(15)
		,@SLKhachHang int out)
AS
Begin
	Select @SLKhachHang = Count(*) From Customers
	Where Country = @TenQuocGia
END
GO
Declare @KQ int
EXEC SLKhachHangTungQuocGia2 N'UK', @KQ out
Print @KQ
GO

--Bai 10
CREATE PROC SLKhachHangTungQuocGia3(
		@TenQuocGia nvarchar (15)
		,@SLKhachHang int out
)
		
AS
Begin
	if @TenQuocGia is null
		Select @SLKhachHang = Count(*) from Customers
	else
		Select @SLKhachHang = Count(*) from Customers
		Where Country = @TenQuocGia
END
GO
Declare @KQ int
EXEC SLKhachHangTungQuocGia3 N'USA',@KQ out
Print @KQ
GO

-- Bai 11
CREATE PROC SLKhachHangTungQuocGia4(
		@TenQuocGia nvarchar (15)
		,@SLKhachHang int out
)
		
AS
Begin
	if @TenQuocGia is null
		Select @SLKhachHang = Count(*) from Customers
		Where Country = 'France'
	else
		Select @SLKhachHang = Count(*) from Customers
		Where Country = @TenQuocGia
END
GO
Declare @KQ int
EXEC SLKhachHangTungQuocGia3 null,@KQ out
Print @KQ
GO

--Bai 12
