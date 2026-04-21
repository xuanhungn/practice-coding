// nam nhuan 
/*
Viết chuong trình nhập vào 1 năm dương lịch,
kiểm tra xem năm đó có phải là năm nhuận hay không
gợi ý :năm nhuận là năm 
(chia hết cho 4, và khoong chia hết cho 100 ) hoặc (chia hheets cho 400)
((năm %4 ===0) && nam %100 !==0)) || (nam %400 ===0)


case test :
      năm nhuận : 2004, 2008, 2012, 2016, 2020, 2024
      năm kh nhuận : 1900, 2025
*/

let nam = Number(prompt("Mời nhập vào 1 năm dương lịch"));
if ((nam % 4 === 0) && (nam % 100 !== 0) || (nam % 400 === 0)) {
    console.log(`${nam} là năm nhuận `);
} else {
    console.log("Không phải năm nhuận")
}