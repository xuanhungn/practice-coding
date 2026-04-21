// nhập vào bài tính chu vi, diện tích hình tròn
let r = parseInt(prompt("Mời nhập r"));
// nhập vào tính chu vi, diện tích chữ nhật
let a = Number(prompt("Nhập chiều dài hình chữ nhật"));
let b = Number(prompt("Nhập chiều rộng hình chữ nhật"))
    // Nhập 3 môn điểm trung bình
let toan = parseFloat(prompt("Nhập điểm toán: "));
let van = parseFloat(prompt("Nhập điểm văn: "));
let anh = parseFloat(prompt("Nhập điểm anh: "));

// công thức tính hình tròn
let PI = Math.PI;
let chuViHinhTron = 2 * PI * r;
let dienTichHinhTron = PI * r * r;

//công thức tính hình chữ nhật
let dienTichHinhChuNhat = a * b;
let chuViHInhChuNhat = (a + b) * 2;
//công thức tính điểm trung bình 3 môn
let diemTrungBinh = (toan + van + anh) / 3;

// xuất ra màn hình
console.log("Kết quả tính hình tròn : ");
console.log("Chu vi hình tròn: " + chuViHinhTron);
console.log("Diện tích hình tròn: " + dienTichHinhTron);

console.log("Kết quả tính chữ nhật: ");
console.log("Chu vi hình chữ nhật: " + chuViHInhChuNhat);
console.log("Diện tích hình chữ nhật: " + dienTichHinhChuNhat);

console.log("Kết quả tính điểm trung bình 3 môn: ");
console.log(diemTrungBinh.toFixed(2));