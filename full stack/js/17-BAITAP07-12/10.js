// nhập tháng
let month = parseInt(prompt("Nhập mooth tháng (1-12):"));

// kiểm tra tính hợp lệ của tháng
if (!isNaN(month) && month >= 1 && month <= 12) { //NaN kiểm tra xem nó có thể chuyển đổi qua số được hay không
    // .KIỂM TRA THÁNG CÓ BAO NHIÊU NGÀY
} else {
    console.log("Tháng không hợp lệ , vui lòng nhập lại từ 1-12 ");
}