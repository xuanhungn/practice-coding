//if - else if - else
/* 
Nhập vào điểm TB, in ra xếp loại học sinh
    Giỏi : dtb <= 8 và dtb >= 8
    Khá : 8 > dtb >= 6.5
    TB : 6.5>dtb>=5
    Yếu : 0 <= dtb <5
*/

let dtb = parseInt(prompt("Mời nhập điểm: "));

if (dtb <= 10 && dtb >= 8) {
    console.log("Học sinh giỏi");
} else if (dtb >= 6.5 && dtb < 8) {
    console.log("Học sinh khá");
} else if (dtb = 6.5 && dtb >= 5) {
    console.log("Học sinh trung bình");
} else if (dtb = 0 && dtb < 5) {
    console.log("Học sinh yếu");
} else {
    console.log("Học sinh ngu"); - 1
}